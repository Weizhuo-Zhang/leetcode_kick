cmake_minimum_required(VERSION 3.15)
project(util)

set(CMAKE_CXX_STANDARD 11)

add_executable(util big_number_operation.cpp spiral_matrix.cpp spriral_matrix_generator.cpp search/src/BinarySearch.cpp search/header/BinarySearch.h)