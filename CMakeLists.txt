cmake_minimum_required(VERSION 3.25.1)
project(yadb C)

set(CMAKE_C_STANDARD 23)

set(SOURCES src/file/block_id.c)
include_directories(include)
add_executable(yadb ${SOURCES})
