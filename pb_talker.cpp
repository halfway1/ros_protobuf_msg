#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>

#include "ros/ros.h"

#include "publish_info.pb.h"
int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  // 将 ROS 默认日志记录器的日志级别设置为 Debug
  ros::NodeHandle n;

  ros::Publisher pub =
      n.advertise<superbai::sample::PublishInfo>("/Sorbai", 1000);

  ros::Rate loop_rate(10);
  // 目标频率为 10 Hz（即每秒 10 次）

  superbai::sample::PublishInfo proto_msg_info;
  proto_msg_info.set_name("sorbai");
  proto_msg_info.set_message_type("test_message");
  proto_msg_info.set_publish_msg("sorbai is a bilibili up");

  int count = 0;
  while (ros::ok()) {
    pub.publish(proto_msg_info);
    // publish函数
    std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}
