// SPDX-License-Identifier: MIT OR Apache-2.0
export module QLL.Core.Math.Rect;
import QLL.Core.Math.Vector;

template<typename T>
struct Rect {
    Rect(T x, T y, T w, T h) noexcept : x_(x), y_(y), w_(w), h_(h) {}
    T x_, y_, w_, h_;
    T left() {return  x_; }
    T right() {return x_ + w_; }
    T top()
};