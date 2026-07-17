#!/bin/bash
# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2026 minilib
set -euo pipefail
rm -rf build
mkdir -p build
cmake -G Ninja -Wno-experimental -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cp build/compile_commands.json .
read