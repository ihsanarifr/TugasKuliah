# CMake generated Testfile for 
# Source directory: /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/modules/photo
# Build directory: /home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/modules/photo
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(opencv_test_photo "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/bin/opencv_test_photo" "--gtest_output=xml:opencv_test_photo.xml")
SET_TESTS_PROPERTIES(opencv_test_photo PROPERTIES  LABELS "Main;opencv_photo;Accuracy" WORKING_DIRECTORY "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/test-reports/accuracy")
ADD_TEST(opencv_perf_photo "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/bin/opencv_perf_photo" "--gtest_output=xml:opencv_perf_photo.xml")
SET_TESTS_PROPERTIES(opencv_perf_photo PROPERTIES  LABELS "Main;opencv_photo;Performance" WORKING_DIRECTORY "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/test-reports/performance")
ADD_TEST(opencv_sanity_photo "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/bin/opencv_perf_photo" "--gtest_output=xml:opencv_perf_photo.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
SET_TESTS_PROPERTIES(opencv_sanity_photo PROPERTIES  LABELS "Main;opencv_photo;Sanity" WORKING_DIRECTORY "/home/ihsanarifr/Documents/TugasKuliah/CodeOpenCV/OpenCV/opencv-3.1.0/build/test-reports/sanity")
