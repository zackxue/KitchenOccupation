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
CMAKE_COMMAND = "/Applications/CMake 2.8-11.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-11.app/Contents/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-11.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gustavhager/Desktop/TSBB11/project/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gustavhager/Desktop/TSBB11/project/build

# Include any dependencies generated for this target.
include Debugging/CMakeFiles/Debugging.dir/depend.make

# Include the progress variables for this target.
include Debugging/CMakeFiles/Debugging.dir/progress.make

# Include the compile flags for this target's objects.
include Debugging/CMakeFiles/Debugging.dir/flags.make

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o: Debugging/CMakeFiles/Debugging.dir/flags.make
Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o: /Users/gustavhager/Desktop/TSBB11/project/src/Debugging/Debug.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/gustavhager/Desktop/TSBB11/project/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o"
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Debugging.dir/Debug.cpp.o -c /Users/gustavhager/Desktop/TSBB11/project/src/Debugging/Debug.cpp

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Debugging.dir/Debug.cpp.i"
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/gustavhager/Desktop/TSBB11/project/src/Debugging/Debug.cpp > CMakeFiles/Debugging.dir/Debug.cpp.i

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Debugging.dir/Debug.cpp.s"
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/gustavhager/Desktop/TSBB11/project/src/Debugging/Debug.cpp -o CMakeFiles/Debugging.dir/Debug.cpp.s

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.requires:
.PHONY : Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.requires

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.provides: Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.requires
	$(MAKE) -f Debugging/CMakeFiles/Debugging.dir/build.make Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.provides.build
.PHONY : Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.provides

Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.provides.build: Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o

# Object files for target Debugging
Debugging_OBJECTS = \
"CMakeFiles/Debugging.dir/Debug.cpp.o"

# External object files for target Debugging
Debugging_EXTERNAL_OBJECTS =

Debugging/libDebugging.a: Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o
Debugging/libDebugging.a: Debugging/CMakeFiles/Debugging.dir/build.make
Debugging/libDebugging.a: Debugging/CMakeFiles/Debugging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libDebugging.a"
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && $(CMAKE_COMMAND) -P CMakeFiles/Debugging.dir/cmake_clean_target.cmake
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Debugging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Debugging/CMakeFiles/Debugging.dir/build: Debugging/libDebugging.a
.PHONY : Debugging/CMakeFiles/Debugging.dir/build

Debugging/CMakeFiles/Debugging.dir/requires: Debugging/CMakeFiles/Debugging.dir/Debug.cpp.o.requires
.PHONY : Debugging/CMakeFiles/Debugging.dir/requires

Debugging/CMakeFiles/Debugging.dir/clean:
	cd /Users/gustavhager/Desktop/TSBB11/project/build/Debugging && $(CMAKE_COMMAND) -P CMakeFiles/Debugging.dir/cmake_clean.cmake
.PHONY : Debugging/CMakeFiles/Debugging.dir/clean

Debugging/CMakeFiles/Debugging.dir/depend:
	cd /Users/gustavhager/Desktop/TSBB11/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gustavhager/Desktop/TSBB11/project/src /Users/gustavhager/Desktop/TSBB11/project/src/Debugging /Users/gustavhager/Desktop/TSBB11/project/build /Users/gustavhager/Desktop/TSBB11/project/build/Debugging /Users/gustavhager/Desktop/TSBB11/project/build/Debugging/CMakeFiles/Debugging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Debugging/CMakeFiles/Debugging.dir/depend

