# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build"

# Include any dependencies generated for this target.
include CMakeFiles/ChessEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChessEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessEngine.dir/flags.make

CMakeFiles/ChessEngine.dir/src/main.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/main.cpp.o: /mnt/c/Users/Tobi-Wan\ Kenobi/Desktop/Chess/src/main.cpp
CMakeFiles/ChessEngine.dir/src/main.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessEngine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/main.cpp.o -MF CMakeFiles/ChessEngine.dir/src/main.cpp.o.d -o CMakeFiles/ChessEngine.dir/src/main.cpp.o -c "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/main.cpp"

CMakeFiles/ChessEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/main.cpp" > CMakeFiles/ChessEngine.dir/src/main.cpp.i

CMakeFiles/ChessEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/main.cpp" -o CMakeFiles/ChessEngine.dir/src/main.cpp.s

CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o: /mnt/c/Users/Tobi-Wan\ Kenobi/Desktop/Chess/src/chessboard.cpp
CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o -MF CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o.d -o CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o -c "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/chessboard.cpp"

CMakeFiles/ChessEngine.dir/src/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/chessboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/chessboard.cpp" > CMakeFiles/ChessEngine.dir/src/chessboard.cpp.i

CMakeFiles/ChessEngine.dir/src/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/chessboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/chessboard.cpp" -o CMakeFiles/ChessEngine.dir/src/chessboard.cpp.s

CMakeFiles/ChessEngine.dir/src/pawn.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/src/pawn.cpp.o: /mnt/c/Users/Tobi-Wan\ Kenobi/Desktop/Chess/src/pawn.cpp
CMakeFiles/ChessEngine.dir/src/pawn.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChessEngine.dir/src/pawn.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/src/pawn.cpp.o -MF CMakeFiles/ChessEngine.dir/src/pawn.cpp.o.d -o CMakeFiles/ChessEngine.dir/src/pawn.cpp.o -c "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/pawn.cpp"

CMakeFiles/ChessEngine.dir/src/pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/src/pawn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/pawn.cpp" > CMakeFiles/ChessEngine.dir/src/pawn.cpp.i

CMakeFiles/ChessEngine.dir/src/pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/src/pawn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/src/pawn.cpp" -o CMakeFiles/ChessEngine.dir/src/pawn.cpp.s

# Object files for target ChessEngine
ChessEngine_OBJECTS = \
"CMakeFiles/ChessEngine.dir/src/main.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o" \
"CMakeFiles/ChessEngine.dir/src/pawn.cpp.o"

# External object files for target ChessEngine
ChessEngine_EXTERNAL_OBJECTS =

ChessEngine: CMakeFiles/ChessEngine.dir/src/main.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/chessboard.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/src/pawn.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/build.make
ChessEngine: CMakeFiles/ChessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ChessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessEngine.dir/build: ChessEngine
.PHONY : CMakeFiles/ChessEngine.dir/build

CMakeFiles/ChessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessEngine.dir/clean

CMakeFiles/ChessEngine.dir/depend:
	cd "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess" "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess" "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build" "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build" "/mnt/c/Users/Tobi-Wan Kenobi/Desktop/Chess/build/CMakeFiles/ChessEngine.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/ChessEngine.dir/depend

