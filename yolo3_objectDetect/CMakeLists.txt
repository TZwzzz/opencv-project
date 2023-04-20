cmake_minimum_required(VERSION 2.6)
#创建工程
project(objectDetect)
#C++版本为11
set(CMAKE_CXX_FLAGS "-std=c++11")
find_package(OpenCV REQUIRED)

include_directories(/home/wilson/OpenCV/opencv-3.4.12/install/include) #加载OpenCV 3.4.12的头文件

add_executable(objectDetect main.cpp objectDetect.cpp) #将程序生成可执行文件
target_link_libraries(objectDetect ${OpenCV_LIBS} pthread) #链接lib文件到可执行文件中
