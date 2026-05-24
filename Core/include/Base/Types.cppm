// SPDX-License-Identifier: MIT OR Apache-2.0
export module FLL.Core.Base.Types;
import std;

export namespace FLL {
    #if defined(__STDCPP_FLOAT64_T__)
        using f4 = std::float32_t;
        using f8 = std::float64_t;
    #else
        using f8 = double;
        using f4 = float;
    #endif
    using i1 = std::int8_t;
    using u1 = std::uint8_t;
    using i2 = std::int16_t;
    using u2 = std::uint16_t;
    using i4 = std::int32_t;
    using u4 = std::uint32_t;
    using i8 = std::int64_t;
    using u8 = std::uint64_t;
}