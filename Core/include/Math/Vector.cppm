// SPDX-License-Identifier: MIT-0 OR Zlib OR MIT OR Apache-2.0
export module QLL.Core.Math.Vector;
export namespace QLL {
    /**
     * @brief 2-element vector
     * 
     * @tparam T Number type
     */
    template <typename T>
    struct Vec2 {
        public:
            constexpr Vec2() noexcept {}
            constexpr Vec2(T x, T y) noexcept : x(x), y(y) {}
            constexpr Vec2 operator+(const Vec2& vec) {
                return Vec2(x + vec.x, y + vec.y);
            }
            constexpr Vec2 operator+=(const Vec2& vec) noexcept {
                x += vec.x;
                y += vec.y;
                return *this;
            }
            constexpr Vec2 operator-=(const Vec2& vec) noexcept {
                x -= vec.x;
                y -= vec.y;
                return *this;
            }
            constexpr Vec2 operator*=(const Vec2& vec) noexcept {
                x *= vec.x;
                y *= vec.y;
                return *this;
            }
            constexpr Vec2 operator*=(const T scalar) noexcept {
                x *= scalar;
                y *= scalar;
                return *this;
            }
            constexpr Vec2 operator/=(const Vec2& vec) noexcept {
                x /= vec.x;
                y /= vec.y;
                return *this;
            }
            constexpr Vec2 operator/=(const T scalar) noexcept {
                x /= scalar;
                y /= scalar;
                return *this;
            }
        private:
            T x, y;
    };
    template <typename T>
    constexpr Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs) noexcept {
        lhs += rhs;
        return lhs;
    }
    template <typename T>
    constexpr Vec2<T> operator-(Vec2<T> lhs, const Vec2<T>& rhs) noexcept {
        lhs -= rhs;
        return lhs;
    }
    template <typename T>
    constexpr Vec2<T> operator*(Vec2<T> lhs, const Vec2<T>& rhs) noexcept {
        lhs *= rhs;
        return lhs;
    }
    template <typename T>
    constexpr Vec2<T> operator*(Vec2<T> vec, T scalar) noexcept {
        vec *= scalar;
        return vec;
    }
    template <typename T>
    constexpr Vec2<T> operator/(Vec2<T> lhs, const Vec2<T>& rhs) noexcept {
        lhs /= rhs;
        return lhs;
    }
    template <typename T>
    constexpr Vec2<T> operator/(Vec2<T> vec, T scalar) noexcept {
        vec /= scalar;
        return vec;
    }
}
