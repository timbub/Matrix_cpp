cmake_minimum_required(VERSION 3.20)

project(MATRIX)

add_executable(det)
target_sources(det PRIVATE main.cpp)
target_link_libraries(det PRIVATE matrix_lib)

add_subdirectory(tests/unit)
