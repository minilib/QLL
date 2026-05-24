export module FLL.Core.Math.Vector;
export namespace FLL {
    template <typename T>
    struct Vec2 {
        public:
            Vec2() noexcept {}
            Vec2(T x, T y) noexcept : x_(x), y_(y) {}
            Vec2 operator+(const Vec2& vec) {
                return Vec2(x_ + vec.x_, y_ + vec.y_);
            }
            Vec2 operator+=(const Vec2& vec) {
                x_ += vec.x_;
                y_ += vec.y_;
                return *this;
            }
            Vec2 operator-=(const Vec2& vec) {
                x_ -= vec.x_;
                y_ -= vec.y_;
                return *this;
            }
            Vec2 operator*=(const Vec2& vec) {
                x_ *= vec.x_;
                y_ *= vec.y_;
                return *this;
            }
            Vec2 operator*=(const T scalar) {
                x_ *= scalar;
                y_ *= scalar;
                return *this;
            }
            Vec2 operator/=(const Vec2& vec) {
                x_ /= vec.x_;
                y_ /= vec.y_;
                return *this;
            }
            Vec2 operator/=(const T scalar) {
                x_ /= scalar;
                y_ /= scalar;
                return *this;
            }
        private:
            T x_, y_;
    };
    template <typename T>
    Vec2<T> operator+(Vec2<T> lhs, const Vec2<T>& rhs) {
        lhs += rhs;
        return lhs;
    }
    template <typename T>
    Vec2<T> operator-(Vec2<T> lhs, const Vec2<T>& rhs) {
        lhs -= rhs;
        return lhs;
    }
    template <typename T>
    Vec2<T> operator*(Vec2<T> lhs, const Vec2<T>& rhs) {
        lhs *= rhs;
        return lhs;
    }
    template <typename T>
    Vec2<T> operator*(Vec2<T> vec, T scalar) {
        vec *= scalar;
        return vec;
    }
    template <typename T>
    Vec2<T> operator/(Vec2<T> lhs, const Vec2<T>& rhs) {
        lhs /= rhs;
        return lhs;
    }
    template <typename T>
    Vec2<T> operator/(Vec2<T> vec, T scalar) {
        vec /= scalar;
        return vec;
    }
}
