#include <iomanip>
#include <iostream>

#include "superbai.pb.h"

void PrintHex(const std::string& str) {
  for (const unsigned char c : str) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(c);
  }
  std::cout << std::endl;
}
// std::hex：将输出格式设置为十六进制。
// std::setw(2)：设置输出的宽度为 2 位。
// std::setfill('0')：用 0 填充不足 2 位的情况。
// static_cast<int>(c)：将字符 c 转换为 int 类型，以便输出其十六进制表示。

int main() {
  // std::string pb_str;
  // superbai::sample::RosProtoTest proto_test;
  // 0801
  // 0000 1000 0000 0001
  // tag-value
  // tag 的二进制：000 1 000
  //  wire_type的二进制： 000  0
  // field_num的二进制：0001     1
  // int32 num = 1;
  // wire_type : 0
  // field_num : 1

  // 200
  // 08c801
  //  0000 1000    c801

  // a00601
  // 1010 0000 0000 0110 0000 0001
  // 010 0000 000 0110
  // 000 01100100/feild_num = 100  000/type=0
  // int

  // proto_test.set_num(1);

  // 12087375706572626169
  // 0001 0010 0000 1000 01110011 0111 0101 01110000011001010111001
  // tag: 001 0 010/type = 2
  // len: 000 1000 8
  // value:01110011 ---115   s
  // 0111 0101 ---117 u

  // proto_test.set_name("superbai");
  // proto_test.SerializeToString(&pb_str);
  // PrintHex(pb_str);

  std::string des;
  const google::protobuf::Descriptor* descriptor =
      superbai::sample::RosProtoTest::descriptor();
  // 获取消息类型RosProtoTest的描述符（Descriptor对象）。描述符包含了该消息类型的元数据，如字段信息
  for (int i = 0; i < descriptor->field_count(); ++i) {
    const google::protobuf::FieldDescriptor* field = descriptor->field(i);
    // 这段代码遍历消息类型的所有字段，descriptor->field_count()返回字段的数量，descriptor->field(i)返回第i个字段的描述符（FieldDescriptor对象）

    des.append("value_name: ");
    des.append(field->name());
    des.append("; ");
    des.append("type: ");
    des.append(google::protobuf::FieldDescriptor::TypeName(field->type()));
    des.append(";\n");
    // 构建每个字段的描述信息，包括字段名和字段类型。field->name()返回字段的名字，google::protobuf::FieldDescriptor::TypeName(field->type())返回字段类型的字符串表示
  }
  std::cout << des << std::endl;
}