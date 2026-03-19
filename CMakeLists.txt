cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

project(MATRIX)

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

find_package(GTest REQUIRED)

add_library(matrix_lib INTERFACE)
target_include_directories(matrix_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/matrix)

enable_testing()
add_subdirectory(determinate)
add_subdirectory(chain)



