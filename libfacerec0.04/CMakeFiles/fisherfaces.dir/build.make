# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/pi/git/emobot/libfacerec0.04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/git/emobot/libfacerec0.04

# Include any dependencies generated for this target.
include CMakeFiles/fisherfaces.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fisherfaces.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fisherfaces.dir/flags.make

CMakeFiles/fisherfaces.dir/src/main.cpp.o: CMakeFiles/fisherfaces.dir/flags.make
CMakeFiles/fisherfaces.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/git/emobot/libfacerec0.04/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/fisherfaces.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fisherfaces.dir/src/main.cpp.o -c /home/pi/git/emobot/libfacerec0.04/src/main.cpp

CMakeFiles/fisherfaces.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fisherfaces.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/git/emobot/libfacerec0.04/src/main.cpp > CMakeFiles/fisherfaces.dir/src/main.cpp.i

CMakeFiles/fisherfaces.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fisherfaces.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/git/emobot/libfacerec0.04/src/main.cpp -o CMakeFiles/fisherfaces.dir/src/main.cpp.s

CMakeFiles/fisherfaces.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/fisherfaces.dir/src/main.cpp.o.requires

CMakeFiles/fisherfaces.dir/src/main.cpp.o.provides: CMakeFiles/fisherfaces.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fisherfaces.dir/build.make CMakeFiles/fisherfaces.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/fisherfaces.dir/src/main.cpp.o.provides

CMakeFiles/fisherfaces.dir/src/main.cpp.o.provides.build: CMakeFiles/fisherfaces.dir/src/main.cpp.o

# Object files for target fisherfaces
fisherfaces_OBJECTS = \
"CMakeFiles/fisherfaces.dir/src/main.cpp.o"

# External object files for target fisherfaces
fisherfaces_EXTERNAL_OBJECTS =

fisherfaces: CMakeFiles/fisherfaces.dir/src/main.cpp.o
fisherfaces: CMakeFiles/fisherfaces.dir/build.make
fisherfaces: libopencv_facerec.a
fisherfaces: CMakeFiles/fisherfaces.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable fisherfaces"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fisherfaces.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fisherfaces.dir/build: fisherfaces
.PHONY : CMakeFiles/fisherfaces.dir/build

CMakeFiles/fisherfaces.dir/requires: CMakeFiles/fisherfaces.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/fisherfaces.dir/requires

CMakeFiles/fisherfaces.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fisherfaces.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fisherfaces.dir/clean

CMakeFiles/fisherfaces.dir/depend:
	cd /home/pi/git/emobot/libfacerec0.04 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/git/emobot/libfacerec0.04 /home/pi/git/emobot/libfacerec0.04 /home/pi/git/emobot/libfacerec0.04 /home/pi/git/emobot/libfacerec0.04 /home/pi/git/emobot/libfacerec0.04/CMakeFiles/fisherfaces.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fisherfaces.dir/depend

