/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
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

#include "ros/poll_manager.h"

#include <signal.h>

#include "ros/common.h"

namespace ros {

const PollManagerPtr& PollManager::instance() {
  static PollManagerPtr poll_manager = boost::make_shared<PollManager>();
  return poll_manager;
}

PollManager::PollManager() : shutting_down_(false) {}

PollManager::~PollManager() { shutdown(); }

// PollManager::start()
void PollManager::start() {
  shutting_down_ = false;
  thread_ = boost::thread(&PollManager::threadFunc, this);
  // thread_ 是 boost::thread 对象，用来管理和控制线程的实例
  // threadFunc函数
}

void PollManager::shutdown() {
  if (shutting_down_) return;

  shutting_down_ = true;
  if (thread_.get_id() != boost::this_thread::get_id()) {
    thread_.join();
  }

  boost::recursive_mutex::scoped_lock lock(signal_mutex_);
  poll_signal_.disconnect_all_slots();
}

// PollManager::start()
void PollManager::threadFunc() {
  // 屏蔽所有信号
  disableAllSignalsInThisThread();

  while (!shutting_down_) {
    {
      boost::recursive_mutex::scoped_lock lock(signal_mutex_);
      // // 执行所有与这个信号相链接的回调函数 监听器函数
      poll_signal_();
    }

    if (shutting_down_) {
      return;
    }

    poll_set_.update(100);
  }
}

// TopicManager::instance()->start()
boost::signals2::connection PollManager::addPollThreadListener(
    const VoidFunc& func) {  // 轮询执行
  boost::recursive_mutex::scoped_lock lock(signal_mutex_);
  return poll_signal_.connect(func);
}
// 通过使用信号与槽机制，可以动态地注册和调用多个监听器函数，实现轮询管理器在不同情况下的灵活响应和操作。

void PollManager::removePollThreadListener(boost::signals2::connection c) {
  boost::recursive_mutex::scoped_lock lock(signal_mutex_);
  c.disconnect();
}

}  // namespace ros
