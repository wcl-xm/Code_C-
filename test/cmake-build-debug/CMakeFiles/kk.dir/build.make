# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "G:\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code_C++\test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code_C++\test\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kk.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kk.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kk.dir/flags.make

CMakeFiles/kk.dir/kk.cpp.obj: CMakeFiles/kk.dir/flags.make
CMakeFiles/kk.dir/kk.cpp.obj: ../kk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code_C++\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kk.dir/kk.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\kk.dir\kk.cpp.obj -c D:\Code_C++\test\kk.cpp

CMakeFiles/kk.dir/kk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kk.dir/kk.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code_C++\test\kk.cpp > CMakeFiles\kk.dir\kk.cpp.i

CMakeFiles/kk.dir/kk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kk.dir/kk.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code_C++\test\kk.cpp -o CMakeFiles\kk.dir\kk.cpp.s

# Object files for target kk
kk_OBJECTS = \
"CMakeFiles/kk.dir/kk.cpp.obj"

# External object files for target kk
kk_EXTERNAL_OBJECTS =

kk.exe: CMakeFiles/kk.dir/kk.cpp.obj
kk.exe: CMakeFiles/kk.dir/build.make
kk.exe: CMakeFiles/kk.dir/linklibs.rsp
kk.exe: CMakeFiles/kk.dir/objects1.rsp
kk.exe: CMakeFiles/kk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code_C++\test\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kk.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\kk.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kk.dir/build: kk.exe

.PHONY : CMakeFiles/kk.dir/build

CMakeFiles/kk.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\kk.dir\cmake_clean.cmake
.PHONY : CMakeFiles/kk.dir/clean

CMakeFiles/kk.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code_C++\test D:\Code_C++\test D:\Code_C++\test\cmake-build-debug D:\Code_C++\test\cmake-build-debug D:\Code_C++\test\cmake-build-debug\CMakeFiles\kk.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kk.dir/depend
