# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danilmorozov/Desktop/labsgit/lab3byte1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab3byte1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3byte1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3byte1.dir/flags.make

CMakeFiles/lab3byte1.dir/biglong.cpp.o: CMakeFiles/lab3byte1.dir/flags.make
CMakeFiles/lab3byte1.dir/biglong.cpp.o: ../biglong.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3byte1.dir/biglong.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab3byte1.dir/biglong.cpp.o -c /Users/danilmorozov/Desktop/labsgit/lab3byte1/biglong.cpp

CMakeFiles/lab3byte1.dir/biglong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3byte1.dir/biglong.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danilmorozov/Desktop/labsgit/lab3byte1/biglong.cpp > CMakeFiles/lab3byte1.dir/biglong.cpp.i

CMakeFiles/lab3byte1.dir/biglong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3byte1.dir/biglong.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danilmorozov/Desktop/labsgit/lab3byte1/biglong.cpp -o CMakeFiles/lab3byte1.dir/biglong.cpp.s

CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o: CMakeFiles/lab3byte1.dir/flags.make
CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o: ../testwithgoogle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o -c /Users/danilmorozov/Desktop/labsgit/lab3byte1/testwithgoogle.cpp

CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danilmorozov/Desktop/labsgit/lab3byte1/testwithgoogle.cpp > CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.i

CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danilmorozov/Desktop/labsgit/lab3byte1/testwithgoogle.cpp -o CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.s

# Object files for target lab3byte1
lab3byte1_OBJECTS = \
"CMakeFiles/lab3byte1.dir/biglong.cpp.o" \
"CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o"

# External object files for target lab3byte1
lab3byte1_EXTERNAL_OBJECTS =

lab3byte1: CMakeFiles/lab3byte1.dir/biglong.cpp.o
lab3byte1: CMakeFiles/lab3byte1.dir/testwithgoogle.cpp.o
lab3byte1: CMakeFiles/lab3byte1.dir/build.make
lab3byte1: lib/libgtestd.a
lab3byte1: lib/libgtest_maind.a
lab3byte1: lib/libgtestd.a
lab3byte1: CMakeFiles/lab3byte1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lab3byte1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3byte1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3byte1.dir/build: lab3byte1

.PHONY : CMakeFiles/lab3byte1.dir/build

CMakeFiles/lab3byte1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3byte1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3byte1.dir/clean

CMakeFiles/lab3byte1.dir/depend:
	cd /Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danilmorozov/Desktop/labsgit/lab3byte1 /Users/danilmorozov/Desktop/labsgit/lab3byte1 /Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug /Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug /Users/danilmorozov/Desktop/labsgit/lab3byte1/cmake-build-debug/CMakeFiles/lab3byte1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab3byte1.dir/depend

