cmake_minimum_required(VERSION 3.10)

project(MatteXCalc)

file(GLOB SRC_FILES src/*.cpp)

add_executable(test ${SRC_FILES})

target_include_directories(test PRIVATE include/)