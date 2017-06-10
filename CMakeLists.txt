cmake_minimum_required(VERSION 3.6)
project(Samsung)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c src/samsung/samsung.c src/samsung/samsung.h)
add_executable(Samsung ${SOURCE_FILES})