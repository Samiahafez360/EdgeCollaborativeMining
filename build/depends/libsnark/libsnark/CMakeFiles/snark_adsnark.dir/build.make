# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/samia/libsnarktut

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samia/libsnarktut/build

# Include any dependencies generated for this target.
include depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/depend.make

# Include the progress variables for this target.
include depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/progress.make

# Include the compile flags for this target's objects.
include depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/flags.make

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/flags.make
depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o: ../depends/libsnark/libsnark/common/default_types/r1cs_ppzkadsnark_pp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samia/libsnarktut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o"
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o -c /home/samia/libsnarktut/depends/libsnark/libsnark/common/default_types/r1cs_ppzkadsnark_pp.cpp

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.i"
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samia/libsnarktut/depends/libsnark/libsnark/common/default_types/r1cs_ppzkadsnark_pp.cpp > CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.i

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.s"
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samia/libsnarktut/depends/libsnark/libsnark/common/default_types/r1cs_ppzkadsnark_pp.cpp -o CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.s

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.requires:

.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.requires

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.provides: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.requires
	$(MAKE) -f depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/build.make depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.provides.build
.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.provides

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.provides.build: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o


# Object files for target snark_adsnark
snark_adsnark_OBJECTS = \
"CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o"

# External object files for target snark_adsnark
snark_adsnark_EXTERNAL_OBJECTS =

depends/libsnark/libsnark/libsnark_adsnark.a: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o
depends/libsnark/libsnark/libsnark_adsnark.a: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/build.make
depends/libsnark/libsnark/libsnark_adsnark.a: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samia/libsnarktut/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libsnark_adsnark.a"
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && $(CMAKE_COMMAND) -P CMakeFiles/snark_adsnark.dir/cmake_clean_target.cmake
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/snark_adsnark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/build: depends/libsnark/libsnark/libsnark_adsnark.a

.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/build

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/requires: depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/common/default_types/r1cs_ppzkadsnark_pp.cpp.o.requires

.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/requires

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/clean:
	cd /home/samia/libsnarktut/build/depends/libsnark/libsnark && $(CMAKE_COMMAND) -P CMakeFiles/snark_adsnark.dir/cmake_clean.cmake
.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/clean

depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/depend:
	cd /home/samia/libsnarktut/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samia/libsnarktut /home/samia/libsnarktut/depends/libsnark/libsnark /home/samia/libsnarktut/build /home/samia/libsnarktut/build/depends/libsnark/libsnark /home/samia/libsnarktut/build/depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : depends/libsnark/libsnark/CMakeFiles/snark_adsnark.dir/depend
