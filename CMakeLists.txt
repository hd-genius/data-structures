cmake_policy(SET CMP0048 NEW)

project(data-structures VERSION 1.0.0)
cmake_minimum_required(VERSION 3.24.3)

set(CMAKE_CXX_STANDARD 14)

# Target: Library

set(PUBLIC_HEADERS src/list.h)

set(LIBRARY_SOURCES ${PUBLIC_HEADERS} src/list.cpp)

add_library(data-structures STATIC
    ${LIBRARY_SOURCES}
)
target_include_directories(data-structures
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Target: Tests

set(INSTALL_GTEST OFF)
add_subdirectory(dependencies/googletest)

enable_testing()

add_executable(
    data-structures-test
    src/test.cpp
    src/list.test.h
    ${LIBRARY_SOURCES}
)
target_sources(data-structures-test PRIVATE ${LIBRARY_SOURCES})
target_link_libraries(
    data-structures-test
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(data-structures-test)
add_test(NAME data-structures-test COMMAND data-structures-test)

# Target: Benchmarks

set (BENCHMARK_ENABLE_INSTALL OFF)
set (BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(dependencies/benchmark)

# add_executable(hellobench hellobench.cpp)
# target_link_libraries(hellobench benchmark)
