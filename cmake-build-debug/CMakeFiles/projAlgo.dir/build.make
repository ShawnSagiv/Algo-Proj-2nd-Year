# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shawnsagiv/projAlgo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shawnsagiv/projAlgo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projAlgo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projAlgo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projAlgo.dir/flags.make

CMakeFiles/projAlgo.dir/main.cpp.o: CMakeFiles/projAlgo.dir/flags.make
CMakeFiles/projAlgo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shawnsagiv/projAlgo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projAlgo.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projAlgo.dir/main.cpp.o -c /Users/shawnsagiv/projAlgo/main.cpp

CMakeFiles/projAlgo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projAlgo.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shawnsagiv/projAlgo/main.cpp > CMakeFiles/projAlgo.dir/main.cpp.i

CMakeFiles/projAlgo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projAlgo.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shawnsagiv/projAlgo/main.cpp -o CMakeFiles/projAlgo.dir/main.cpp.s

# Object files for target projAlgo
projAlgo_OBJECTS = \
"CMakeFiles/projAlgo.dir/main.cpp.o"

# External object files for target projAlgo
projAlgo_EXTERNAL_OBJECTS =

projAlgo: CMakeFiles/projAlgo.dir/main.cpp.o
projAlgo: CMakeFiles/projAlgo.dir/build.make
projAlgo: CMakeFiles/projAlgo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shawnsagiv/projAlgo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projAlgo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projAlgo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projAlgo.dir/build: projAlgo

.PHONY : CMakeFiles/projAlgo.dir/build

CMakeFiles/projAlgo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projAlgo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projAlgo.dir/clean

CMakeFiles/projAlgo.dir/depend:
	cd /Users/shawnsagiv/projAlgo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shawnsagiv/projAlgo /Users/shawnsagiv/projAlgo /Users/shawnsagiv/projAlgo/cmake-build-debug /Users/shawnsagiv/projAlgo/cmake-build-debug /Users/shawnsagiv/projAlgo/cmake-build-debug/CMakeFiles/projAlgo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projAlgo.dir/depend

