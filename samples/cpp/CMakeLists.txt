# Dot Files - This CMakeLists is intended to test 
#   the dot files related to C++.
#
# Copyright (c) 2026, Augusto Damasceno.
# All rights reserved.
#
# SPDX-License-Identifier: BSD-2-Clause
#
# See https://github.com/augustodamasceno/dotfiles
#

cmake_minimum_required(VERSION 3.10)
project(dotfiles_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g3 -ggdb)
endif()

add_executable(main main.cpp)

# Google Tests
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK             OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests tests/test_main.cpp)
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
