# cpp-starter: C/C++ Codespaces Starter Template Project

A reusable C17/C++23 command-line project template using CMake,
Ninja, GitHub Codespaces, and Visual Studio Code.

## Features

- C17 and C++23
- Separate C and C++ static libraries
- C/C++ interoperability
- CMake and Ninja
- `Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`
- CTest unit testing
- Doxygen documentation
- Clang Format and Clang Tidy
- GitHub Codespaces development container
- VS Code build tasks and debugging

## Requirements

- CMake 3.25+
- Ninja
- GCC or Clang with C++23 support
- Doxygen (optional)
- GDB (optional)

## Project targets

| Target | Description |
|--------|-------------|
| greeting | C++ static library |
| byte_transport | Header-only C++23 transport component |
| sensor_driver | C static library |
| starter | Command-line executable |
| starter_tests | Unit tests |
| docs | Doxygen HTML documentation |

## Configure

```bash
cmake --preset debug
```

Available presets:

- `debug`
- `release`
- `relwithdebinfo`
- `minsizerel`

Replace `debug` with any of the available presets above.

## Build

```bash
cmake --build --preset debug
```

## Run

```bash
./build/debug/app/starter
```

## Test

```bash
ctest --preset debug
```

## Documentation

```bash
cmake --build --preset debug --target docs
```

Open:

```text
build/debug/docs/html/index.html
```

## Formatting

```bash
find app components tests -type f \
    \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
    -exec clang-format -i {} +
```

## Static analysis

```bash
run-clang-tidy -p build/debug
```

## Debugging

Use the VS Code Debug launch configurations, or:

```bash
gdb ./build/debug/app/starter
```

## Development environment

The `.devcontainer` directory defines the Codespaces environment.

The `.vscode` directory contains recommended extensions,
editor settings, build tasks, and debugging configurations.

CMakePresets.json is the source of truth for build configurations.
