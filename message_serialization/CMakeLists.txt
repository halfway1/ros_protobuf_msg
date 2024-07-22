
# project(roscpp_serialization)
# find_package(catkin REQUIRED COMPONENTS cpp_common roscpp_traits rostime)
# catkin_package(
#   INCLUDE_DIRS include
#   LIBRARIES roscpp_serialization
#   CATKIN_DEPENDS cpp_common roscpp_traits rostime
# )

include_directories(include ${catkin_INCLUDE_DIRS})
# include_directories：告诉 CMake 在构建过程中要搜索的头文件目录。
link_directories(${catkin_LIBRARY_DIRS})
# link_directories：告诉 CMake 在链接过程中要搜索的库文件目录
# include_directories(message_serialization/ros)

add_library(roscpp_proto_serialization src/serialization.cpp)

install(TARGETS roscpp_proto_serialization
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})
# 安装 roscpp_proto_serialization 库   指定静态库（.a 文件）安装的位置
# 指定共享库（.so 文件）安装的位置。  指定可执行文件（如果有的话）安装的位置

message("!!!!!!!!!!!!!!!!!!!!!!")
message("var = ${CMAKE_CURRENT_SOURCE_DIR}")

set(files_to_install
${CMAKE_CURRENT_SOURCE_DIR}/include/ros/*
)
# 这段代码将 include/ros/ 目录下的所有文件的路径存储在变量 files_to_install 中


add_custom_target(copy_serialization_files
  COMMAND ${CMAKE_COMMAND} -E copy ${files_to_install} /opt/ros/noetic/include/ros/
)
# 不会立即执行


# install(DIRECTORY include/
#   DESTINATION /opt/ros/melodic/include/
#   FILES_MATCHING PATTERN "*.h")
