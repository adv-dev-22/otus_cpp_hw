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
CMAKE_COMMAND = /usr/local/cmake-3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/adv-dev-22/otus_cpp_hw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/adv-dev-22/otus_cpp_hw

# Include any dependencies generated for this target.
include 01/CMakeFiles/helloworld_cli.dir/depend.make

# Include the progress variables for this target.
include 01/CMakeFiles/helloworld_cli.dir/progress.make

# Include the compile flags for this target's objects.
include 01/CMakeFiles/helloworld_cli.dir/flags.make

01/CMakeFiles/helloworld_cli.dir/main.cpp.o: 01/CMakeFiles/helloworld_cli.dir/flags.make
01/CMakeFiles/helloworld_cli.dir/main.cpp.o: 01/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/adv-dev-22/otus_cpp_hw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 01/CMakeFiles/helloworld_cli.dir/main.cpp.o"
	cd /home/travis/build/adv-dev-22/otus_cpp_hw/01 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/helloworld_cli.dir/main.cpp.o -c /home/travis/build/adv-dev-22/otus_cpp_hw/01/main.cpp

01/CMakeFiles/helloworld_cli.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/helloworld_cli.dir/main.cpp.i"
	cd /home/travis/build/adv-dev-22/otus_cpp_hw/01 && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/adv-dev-22/otus_cpp_hw/01/main.cpp > CMakeFiles/helloworld_cli.dir/main.cpp.i

01/CMakeFiles/helloworld_cli.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/helloworld_cli.dir/main.cpp.s"
	cd /home/travis/build/adv-dev-22/otus_cpp_hw/01 && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/adv-dev-22/otus_cpp_hw/01/main.cpp -o CMakeFiles/helloworld_cli.dir/main.cpp.s

# Object files for target helloworld_cli
helloworld_cli_OBJECTS = \
"CMakeFiles/helloworld_cli.dir/main.cpp.o"

# External object files for target helloworld_cli
helloworld_cli_EXTERNAL_OBJECTS =

01/helloworld_cli: 01/CMakeFiles/helloworld_cli.dir/main.cpp.o
01/helloworld_cli: 01/CMakeFiles/helloworld_cli.dir/build.make
01/helloworld_cli: 01/libhw_version.a
01/helloworld_cli: 01/CMakeFiles/helloworld_cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/adv-dev-22/otus_cpp_hw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable helloworld_cli"
	cd /home/travis/build/adv-dev-22/otus_cpp_hw/01 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/helloworld_cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
01/CMakeFiles/helloworld_cli.dir/build: 01/helloworld_cli

.PHONY : 01/CMakeFiles/helloworld_cli.dir/build

01/CMakeFiles/helloworld_cli.dir/clean:
	cd /home/travis/build/adv-dev-22/otus_cpp_hw/01 && $(CMAKE_COMMAND) -P CMakeFiles/helloworld_cli.dir/cmake_clean.cmake
.PHONY : 01/CMakeFiles/helloworld_cli.dir/clean

01/CMakeFiles/helloworld_cli.dir/depend:
	cd /home/travis/build/adv-dev-22/otus_cpp_hw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/adv-dev-22/otus_cpp_hw /home/travis/build/adv-dev-22/otus_cpp_hw/01 /home/travis/build/adv-dev-22/otus_cpp_hw /home/travis/build/adv-dev-22/otus_cpp_hw/01 /home/travis/build/adv-dev-22/otus_cpp_hw/01/CMakeFiles/helloworld_cli.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 01/CMakeFiles/helloworld_cli.dir/depend
