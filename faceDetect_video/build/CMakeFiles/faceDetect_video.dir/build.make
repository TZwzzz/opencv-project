# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build

# Include any dependencies generated for this target.
include CMakeFiles/faceDetect_video.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/faceDetect_video.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/faceDetect_video.dir/flags.make

CMakeFiles/faceDetect_video.dir/main.cpp.o: CMakeFiles/faceDetect_video.dir/flags.make
CMakeFiles/faceDetect_video.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/faceDetect_video.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/faceDetect_video.dir/main.cpp.o -c /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/main.cpp

CMakeFiles/faceDetect_video.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/faceDetect_video.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/main.cpp > CMakeFiles/faceDetect_video.dir/main.cpp.i

CMakeFiles/faceDetect_video.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/faceDetect_video.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/main.cpp -o CMakeFiles/faceDetect_video.dir/main.cpp.s

CMakeFiles/faceDetect_video.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/faceDetect_video.dir/main.cpp.o.requires

CMakeFiles/faceDetect_video.dir/main.cpp.o.provides: CMakeFiles/faceDetect_video.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/faceDetect_video.dir/build.make CMakeFiles/faceDetect_video.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/faceDetect_video.dir/main.cpp.o.provides

CMakeFiles/faceDetect_video.dir/main.cpp.o.provides.build: CMakeFiles/faceDetect_video.dir/main.cpp.o


CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o: CMakeFiles/faceDetect_video.dir/flags.make
CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o: ../faceDetect_video.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o -c /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/faceDetect_video.cpp

CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/faceDetect_video.cpp > CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.i

CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/faceDetect_video.cpp -o CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.s

CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.requires:

.PHONY : CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.requires

CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.provides: CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.requires
	$(MAKE) -f CMakeFiles/faceDetect_video.dir/build.make CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.provides.build
.PHONY : CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.provides

CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.provides.build: CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o


# Object files for target faceDetect_video
faceDetect_video_OBJECTS = \
"CMakeFiles/faceDetect_video.dir/main.cpp.o" \
"CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o"

# External object files for target faceDetect_video
faceDetect_video_EXTERNAL_OBJECTS =

faceDetect_video: CMakeFiles/faceDetect_video.dir/main.cpp.o
faceDetect_video: CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o
faceDetect_video: CMakeFiles/faceDetect_video.dir/build.make
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_stitching.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_superres.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_videostab.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_aruco.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_bgsegm.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_bioinspired.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_ccalib.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_dnn_objdetect.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_dpm.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_face.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_freetype.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_fuzzy.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_hdf.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_hfs.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_img_hash.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_line_descriptor.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_optflow.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_reg.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_rgbd.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_saliency.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_stereo.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_structured_light.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_surface_matching.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_tracking.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_xfeatures2d.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_ximgproc.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_xobjdetect.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_xphoto.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_shape.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_highgui.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_videoio.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_phase_unwrapping.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_video.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_datasets.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_plot.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_text.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_dnn.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_ml.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_imgcodecs.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_objdetect.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_calib3d.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_features2d.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_flann.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_photo.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_imgproc.so.3.4.12
faceDetect_video: /home/wilson/OpenCV/opencv-3.4.12/install/lib/libopencv_core.so.3.4.12
faceDetect_video: CMakeFiles/faceDetect_video.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable faceDetect_video"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/faceDetect_video.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/faceDetect_video.dir/build: faceDetect_video

.PHONY : CMakeFiles/faceDetect_video.dir/build

CMakeFiles/faceDetect_video.dir/requires: CMakeFiles/faceDetect_video.dir/main.cpp.o.requires
CMakeFiles/faceDetect_video.dir/requires: CMakeFiles/faceDetect_video.dir/faceDetect_video.cpp.o.requires

.PHONY : CMakeFiles/faceDetect_video.dir/requires

CMakeFiles/faceDetect_video.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/faceDetect_video.dir/cmake_clean.cmake
.PHONY : CMakeFiles/faceDetect_video.dir/clean

CMakeFiles/faceDetect_video.dir/depend:
	cd /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build /home/wilson/OpenCV/opencv-3.4.12/my_project/faceDetect_video/build/CMakeFiles/faceDetect_video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/faceDetect_video.dir/depend

