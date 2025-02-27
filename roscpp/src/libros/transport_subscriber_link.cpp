
/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the
 * names of its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "ros/transport_subscriber_link.h"

#include <boost/bind.hpp>

#include "ros/connection.h"
#include "ros/connection_manager.h"
#include "ros/file_log.h"
#include "ros/header.h"
#include "ros/publication.h"
#include "ros/this_node.h"
#include "ros/topic_manager.h"
#include "ros/transport/transport.h"

namespace ros {

TransportSubscriberLink::TransportSubscriberLink()
    : writing_message_(false), header_written_(false), queue_full_(false) {}

TransportSubscriberLink::~TransportSubscriberLink() {
  drop();
  connection_->removeDropListener(dropped_conn_);
}

bool TransportSubscriberLink::initialize(const ConnectionPtr& connection) {
  connection_ = connection;
  dropped_conn_ = connection_->addDropListener(
      boost::bind(&TransportSubscriberLink::onConnectionDropped, this,
                  boost::placeholders::_1));

  return true;
}

bool TransportSubscriberLink::handleHeader(const Header& header) {
  std::string topic;
  if (!header.getValue("topic", topic)) {
    std::string msg(
        "Header from subscriber did not have the required element: topic");

    ROS_ERROR("%s", msg.c_str());
    connection_->sendHeaderError(msg);

    return false;
  }

  // This will get validated by validateHeader below
  std::string client_callerid;
  header.getValue("callerid", client_callerid);
  PublicationPtr pt = TopicManager::instance()->lookupPublication(topic);
  if (!pt) {
    std::string msg =
        std::string("received a connection for a nonexistent topic [") + topic +
        std::string("] from [" +
                    connection_->getTransport()->getTransportInfo() + "] [" +
                    client_callerid + "].");

    ROSCPP_LOG_DEBUG("%s", msg.c_str());
    connection_->sendHeaderError(msg);

    return false;
  }

  std::string error_msg;
  if (!pt->validateHeader(header, error_msg)) {
    ROSCPP_LOG_DEBUG("%s", error_msg.c_str());
    connection_->sendHeaderError(error_msg);

    return false;
  }

  destination_caller_id_ = client_callerid;
  connection_id_ = ConnectionManager::instance()->getNewConnectionID();
  topic_ = pt->getName();
  parent_ = PublicationWPtr(pt);

  // Send back a success, with info
  M_string m;
  m["type"] = pt->getDataType();
  m["md5sum"] = pt->getMD5Sum();
  m["message_definition"] = pt->getMessageDefinition();
  m["callerid"] = this_node::getName();
  m["latching"] = pt->isLatching() ? "1" : "0";
  m["topic"] = topic_;
  connection_->writeHeader(
      m, boost::bind(&TransportSubscriberLink::onHeaderWritten, this,
                     boost::placeholders::_1));

  pt->addSubscriberLink(shared_from_this());

  return true;
}

void TransportSubscriberLink::onConnectionDropped(const ConnectionPtr& conn) {
  (void)conn;
  ROS_ASSERT(conn == connection_);

  PublicationPtr parent = parent_.lock();

  if (parent) {
    ROSCPP_CONN_LOG_DEBUG("Connection to subscriber [%s] to topic [%s] dropped",
                          connection_->getRemoteString().c_str(),
                          topic_.c_str());

    parent->removeSubscriberLink(shared_from_this());
  }
}

void TransportSubscriberLink::onHeaderWritten(const ConnectionPtr& conn) {
  (void)conn;
  header_written_ = true;
  startMessageWrite(true);
}

void TransportSubscriberLink::onMessageWritten(const ConnectionPtr& conn) {
  (void)conn;
  writing_message_ = false;
  startMessageWrite(true);
}

// startMessageWrite
void TransportSubscriberLink::startMessageWrite(bool immediate_write) {
  boost::shared_array<uint8_t> dummy;
  SerializedMessage m(dummy, (uint32_t)0);

  {
    boost::mutex::scoped_lock lock(outbox_mutex_);
    if (writing_message_ || !header_written_) {
      // 如果当前正在写入消息 writing_message_ 或者头信息尚未写入
      return;
    }

    if (!outbox_.empty()) {  // 如果出站队列 outbox_ 非空
      writing_message_ = true;
      m = outbox_.front();
      outbox_.pop();
      // 设置 writing_message_ 标志为 true，表示正在写入消息。
      // 将队列中的第一个消息 m 取出，并从队列中移除。
    }
  }

  if (m.num_bytes > 0) {
    // write
    connection_->write(m.buf, m.num_bytes,
                       boost::bind(&TransportSubscriberLink::onMessageWritten,
                                   this, boost::placeholders::_1),
                       immediate_write);
  }
}

// enqueueMessage
void TransportSubscriberLink::enqueueMessage(const SerializedMessage& m,
                                             bool ser, bool nocopy) {
  (void)nocopy;
  if (!ser) {
    return;
  }
  // 如果 ser 为 false，表示不需要序列化，函数直接返回

  {
    boost::mutex::scoped_lock lock(outbox_mutex_);

    int max_queue = 0;
    if (PublicationPtr parent = parent_.lock()) {
      max_queue = parent->getMaxQueue();
    }

    ROS_DEBUG_NAMED("superdebug",
                    "TransportSubscriberLink on topic [%s] to caller [%s], "
                    "queueing message (queue size [%d])",
                    topic_.c_str(), destination_caller_id_.c_str(),
                    (int)outbox_.size());

    if (max_queue > 0 && (int)outbox_.size() >= max_queue) {
      if (!queue_full_) {
        ROS_DEBUG(
            "Outgoing queue full for topic [%s].  "
            "Discarding oldest message",
            topic_.c_str());
      }

      outbox_
          .pop();  // toss out the oldest thing in the queue to make room for us
      queue_full_ = true;
    } else {
      queue_full_ = false;
    }

    outbox_.push(m);
  }

  startMessageWrite(false);
  // startMessageWrite

  stats_.messages_sent_++;
  stats_.bytes_sent_ += m.num_bytes;
  stats_.message_data_sent_ += m.num_bytes;
  // 更新统计信息：增加已发送消息数和字节数
}

std::string TransportSubscriberLink::getTransportType() {
  return connection_->getTransport()->getType();
}

std::string TransportSubscriberLink::getTransportInfo() {
  return connection_->getTransport()->getTransportInfo();
}

void TransportSubscriberLink::drop() {
  // Only drop the connection if it's not already sending a header error
  // If it is, it will automatically drop itself
  if (connection_->isSendingHeaderError()) {
    connection_->removeDropListener(dropped_conn_);
  } else {
    connection_->drop(Connection::Destructing);
  }
}

}  // namespace ros
