cmake_minimum_required(VERSION 3.12)
project(cag)

set(CMAKE_CXX_STANDARD 11)


add_executable(
        test main.cpp
        cag/src/file.cpp cag/inc/file.h
        cag/src/path.cpp cag/inc/path.h
)