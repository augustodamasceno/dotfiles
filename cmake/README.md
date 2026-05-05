# CMake Template — C++17 with LibTorch

Copyright (c) 2026, Augusto Damasceno. All rights reserved.  
SPDX-License-Identifier: BSD-2-Clause
---

## Overview

This is a C++17 project template demonstrating a clean CMake structure with:

- **LibTorch 2.5.1 (CPU)** — downloaded automatically via `FetchContent`
- **GoogleTest v1.15.2** — downloaded automatically via `FetchContent`
- **clang-tidy** — optional static analysis, auto-detected at configure time
- **CTest** integration for running all unit tests

---

## Project Structure

```
cmake/
├── CMakeLists.txt          # Root build file (6-section layout)
├── main.cpp                # Entry point — XOR demo with LibTorch
│
├── include/                # Public headers
│   ├── core/
│   │   ├── core.h          # Core: XOR dataset provider
│   │   └── math_ops.h      # Core: clamp / lerp
│   ├── ui/
│   │   ├── ui.h            # Ui: banner / result / accuracy printer
│   │   └── formatter.h     # Ui: float-to-string / pad-left
│   └── utils/
│       ├── utils.h         # Utils: normalize / accuracy
│       └── string_utils.h  # Utils: trim / toUpper
│
├── src/                    # Implementations
│   ├── core/
│   ├── ui/
│   └── utils/
│
└── tests/
    ├── CMakeLists.txt
    ├── fixtures/
    │   └── dataset_fixture.h   # Shared GTest base fixture (loads CSV once)
    ├── resources/
    │   └── xor_dataset.csv     # Shared test data (input1, input2, expected)
    ├── core/                   # Tests for core module
    ├── ui/                     # Tests for ui module
    └── utils/                  # Tests for utils module
```

---

## CMakeLists Sections

| # | Section | Purpose |
|---|---------|---------|
| 1 | Preamble & Project | `cmake_minimum_required`, `project()` with version and description |
| 2 | Global Configuration | C++17 settings, `compile_commands.json`, build options |
| 3 | Dependencies | clang-tidy discovery, LibTorch + GoogleTest via `FetchContent` |
| 4 | Target Definition | Declare `template_lib` (static) and `template_app` (executable) |
| 5 | Target Configuration | `target_sources`, `target_include_directories`, `target_compile_options`, linking |
| 6 | Testing | `enable_testing()`, `add_subdirectory(tests)`, `run_all_tests` target |

---

## Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `TEMPLATE_BUILD_TESTS` | `ON` | Build the unit test executables |
| `TEMPLATE_WARNINGS_AS_ERRORS` | `OFF` | Promote `-Wall` warnings to errors (`-Werror` / `/WX`) |

---

## Requirements

- CMake ≥ 3.21
- C++17 compiler:
  - **Windows:** MSVC (Visual Studio 18 2026, 17 2022, or 16 2019) — **MinGW/GCC is not supported** (LibTorch Windows binaries require MSVC ABI)
  - **Linux:** GCC ≥ 9 or Clang ≥ 9
  - **macOS:** Clang ≥ 9 (Xcode or Homebrew LLVM)
- Internet access on first configure (LibTorch ~200 MB, GoogleTest ~5 MB)

---

## Configure & Build

```bash
# Linux / macOS — from the cmake/ directory
cmake -B build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake -B build -DTEMPLATE_BUILD_TESTS=OFF
cmake -B build -DTEMPLATE_WARNINGS_AS_ERRORS=ON
cmake --build build

# Build a specific target
cmake --build build --target template_app
cmake --build build --target test_core
```

```powershell
# Windows (PowerShell) — must use MSVC, not MinGW
cmake -B build -G "Visual Studio 18 2026" -A x64
cmake -B build -G "Visual Studio 18 2026" -A x64 -DTEMPLATE_BUILD_TESTS=OFF
cmake --build build --config Release

# Build a specific target
cmake --build build --config Release --target template_app
cmake --build build --config Release --target test_core
```

> **Windows note:** LibTorch DLLs are copied next to `template_app.exe`
> automatically via a `POST_BUILD` step — no manual PATH changes needed.

---

## Changing the Compiler (Windows)

CMake caches the compiler on first configure — you **must delete the build directory** before switching.

```powershell
# Step 1 — delete the cache
Remove-Item -Recurse -Force build

# Step 2 — reconfigure with MSVC
cmake -B build -G "Visual Studio 18 2026" -A x64   # VS 2026
cmake -B build -G "Visual Studio 17 2022" -A x64   # VS 2022

# Step 3 — build
cmake --build build --config Release
```

To list all generators available on your machine:
```powershell
cmake --help
```

If Visual Studio is not installed, you have two options:

**Option A — Visual Studio Build Tools (recommended, no IDE needed, ~4 GB):**
1. Download from https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022
2. Run the installer and select the **"C++ build tools"** workload
3. Reopen PowerShell and reconfigure:
```powershell
cmake -B build -G "Visual Studio 18 2026" -A x64
```

**Option B — LLVM `clang-cl` (if LLVM for Windows is already installed):**  
`clang-cl` uses the MSVC ABI and is compatible with LibTorch without a full VS install.
```powershell
cmake -B build -G "Ninja" `
    -DCMAKE_C_COMPILER=clang-cl `
    -DCMAKE_CXX_COMPILER=clang-cl
cmake --build build
```
> Requires LLVM from https://releases.llvm.org — **not** the MSYS2/MinGW clang.

> **Why MinGW cannot be used:** PyTorch only ships pre-built Windows binaries compiled with MSVC. MinGW and MSVC use incompatible C++ ABIs on Windows — linking against LibTorch with MinGW will always fail with `__assert_fail` / `dllimport` errors.

---

## Run the Application

```bash
# Linux / macOS
./build/template_app
```

```powershell
# Windows
.\build\Release\template_app.exe
```

---

## Run Tests

```bash
# Linux / macOS — run all tests via CTest
cd build
ctest --output-on-failure

# Run all tests via the custom target
cmake --build build --target run_all_tests

# Run a specific test binary directly
./build/tests/test_core
./build/tests/test_ui
./build/tests/test_utils

# Run a single named test case
./build/tests/test_utils --gtest_filter="DatasetFixture.NormalizeRange"

# Run all tests matching a pattern
./build/tests/test_core --gtest_filter="DatasetFixture.*"
```

```powershell
# Windows
cd build
ctest -C Release --output-on-failure

cmake --build build --config Release --target run_all_tests

.\tests\Release\test_core.exe
.\tests\Release\test_core.exe --gtest_filter="DatasetFixture.*"
```

---

## Test Architecture

All test suites share a single fixture defined in `tests/fixtures/dataset_fixture.h`:

```cpp
class DatasetFixture : public ::testing::Test {
protected:
    inline static std::vector<Core::Sample> dataset;
    static void SetUpTestSuite();   // loads xor_dataset.csv once per suite
    static void TearDownTestSuite();
};
```

- `SetUpTestSuite` reads `tests/resources/xor_dataset.csv` **once** before the first test in a suite runs.
- The CSV path is injected at compile time via the `TEST_RESOURCES_DIR` macro — no hardcoded paths.
- Every test file in `tests/core/`, `tests/ui/`, `tests/utils/` is compiled automatically (CMake `GLOB`).

---

## Lint

clang-tidy runs automatically during the build if it is installed.  
`compile_commands.json` is always generated in the build directory and can be used by editors or standalone clang-tidy invocations:

```bash
clang-tidy src/core/core.cpp -p build
```
