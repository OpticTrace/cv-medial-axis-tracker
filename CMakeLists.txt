cmake_minimum_required(VERSION 3.10)
project(CV_MedialAxisTracker)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} include)

add_executable(MedialAxisTracker src/main.cpp src/MedialAxis.cpp)

target_link_libraries(MedialAxisTracker ${OpenCV_LIBS})