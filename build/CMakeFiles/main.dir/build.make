# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shashank/Documents/meshing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shashank/Documents/meshing/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shashank/Documents/meshing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/shashank/Documents/meshing/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shashank/Documents/meshing/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shashank/Documents/meshing/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/main.cpp.o.requires

CMakeFiles/main.dir/src/main.cpp.o.provides: CMakeFiles/main.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/main.cpp.o.provides

CMakeFiles/main.dir/src/main.cpp.o.provides.build: CMakeFiles/main.dir/src/main.cpp.o


CMakeFiles/main.dir/src/unionFind.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/unionFind.cpp.o: ../src/unionFind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shashank/Documents/meshing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/unionFind.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/unionFind.cpp.o -c /home/shashank/Documents/meshing/src/unionFind.cpp

CMakeFiles/main.dir/src/unionFind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/unionFind.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shashank/Documents/meshing/src/unionFind.cpp > CMakeFiles/main.dir/src/unionFind.cpp.i

CMakeFiles/main.dir/src/unionFind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/unionFind.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shashank/Documents/meshing/src/unionFind.cpp -o CMakeFiles/main.dir/src/unionFind.cpp.s

CMakeFiles/main.dir/src/unionFind.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/src/unionFind.cpp.o.requires

CMakeFiles/main.dir/src/unionFind.cpp.o.provides: CMakeFiles/main.dir/src/unionFind.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/unionFind.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/src/unionFind.cpp.o.provides

CMakeFiles/main.dir/src/unionFind.cpp.o.provides.build: CMakeFiles/main.dir/src/unionFind.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/unionFind.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/unionFind.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
main: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shashank/Documents/meshing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/unionFind.cpp.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/shashank/Documents/meshing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shashank/Documents/meshing /home/shashank/Documents/meshing /home/shashank/Documents/meshing/build /home/shashank/Documents/meshing/build /home/shashank/Documents/meshing/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
