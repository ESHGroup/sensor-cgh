# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /opt/workspace/sensor-cgh/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/workspace/sensor-cgh

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /opt/workspace/sensor-cgh/CMakeFiles /opt/workspace/sensor-cgh/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /opt/workspace/sensor-cgh/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named sensor-cgh

# Build rule for target.
sensor-cgh: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 sensor-cgh
.PHONY : sensor-cgh

# fast build rule for target.
sensor-cgh/fast:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/build
.PHONY : sensor-cgh/fast

DepthCapture.o: DepthCapture.cpp.o
.PHONY : DepthCapture.o

# target to build an object file
DepthCapture.cpp.o:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/DepthCapture.cpp.o
.PHONY : DepthCapture.cpp.o

DepthCapture.i: DepthCapture.cpp.i
.PHONY : DepthCapture.i

# target to preprocess a source file
DepthCapture.cpp.i:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/DepthCapture.cpp.i
.PHONY : DepthCapture.cpp.i

DepthCapture.s: DepthCapture.cpp.s
.PHONY : DepthCapture.s

# target to generate assembly for a file
DepthCapture.cpp.s:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/DepthCapture.cpp.s
.PHONY : DepthCapture.cpp.s

HoloFilm.o: HoloFilm.cpp.o
.PHONY : HoloFilm.o

# target to build an object file
HoloFilm.cpp.o:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/HoloFilm.cpp.o
.PHONY : HoloFilm.cpp.o

HoloFilm.i: HoloFilm.cpp.i
.PHONY : HoloFilm.i

# target to preprocess a source file
HoloFilm.cpp.i:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/HoloFilm.cpp.i
.PHONY : HoloFilm.cpp.i

HoloFilm.s: HoloFilm.cpp.s
.PHONY : HoloFilm.s

# target to generate assembly for a file
HoloFilm.cpp.s:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/HoloFilm.cpp.s
.PHONY : HoloFilm.cpp.s

ParseWavefrontObj.o: ParseWavefrontObj.cpp.o
.PHONY : ParseWavefrontObj.o

# target to build an object file
ParseWavefrontObj.cpp.o:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/ParseWavefrontObj.cpp.o
.PHONY : ParseWavefrontObj.cpp.o

ParseWavefrontObj.i: ParseWavefrontObj.cpp.i
.PHONY : ParseWavefrontObj.i

# target to preprocess a source file
ParseWavefrontObj.cpp.i:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/ParseWavefrontObj.cpp.i
.PHONY : ParseWavefrontObj.cpp.i

ParseWavefrontObj.s: ParseWavefrontObj.cpp.s
.PHONY : ParseWavefrontObj.s

# target to generate assembly for a file
ParseWavefrontObj.cpp.s:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/ParseWavefrontObj.cpp.s
.PHONY : ParseWavefrontObj.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/sensor-cgh.dir/build.make CMakeFiles/sensor-cgh.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... sensor-cgh"
	@echo "... DepthCapture.o"
	@echo "... DepthCapture.i"
	@echo "... DepthCapture.s"
	@echo "... HoloFilm.o"
	@echo "... HoloFilm.i"
	@echo "... HoloFilm.s"
	@echo "... ParseWavefrontObj.o"
	@echo "... ParseWavefrontObj.i"
	@echo "... ParseWavefrontObj.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
