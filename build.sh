#!/bin/bash
set -euo pipefail
rm -rf build
mkdir -p build
cmake -G Ninja -Wno-experimental -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cp build/compile_commands.json .
read