cmake_minimum_required(VERSION 3.6)
project(rtree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        rtreenode.cpp rtreenode.h rectangle.h rectangle.cpp main.cpp rtree.h rtree.cpp split.h linearsplit.h linearsplit.cpp greeneSplit.h greeneSplit.cpp split.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(rtree ${SOURCE_FILES})