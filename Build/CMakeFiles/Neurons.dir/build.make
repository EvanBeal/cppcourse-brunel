# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evan/Desktop/NeuronMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evan/Desktop/NeuronMake/Build

# Include any dependencies generated for this target.
include CMakeFiles/Neurons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Neurons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Neurons.dir/flags.make

CMakeFiles/Neurons.dir/network.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/network.cpp.o: ../network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evan/Desktop/NeuronMake/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Neurons.dir/network.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/network.cpp.o -c /Users/evan/Desktop/NeuronMake/network.cpp

CMakeFiles/Neurons.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/network.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Desktop/NeuronMake/network.cpp > CMakeFiles/Neurons.dir/network.cpp.i

CMakeFiles/Neurons.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/network.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Desktop/NeuronMake/network.cpp -o CMakeFiles/Neurons.dir/network.cpp.s

CMakeFiles/Neurons.dir/network.cpp.o.requires:

.PHONY : CMakeFiles/Neurons.dir/network.cpp.o.requires

CMakeFiles/Neurons.dir/network.cpp.o.provides: CMakeFiles/Neurons.dir/network.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/network.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/network.cpp.o.provides

CMakeFiles/Neurons.dir/network.cpp.o.provides.build: CMakeFiles/Neurons.dir/network.cpp.o


CMakeFiles/Neurons.dir/neuron.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/neuron.cpp.o: ../neuron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evan/Desktop/NeuronMake/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Neurons.dir/neuron.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/neuron.cpp.o -c /Users/evan/Desktop/NeuronMake/neuron.cpp

CMakeFiles/Neurons.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/neuron.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Desktop/NeuronMake/neuron.cpp > CMakeFiles/Neurons.dir/neuron.cpp.i

CMakeFiles/Neurons.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/neuron.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Desktop/NeuronMake/neuron.cpp -o CMakeFiles/Neurons.dir/neuron.cpp.s

CMakeFiles/Neurons.dir/neuron.cpp.o.requires:

.PHONY : CMakeFiles/Neurons.dir/neuron.cpp.o.requires

CMakeFiles/Neurons.dir/neuron.cpp.o.provides: CMakeFiles/Neurons.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/neuron.cpp.o.provides

CMakeFiles/Neurons.dir/neuron.cpp.o.provides.build: CMakeFiles/Neurons.dir/neuron.cpp.o


CMakeFiles/Neurons.dir/main.cpp.o: CMakeFiles/Neurons.dir/flags.make
CMakeFiles/Neurons.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evan/Desktop/NeuronMake/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Neurons.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neurons.dir/main.cpp.o -c /Users/evan/Desktop/NeuronMake/main.cpp

CMakeFiles/Neurons.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neurons.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evan/Desktop/NeuronMake/main.cpp > CMakeFiles/Neurons.dir/main.cpp.i

CMakeFiles/Neurons.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neurons.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evan/Desktop/NeuronMake/main.cpp -o CMakeFiles/Neurons.dir/main.cpp.s

CMakeFiles/Neurons.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Neurons.dir/main.cpp.o.requires

CMakeFiles/Neurons.dir/main.cpp.o.provides: CMakeFiles/Neurons.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Neurons.dir/build.make CMakeFiles/Neurons.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Neurons.dir/main.cpp.o.provides

CMakeFiles/Neurons.dir/main.cpp.o.provides.build: CMakeFiles/Neurons.dir/main.cpp.o


# Object files for target Neurons
Neurons_OBJECTS = \
"CMakeFiles/Neurons.dir/network.cpp.o" \
"CMakeFiles/Neurons.dir/neuron.cpp.o" \
"CMakeFiles/Neurons.dir/main.cpp.o"

# External object files for target Neurons
Neurons_EXTERNAL_OBJECTS =

Neurons: CMakeFiles/Neurons.dir/network.cpp.o
Neurons: CMakeFiles/Neurons.dir/neuron.cpp.o
Neurons: CMakeFiles/Neurons.dir/main.cpp.o
Neurons: CMakeFiles/Neurons.dir/build.make
Neurons: CMakeFiles/Neurons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evan/Desktop/NeuronMake/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Neurons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Neurons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Neurons.dir/build: Neurons

.PHONY : CMakeFiles/Neurons.dir/build

CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/network.cpp.o.requires
CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/neuron.cpp.o.requires
CMakeFiles/Neurons.dir/requires: CMakeFiles/Neurons.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Neurons.dir/requires

CMakeFiles/Neurons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Neurons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Neurons.dir/clean

CMakeFiles/Neurons.dir/depend:
	cd /Users/evan/Desktop/NeuronMake/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evan/Desktop/NeuronMake /Users/evan/Desktop/NeuronMake /Users/evan/Desktop/NeuronMake/Build /Users/evan/Desktop/NeuronMake/Build /Users/evan/Desktop/NeuronMake/Build/CMakeFiles/Neurons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Neurons.dir/depend

