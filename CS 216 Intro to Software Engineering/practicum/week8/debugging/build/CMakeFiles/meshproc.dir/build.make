# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build

# Include any dependencies generated for this target.
include CMakeFiles/meshproc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/meshproc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/meshproc.dir/flags.make

CMakeFiles/meshproc.dir/main.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/main.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/main.cpp

CMakeFiles/meshproc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/main.cpp > CMakeFiles/meshproc.dir/main.cpp.i

CMakeFiles/meshproc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/main.cpp -o CMakeFiles/meshproc.dir/main.cpp.s

CMakeFiles/meshproc.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/main.cpp.o.requires

CMakeFiles/meshproc.dir/main.cpp.o.provides: CMakeFiles/meshproc.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/main.cpp.o.provides

CMakeFiles/meshproc.dir/main.cpp.o.provides.build: CMakeFiles/meshproc.dir/main.cpp.o
.PHONY : CMakeFiles/meshproc.dir/main.cpp.o.provides.build

CMakeFiles/meshproc.dir/point.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/point.cpp.o: ../point.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/point.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/point.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/point.cpp

CMakeFiles/meshproc.dir/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/point.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/point.cpp > CMakeFiles/meshproc.dir/point.cpp.i

CMakeFiles/meshproc.dir/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/point.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/point.cpp -o CMakeFiles/meshproc.dir/point.cpp.s

CMakeFiles/meshproc.dir/point.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/point.cpp.o.requires

CMakeFiles/meshproc.dir/point.cpp.o.provides: CMakeFiles/meshproc.dir/point.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/point.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/point.cpp.o.provides

CMakeFiles/meshproc.dir/point.cpp.o.provides.build: CMakeFiles/meshproc.dir/point.cpp.o
.PHONY : CMakeFiles/meshproc.dir/point.cpp.o.provides.build

CMakeFiles/meshproc.dir/polygon.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/polygon.cpp.o: ../polygon.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/polygon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/polygon.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/polygon.cpp

CMakeFiles/meshproc.dir/polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/polygon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/polygon.cpp > CMakeFiles/meshproc.dir/polygon.cpp.i

CMakeFiles/meshproc.dir/polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/polygon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/polygon.cpp -o CMakeFiles/meshproc.dir/polygon.cpp.s

CMakeFiles/meshproc.dir/polygon.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/polygon.cpp.o.requires

CMakeFiles/meshproc.dir/polygon.cpp.o.provides: CMakeFiles/meshproc.dir/polygon.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/polygon.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/polygon.cpp.o.provides

CMakeFiles/meshproc.dir/polygon.cpp.o.provides.build: CMakeFiles/meshproc.dir/polygon.cpp.o
.PHONY : CMakeFiles/meshproc.dir/polygon.cpp.o.provides.build

CMakeFiles/meshproc.dir/triangle.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/triangle.cpp.o: ../triangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/triangle.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/triangle.cpp

CMakeFiles/meshproc.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/triangle.cpp > CMakeFiles/meshproc.dir/triangle.cpp.i

CMakeFiles/meshproc.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/triangle.cpp -o CMakeFiles/meshproc.dir/triangle.cpp.s

CMakeFiles/meshproc.dir/triangle.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/triangle.cpp.o.requires

CMakeFiles/meshproc.dir/triangle.cpp.o.provides: CMakeFiles/meshproc.dir/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/triangle.cpp.o.provides

CMakeFiles/meshproc.dir/triangle.cpp.o.provides.build: CMakeFiles/meshproc.dir/triangle.cpp.o
.PHONY : CMakeFiles/meshproc.dir/triangle.cpp.o.provides.build

CMakeFiles/meshproc.dir/rectangle.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/rectangle.cpp.o: ../rectangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/rectangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/rectangle.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/rectangle.cpp

CMakeFiles/meshproc.dir/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/rectangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/rectangle.cpp > CMakeFiles/meshproc.dir/rectangle.cpp.i

CMakeFiles/meshproc.dir/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/rectangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/rectangle.cpp -o CMakeFiles/meshproc.dir/rectangle.cpp.s

CMakeFiles/meshproc.dir/rectangle.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/rectangle.cpp.o.requires

CMakeFiles/meshproc.dir/rectangle.cpp.o.provides: CMakeFiles/meshproc.dir/rectangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/rectangle.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/rectangle.cpp.o.provides

CMakeFiles/meshproc.dir/rectangle.cpp.o.provides.build: CMakeFiles/meshproc.dir/rectangle.cpp.o
.PHONY : CMakeFiles/meshproc.dir/rectangle.cpp.o.provides.build

CMakeFiles/meshproc.dir/square.cpp.o: CMakeFiles/meshproc.dir/flags.make
CMakeFiles/meshproc.dir/square.cpp.o: ../square.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/meshproc.dir/square.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/meshproc.dir/square.cpp.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/square.cpp

CMakeFiles/meshproc.dir/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/meshproc.dir/square.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/square.cpp > CMakeFiles/meshproc.dir/square.cpp.i

CMakeFiles/meshproc.dir/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/meshproc.dir/square.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/square.cpp -o CMakeFiles/meshproc.dir/square.cpp.s

CMakeFiles/meshproc.dir/square.cpp.o.requires:
.PHONY : CMakeFiles/meshproc.dir/square.cpp.o.requires

CMakeFiles/meshproc.dir/square.cpp.o.provides: CMakeFiles/meshproc.dir/square.cpp.o.requires
	$(MAKE) -f CMakeFiles/meshproc.dir/build.make CMakeFiles/meshproc.dir/square.cpp.o.provides.build
.PHONY : CMakeFiles/meshproc.dir/square.cpp.o.provides

CMakeFiles/meshproc.dir/square.cpp.o.provides.build: CMakeFiles/meshproc.dir/square.cpp.o
.PHONY : CMakeFiles/meshproc.dir/square.cpp.o.provides.build

# Object files for target meshproc
meshproc_OBJECTS = \
"CMakeFiles/meshproc.dir/main.cpp.o" \
"CMakeFiles/meshproc.dir/point.cpp.o" \
"CMakeFiles/meshproc.dir/polygon.cpp.o" \
"CMakeFiles/meshproc.dir/triangle.cpp.o" \
"CMakeFiles/meshproc.dir/rectangle.cpp.o" \
"CMakeFiles/meshproc.dir/square.cpp.o"

# External object files for target meshproc
meshproc_EXTERNAL_OBJECTS =

meshproc: CMakeFiles/meshproc.dir/main.cpp.o
meshproc: CMakeFiles/meshproc.dir/point.cpp.o
meshproc: CMakeFiles/meshproc.dir/polygon.cpp.o
meshproc: CMakeFiles/meshproc.dir/triangle.cpp.o
meshproc: CMakeFiles/meshproc.dir/rectangle.cpp.o
meshproc: CMakeFiles/meshproc.dir/square.cpp.o
meshproc: CMakeFiles/meshproc.dir/build.make
meshproc: CMakeFiles/meshproc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable meshproc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/meshproc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/meshproc.dir/build: meshproc
.PHONY : CMakeFiles/meshproc.dir/build

CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/main.cpp.o.requires
CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/point.cpp.o.requires
CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/polygon.cpp.o.requires
CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/triangle.cpp.o.requires
CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/rectangle.cpp.o.requires
CMakeFiles/meshproc.dir/requires: CMakeFiles/meshproc.dir/square.cpp.o.requires
.PHONY : CMakeFiles/meshproc.dir/requires

CMakeFiles/meshproc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/meshproc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/meshproc.dir/clean

CMakeFiles/meshproc.dir/depend:
	cd /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build /u/zon-d2/ugrad/shliu2/cs216/practicum/week8/debugging/build/CMakeFiles/meshproc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/meshproc.dir/depend

