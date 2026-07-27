// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib
export module QLL.Core.Base.Macros;
// 1. OS・コンパイラ判定
#if defined(_WIN32)
    export constexpr int QLL_IS_WINDOWS = 1;
    export constexpr int QLL_IS_LINUX = 0;
#elif defined(__linux__)
    export constexpr int QLL_IS_LINUX = 1;
    export constexpr int QLL_IS_WINDOWS = 1;
#endif

#if defined(_MSC_VER)
    export constexpr int QLL_IS_MSVC = 1;
    export constexpr int QLL_IS_CLANG = 0;
    export constexpr int QLL_IS_GCC = 0;
    export constexpr int QLL_IS_GNU = 0;
#elif defined(__clang__)
    export constexpr int QLL_IS_MSVC = 0;
    export constexpr int QLL_IS_CLANG = 1;
    export constexpr int QLL_IS_GCC = 0;
    export constexpr int QLL_IS_GNU = 1;
#elif defined(__GNUC__)
    export constexpr int QLL_IS_MSVC = 0;
    export constexpr int QLL_IS_CLANG = 0;
    export constexpr int QLL_IS_GCC = 1;
    export constexpr int QLL_IS_GNU = 1;
#endif
#if defined(_M_X64) || defined(__x86_64__)
    export constexpr int QLL_X86_64 = 1;
    export constexpr int QLL_ARM64 = 0;
#elif defined(_M_ARM64) || defined(__aarch64__)
    export constexpr int QLL_X86_64 = 0;
    export constexpr int QLL_ARM64 =  1;
#endif