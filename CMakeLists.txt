cmake_minimum_required(VERSION 3.12)
project(cag)

set(CMAKE_CXX_STANDARD 11)

include_directories(cag/inc)
file(GLOB CAG_SRCFILES cag/src/*.cpp)
#target_sources(cag/src/file.cpp)
#link_directories(cag/src)

add_executable( test main.cpp ${CAG_SRCFILES})