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

#ifndef ROSLIB_PROTOBUFFER_TRAITS_H
#define ROSLIB_PROTOBUFFER_TRAITS_H

#include <map>
#include <string>
#include <typeinfo>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <ros/time.h>

#include "message_forward.h"
#include "message_traits.h"

namespace ros {
namespace message_traits {
// protobuffer trait
// static std::map<std::string, std::string> type_md5_map;

template <typename T>
// 当我们将 MyMessage 作为模板参数 T
// 传递给模板特化时，它会匹配这个模板特化的实现。(偏特化)
// std::enable_if<true>::type 将被解析为 void 类型。
struct DataType<T, typename std::enable_if<std::is_base_of<
                       ::google::protobuf::Message, T>::value>::type> {
  static const char* value() {  // 返回消息类型 T 的数据类型名称 // 无参
    static std::string data_type = "";
    data_type = "pb_msgs/" + T::descriptor()->name();
    // T::descriptor()->name() 返回消息类型的名称
    return data_type.c_str();
    // 返回 data_type 的 C 风格字符串（const char*）
  }
  static const char* value(const T&) { return value(); }  // 有参
};

template <typename T>
struct MD5Sum<T, typename std::enable_if<std::is_base_of<
                     ::google::protobuf::Message, T>::value>::type> {
  // std::enable_if 和 std::is_base_of 用于在编译时检查类型 T 是否继承自
  // ::google::protobuf::Message
  static const char* value() { return "proto_md5"; }
  static const char* value(const T&) { return value(); }
};

template <typename T>
struct Definition<T, typename std::enable_if<std::is_base_of<
                         ::google::protobuf::Message, T>::value>::type> {
  static const char* value() {  // 返回消息定义信息的字符串
    const google::protobuf::Descriptor* descriptor = T::descriptor();
    // 获取消息类型 T 的描述符

    static std::string des;                // 静态局部变量
    static std::atomic<bool> flag{false};  // 原子操作，避免用锁

    // 不是第一次调用
    if (flag) {
      return des.c_str();
    }
    if (descriptor) {
      des.append("\n================\n");
      des.append("file_name: ");
      des.append(descriptor->file()->name());  // 添加文件名
      des.append(";\n");
      des.append("proto name: ");
      des.append(descriptor->full_name());  // 添加 proto 名称
      des.append(";\n");

      // for (int i = 0; i < descriptor->field_count(); ++i) {
      //   const google::protobuf::FieldDescriptor* field =
      //   descriptor->field(i); std::cout << "Field name: " << field->name()
      //             << ", type: " << field->type()
      //             << "file: " << field->file()->name() << std::endl;
      //   des.append("value_name: ");
      //   des.append(field->name());
      //   des.append("; ");
      //   des.append("type: ");
      //   des.append(google::protobuf::FieldDescriptor::TypeName(field->type()));
      //   des.append(";\n");
      // }
      des.append(descriptor->DebugString());
      des.append("1================\n");
      flag = true;
    } else {
      std::cout << "Descriptor is null." << std::endl;
    }

    return des.c_str();
  }
  static const char* value(const T&) { return value(); }
};

template <typename T>
struct HasHeader<T, typename std::enable_if<std::is_base_of<
                        ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct HasHeader<T const, typename std::enable_if<std::is_base_of<
                              ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsFixedSize<T, typename std::enable_if<std::is_base_of<
                          ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsFixedSize<T const, typename std::enable_if<std::is_base_of<
                                ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsMessage<T, typename std::enable_if<std::is_base_of<
                        ::google::protobuf::Message, T>::value>::type>
    : TrueType {};

template <typename T>
struct IsMessage<T const, typename std::enable_if<std::is_base_of<
                              ::google::protobuf::Message, T>::value>::type>
    : TrueType {};

}  // namespace message_traits
}  // namespace ros

#endif  // ROSLIB_MESSAGE_TRAITS_H
