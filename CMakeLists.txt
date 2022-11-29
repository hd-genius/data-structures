cmake_policy(SET CMP0048 NEW)

project(data-structures VERSION 1.0.0)
cmake_minimum_required(VERSION 3.24.3)

set(CMAKE_CXX_STANDARD 14)

add_library(data-structures
    src/main.cpp
    src/list.h
    src/list.cpp
)

set(INSTALL_GTEST OFF)
add_subdirectory(dependencies/googletest)

enable_testing()

add_executable(
    data-structures-test
    src/test.cpp
)
target_link_libraries(
    data-structures-test
    GTest::gtest_main
    data-structures
)
include(GoogleTest)
gtest_discover_tests(data-structures-test)
add_test(NAME data-structures-test COMMAND data-structures-test)

set (BENCHMARK_ENABLE_INSTALL OFF)
set (BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(dependencies/benchmark)

# add_executable(hellobench hellobench.cpp)
# target_link_libraries(hellobench benchmark)
