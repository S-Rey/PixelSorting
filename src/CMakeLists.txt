cmake_minimum_required(VERSION 3.7)
project(src)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        read_write.h error.h)

add_executable(pixel-sorting ${SOURCE_FILES})