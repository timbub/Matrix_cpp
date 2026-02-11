cmake_minimum_required(VERSION 3.20)

project(matrix)

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
target_include_directories(matrix_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(matrix_lib INTERFACE Matrix.hpp BufMatrix.hpp)

add_executable(matrix main.cpp)

target_link_libraries(matrix PRIVATE matrix_lib)

enable_testing()
add_subdirectory(tests/unit)
