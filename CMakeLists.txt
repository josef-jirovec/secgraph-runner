cmake_minimum_required(VERSION 3.15)
project(secgraph_runner)

set(CMAKE_CXX_STANDARD 17)

add_executable(secgraph_runner src/main.cpp src/SecGraphRunner.hpp src/IOHandler.hpp src/IOHandler.cpp src/SecGraphRunner.cpp src/MessageContainer.hpp src/RunnerState.hpp)