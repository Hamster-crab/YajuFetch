cmake_minimum_required(VERSION 3.10)

project(yajufetch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(yajufetch src/main.cpp)

if(UNIX)
    target_compile_definitions(yajufetch PRIVATE _POSIX_C_SOURCE=200809L)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

target_compile_options(yajufetch PRIVATE -Wall -Wextra -O2)

