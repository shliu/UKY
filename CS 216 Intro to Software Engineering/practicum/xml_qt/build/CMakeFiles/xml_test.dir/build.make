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
CMAKE_SOURCE_DIR = /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build

# Include any dependencies generated for this target.
include CMakeFiles/xml_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xml_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xml_test.dir/flags.make

CMakeFiles/xml_test.dir/main.o: CMakeFiles/xml_test.dir/flags.make
CMakeFiles/xml_test.dir/main.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/xml_test.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/xml_test.dir/main.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/main.cpp

CMakeFiles/xml_test.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml_test.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/main.cpp > CMakeFiles/xml_test.dir/main.i

CMakeFiles/xml_test.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml_test.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/main.cpp -o CMakeFiles/xml_test.dir/main.s

CMakeFiles/xml_test.dir/main.o.requires:
.PHONY : CMakeFiles/xml_test.dir/main.o.requires

CMakeFiles/xml_test.dir/main.o.provides: CMakeFiles/xml_test.dir/main.o.requires
	$(MAKE) -f CMakeFiles/xml_test.dir/build.make CMakeFiles/xml_test.dir/main.o.provides.build
.PHONY : CMakeFiles/xml_test.dir/main.o.provides

CMakeFiles/xml_test.dir/main.o.provides.build: CMakeFiles/xml_test.dir/main.o
.PHONY : CMakeFiles/xml_test.dir/main.o.provides.build

CMakeFiles/xml_test.dir/address.o: CMakeFiles/xml_test.dir/flags.make
CMakeFiles/xml_test.dir/address.o: ../address.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/xml_test.dir/address.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/xml_test.dir/address.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/address.cpp

CMakeFiles/xml_test.dir/address.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml_test.dir/address.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/address.cpp > CMakeFiles/xml_test.dir/address.i

CMakeFiles/xml_test.dir/address.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml_test.dir/address.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/address.cpp -o CMakeFiles/xml_test.dir/address.s

CMakeFiles/xml_test.dir/address.o.requires:
.PHONY : CMakeFiles/xml_test.dir/address.o.requires

CMakeFiles/xml_test.dir/address.o.provides: CMakeFiles/xml_test.dir/address.o.requires
	$(MAKE) -f CMakeFiles/xml_test.dir/build.make CMakeFiles/xml_test.dir/address.o.provides.build
.PHONY : CMakeFiles/xml_test.dir/address.o.provides

CMakeFiles/xml_test.dir/address.o.provides.build: CMakeFiles/xml_test.dir/address.o
.PHONY : CMakeFiles/xml_test.dir/address.o.provides.build

CMakeFiles/xml_test.dir/addressprocessor.o: CMakeFiles/xml_test.dir/flags.make
CMakeFiles/xml_test.dir/addressprocessor.o: ../addressprocessor.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/xml_test.dir/addressprocessor.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/xml_test.dir/addressprocessor.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/addressprocessor.cpp

CMakeFiles/xml_test.dir/addressprocessor.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml_test.dir/addressprocessor.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/addressprocessor.cpp > CMakeFiles/xml_test.dir/addressprocessor.i

CMakeFiles/xml_test.dir/addressprocessor.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml_test.dir/addressprocessor.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/addressprocessor.cpp -o CMakeFiles/xml_test.dir/addressprocessor.s

CMakeFiles/xml_test.dir/addressprocessor.o.requires:
.PHONY : CMakeFiles/xml_test.dir/addressprocessor.o.requires

CMakeFiles/xml_test.dir/addressprocessor.o.provides: CMakeFiles/xml_test.dir/addressprocessor.o.requires
	$(MAKE) -f CMakeFiles/xml_test.dir/build.make CMakeFiles/xml_test.dir/addressprocessor.o.provides.build
.PHONY : CMakeFiles/xml_test.dir/addressprocessor.o.provides

CMakeFiles/xml_test.dir/addressprocessor.o.provides.build: CMakeFiles/xml_test.dir/addressprocessor.o
.PHONY : CMakeFiles/xml_test.dir/addressprocessor.o.provides.build

CMakeFiles/xml_test.dir/qrc_addresslist.o: CMakeFiles/xml_test.dir/flags.make
CMakeFiles/xml_test.dir/qrc_addresslist.o: qrc_addresslist.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/xml_test.dir/qrc_addresslist.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/xml_test.dir/qrc_addresslist.o -c /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/qrc_addresslist.cxx

CMakeFiles/xml_test.dir/qrc_addresslist.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xml_test.dir/qrc_addresslist.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/qrc_addresslist.cxx > CMakeFiles/xml_test.dir/qrc_addresslist.i

CMakeFiles/xml_test.dir/qrc_addresslist.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xml_test.dir/qrc_addresslist.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/qrc_addresslist.cxx -o CMakeFiles/xml_test.dir/qrc_addresslist.s

CMakeFiles/xml_test.dir/qrc_addresslist.o.requires:
.PHONY : CMakeFiles/xml_test.dir/qrc_addresslist.o.requires

CMakeFiles/xml_test.dir/qrc_addresslist.o.provides: CMakeFiles/xml_test.dir/qrc_addresslist.o.requires
	$(MAKE) -f CMakeFiles/xml_test.dir/build.make CMakeFiles/xml_test.dir/qrc_addresslist.o.provides.build
.PHONY : CMakeFiles/xml_test.dir/qrc_addresslist.o.provides

CMakeFiles/xml_test.dir/qrc_addresslist.o.provides.build: CMakeFiles/xml_test.dir/qrc_addresslist.o
.PHONY : CMakeFiles/xml_test.dir/qrc_addresslist.o.provides.build

qrc_addresslist.cxx: ../addresslist.xsd
qrc_addresslist.cxx: ../addresslist.qrc
	$(CMAKE_COMMAND) -E cmake_progress_report /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating qrc_addresslist.cxx"
	/usr/bin/rcc -name addresslist -o /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/qrc_addresslist.cxx /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/addresslist.qrc

# Object files for target xml_test
xml_test_OBJECTS = \
"CMakeFiles/xml_test.dir/main.o" \
"CMakeFiles/xml_test.dir/address.o" \
"CMakeFiles/xml_test.dir/addressprocessor.o" \
"CMakeFiles/xml_test.dir/qrc_addresslist.o"

# External object files for target xml_test
xml_test_EXTERNAL_OBJECTS =

xml_test: CMakeFiles/xml_test.dir/main.o
xml_test: CMakeFiles/xml_test.dir/address.o
xml_test: CMakeFiles/xml_test.dir/addressprocessor.o
xml_test: CMakeFiles/xml_test.dir/qrc_addresslist.o
xml_test: /usr/lib/libQtGui.so
xml_test: /usr/lib/libpng.so
xml_test: /usr/lib/libSM.so
xml_test: /usr/lib/libICE.so
xml_test: /usr/lib/libXext.so
xml_test: /usr/lib/libX11.so
xml_test: /usr/lib/libm.so
xml_test: /usr/lib/libQtXml.so
xml_test: /usr/lib/libQtXmlPatterns.so
xml_test: /usr/lib/libQtNetwork.so
xml_test: /usr/lib/libQtCore.so
xml_test: /usr/lib/libz.so
xml_test: /usr/lib/librt.so
xml_test: CMakeFiles/xml_test.dir/build.make
xml_test: CMakeFiles/xml_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable xml_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xml_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xml_test.dir/build: xml_test
.PHONY : CMakeFiles/xml_test.dir/build

CMakeFiles/xml_test.dir/requires: CMakeFiles/xml_test.dir/main.o.requires
CMakeFiles/xml_test.dir/requires: CMakeFiles/xml_test.dir/address.o.requires
CMakeFiles/xml_test.dir/requires: CMakeFiles/xml_test.dir/addressprocessor.o.requires
CMakeFiles/xml_test.dir/requires: CMakeFiles/xml_test.dir/qrc_addresslist.o.requires
.PHONY : CMakeFiles/xml_test.dir/requires

CMakeFiles/xml_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xml_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xml_test.dir/clean

CMakeFiles/xml_test.dir/depend: qrc_addresslist.cxx
	cd /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build /u/zon-d2/ugrad/shliu2/cs216/practicum/xml_qt/build/CMakeFiles/xml_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xml_test.dir/depend
