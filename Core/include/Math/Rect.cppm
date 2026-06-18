// SPDX-License-Identifier: MIT OR Apache-2.0

export module QLL.Core.Math.Rect;
import QLL.Core.Base.Types;
import QLL.Core.Math.Vector;

namespace FLL {
/**
 * @brief Maintain Rect
 * 
 * @note Origin is top-left
 * @tparam T Number type
 */
template<typename T>
struct Rect {
    Rect() = default;
    Rect(T x, T y, T w, T h) noexcept : x(x), y(y), w(w), h(h) {}
    Rect(Vec2<T> pos_, Vec2<T> size_) noexcept : pos(pos_), size(size_) {}
    union {
        struct {Vec2<T> pos, size; };
        struct {
            T x = 0;
            T y = 0;
            T w = 0;
            T h = 0;
        };
    };
    T left() const noexcept {return  x; }
    T right() const noexcept {return x + w; }
    T top() const noexcept {return y; }
    T bottom() const noexcept {return y + h; }
    Vec2<T> topLeft() const noexcept {return {x, y}; }
    Vec2<T> topRight() const noexcept {return {x + w, y}; }
    Vec2<T> bottomLeft() const noexcept {return {x, y+ h}; }
    Vec2<T> bottomRight() const noexcept {return {x + w, y+ h}; }
    Vec2<T> center() const noexcept {return {x + w / 2, y + h / 2}; }
    Rect move(T dx, T dy) noexcept {
        x += dx;
        y += dy;
        return *this;
    }
    Rect move(Vec2<T> vec) noexcept {
        pos += vec;
        return *this;
    }
    Rect scale(T scaleX, T scaleY) {
        x *= scaleX;
        y *= scaleY;
        return *this;
    } 
    Rect scale(Vec2<T> vec) noexcept {
        size *= vec;
        return *this;
    }
};
}