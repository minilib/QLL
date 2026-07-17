// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib
export module QLL.Core.Base.Macros;
// 1. OS・コンパイラ判定
#if defined(_WIN32)
    export constexpr int QLL_IS_PLATFORM_WINDOWS = 1;
    export constexpr int QLL_IS_PLATFORM_LINUX = 0;
#elif defined(__linux__)
    export constexpr int QLL_IS_PLATFORM_LINUX = 1;
    export constexpr int QLL_IS_PLATFORM_WINDOWS = 1;
#endif

#if defined(_MSC_VER)
    export constexpr int QLL_IS_COMPILER_MSVC = 1;
    export constexpr int QLL_IS_COMPILER_GCC = 0;
#elif defined(__GNUC__) || defined(__clang__)
    export constexpr int QLL_IS_COMPILER_GCC = 1;
    int QLL_IS_COMPILER_MSVC = 0;
#endif
#if defined(_M_X64) || defined(__x86_64__)
    export constexpr int QLL_CPU_X86_64 = 1;
    export constexpr int QLL_CPU_ARM64 = 0;
#elif defined(_M_ARM64) || defined(__aarch64__)
    export constexpr int QLL_CPU_X86_64 = 0;
    export constexpr int QLL_CPU_ARM64 =  1;
#endif