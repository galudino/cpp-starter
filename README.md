# cpp-starter

A C17/C++23 CMake template for sketching projects in GitHub Codespaces,
including from an iPad. Open a Codespace and it arrives configured and
built: run, debug, and test from the CMake Tools status bar without
touching a terminal.

## Features

- C17 and C++23 (GCC 14, so `std::print` works)
- One example of each library kind: compiled C++, C with an `extern "C"`
  header, and header-only C++
- CMake presets with Ninja: `debug`, `release`, `asan-ubsan`
- doctest unit tests, discovered per test case by CTest and the VS Code
  Test Explorer
- clang-format, clang-tidy, and Doxygen
- GitHub Actions CI: GCC 14 and Clang 18, all presets, warnings as errors,
  plus a format and lint job

## Quick start in Codespaces

1. **Use this template** → **Create a new repository**.
2. In the new repository: **Code** → **Codespaces** → **Create codespace on main**.
3. Wait for the `postCreateCommand` to finish configuring and building.
4. Use the CMake Tools buttons in the status bar to build, run, debug, and
   test. Every task in `.vscode/tasks.json` is also available from the
   Command Palette under **Tasks: Run Task**.

### iPad tips

- iPad keyboards usually have no function keys, so F5/F7-style shortcuts
  are out. The status bar buttons and **Tasks: Run Task** cover the same
  actions.
- The Command Palette is also in the menu (☰) → **View** → **Command Palette**.
- New Codespaces build the container image first, which takes a couple of
  minutes. To skip that, enable prebuilds under the repository's
  **Settings** → **Codespaces** → **Set up prebuild**.

## Start a new sketch

1. Rename the project, namespace, include directory, and targets:

   ```bash
   ./scripts/rename.sh my_sketch
   ```

   This replaces `cpp_starter`, `starter`, and `STARTER_` throughout the
   repository, moves each `include/starter/` to `include/my_sketch/`, and
   deletes the script. Commit or stash first; it refuses to run on a dirty
   tree.

2. Delete the example components you don't need. Each one is a folder
   plus a line in three places:

   | Remove | And its line in |
   |--------|-----------------|
   | `components/<name>/` | `CMakeLists.txt` (`add_subdirectory`) |
   | `tests/<name>_tests.cpp` | `tests/CMakeLists.txt` (source and link) |
   | | `app/CMakeLists.txt` and `app/main.cpp`, if the app uses it |

3. Update `LICENSE`, the `project()` description in `CMakeLists.txt`, and
   `PROJECT_BRIEF` in `docs/Doxyfile.in`.

## Layout

```text
app/                    Command-line executable (main.cpp)
components/
    greeting/           Compiled C++ library        starter::greeting
    ring_buffer/        Header-only C++ library     starter::ring_buffer
    sensor/             C library                   starter::sensor
tests/                  doctest unit tests, one file per component
cmake/                  Shared CMake helpers (compiler warnings)
docs/                   Doxygen configuration
scripts/rename.sh       One-time project rename
```

Each component has its own `CMakeLists.txt` that defines a
`starter_<name>` target with a `starter::<name>` alias, and puts its public
headers under `include/starter/`. Link against the alias:

```cmake
target_link_libraries(my_target PRIVATE starter::ring_buffer)
```

### Adding a component

Copy the component folder closest to what you need (`ring_buffer` for
header-only, `greeting` for compiled C++, `sensor` for C), rename the
files and targets inside it, and add an `add_subdirectory` line to the
root `CMakeLists.txt`.

## Command line

```bash
cmake --preset debug                    # configure
cmake --build --preset debug            # build
./build/debug/app/starter               # run
ctest --preset debug                    # test
```

Replace `debug` with any preset:

| Preset | Purpose |
|--------|---------|
| `debug` | Day-to-day development |
| `release` | Optimized build |
| `asan-ubsan` | Debug build with AddressSanitizer and UndefinedBehaviorSanitizer; any report fails the test |

To fail the build on compiler warnings (as CI does), add
`-DCMAKE_COMPILE_WARNING_AS_ERROR=ON` when configuring.

### Formatting and static analysis

```bash
git ls-files '*.c' '*.cpp' '*.h' '*.hpp' | xargs clang-format -i
run-clang-tidy -quiet -p build/debug "^$PWD/(app|components|tests)/.*\.(c|cpp)$"
```

### Documentation

```bash
cmake --build --preset debug --target docs
```

Output goes to `build/debug/docs/html/index.html`.

## Targets

| Target | Description |
|--------|-------------|
| `starter` | Command-line executable |
| `starter_greeting` | Compiled C++ library (`starter::greeting`) |
| `starter_ring_buffer` | Header-only C++ library (`starter::ring_buffer`) |
| `starter_sensor` | C library (`starter::sensor`) |
| `starter_tests` | doctest unit tests |
| `docs` | Doxygen HTML, when Doxygen is installed |

`STARTER_BUILD_TESTS` and `STARTER_BUILD_DOCS` default to `ON` when this
is the top-level project and `OFF` when it is added to another project
with `add_subdirectory` or `FetchContent`.

## Building outside Codespaces

The devcontainer has everything installed. Elsewhere you need:

- CMake 3.25+ and Ninja
- GCC 14+, or Clang 18+ with a standard library that provides `<print>`
  (libstdc++ 14 or libc++ 17)
- Network access on first configure, to fetch doctest
- Optional: clang-format, clang-tidy, Doxygen, GDB

## License

MIT. See [LICENSE](LICENSE).
