# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sems/Ceng112-DataStructures/homeworks/hw02a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sems/Ceng112-DataStructures/homeworks/hw02a/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sems/Ceng112-DataStructures/homeworks/hw02a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /Users/sems/Ceng112-DataStructures/homeworks/hw02a/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sems/Ceng112-DataStructures/homeworks/hw02a/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sems/Ceng112-DataStructures/homeworks/hw02a/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/main.cpp.o.requires

CMakeFiles/main.dir/main.cpp.o.provides: CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/main.cpp.o.provides

CMakeFiles/main.dir/main.cpp.o.provides.build: CMakeFiles/main.dir/main.cpp.o


CMakeFiles/main.dir/GPSCoord.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/GPSCoord.cpp.o: ../GPSCoord.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sems/Ceng112-DataStructures/homeworks/hw02a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/GPSCoord.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/GPSCoord.cpp.o -c /Users/sems/Ceng112-DataStructures/homeworks/hw02a/GPSCoord.cpp

CMakeFiles/main.dir/GPSCoord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/GPSCoord.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sems/Ceng112-DataStructures/homeworks/hw02a/GPSCoord.cpp > CMakeFiles/main.dir/GPSCoord.cpp.i

CMakeFiles/main.dir/GPSCoord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/GPSCoord.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sems/Ceng112-DataStructures/homeworks/hw02a/GPSCoord.cpp -o CMakeFiles/main.dir/GPSCoord.cpp.s

CMakeFiles/main.dir/GPSCoord.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/GPSCoord.cpp.o.requires

CMakeFiles/main.dir/GPSCoord.cpp.o.provides: CMakeFiles/main.dir/GPSCoord.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GPSCoord.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/GPSCoord.cpp.o.provides

CMakeFiles/main.dir/GPSCoord.cpp.o.provides.build: CMakeFiles/main.dir/GPSCoord.cpp.o


CMakeFiles/main.dir/Utils.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Utils.cpp.o: ../Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sems/Ceng112-DataStructures/homeworks/hw02a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/Utils.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/Utils.cpp.o -c /Users/sems/Ceng112-DataStructures/homeworks/hw02a/Utils.cpp

CMakeFiles/main.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Utils.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sems/Ceng112-DataStructures/homeworks/hw02a/Utils.cpp > CMakeFiles/main.dir/Utils.cpp.i

CMakeFiles/main.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Utils.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sems/Ceng112-DataStructures/homeworks/hw02a/Utils.cpp -o CMakeFiles/main.dir/Utils.cpp.s

CMakeFiles/main.dir/Utils.cpp.o.requires:

.PHONY : CMakeFiles/main.dir/Utils.cpp.o.requires

CMakeFiles/main.dir/Utils.cpp.o.provides: CMakeFiles/main.dir/Utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Utils.cpp.o.provides.build
.PHONY : CMakeFiles/main.dir/Utils.cpp.o.provides

CMakeFiles/main.dir/Utils.cpp.o.provides.build: CMakeFiles/main.dir/Utils.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/GPSCoord.cpp.o" \
"CMakeFiles/main.dir/Utils.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/GPSCoord.cpp.o
main: CMakeFiles/main.dir/Utils.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sems/Ceng112-DataStructures/homeworks/hw02a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/main.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/GPSCoord.cpp.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/Utils.cpp.o.requires

.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/sems/Ceng112-DataStructures/homeworks/hw02a/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sems/Ceng112-DataStructures/homeworks/hw02a /Users/sems/Ceng112-DataStructures/homeworks/hw02a /Users/sems/Ceng112-DataStructures/homeworks/hw02a/build /Users/sems/Ceng112-DataStructures/homeworks/hw02a/build /Users/sems/Ceng112-DataStructures/homeworks/hw02a/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

