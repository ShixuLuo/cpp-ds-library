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

include_directories(${INCLUDE_DIR})

# Add library
add_library(ds_library STATIC
    ${SRC_DIR}/array.cpp
    ${SRC_DIR}/linkedlist.cpp
)

# Add test executables
add_executable(test_array
    ${TEST_DIR}/test_array.cpp
)
target_link_libraries(test_array ds_library)

add_executable(test_linkedlist
    ${TEST_DIR}/test_linkedlist.cpp
)
target_link_libraries(test_linkedlist ds_library)

# Output the build type for verification
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler flags (Debug): ${CMAKE_CXX_FLAGS_DEBUG}")
