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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arayaq/castor/diglet/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arayaq/castor/diglet/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/serverprovider.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/serverprovider.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/serverprovider.dir/flags.make

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o: bin/CMakeFiles/serverprovider.dir/flags.make
bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o: /home/arayaq/castor/diglet/src/bin/serverprovider.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/arayaq/castor/diglet/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/serverprovider.dir/serverprovider.cpp.o -c /home/arayaq/castor/diglet/src/bin/serverprovider.cpp

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverprovider.dir/serverprovider.cpp.i"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/arayaq/castor/diglet/src/bin/serverprovider.cpp > CMakeFiles/serverprovider.dir/serverprovider.cpp.i

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverprovider.dir/serverprovider.cpp.s"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/arayaq/castor/diglet/src/bin/serverprovider.cpp -o CMakeFiles/serverprovider.dir/serverprovider.cpp.s

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.requires:
.PHONY : bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.requires

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.provides: bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/serverprovider.dir/build.make bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.provides.build
.PHONY : bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.provides

bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.provides.build: bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o: bin/CMakeFiles/serverprovider.dir/flags.make
bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o: bin/serverprovider_automoc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/arayaq/castor/diglet/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o -c /home/arayaq/castor/diglet/build/bin/serverprovider_automoc.cpp

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.i"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/arayaq/castor/diglet/build/bin/serverprovider_automoc.cpp > CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.i

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.s"
	cd /home/arayaq/castor/diglet/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/arayaq/castor/diglet/build/bin/serverprovider_automoc.cpp -o CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.s

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.requires:
.PHONY : bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.requires

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.provides: bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.requires
	$(MAKE) -f bin/CMakeFiles/serverprovider.dir/build.make bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.provides.build
.PHONY : bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.provides

bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.provides.build: bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o

# Object files for target serverprovider
serverprovider_OBJECTS = \
"CMakeFiles/serverprovider.dir/serverprovider.cpp.o" \
"CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o"

# External object files for target serverprovider
serverprovider_EXTERNAL_OBJECTS =

bin/serverprovider: bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o
bin/serverprovider: bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o
bin/serverprovider: bin/CMakeFiles/serverprovider.dir/build.make
bin/serverprovider: bin/CMakeFiles/serverprovider.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable serverprovider"
	cd /home/arayaq/castor/diglet/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverprovider.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/serverprovider.dir/build: bin/serverprovider
.PHONY : bin/CMakeFiles/serverprovider.dir/build

bin/CMakeFiles/serverprovider.dir/requires: bin/CMakeFiles/serverprovider.dir/serverprovider.cpp.o.requires
bin/CMakeFiles/serverprovider.dir/requires: bin/CMakeFiles/serverprovider.dir/serverprovider_automoc.cpp.o.requires
.PHONY : bin/CMakeFiles/serverprovider.dir/requires

bin/CMakeFiles/serverprovider.dir/clean:
	cd /home/arayaq/castor/diglet/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/serverprovider.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/serverprovider.dir/clean

bin/CMakeFiles/serverprovider.dir/depend:
	cd /home/arayaq/castor/diglet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arayaq/castor/diglet/src /home/arayaq/castor/diglet/src/bin /home/arayaq/castor/diglet/build /home/arayaq/castor/diglet/build/bin /home/arayaq/castor/diglet/build/bin/CMakeFiles/serverprovider.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/serverprovider.dir/depend

