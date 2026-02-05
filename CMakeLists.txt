cmake_minimum_required(VERSION 3.20)

project(matrix)
add_executable(matrix)

add_compile_options(
    $<$<CONFIG:Debug>:-fsanitize=address>
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
)

add_link_options(
    $<$<CONFIG:Debug>:-fsanitize=address>
    $<$<CONFIG:Debug>:-g>
    $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
)

target_sources(matrix PRIVATE main.cpp Matrix.hpp BufMatrix.hpp)
