# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code_Libaray\Clion_library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code_Libaray\Clion_library\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Clion_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Clion_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Clion_library.dir/flags.make

CMakeFiles/Clion_library.dir/main.cpp.obj: CMakeFiles/Clion_library.dir/flags.make
CMakeFiles/Clion_library.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code_Libaray\Clion_library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Clion_library.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Clion_library.dir\main.cpp.obj -c D:\Code_Libaray\Clion_library\main.cpp

CMakeFiles/Clion_library.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Clion_library.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code_Libaray\Clion_library\main.cpp > CMakeFiles\Clion_library.dir\main.cpp.i

CMakeFiles/Clion_library.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Clion_library.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code_Libaray\Clion_library\main.cpp -o CMakeFiles\Clion_library.dir\main.cpp.s

CMakeFiles/Clion_library.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Clion_library.dir/main.cpp.obj.requires

CMakeFiles/Clion_library.dir/main.cpp.obj.provides: CMakeFiles/Clion_library.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Clion_library.dir\build.make CMakeFiles/Clion_library.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Clion_library.dir/main.cpp.obj.provides

CMakeFiles/Clion_library.dir/main.cpp.obj.provides.build: CMakeFiles/Clion_library.dir/main.cpp.obj


# Object files for target Clion_library
Clion_library_OBJECTS = \
"CMakeFiles/Clion_library.dir/main.cpp.obj"

# External object files for target Clion_library
Clion_library_EXTERNAL_OBJECTS =

Clion_library.exe: CMakeFiles/Clion_library.dir/main.cpp.obj
Clion_library.exe: CMakeFiles/Clion_library.dir/build.make
Clion_library.exe: CMakeFiles/Clion_library.dir/linklibs.rsp
Clion_library.exe: CMakeFiles/Clion_library.dir/objects1.rsp
Clion_library.exe: CMakeFiles/Clion_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code_Libaray\Clion_library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Clion_library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Clion_library.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Clion_library.dir/build: Clion_library.exe

.PHONY : CMakeFiles/Clion_library.dir/build

CMakeFiles/Clion_library.dir/requires: CMakeFiles/Clion_library.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Clion_library.dir/requires

CMakeFiles/Clion_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Clion_library.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Clion_library.dir/clean

CMakeFiles/Clion_library.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code_Libaray\Clion_library D:\Code_Libaray\Clion_library D:\Code_Libaray\Clion_library\cmake-build-debug D:\Code_Libaray\Clion_library\cmake-build-debug D:\Code_Libaray\Clion_library\cmake-build-debug\CMakeFiles\Clion_library.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Clion_library.dir/depend

