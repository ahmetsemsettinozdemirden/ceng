# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sems/CLionProjects/cuda-saxpy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cuda_saxpy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cuda_saxpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cuda_saxpy.dir/flags.make

CMakeFiles/cuda_saxpy.dir/main.c.o: CMakeFiles/cuda_saxpy.dir/flags.make
CMakeFiles/cuda_saxpy.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cuda_saxpy.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cuda_saxpy.dir/main.c.o   -c /Users/sems/CLionProjects/cuda-saxpy/main.c

CMakeFiles/cuda_saxpy.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cuda_saxpy.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/sems/CLionProjects/cuda-saxpy/main.c > CMakeFiles/cuda_saxpy.dir/main.c.i

CMakeFiles/cuda_saxpy.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cuda_saxpy.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/sems/CLionProjects/cuda-saxpy/main.c -o CMakeFiles/cuda_saxpy.dir/main.c.s

# Object files for target cuda_saxpy
cuda_saxpy_OBJECTS = \
"CMakeFiles/cuda_saxpy.dir/main.c.o"

# External object files for target cuda_saxpy
cuda_saxpy_EXTERNAL_OBJECTS =

cuda_saxpy: CMakeFiles/cuda_saxpy.dir/main.c.o
cuda_saxpy: CMakeFiles/cuda_saxpy.dir/build.make
cuda_saxpy: CMakeFiles/cuda_saxpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cuda_saxpy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cuda_saxpy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cuda_saxpy.dir/build: cuda_saxpy

.PHONY : CMakeFiles/cuda_saxpy.dir/build

CMakeFiles/cuda_saxpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cuda_saxpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cuda_saxpy.dir/clean

CMakeFiles/cuda_saxpy.dir/depend:
	cd /Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sems/CLionProjects/cuda-saxpy /Users/sems/CLionProjects/cuda-saxpy /Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug /Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug /Users/sems/CLionProjects/cuda-saxpy/cmake-build-debug/CMakeFiles/cuda_saxpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cuda_saxpy.dir/depend

