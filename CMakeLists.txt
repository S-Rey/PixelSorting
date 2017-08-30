cmake_minimum_required(VERSION 3.7)
project(PixelSorting)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        src/error.c
        src/error.h
        src/main.c
        src/read_write.h)

add_executable(PixelSorting ${SOURCE_FILES})
target_link_libraries(PixelSorting ${PNG_LIBRARY})
