

set(traits_files
${CMAKE_CURRENT_SOURCE_DIR}/include/ros/*
)


add_custom_target(copy_traits_files
  COMMAND ${CMAKE_COMMAND} -E copy ${traits_files} /opt/ros/noetic/include/ros/
)
# - 用于在构建过程中添加自定义目标 该命令可以用于添加一些不需要编译的操作，如运行脚本、复制文件等
# 这里不执行

# install(DIRECTORY include/
#   DESTINATION /opt/ros/noetic/include/
#   FILES_MATCHING PATTERN "*.h")
