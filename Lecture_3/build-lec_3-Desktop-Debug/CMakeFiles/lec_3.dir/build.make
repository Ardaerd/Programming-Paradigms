# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/arda/Cs_321/Lecture_3/lec_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/lec_3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lec_3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lec_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lec_3.dir/flags.make

CMakeFiles/lec_3.dir/main.cpp.o: CMakeFiles/lec_3.dir/flags.make
CMakeFiles/lec_3.dir/main.cpp.o: /home/arda/Cs_321/Lecture_3/lec_3/main.cpp
CMakeFiles/lec_3.dir/main.cpp.o: CMakeFiles/lec_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lec_3.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lec_3.dir/main.cpp.o -MF CMakeFiles/lec_3.dir/main.cpp.o.d -o CMakeFiles/lec_3.dir/main.cpp.o -c /home/arda/Cs_321/Lecture_3/lec_3/main.cpp

CMakeFiles/lec_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lec_3.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arda/Cs_321/Lecture_3/lec_3/main.cpp > CMakeFiles/lec_3.dir/main.cpp.i

CMakeFiles/lec_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lec_3.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arda/Cs_321/Lecture_3/lec_3/main.cpp -o CMakeFiles/lec_3.dir/main.cpp.s

# Object files for target lec_3
lec_3_OBJECTS = \
"CMakeFiles/lec_3.dir/main.cpp.o"

# External object files for target lec_3
lec_3_EXTERNAL_OBJECTS =

lec_3: CMakeFiles/lec_3.dir/main.cpp.o
lec_3: CMakeFiles/lec_3.dir/build.make
lec_3: CMakeFiles/lec_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lec_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lec_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lec_3.dir/build: lec_3
.PHONY : CMakeFiles/lec_3.dir/build

CMakeFiles/lec_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lec_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lec_3.dir/clean

CMakeFiles/lec_3.dir/depend:
	cd /home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arda/Cs_321/Lecture_3/lec_3 /home/arda/Cs_321/Lecture_3/lec_3 /home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug /home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug /home/arda/Cs_321/Lecture_3/build-lec_3-Desktop-Debug/CMakeFiles/lec_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lec_3.dir/depend

