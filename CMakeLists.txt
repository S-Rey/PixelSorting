cmake_minimum_required(VERSION 3.7)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(pixelsort)

include (FindPkgConfig)
if (NOT PKG_CONFIG_FOUND)
    message (FATAL_ERROR "pkg-config not found")
endif ()

pkg_check_modules (LIBPNG libpng16 REQUIRED)
if (NOT LIBPNG_FOUND)
    message(FATAL_ERROR "You don't seem to have libpng16 development libraries installed")
else ()
    include_directories (${LIBPNG_INCLUDE_DIRS})
    link_directories (${LIBPNG_LIBRARY_DIRS})
    link_libraries (${LIBPNG_LIBRARIES})
endif ()

set(SOURCE_FILES
        src/main.c
        src/read_write.h)

add_executable(pixelsort ${SOURCE_FILES} ${LIBPNG_LINK_FLAGS})
