# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/maxime/Documents/Ensi/Prog/LabyrinthC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/main.c.o   -c /Users/maxime/Documents/Ensi/Prog/LabyrinthC/main.c

CMakeFiles/untitled.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maxime/Documents/Ensi/Prog/LabyrinthC/main.c > CMakeFiles/untitled.dir/main.c.i

CMakeFiles/untitled.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maxime/Documents/Ensi/Prog/LabyrinthC/main.c -o CMakeFiles/untitled.dir/main.c.s

CMakeFiles/untitled.dir/functions_sauves.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/functions_sauves.c.o: ../functions_sauves.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled.dir/functions_sauves.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/functions_sauves.c.o   -c /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_sauves.c

CMakeFiles/untitled.dir/functions_sauves.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/functions_sauves.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_sauves.c > CMakeFiles/untitled.dir/functions_sauves.c.i

CMakeFiles/untitled.dir/functions_sauves.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/functions_sauves.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_sauves.c -o CMakeFiles/untitled.dir/functions_sauves.c.s

CMakeFiles/untitled.dir/functions_init_labyrinth.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/functions_init_labyrinth.c.o: ../functions_init_labyrinth.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled.dir/functions_init_labyrinth.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/functions_init_labyrinth.c.o   -c /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_init_labyrinth.c

CMakeFiles/untitled.dir/functions_init_labyrinth.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/functions_init_labyrinth.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_init_labyrinth.c > CMakeFiles/untitled.dir/functions_init_labyrinth.c.i

CMakeFiles/untitled.dir/functions_init_labyrinth.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/functions_init_labyrinth.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_init_labyrinth.c -o CMakeFiles/untitled.dir/functions_init_labyrinth.c.s

CMakeFiles/untitled.dir/functions.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/functions.c.o: ../functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled.dir/functions.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/functions.c.o   -c /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions.c

CMakeFiles/untitled.dir/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/functions.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions.c > CMakeFiles/untitled.dir/functions.c.i

CMakeFiles/untitled.dir/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/functions.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions.c -o CMakeFiles/untitled.dir/functions.c.s

CMakeFiles/untitled.dir/functions_play.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/functions_play.c.o: ../functions_play.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/untitled.dir/functions_play.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/functions_play.c.o   -c /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_play.c

CMakeFiles/untitled.dir/functions_play.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/functions_play.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_play.c > CMakeFiles/untitled.dir/functions_play.c.i

CMakeFiles/untitled.dir/functions_play.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/functions_play.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/maxime/Documents/Ensi/Prog/LabyrinthC/functions_play.c -o CMakeFiles/untitled.dir/functions_play.c.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.c.o" \
"CMakeFiles/untitled.dir/functions_sauves.c.o" \
"CMakeFiles/untitled.dir/functions_init_labyrinth.c.o" \
"CMakeFiles/untitled.dir/functions.c.o" \
"CMakeFiles/untitled.dir/functions_play.c.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/main.c.o
untitled: CMakeFiles/untitled.dir/functions_sauves.c.o
untitled: CMakeFiles/untitled.dir/functions_init_labyrinth.c.o
untitled: CMakeFiles/untitled.dir/functions.c.o
untitled: CMakeFiles/untitled.dir/functions_play.c.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maxime/Documents/Ensi/Prog/LabyrinthC /Users/maxime/Documents/Ensi/Prog/LabyrinthC /Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug /Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug /Users/maxime/Documents/Ensi/Prog/LabyrinthC/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

