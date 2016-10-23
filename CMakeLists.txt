cmake_minimum_required(VERSION 3.6)
project(rtree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    rtree.cpp rtree.h rectangle.h rectangle.cpp main.cpp)

add_executable(rtree ${SOURCE_FILES})