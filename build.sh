#!/bin/bash
# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2026 minilib
set -euo pipefail
rm -rf build
mkdir -p build
cmake -G Ninja -Wno-experimental -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cp build/Core/CMakeFiles/@cmake_cxx_std.dir/std.pcm pcm
rm -rf pcm
mkdir -p pcm
find build -type f -name "*.pcm" -exec cp -t pcm {} +
PCMS=()
for file in pcm/*; do PCMS+=("$(basename "$file" ."${file##*.}")"); done
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]]; then
    CURRENT_PATH=$(pwd -W)
else
    CURRENT_PATH=$PWD
fi
MODULE_FILES=""
for name in "${PCMS[@]}"; do MODULE_FILES=$(cat << EOF
$MODULE_FILES
-fmodule-file=$name=$CURRENT_PATH/pcm/$name.pcm,
EOF
); done
cat << EOF > .clangd
CompileFlags:
    Add: [
        "-std=c++26",
        "-stdlib=libc++",
        "-g",
        "-D_WIN32",
        "-D_CRT_SECURE_NO_WARNINGS",
        "-IC:/dev/C++/QLL",
        "-IC:/dev/C++/QLL/Core/include",$MODULE_FILES
    ]
Index:
  Background: Build
EOF
cat .clangd