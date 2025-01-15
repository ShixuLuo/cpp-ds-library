cmake_minimum_required(VERSION 3.10) # Set the minimum CMake version
project(cpp-ds-library)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project directory
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

include_directories(${INCLUDE_DIR})

add_library(ds_library STATIC
    ${SRC_DIR}/array.cpp
)

add_executable(test_array
    ${TEST_DIR}/test_array.cpp
)

target_link_libraries(test_array ds_library)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
