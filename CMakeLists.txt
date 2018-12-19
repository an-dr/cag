cmake_minimum_required(VERSION 3.12)
project(cag)

set(CMAKE_CXX_STANDARD 11)

include_directories(cag/inc)
include_directories(test)

file(GLOB CAG_SRCFILES cag/src/*.cpp)
file(GLOB CAG_CSRCFILES cag/src/*.c)

file(GLOB TEST_SRCFILES test/*.cpp)
file(GLOB TEST_CSRCFILES test/*.c)
#target_sources(cag/src/file.cpp)
#link_directories(cag/src)

add_executable( test main.cpp ${CAG_SRCFILES} ${CAG_CSRCFILES} ${TEST_SRCFILES} ${TEST_CSRCFILES})