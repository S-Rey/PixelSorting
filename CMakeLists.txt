cmake_minimum_required(VERSION 3.7)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(pixelsort)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        src/main.c
        src/read_write.h)

add_executable(pixelsort ${SOURCE_FILES})
target_link_libraries(pixelsort ${PNG_LIBRARY})
