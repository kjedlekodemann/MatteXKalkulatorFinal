cmake_minimum_required(VERSION 3.10)

project(MatteXCalc)

file(GLOB SRC_FILES src/*.cpp)

add_executable(MatteXKalkulator ${SRC_FILES})
target_link_libraries(MatteXKalkulator ntdll)
target_include_directories(MatteXKalkulator PRIVATE include/)