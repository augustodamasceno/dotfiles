# CMake Template
#
# Copyright (c) 2026, Augusto Damasceno. All rights reserved.
# SPDX-License-Identifier: BSD-2-Clause

# ==============================================================================
# 1. PREAMBLE & PROJECT DEFINITION
# ==============================================================================
cmake_minimum_required(VERSION 3.21...3.28)

project(cmake_template
    VERSION     1.0.0
    DESCRIPTION "CMake Template using C++17 with LibTorch"
    LANGUAGES   CXX
)

if(WIN32 AND MINGW)
    message(FATAL_ERROR
        "LibTorch Windows binaries are built with MSVC and are not compatible "
        "with MinGW/GCC.\n"
        "Please reconfigure with the MSVC generator:\n"
        "  cmake -B build -G \"Visual Studio 18 2026\" -A x64"
    )
endif()

# ==============================================================================
# 2. GLOBAL CONFIGURATION & OPTIONS
# ==============================================================================
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(TEMPLATE_BUILD_TESTS          "Enable building unit tests"         ON)
option(TEMPLATE_WARNINGS_AS_ERRORS   "Treat compiler warnings as errors"  OFF)

# ==============================================================================
# 3. DEPENDENCIES
# ==============================================================================
# --- Clang-Tidy (optional lint) — scoped to template_lib only ---
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(CLANG_TIDY_EXE)
    message(STATUS "Found Clang-Tidy: ${CLANG_TIDY_EXE}")
else()
    message(WARNING "Clang-Tidy not found! Linting is disabled.")
endif()

# --- LibTorch (CPU) via FetchContent ---
include(FetchContent)

if(WIN32)
    set(LIBTORCH_URL
        "https://download.pytorch.org/libtorch/cpu/libtorch-win-shared-with-deps-2.5.1%2Bcpu.zip")
elseif(APPLE)
    set(LIBTORCH_URL
        "https://download.pytorch.org/libtorch/cpu/libtorch-macos-arm64-2.5.1.zip")
else()
    set(LIBTORCH_URL
        "https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-2.5.1%2Bcpu.zip")
endif()

FetchContent_Declare(libtorch URL ${LIBTORCH_URL})
# LibTorch is a pre-built binary, not a CMake source project.
# FetchContent_MakeAvailable cannot be used here — it would try to
# configure/build it as a CMake project and fail.
# CMP0169=OLD suppresses the deprecation warning for the direct
# FetchContent_Populate() call that is required in this case.
cmake_policy(SET CMP0169 OLD)
FetchContent_Populate(libtorch)
list(APPEND CMAKE_PREFIX_PATH "${libtorch_SOURCE_DIR}")
find_package(Torch REQUIRED)

# --- GoogleTest via FetchContent ---
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
    GIT_SHALLOW    TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK             OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ==============================================================================
# 4. TARGET DEFINITION
# ==============================================================================
add_library(template_lib STATIC)
add_executable(template_app)

# ==============================================================================
# 5. TARGET CONFIGURATION
# ==============================================================================
# --- template_lib ---
target_sources(template_lib PRIVATE
    src/core/core.cpp
    src/core/math_ops.cpp
    src/ui/ui.cpp
    src/ui/formatter.cpp
    src/utils/utils.cpp
    src/utils/string_utils.cpp
)

target_include_directories(template_lib
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(template_lib PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic
        $<$<BOOL:${TEMPLATE_WARNINGS_AS_ERRORS}>:-Werror>
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        $<$<BOOL:${TEMPLATE_WARNINGS_AS_ERRORS}>:/WX>
    >
)

if(CLANG_TIDY_EXE)
    set_target_properties(template_lib PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
    )
endif()

# --- template_app executable ---
target_sources(template_app PRIVATE main.cpp)

target_link_libraries(template_app PRIVATE
    template_lib
    ${TORCH_LIBRARIES}
)

target_compile_options(template_app PRIVATE
    ${TORCH_CXX_FLAGS}
)

if(WIN32)
    file(GLOB TORCH_DLLS "${libtorch_SOURCE_DIR}/lib/*.dll")
    add_custom_command(TARGET template_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${TORCH_DLLS}
            $<TARGET_FILE_DIR:template_app>
    )
endif()

# ==============================================================================
# 6. TESTING & SUBDIRECTORIES
# ==============================================================================
if(TEMPLATE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)

    # Avoid collision with CMake's built-in RUN_TESTS target on Visual Studio
    # (target names are case-insensitive there).
    add_custom_target(run_all_tests
        COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --output-on-failure
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    add_dependencies(run_all_tests test_core test_ui test_utils)
endif()


