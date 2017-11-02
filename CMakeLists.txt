cmake_minimum_required(VERSION 3.7)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(pixelsorting)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        src/main.c
        src/read_write.h)

add_executable(pixelsorting ${SOURCE_FILES})
target_link_libraries(pixelsorting ${PNG_LIBRARY})
