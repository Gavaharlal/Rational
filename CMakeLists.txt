cmake_minimum_required(VERSION 3.9)
project(Task4)

set(CMAKE_CXX_STANDARD 11)

add_executable(Task4 main.cpp cmake-build-debug/lib_rational.cpp cmake-build-debug/lib_rational.h)