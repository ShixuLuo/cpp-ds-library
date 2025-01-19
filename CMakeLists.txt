cmake_minimum_required(VERSION 3.10) # Set the minimum CMake version
project(cpp-ds-library)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default to Debug build if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add compiler flags for Debug
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0") # Enable debug symbols and disable optimization

# Project directories
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

include_directories(${INCLUDE_DIR} ${TEST_DIR})

# Add library
add_library(ds_library STATIC
    ${SRC_DIR}/array.cpp
    ${SRC_DIR}/linkedlist.cpp
    ${SRC_DIR}/list.cpp
)

# Enable testing
enable_testing()

# Macro for defining test executables
macro(add_doctest_test test_name source_file)
    add_executable(${test_name} ${source_file})
    target_link_libraries(${test_name} ds_library)
    add_test(NAME ${test_name} COMMAND ${test_name})
endmacro()

# Add test executables using the macro
add_doctest_test(test_array ${TEST_DIR}/test_array.cpp)
add_doctest_test(test_linkedlist ${TEST_DIR}/test_linkedlist.cpp)
add_doctest_test(test_list ${TEST_DIR}/test_list.cpp)

# Output the build type for verification
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler flags (Debug): ${CMAKE_CXX_FLAGS_DEBUG}")
