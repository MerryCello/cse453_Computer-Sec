cmake_minimum_required(VERSION 3.17)
project(computerSecurity)

set(CMAKE_CXX_STANDARD 14)

add_executable(computerSecurity
        main.cpp
        pathDebunker.cpp
        pathDebunker.h
        injection.cpp
        injection.h)