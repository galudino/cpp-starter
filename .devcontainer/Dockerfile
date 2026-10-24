
FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        clang \
        clang-format \
        clang-tidy \
        cmake \
        ninja-build \
        gdb \
        lldb \
        doxygen \
        graphviz \
    && rm -rf /var/lib/apt/lists/*
