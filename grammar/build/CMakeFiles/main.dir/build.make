# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/743/bin/cmake

# The command to remove a file.
RM = /snap/cmake/743/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aseal/Documents/invint/grammar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aseal/Documents/invint/grammar/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

antlr4cpp_generated_src/invLexer/invLexer.interp: ../invLexer.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building SampleGrammarLexer with ANTLR 4.9.1"
	cd /home/aseal/Documents/invint/grammar && /usr/bin/java -jar /usr/local/lib/antlr-4.9.1-complete.jar invLexer.g4 -o /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invLexer -no-listener -Dlanguage=Cpp -package antlrcpptest

antlr4cpp_generated_src/invLexer/invLexer.tokens: antlr4cpp_generated_src/invLexer/invLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invLexer/invLexer.tokens

antlr4cpp_generated_src/invLexer/invLexer.h: antlr4cpp_generated_src/invLexer/invLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invLexer/invLexer.h

antlr4cpp_generated_src/invLexer/invLexer.cpp: antlr4cpp_generated_src/invLexer/invLexer.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invLexer/invLexer.cpp

antlr4cpp_generated_src/invParser/invParser.interp: ../invParser.g4
antlr4cpp_generated_src/invParser/invParser.interp: ../invLexer.g4
antlr4cpp_generated_src/invParser/invParser.interp: antlr4cpp_generated_src/invLexer/invLexer.interp
antlr4cpp_generated_src/invParser/invParser.interp: antlr4cpp_generated_src/invLexer/invLexer.tokens
antlr4cpp_generated_src/invParser/invParser.interp: antlr4cpp_generated_src/invLexer/invLexer.h
antlr4cpp_generated_src/invParser/invParser.interp: antlr4cpp_generated_src/invLexer/invLexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building SampleGrammarParser with ANTLR 4.9.1"
	cd /home/aseal/Documents/invint/grammar && /usr/bin/java -jar /usr/local/lib/antlr-4.9.1-complete.jar invParser.g4 -o /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invParser -no-listener -Dlanguage=Cpp -lib /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invLexer -package antlrcpptest

antlr4cpp_generated_src/invParser/invParser.tokens: antlr4cpp_generated_src/invParser/invParser.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invParser/invParser.tokens

antlr4cpp_generated_src/invParser/invParser.h: antlr4cpp_generated_src/invParser/invParser.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invParser/invParser.h

antlr4cpp_generated_src/invParser/invParser.cpp: antlr4cpp_generated_src/invParser/invParser.interp
	@$(CMAKE_COMMAND) -E touch_nocreate antlr4cpp_generated_src/invParser/invParser.cpp

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/aseal/Documents/invint/grammar/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aseal/Documents/invint/grammar/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aseal/Documents/invint/grammar/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o: antlr4cpp_generated_src/invLexer/invLexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o -c /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invLexer/invLexer.cpp

CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invLexer/invLexer.cpp > CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.i

CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invLexer/invLexer.cpp -o CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.s

CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o: antlr4cpp_generated_src/invParser/invParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o -c /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invParser/invParser.cpp

CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invParser/invParser.cpp > CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.i

CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aseal/Documents/invint/grammar/build/antlr4cpp_generated_src/invParser/invParser.cpp -o CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o" \
"CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/antlr4cpp_generated_src/invLexer/invLexer.cpp.o
main: CMakeFiles/main.dir/antlr4cpp_generated_src/invParser/invParser.cpp.o
main: CMakeFiles/main.dir/build.make
main: antlr4_runtime/src/antlr4_runtime/runtime/Cpp/dist/libantlr4-runtime.a
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aseal/Documents/invint/grammar/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invLexer/invLexer.cpp
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invLexer/invLexer.h
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invLexer/invLexer.interp
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invLexer/invLexer.tokens
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invParser/invParser.cpp
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invParser/invParser.h
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invParser/invParser.interp
CMakeFiles/main.dir/depend: antlr4cpp_generated_src/invParser/invParser.tokens
	cd /home/aseal/Documents/invint/grammar/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aseal/Documents/invint/grammar /home/aseal/Documents/invint/grammar /home/aseal/Documents/invint/grammar/build /home/aseal/Documents/invint/grammar/build /home/aseal/Documents/invint/grammar/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

