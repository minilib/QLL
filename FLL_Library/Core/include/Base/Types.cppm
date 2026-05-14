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
    struct Vec2 {
        f4 x, y;
        Vec2() noexcept = default;
        constexpr Vec2(const f4 x_, const f4 y_) noexcept : x(x_), y(y_) {}
    };
    struct Vec3 {
        f4 x, y, z;
        Vec3() noexcept = default;
        constexpr Vec3(const f4 x_, const f4 y_, const f4 z_) noexcept : x(x_), y(y_), z(z_) {}
    };
    struct Vec4 {
        f4 x, y, z, w;
        Vec4() noexcept = default;
        constexpr Vec4(const f4 x_, const f4 y_, const f4 z_, const f4 w_ = 1.0f) noexcept : x(x_), y(y_), z(z_), w(w_) {}
    };
    using i1 = std::int8_t;
    using u1 = std::uint8_t;
    using i2 = std::int16_t;
    using u2 = std::uint16_t;
    using i4 = std::int32_t;
    using u4 = std::uint32_t;
    using i8 = std::int64_t;
    using u8 = std::uint64_t;
}