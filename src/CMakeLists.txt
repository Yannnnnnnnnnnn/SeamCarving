cmake_minimum_required(VERSION 2.8)

PROJECT(SeamCarving)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. DIR_SRCS)
add_executable(SeamCarving ${DIR_SRCS})


include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(SeamCarving ${OpenCV_LIBS})
