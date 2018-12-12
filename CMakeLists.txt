cmake_minimum_required(VERSION 3.10)
project(BranchMisprediction)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O1 -g")

add_executable(BranchMisprediction src/main.cpp)