cmake_minimum_required(VERSION 3.9)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorting timealgorithms.cxx mergesort.h mergesort.cpp insertionsort.h insertionsort.cpp quicksort.h quicksort.cpp)