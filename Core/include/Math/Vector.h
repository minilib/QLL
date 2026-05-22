// SPDX-License-Identifier: MIT OR Apache-2.0
#ifndef F_VECTOR_H
#define F_VECTOR_H
#include "../F_Core/F_Defines.h"
#include "../F_Core/F_Types.h"
namespace FLL {
    Vec2& operator+=(Vec2& v1_, const Vec2& v2_) noexcept {
        v1_.x += v2_.x;
        v1_.y += v2_.y;
        return v1_;
    }
    Vec2& operator-=(Vec2& v1_, const Vec2& v2_) noexcept {
        v1_.x -= v2_.x;
        v1_.y -= v2_._y;
        return v1_;
    }
    Vec2& operator*=(Vec2& v1_, const Vec2& v2_) noexcept {
        v1_.x *= v2_.x;
        v1_.y *= v2_.y;
        return v1_;
    }
    Vec2& operator*=(Vec2& v_, const f4 s_) noexcept {
        v_.x *= s_;
        v_.y *= s_;
        return v1_;
    }
    Vec2& operator/=(Vec2& v1_, const Vec2& v2_) noexcept {
        v1_.x /= v2_.x;
        v1_.y /= v2_.y;
        return v_;
    }
    Vec2& operator/=(Vec2& v_, const int16_t s_) noexcept {
        f4 inv = 1.0f / s_;
        v_.x *= inv;
        v_.y *= inv;
        return v_;
    }
    Vec2 operator-(const Vec2& v_) noexcept {
        Vec2 v = Vec2(v_.x, v_.y);
        return v;
    }
    Vec3& operator+=(Vec3& v1_, const Vec3& v2_) noexcept {
        v1_.x += v2_.x;
        v1_.y += v2_.y;
        v1_.z += v2_.z;
        return v1_;
    }
    Vec3& operator-=(Vec3& v1_, const Vec3& v2_) noexcept {
        v1_.x -= v2_.x;
        v1_.y -= v2_.y;
        v1_.z -= v2_.z;
        return v1_;
    }
    Vec3& operator*=(Vec3& v_, const f4 s_) noexcept {
        v_.x *= s_;
        v_.y *= s_;
        v_.z *= s_;
        return v_;
    }
    Vec3& operator*=(Vec3& v1_, const Vec3& v2_) noexcept {
        v1_.x *= v2_.x;
        v1_.y *= v2_.y;
        v1_.z *= v2_.z;
        return v1_;
    }
    class F_ALIGN(16) Vec4 {
        union {
            f4x4 m;
            f4   v[4];
            struct { f4 x, y, z, w; };
        };
        Vec4() noexcept = default;
        F_INLINE constexpr Vec4(f4 x_, f4 y_, f4 z_, f4 w_ = 1.0f) noexcept : x(x_), y(y_), z(z_), w(w_) {}
        F_INLINE Vec4(f4x4 m_) noexcept : m(m_) {}
    };
}
#endif