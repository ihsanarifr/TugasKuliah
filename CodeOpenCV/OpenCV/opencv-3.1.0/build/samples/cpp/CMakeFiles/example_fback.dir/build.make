# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build

# Include any dependencies generated for this target.
include samples/cpp/CMakeFiles/example_fback.dir/depend.make

# Include the progress variables for this target.
include samples/cpp/CMakeFiles/example_fback.dir/progress.make

# Include the compile flags for this target's objects.
include samples/cpp/CMakeFiles/example_fback.dir/flags.make

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o: samples/cpp/CMakeFiles/example_fback.dir/flags.make
samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o: ../samples/cpp/fback.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o"
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_fback.dir/fback.cpp.o -c /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/samples/cpp/fback.cpp

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_fback.dir/fback.cpp.i"
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/samples/cpp/fback.cpp > CMakeFiles/example_fback.dir/fback.cpp.i

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_fback.dir/fback.cpp.s"
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/samples/cpp/fback.cpp -o CMakeFiles/example_fback.dir/fback.cpp.s

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.requires:
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.requires

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.provides: samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.requires
	$(MAKE) -f samples/cpp/CMakeFiles/example_fback.dir/build.make samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.provides.build
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.provides

samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.provides.build: samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o

# Object files for target example_fback
example_fback_OBJECTS = \
"CMakeFiles/example_fback.dir/fback.cpp.o"

# External object files for target example_fback
example_fback_EXTERNAL_OBJECTS =

bin/cpp-example-fback: samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o
bin/cpp-example-fback: samples/cpp/CMakeFiles/example_fback.dir/build.make
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libGL.so
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libSM.so
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libICE.so
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libX11.so
bin/cpp-example-fback: /usr/lib/x86_64-linux-gnu/libXext.so
bin/cpp-example-fback: ../3rdparty/ippicv/unpack/ippicv_lnx/lib/intel64/libippicv.a
bin/cpp-example-fback: lib/libopencv_core.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgproc.so.3.1.0
bin/cpp-example-fback: lib/libopencv_flann.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgcodecs.so.3.1.0
bin/cpp-example-fback: lib/libopencv_videoio.so.3.1.0
bin/cpp-example-fback: lib/libopencv_highgui.so.3.1.0
bin/cpp-example-fback: lib/libopencv_ml.so.3.1.0
bin/cpp-example-fback: lib/libopencv_video.so.3.1.0
bin/cpp-example-fback: lib/libopencv_objdetect.so.3.1.0
bin/cpp-example-fback: lib/libopencv_photo.so.3.1.0
bin/cpp-example-fback: lib/libopencv_features2d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_calib3d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_stitching.so.3.1.0
bin/cpp-example-fback: lib/libopencv_videostab.so.3.1.0
bin/cpp-example-fback: lib/libopencv_shape.so.3.1.0
bin/cpp-example-fback: lib/libopencv_calib3d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_core.so.3.1.0
bin/cpp-example-fback: lib/libopencv_features2d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_flann.so.3.1.0
bin/cpp-example-fback: lib/libopencv_highgui.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgcodecs.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgproc.so.3.1.0
bin/cpp-example-fback: lib/libopencv_ml.so.3.1.0
bin/cpp-example-fback: lib/libopencv_objdetect.so.3.1.0
bin/cpp-example-fback: lib/libopencv_photo.so.3.1.0
bin/cpp-example-fback: lib/libopencv_shape.so.3.1.0
bin/cpp-example-fback: lib/libopencv_stitching.so.3.1.0
bin/cpp-example-fback: lib/libopencv_superres.so.3.1.0
bin/cpp-example-fback: lib/libopencv_video.so.3.1.0
bin/cpp-example-fback: lib/libopencv_videoio.so.3.1.0
bin/cpp-example-fback: lib/libopencv_videostab.so.3.1.0
bin/cpp-example-fback: lib/libopencv_objdetect.so.3.1.0
bin/cpp-example-fback: lib/libopencv_photo.so.3.1.0
bin/cpp-example-fback: lib/libopencv_calib3d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_features2d.so.3.1.0
bin/cpp-example-fback: lib/libopencv_flann.so.3.1.0
bin/cpp-example-fback: lib/libopencv_highgui.so.3.1.0
bin/cpp-example-fback: lib/libopencv_ml.so.3.1.0
bin/cpp-example-fback: lib/libopencv_videoio.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgcodecs.so.3.1.0
bin/cpp-example-fback: lib/libopencv_video.so.3.1.0
bin/cpp-example-fback: lib/libopencv_imgproc.so.3.1.0
bin/cpp-example-fback: lib/libopencv_core.so.3.1.0
bin/cpp-example-fback: samples/cpp/CMakeFiles/example_fback.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/cpp-example-fback"
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_fback.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
samples/cpp/CMakeFiles/example_fback.dir/build: bin/cpp-example-fback
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/build

samples/cpp/CMakeFiles/example_fback.dir/requires: samples/cpp/CMakeFiles/example_fback.dir/fback.cpp.o.requires
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/requires

samples/cpp/CMakeFiles/example_fback.dir/clean:
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp && $(CMAKE_COMMAND) -P CMakeFiles/example_fback.dir/cmake_clean.cmake
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/clean

samples/cpp/CMakeFiles/example_fback.dir/depend:
	cd /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0 /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/samples/cpp /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/samples/cpp/CMakeFiles/example_fback.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : samples/cpp/CMakeFiles/example_fback.dir/depend

