cmake_minimum_required(VERSION 3.15)
project(secgraph_runner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(secgraph_runner src/main.cpp src/IOHandler.cpp src/SecGraphRunner.cpp)

target_link_libraries(secgraph_runner stdc++fs)