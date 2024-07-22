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

#ifndef ROSLIB_SERIALIZED_MESSAGE_H
#define ROSLIB_SERIALIZED_MESSAGE_H

#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>

#include "roscpp_serialization_macros.h"

namespace ros {

// ROSCPP_SERIALIZATION_DECL 宏的作用是控制符号的可见性，以确保类
// SerializedMessage 在共享库和使用该共享库的应用程序中都能够正确地访问
class ROSCPP_SERIALIZATION_DECL SerializedMessage {
 public:
  boost::shared_array<uint8_t> buf;
  // 存储被序列化的消息的字节流---每一个字节存储8位
  //  uint8_t 表示一个 8 位（1 字节）无符号整数。
  //  由于它是无符号的，所以其取值范围是 0 到 255
  // uint8_t 经常用于字节操作、序列化、网络协议实现、嵌入式系统编程等场景
  size_t num_bytes;        // 存储字节流的长度
  uint8_t* message_start;  // 指向消息字节流的起始位置的指针

  boost::shared_ptr<void const> message;  // 用于存储反序列化后的消息
  const std::type_info* type_info;        // 用于存储消息的类型信息

  SerializedMessage()
      : buf(boost::shared_array<uint8_t>()),
        num_bytes(0),
        message_start(0),
        type_info(0) {}

  SerializedMessage(boost::shared_array<uint8_t> buf, size_t num_bytes)
      : buf(buf),
        num_bytes(num_bytes),
        message_start(buf ? buf.get() : 0),
        type_info(0) {}
};

}  // namespace ros

#endif  // ROSLIB_SERIALIZED_MESSAGE_H
