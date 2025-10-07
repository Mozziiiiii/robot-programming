#Vesrion of CMake required and project name
cmake_minimum_required(VERSION 3.28.3)
project(rp_01_1st_example)

#Standard settings for language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(rp_01 many_object_in_stack_example.cpp)

#Things to flex:
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")
