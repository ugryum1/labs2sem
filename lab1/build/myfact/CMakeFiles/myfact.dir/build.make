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
CMAKE_SOURCE_DIR = /home/ugryum/labs2sem/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ugryum/labs2sem/lab1/build

# Include any dependencies generated for this target.
include myfact/CMakeFiles/myfact.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include myfact/CMakeFiles/myfact.dir/compiler_depend.make

# Include the progress variables for this target.
include myfact/CMakeFiles/myfact.dir/progress.make

# Include the compile flags for this target's objects.
include myfact/CMakeFiles/myfact.dir/flags.make

myfact/CMakeFiles/myfact.dir/myfact.cpp.o: myfact/CMakeFiles/myfact.dir/flags.make
myfact/CMakeFiles/myfact.dir/myfact.cpp.o: /home/ugryum/labs2sem/lab1/myfact/myfact.cpp
myfact/CMakeFiles/myfact.dir/myfact.cpp.o: myfact/CMakeFiles/myfact.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ugryum/labs2sem/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object myfact/CMakeFiles/myfact.dir/myfact.cpp.o"
	cd /home/ugryum/labs2sem/lab1/build/myfact && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT myfact/CMakeFiles/myfact.dir/myfact.cpp.o -MF CMakeFiles/myfact.dir/myfact.cpp.o.d -o CMakeFiles/myfact.dir/myfact.cpp.o -c /home/ugryum/labs2sem/lab1/myfact/myfact.cpp

myfact/CMakeFiles/myfact.dir/myfact.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myfact.dir/myfact.cpp.i"
	cd /home/ugryum/labs2sem/lab1/build/myfact && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ugryum/labs2sem/lab1/myfact/myfact.cpp > CMakeFiles/myfact.dir/myfact.cpp.i

myfact/CMakeFiles/myfact.dir/myfact.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myfact.dir/myfact.cpp.s"
	cd /home/ugryum/labs2sem/lab1/build/myfact && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ugryum/labs2sem/lab1/myfact/myfact.cpp -o CMakeFiles/myfact.dir/myfact.cpp.s

# Object files for target myfact
myfact_OBJECTS = \
"CMakeFiles/myfact.dir/myfact.cpp.o"

# External object files for target myfact
myfact_EXTERNAL_OBJECTS =

myfact/libmyfact.a: myfact/CMakeFiles/myfact.dir/myfact.cpp.o
myfact/libmyfact.a: myfact/CMakeFiles/myfact.dir/build.make
myfact/libmyfact.a: myfact/CMakeFiles/myfact.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ugryum/labs2sem/lab1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmyfact.a"
	cd /home/ugryum/labs2sem/lab1/build/myfact && $(CMAKE_COMMAND) -P CMakeFiles/myfact.dir/cmake_clean_target.cmake
	cd /home/ugryum/labs2sem/lab1/build/myfact && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myfact.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
myfact/CMakeFiles/myfact.dir/build: myfact/libmyfact.a
.PHONY : myfact/CMakeFiles/myfact.dir/build

myfact/CMakeFiles/myfact.dir/clean:
	cd /home/ugryum/labs2sem/lab1/build/myfact && $(CMAKE_COMMAND) -P CMakeFiles/myfact.dir/cmake_clean.cmake
.PHONY : myfact/CMakeFiles/myfact.dir/clean

myfact/CMakeFiles/myfact.dir/depend:
	cd /home/ugryum/labs2sem/lab1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ugryum/labs2sem/lab1 /home/ugryum/labs2sem/lab1/myfact /home/ugryum/labs2sem/lab1/build /home/ugryum/labs2sem/lab1/build/myfact /home/ugryum/labs2sem/lab1/build/myfact/CMakeFiles/myfact.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : myfact/CMakeFiles/myfact.dir/depend

