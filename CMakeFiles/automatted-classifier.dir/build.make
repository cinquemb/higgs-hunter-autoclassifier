# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cinquemb/higgs-hunter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cinquemb/higgs-hunter

# Include any dependencies generated for this target.
include CMakeFiles/automatted-classifier.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/automatted-classifier.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/automatted-classifier.dir/flags.make

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o: CMakeFiles/automatted-classifier.dir/flags.make
CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o: automatted-classifier.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/cinquemb/higgs-hunter/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o -c /Users/cinquemb/higgs-hunter/automatted-classifier.cpp

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/cinquemb/higgs-hunter/automatted-classifier.cpp > CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.i

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/cinquemb/higgs-hunter/automatted-classifier.cpp -o CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.s

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.requires:
.PHONY : CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.requires

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.provides: CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.requires
	$(MAKE) -f CMakeFiles/automatted-classifier.dir/build.make CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.provides.build
.PHONY : CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.provides

CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.provides.build: CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o

# Object files for target automatted-classifier
automatted__classifier_OBJECTS = \
"CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o"

# External object files for target automatted-classifier
automatted__classifier_EXTERNAL_OBJECTS =

automatted-classifier: CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o
automatted-classifier: CMakeFiles/automatted-classifier.dir/build.make
automatted-classifier: /usr/local/lib/libopencv_videostab.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_videoio.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_video.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_ts.a
automatted-classifier: /usr/local/lib/libopencv_superres.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_stitching.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_shape.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_photo.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_objdetect.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_ml.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_imgproc.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_imgcodecs.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_highgui.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_flann.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_features2d.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_core.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_calib3d.3.0.0.dylib
automatted-classifier: /usr/local/share/OpenCV/3rdparty/lib/libippicv.a
automatted-classifier: /usr/local/lib/libopencv_features2d.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_ml.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_highgui.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_videoio.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_imgcodecs.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_flann.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_video.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_imgproc.3.0.0.dylib
automatted-classifier: /usr/local/lib/libopencv_core.3.0.0.dylib
automatted-classifier: CMakeFiles/automatted-classifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable automatted-classifier"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/automatted-classifier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/automatted-classifier.dir/build: automatted-classifier
.PHONY : CMakeFiles/automatted-classifier.dir/build

CMakeFiles/automatted-classifier.dir/requires: CMakeFiles/automatted-classifier.dir/automatted-classifier.cpp.o.requires
.PHONY : CMakeFiles/automatted-classifier.dir/requires

CMakeFiles/automatted-classifier.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/automatted-classifier.dir/cmake_clean.cmake
.PHONY : CMakeFiles/automatted-classifier.dir/clean

CMakeFiles/automatted-classifier.dir/depend:
	cd /Users/cinquemb/higgs-hunter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cinquemb/higgs-hunter /Users/cinquemb/higgs-hunter /Users/cinquemb/higgs-hunter /Users/cinquemb/higgs-hunter /Users/cinquemb/higgs-hunter/CMakeFiles/automatted-classifier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/automatted-classifier.dir/depend

