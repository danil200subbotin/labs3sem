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
CMAKE_SOURCE_DIR = /Users/danilmorozov/Desktop/labsgit/application_program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/application_program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/application_program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/application_program.dir/flags.make

CMakeFiles/application_program.dir/main.cpp.o: CMakeFiles/application_program.dir/flags.make
CMakeFiles/application_program.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/application_program.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/application_program.dir/main.cpp.o -c /Users/danilmorozov/Desktop/labsgit/application_program/main.cpp

CMakeFiles/application_program.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/application_program.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danilmorozov/Desktop/labsgit/application_program/main.cpp > CMakeFiles/application_program.dir/main.cpp.i

CMakeFiles/application_program.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/application_program.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danilmorozov/Desktop/labsgit/application_program/main.cpp -o CMakeFiles/application_program.dir/main.cpp.s

CMakeFiles/application_program.dir/utils.cpp.o: CMakeFiles/application_program.dir/flags.make
CMakeFiles/application_program.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/application_program.dir/utils.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/application_program.dir/utils.cpp.o -c /Users/danilmorozov/Desktop/labsgit/application_program/utils.cpp

CMakeFiles/application_program.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/application_program.dir/utils.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danilmorozov/Desktop/labsgit/application_program/utils.cpp > CMakeFiles/application_program.dir/utils.cpp.i

CMakeFiles/application_program.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/application_program.dir/utils.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danilmorozov/Desktop/labsgit/application_program/utils.cpp -o CMakeFiles/application_program.dir/utils.cpp.s

# Object files for target application_program
application_program_OBJECTS = \
"CMakeFiles/application_program.dir/main.cpp.o" \
"CMakeFiles/application_program.dir/utils.cpp.o"

# External object files for target application_program
application_program_EXTERNAL_OBJECTS =

application_program: CMakeFiles/application_program.dir/main.cpp.o
application_program: CMakeFiles/application_program.dir/utils.cpp.o
application_program: CMakeFiles/application_program.dir/build.make
application_program: CMakeFiles/application_program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable application_program"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application_program.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/application_program.dir/build: application_program

.PHONY : CMakeFiles/application_program.dir/build

CMakeFiles/application_program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application_program.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application_program.dir/clean

CMakeFiles/application_program.dir/depend:
	cd /Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danilmorozov/Desktop/labsgit/application_program /Users/danilmorozov/Desktop/labsgit/application_program /Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug /Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug /Users/danilmorozov/Desktop/labsgit/application_program/cmake-build-debug/CMakeFiles/application_program.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/application_program.dir/depend
