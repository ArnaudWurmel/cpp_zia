# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wurmel_a/CLionProjects/cpp_zia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wurmel_a/CLionProjects/cpp_zia

# Include any dependencies generated for this target.
include CMakeFiles/cpp_zia.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_zia.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_zia.dir/flags.make

CMakeFiles/cpp_zia.dir/main.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_zia.dir/main.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/main.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/main.cpp

CMakeFiles/cpp_zia.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/main.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/main.cpp > CMakeFiles/cpp_zia.dir/main.cpp.i

CMakeFiles/cpp_zia.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/main.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/main.cpp -o CMakeFiles/cpp_zia.dir/main.cpp.s

CMakeFiles/cpp_zia.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/main.cpp.o.requires

CMakeFiles/cpp_zia.dir/main.cpp.o.provides: CMakeFiles/cpp_zia.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/main.cpp.o.provides

CMakeFiles/cpp_zia.dir/main.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/main.cpp.o


CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o: Zia/Zia.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Zia.cpp

CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Zia.cpp > CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.i

CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Zia.cpp -o CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.s

CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.requires

CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.provides: CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.provides

CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o


CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o: Logger/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Logger/Logger.cpp

CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Logger/Logger.cpp > CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.i

CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Logger/Logger.cpp -o CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.s

CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.requires

CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.provides: CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.provides

CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o


CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o: Logger/LoggerConfiguration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Logger/LoggerConfiguration.cpp

CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Logger/LoggerConfiguration.cpp > CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.i

CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Logger/LoggerConfiguration.cpp -o CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.s

CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.requires

CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.provides: CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.provides

CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o


CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o: Zia/ArgParsing/ArgParsing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Zia/ArgParsing/ArgParsing.cpp

CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Zia/ArgParsing/ArgParsing.cpp > CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.i

CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Zia/ArgParsing/ArgParsing.cpp -o CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.s

CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.requires

CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.provides: CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.provides

CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o


CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o: Zia/Exceptions/Exceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Exceptions/Exceptions.cpp

CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Exceptions/Exceptions.cpp > CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.i

CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Zia/Exceptions/Exceptions.cpp -o CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.s

CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.requires

CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.provides: CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.provides

CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o


CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o: ConfParser/ADirectoryReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/ADirectoryReader.cpp

CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/ADirectoryReader.cpp > CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.i

CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/ADirectoryReader.cpp -o CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.s

CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.requires

CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.provides: CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.provides

CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o


CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o: ConfParser/Configuration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/Configuration.cpp

CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/Configuration.cpp > CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.i

CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/Configuration.cpp -o CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.s

CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.requires

CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.provides: CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.provides

CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o


CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o: ConfParser/JsonConfParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/JsonConfParser.cpp

CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/JsonConfParser.cpp > CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.i

CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/JsonConfParser.cpp -o CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.s

CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.requires

CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.provides: CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.provides

CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o


CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o: ConfParser/LinuxDirectoryReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/LinuxDirectoryReader.cpp

CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/LinuxDirectoryReader.cpp > CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.i

CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/ConfParser/LinuxDirectoryReader.cpp -o CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.s

CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.requires

CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.provides: CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.provides

CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o


CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o: Zia/VHostManager/VHostManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHostManager.cpp

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHostManager.cpp > CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.i

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHostManager.cpp -o CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.s

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.requires

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.provides: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.provides

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o


CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o: CMakeFiles/cpp_zia.dir/flags.make
CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o: Zia/VHostManager/VHost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o"
	g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o -c /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHost.cpp

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.i"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHost.cpp > CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.i

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.s"
	g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wurmel_a/CLionProjects/cpp_zia/Zia/VHostManager/VHost.cpp -o CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.s

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.requires:

.PHONY : CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.requires

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.provides: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.requires
	$(MAKE) -f CMakeFiles/cpp_zia.dir/build.make CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.provides.build
.PHONY : CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.provides

CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.provides.build: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o


# Object files for target cpp_zia
cpp_zia_OBJECTS = \
"CMakeFiles/cpp_zia.dir/main.cpp.o" \
"CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o" \
"CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o" \
"CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o" \
"CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o" \
"CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o" \
"CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o" \
"CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o" \
"CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o" \
"CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o" \
"CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o" \
"CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o"

# External object files for target cpp_zia
cpp_zia_EXTERNAL_OBJECTS =

cpp_zia: CMakeFiles/cpp_zia.dir/main.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o
cpp_zia: CMakeFiles/cpp_zia.dir/build.make
cpp_zia: CMakeFiles/cpp_zia.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable cpp_zia"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_zia.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_zia.dir/build: cpp_zia

.PHONY : CMakeFiles/cpp_zia.dir/build

CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/main.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Zia/Zia.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Logger/Logger.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Logger/LoggerConfiguration.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Zia/ArgParsing/ArgParsing.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Zia/Exceptions/Exceptions.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/ConfParser/ADirectoryReader.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/ConfParser/Configuration.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/ConfParser/JsonConfParser.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/ConfParser/LinuxDirectoryReader.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHostManager.cpp.o.requires
CMakeFiles/cpp_zia.dir/requires: CMakeFiles/cpp_zia.dir/Zia/VHostManager/VHost.cpp.o.requires

.PHONY : CMakeFiles/cpp_zia.dir/requires

CMakeFiles/cpp_zia.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_zia.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_zia.dir/clean

CMakeFiles/cpp_zia.dir/depend:
	cd /Users/wurmel_a/CLionProjects/cpp_zia && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wurmel_a/CLionProjects/cpp_zia /Users/wurmel_a/CLionProjects/cpp_zia /Users/wurmel_a/CLionProjects/cpp_zia /Users/wurmel_a/CLionProjects/cpp_zia /Users/wurmel_a/CLionProjects/cpp_zia/CMakeFiles/cpp_zia.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_zia.dir/depend

