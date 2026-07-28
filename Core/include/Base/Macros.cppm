// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
// //Copyright (c) 2026 minilib
export module QLL.Core.Base.Macros;
// 1. OS・コンパイラ判定
export constexpr bool QLL_IS_WINDOWS =
#ifdef _WIN64
    true;
#else 
    false;
#endif
export constexpr bool QLL_IS_LINUX =
#ifdef __linux__
    true;
#else 
    false;
#endif
#ifdef __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_OS_OSX
        export constexpr bool QLL_IS_MAC = true;
        export constexpr bool QLL_IS_IOS = false;
    #elif TARGET_OS_IOS
        export constexpr bool QLL_IS_MAC = false;
        export constexpr bool QLL_IS_IOS = true;
    #endif
#else 
    export constexpr bool QLL_IS_MAC = false;
    export constexpr bool QLL_IS_IOS = false;
#endif


export constexpr bool QLL_IS_MSVC =
#ifdef _MSC_VER
    true;
#else 
    false;
#endif
#ifdef __clang__
    export constexpr bool QLL_IS_CLANG = true;
    export constexpr bool QLL_IS_GCC = false;
    export constexpr bool QLL_IS_GNU = true;
#elif defined(__GNUC__)
    export constexpr bool QLL_IS_CLANG = false;
    export constexpr bool QLL_IS_GCC = true;
    export constexpr bool QLL_IS_GNU = true;
#endif
export constexpr int QLL_X86_64 =
#if defined(_M_X64) || defined(__x86_64__)
    true;
#else
    false;
#endif
export constexpr int QLL_ARM64 =
#if defined(_M_ARM64) || defined(__aarch64__)
    true;
#else
    false;
#endif