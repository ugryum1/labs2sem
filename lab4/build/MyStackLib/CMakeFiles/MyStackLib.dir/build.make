# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ugryum/labs2sem/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ugryum/labs2sem/lab4/build

# Include any dependencies generated for this target.
include MyStackLib/CMakeFiles/MyStackLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include MyStackLib/CMakeFiles/MyStackLib.dir/compiler_depend.make

# Include the progress variables for this target.
include MyStackLib/CMakeFiles/MyStackLib.dir/progress.make

# Include the compile flags for this target's objects.
include MyStackLib/CMakeFiles/MyStackLib.dir/flags.make

MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o: MyStackLib/CMakeFiles/MyStackLib.dir/flags.make
MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o: /home/ugryum/labs2sem/lab4/MyStackLib/MyStack.cpp
MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o: MyStackLib/CMakeFiles/MyStackLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ugryum/labs2sem/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o"
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o -MF CMakeFiles/MyStackLib.dir/MyStack.cpp.o.d -o CMakeFiles/MyStackLib.dir/MyStack.cpp.o -c /home/ugryum/labs2sem/lab4/MyStackLib/MyStack.cpp

MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyStackLib.dir/MyStack.cpp.i"
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ugryum/labs2sem/lab4/MyStackLib/MyStack.cpp > CMakeFiles/MyStackLib.dir/MyStack.cpp.i

MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyStackLib.dir/MyStack.cpp.s"
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ugryum/labs2sem/lab4/MyStackLib/MyStack.cpp -o CMakeFiles/MyStackLib.dir/MyStack.cpp.s

# Object files for target MyStackLib
MyStackLib_OBJECTS = \
"CMakeFiles/MyStackLib.dir/MyStack.cpp.o"

# External object files for target MyStackLib
MyStackLib_EXTERNAL_OBJECTS =

MyStackLib/libMyStackLib.a: MyStackLib/CMakeFiles/MyStackLib.dir/MyStack.cpp.o
MyStackLib/libMyStackLib.a: MyStackLib/CMakeFiles/MyStackLib.dir/build.make
MyStackLib/libMyStackLib.a: MyStackLib/CMakeFiles/MyStackLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ugryum/labs2sem/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMyStackLib.a"
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && $(CMAKE_COMMAND) -P CMakeFiles/MyStackLib.dir/cmake_clean_target.cmake
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyStackLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MyStackLib/CMakeFiles/MyStackLib.dir/build: MyStackLib/libMyStackLib.a
.PHONY : MyStackLib/CMakeFiles/MyStackLib.dir/build

MyStackLib/CMakeFiles/MyStackLib.dir/clean:
	cd /home/ugryum/labs2sem/lab4/build/MyStackLib && $(CMAKE_COMMAND) -P CMakeFiles/MyStackLib.dir/cmake_clean.cmake
.PHONY : MyStackLib/CMakeFiles/MyStackLib.dir/clean

MyStackLib/CMakeFiles/MyStackLib.dir/depend:
	cd /home/ugryum/labs2sem/lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ugryum/labs2sem/lab4 /home/ugryum/labs2sem/lab4/MyStackLib /home/ugryum/labs2sem/lab4/build /home/ugryum/labs2sem/lab4/build/MyStackLib /home/ugryum/labs2sem/lab4/build/MyStackLib/CMakeFiles/MyStackLib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : MyStackLib/CMakeFiles/MyStackLib.dir/depend

