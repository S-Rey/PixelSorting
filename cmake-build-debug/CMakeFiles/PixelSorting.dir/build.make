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
CMAKE_COMMAND = /opt/Clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/Clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samuel/GIT/PixelSorting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuel/GIT/PixelSorting/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PixelSorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PixelSorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PixelSorting.dir/flags.make

CMakeFiles/PixelSorting.dir/src/error.c.o: CMakeFiles/PixelSorting.dir/flags.make
CMakeFiles/PixelSorting.dir/src/error.c.o: ../src/error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/GIT/PixelSorting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PixelSorting.dir/src/error.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PixelSorting.dir/src/error.c.o   -c /home/samuel/GIT/PixelSorting/src/error.c

CMakeFiles/PixelSorting.dir/src/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PixelSorting.dir/src/error.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuel/GIT/PixelSorting/src/error.c > CMakeFiles/PixelSorting.dir/src/error.c.i

CMakeFiles/PixelSorting.dir/src/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PixelSorting.dir/src/error.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuel/GIT/PixelSorting/src/error.c -o CMakeFiles/PixelSorting.dir/src/error.c.s

CMakeFiles/PixelSorting.dir/src/error.c.o.requires:

.PHONY : CMakeFiles/PixelSorting.dir/src/error.c.o.requires

CMakeFiles/PixelSorting.dir/src/error.c.o.provides: CMakeFiles/PixelSorting.dir/src/error.c.o.requires
	$(MAKE) -f CMakeFiles/PixelSorting.dir/build.make CMakeFiles/PixelSorting.dir/src/error.c.o.provides.build
.PHONY : CMakeFiles/PixelSorting.dir/src/error.c.o.provides

CMakeFiles/PixelSorting.dir/src/error.c.o.provides.build: CMakeFiles/PixelSorting.dir/src/error.c.o


CMakeFiles/PixelSorting.dir/src/main.c.o: CMakeFiles/PixelSorting.dir/flags.make
CMakeFiles/PixelSorting.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuel/GIT/PixelSorting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PixelSorting.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PixelSorting.dir/src/main.c.o   -c /home/samuel/GIT/PixelSorting/src/main.c

CMakeFiles/PixelSorting.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PixelSorting.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuel/GIT/PixelSorting/src/main.c > CMakeFiles/PixelSorting.dir/src/main.c.i

CMakeFiles/PixelSorting.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PixelSorting.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuel/GIT/PixelSorting/src/main.c -o CMakeFiles/PixelSorting.dir/src/main.c.s

CMakeFiles/PixelSorting.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/PixelSorting.dir/src/main.c.o.requires

CMakeFiles/PixelSorting.dir/src/main.c.o.provides: CMakeFiles/PixelSorting.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/PixelSorting.dir/build.make CMakeFiles/PixelSorting.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/PixelSorting.dir/src/main.c.o.provides

CMakeFiles/PixelSorting.dir/src/main.c.o.provides.build: CMakeFiles/PixelSorting.dir/src/main.c.o


# Object files for target PixelSorting
PixelSorting_OBJECTS = \
"CMakeFiles/PixelSorting.dir/src/error.c.o" \
"CMakeFiles/PixelSorting.dir/src/main.c.o"

# External object files for target PixelSorting
PixelSorting_EXTERNAL_OBJECTS =

PixelSorting: CMakeFiles/PixelSorting.dir/src/error.c.o
PixelSorting: CMakeFiles/PixelSorting.dir/src/main.c.o
PixelSorting: CMakeFiles/PixelSorting.dir/build.make
PixelSorting: /usr/lib64/libpng.so
PixelSorting: CMakeFiles/PixelSorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuel/GIT/PixelSorting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable PixelSorting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PixelSorting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PixelSorting.dir/build: PixelSorting

.PHONY : CMakeFiles/PixelSorting.dir/build

CMakeFiles/PixelSorting.dir/requires: CMakeFiles/PixelSorting.dir/src/error.c.o.requires
CMakeFiles/PixelSorting.dir/requires: CMakeFiles/PixelSorting.dir/src/main.c.o.requires

.PHONY : CMakeFiles/PixelSorting.dir/requires

CMakeFiles/PixelSorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PixelSorting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PixelSorting.dir/clean

CMakeFiles/PixelSorting.dir/depend:
	cd /home/samuel/GIT/PixelSorting/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuel/GIT/PixelSorting /home/samuel/GIT/PixelSorting /home/samuel/GIT/PixelSorting/cmake-build-debug /home/samuel/GIT/PixelSorting/cmake-build-debug /home/samuel/GIT/PixelSorting/cmake-build-debug/CMakeFiles/PixelSorting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PixelSorting.dir/depend

