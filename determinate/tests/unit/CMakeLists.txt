add_executable(unit tests.cpp)
target_link_libraries(unit PRIVATE matrix_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit)