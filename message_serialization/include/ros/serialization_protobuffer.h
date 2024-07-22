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
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, ORS
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROSCPP_SERIALIZATION_PROTOBUFFER_H
#define ROSCPP_SERIALIZATION_PROTOBUFFER_H

#include <google/protobuf/message.h>

#include "serialization.h"

namespace ros {
namespace serialization {
// protobuffer serialization

// Serializer类，实现这个类的偏特化
// std::is base of<::google::protobuf::Message, std::string>::value false
// std::is base of<::google::protobuf::Message, bool>::value false
// std::is base of<::google::protobuf::Message,
// superbai::sample::PublishInfo>::value true std::is base
// of<::google::protobuf::Message, superbai::sample::work>::value true
// std::enable_if<std::is base of<true>::type void
// T是否为::google::protobuf::Messag的子类
// std::is_base_of<::google::protobuf::Message,
// T>::value>为真时，走偏特化，反之全特化 需要重写类中相应函数
template <typename T>
struct Serializer<T, typename std::enable_if<std::is_base_of<
                         ::google::protobuf::Message, T>::value>::type> {
  // ros::serialization::Serializer<superbai::sample::PublishInfo,
  // void>::write<ros::serialization::OStream>(ros::serialization::OStream&,
  // superbai::sample::PublishInfo const&)
  template <typename Stream>
  inline static void write(Stream &stream, const T &t) {
    std::string pb_str;
    // 传进来的对象如何序列化为二进制
    // 序列化t对象，把二进制的数据存到pb_str
    // t已经是proto的数据类型，可以使用proto一些接口
    t.SerializeToString(&pb_str);
    // 4个字节
    uint32_t len = (uint32_t)pb_str.size();

    // OStream
    // std::string
    // // 调用的是基本数据类型的特化
    stream.next(len);
    // next

    if (len > 0) {
      memcpy(stream.advance((uint32_t)len), pb_str.data(), len);
      // pb_str.data() 返回指向字符串内容的指针。如果 pb_str
      // 是空字符串（即尚未设置内容），则返回的指针指向一个空字符串
    }
    // std::cout << "pb_str" << std::endl;
    // stream.next(pb_str);
  }

  // ros反序列化的接口
  template <typename Stream>
  inline static void read(Stream &stream, T &t) {
    uint32_t len;
    // IStream
    stream.next(len);
    // std::cout << "len: " << len << std::endl;

    std::string pb_str;
    if (len > 0) {
      const char *data_ptr =
          reinterpret_cast<const char *>(stream.advance(len));
      // 将流的当前位置前进 len 字节，并返回前进后的位置指针。
      // 使用 reinterpret_cast 将指针转换为 const char* 类型

      pb_str = std::string(data_ptr, len);
      // 从指针 data_ptr 所指向的内存位置开始，读取 len
      // 个字节，并使用这些字节构造一个 std::string 对象 pb_str
    } else {
      pb_str.clear();
    }

    // stream.next(pb_str);
    t.ParseFromString(pb_str);  // protobuf 反序列化接口
  }

  inline static uint32_t serializedLength(const T &t) {
    std::string pb_str;
    t.SerializeToString(&pb_str);  // protobuf 反序列化接口
    return 4 + (uint32_t)pb_str.size();
  }
};

// 重写write() read() serializedLength()三个函数

}  // namespace serialization
}  // namespace ros

#endif  // ROSCPP_SERIALIZATION_H
