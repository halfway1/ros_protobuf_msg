# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /work

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/build

# Include any dependencies generated for this target.
include CMakeFiles/pb_talker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pb_talker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pb_talker.dir/flags.make

CMakeFiles/pb_talker.dir/pb_talker.cpp.o: CMakeFiles/pb_talker.dir/flags.make
CMakeFiles/pb_talker.dir/pb_talker.cpp.o: ../pb_talker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pb_talker.dir/pb_talker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pb_talker.dir/pb_talker.cpp.o -c /work/pb_talker.cpp

CMakeFiles/pb_talker.dir/pb_talker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pb_talker.dir/pb_talker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /work/pb_talker.cpp > CMakeFiles/pb_talker.dir/pb_talker.cpp.i

CMakeFiles/pb_talker.dir/pb_talker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pb_talker.dir/pb_talker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /work/pb_talker.cpp -o CMakeFiles/pb_talker.dir/pb_talker.cpp.s

# Object files for target pb_talker
pb_talker_OBJECTS = \
"CMakeFiles/pb_talker.dir/pb_talker.cpp.o"

# External object files for target pb_talker
pb_talker_EXTERNAL_OBJECTS =

devel/lib/myproject/pb_talker: CMakeFiles/pb_talker.dir/pb_talker.cpp.o
devel/lib/myproject/pb_talker: CMakeFiles/pb_talker.dir/build.make
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/libroscpp.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/librosconsole.so
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/librosconsole_log4cxx.so
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/librosconsole_backend_interface.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/libroscpp_serialization.so
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/libxmlrpcpp.so
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/librostime.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
devel/lib/myproject/pb_talker: /opt/ros/noetic/lib/libcpp_common.so
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
devel/lib/myproject/pb_talker: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/myproject/pb_talker: devel/lib/libpb_proto.so
devel/lib/myproject/pb_talker: devel/lib/libroscpp_proto_serialization.so
devel/lib/myproject/pb_talker: /usr/local/lib/libprotobuf.so
devel/lib/myproject/pb_talker: CMakeFiles/pb_talker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable devel/lib/myproject/pb_talker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pb_talker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pb_talker.dir/build: devel/lib/myproject/pb_talker

.PHONY : CMakeFiles/pb_talker.dir/build

CMakeFiles/pb_talker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pb_talker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pb_talker.dir/clean

CMakeFiles/pb_talker.dir/depend:
	cd /work/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work /work /work/build /work/build /work/build/CMakeFiles/pb_talker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pb_talker.dir/depend

