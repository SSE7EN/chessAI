# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release

# Include any dependencies generated for this target.
include CMakeFiles/chess-engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chess-engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess-engine.dir/flags.make

CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o: ../src/ai/aIEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/ai/aIEngine.cpp

CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/ai/aIEngine.cpp > CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.i

CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/ai/aIEngine.cpp -o CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.s

CMakeFiles/chess-engine.dir/src/board/board.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/board/board.cpp.o: ../src/board/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess-engine.dir/src/board/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/board/board.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/board.cpp

CMakeFiles/chess-engine.dir/src/board/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/board/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/board.cpp > CMakeFiles/chess-engine.dir/src/board/board.cpp.i

CMakeFiles/chess-engine.dir/src/board/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/board/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/board.cpp -o CMakeFiles/chess-engine.dir/src/board/board.cpp.s

CMakeFiles/chess-engine.dir/src/board/piece.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/board/piece.cpp.o: ../src/board/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess-engine.dir/src/board/piece.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/board/piece.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/piece.cpp

CMakeFiles/chess-engine.dir/src/board/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/board/piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/piece.cpp > CMakeFiles/chess-engine.dir/src/board/piece.cpp.i

CMakeFiles/chess-engine.dir/src/board/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/board/piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/piece.cpp -o CMakeFiles/chess-engine.dir/src/board/piece.cpp.s

CMakeFiles/chess-engine.dir/src/board/spot.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/board/spot.cpp.o: ../src/board/spot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess-engine.dir/src/board/spot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/board/spot.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/spot.cpp

CMakeFiles/chess-engine.dir/src/board/spot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/board/spot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/spot.cpp > CMakeFiles/chess-engine.dir/src/board/spot.cpp.i

CMakeFiles/chess-engine.dir/src/board/spot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/board/spot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/board/spot.cpp -o CMakeFiles/chess-engine.dir/src/board/spot.cpp.s

CMakeFiles/chess-engine.dir/src/game.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess-engine.dir/src/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/game.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/game.cpp

CMakeFiles/chess-engine.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/game.cpp > CMakeFiles/chess-engine.dir/src/game.cpp.i

CMakeFiles/chess-engine.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/game.cpp -o CMakeFiles/chess-engine.dir/src/game.cpp.s

CMakeFiles/chess-engine.dir/src/main.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess-engine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/main.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/main.cpp

CMakeFiles/chess-engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/main.cpp > CMakeFiles/chess-engine.dir/src/main.cpp.i

CMakeFiles/chess-engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/main.cpp -o CMakeFiles/chess-engine.dir/src/main.cpp.s

CMakeFiles/chess-engine.dir/src/util/move.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/util/move.cpp.o: ../src/util/move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/chess-engine.dir/src/util/move.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/util/move.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/move.cpp

CMakeFiles/chess-engine.dir/src/util/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/util/move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/move.cpp > CMakeFiles/chess-engine.dir/src/util/move.cpp.i

CMakeFiles/chess-engine.dir/src/util/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/util/move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/move.cpp -o CMakeFiles/chess-engine.dir/src/util/move.cpp.s

CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o: CMakeFiles/chess-engine.dir/flags.make
CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o: ../src/util/searchMove.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o -c /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/searchMove.cpp

CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/searchMove.cpp > CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.i

CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/src/util/searchMove.cpp -o CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.s

# Object files for target chess-engine
chess__engine_OBJECTS = \
"CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o" \
"CMakeFiles/chess-engine.dir/src/board/board.cpp.o" \
"CMakeFiles/chess-engine.dir/src/board/piece.cpp.o" \
"CMakeFiles/chess-engine.dir/src/board/spot.cpp.o" \
"CMakeFiles/chess-engine.dir/src/game.cpp.o" \
"CMakeFiles/chess-engine.dir/src/main.cpp.o" \
"CMakeFiles/chess-engine.dir/src/util/move.cpp.o" \
"CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o"

# External object files for target chess-engine
chess__engine_EXTERNAL_OBJECTS =

chess-engine: CMakeFiles/chess-engine.dir/src/ai/aIEngine.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/board/board.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/board/piece.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/board/spot.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/game.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/main.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/util/move.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/src/util/searchMove.cpp.o
chess-engine: CMakeFiles/chess-engine.dir/build.make
chess-engine: CMakeFiles/chess-engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable chess-engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess-engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess-engine.dir/build: chess-engine

.PHONY : CMakeFiles/chess-engine.dir/build

CMakeFiles/chess-engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess-engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess-engine.dir/clean

CMakeFiles/chess-engine.dir/depend:
	cd /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release /home/se7en/Studia/3Semestr/lab/pk3/git/Projekt/cpp/Release/CMakeFiles/chess-engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess-engine.dir/depend

