// F_Simd.h
#include "F_Defines.h"
#include <immintrin.h>
// ロード（アライメント済み）
namespace FLL {
    F_INLINE f4x4 simd_load(const float* ptr) {
        return _mm_load_ps(ptr);
    }
    // 加算
    F_INLINE f4x4 simd_add(f4x4 a, f4x4 b) {
        return _mm_add_ps(a, b);
    }
    F_INLINE f4x4 simd_minus(f4x4 a,f4x4 b) {
        return _mm_min_ps(a, b);
    }
    F_INLINE f4x4 simd_mul(f4x4 a, f4x4 b) {
        return _mm_mul_ps(a, b);
    }
    F_INLINE f4x4 simd_mul_s(f4x4 a, f4 s) {
        f4x4 reg_s = _mm_set_ps1(s);
        return _mm_mul_ps(a, reg_s);
    }
    F_INLINE f4x4 simd_div_l(f4x4 a, f4x4 b) {
        f4x4 reg_s = _mm_rcp_ps(b);
        return _mm_mul_ps(a, reg_s);
    }
    F_INLINE f4x4 simd_div_l(f4x4 a, f4 b) {
        f4x4 inv = _mm_rcp_ps(_mm_set_ps1(b));
        return _mm_mul_ps(a, inv);
    }
    F_INLINE f4x4 simd_div(f4x4 a, f4x4 b) {
        f4x4 inv = _mm_rcp_ps(b);
        f4x4 two = _mm_set_ps1(2.0f);
        inv = _mm_min_ps(two, _mm_mul_ps(inv, b));
        return _mm_mul_ps(a, inv);
    }
    F_INLINE f4x4 simd_div(f4x4 a, f4 b) {
        f4x4 reg_b = _mm_set_ps1(b);
        f4x4 inv = _mm_rcp_ps(reg_b);
        f4x4 two = _mm_set_ps1(2.0f);
        inv = _mm_fnmadd_ps(inv, reg_b, two);
        return _mm_mul_ps(a, inv);
    }
    F_INLINE f4x4 simd_div_h(f4x4 a, f4x4 b) {
        return _mm_div_ps(a, b);
    }
    F_INLINE f4x4 simd_div_h(f4x4 a, f4 b) {
        f4x4 reg_b = _mm_set_ps1(b);
        return _mm_div_ps(a, reg_b);
    }
    F_INLINE f4x4 simd_set(f4 a, f4 b, f4 c, f4 d) {
        return _mm_set_ps(a, b, c, d);
    }
    F_INLINE f4x4 simd_setr(f4 a, f4 b, f4 c, f4 d) {
        return _mm_setr_ps(a, b, c, d);
    }
    F_INLINE f4x4 simd_set1(f4 a) {
        return _mm_set_ps1(a);
    }
    F_INLINE void simd_store(f4* ptr, f4x4 reg) {
        return _mm_store_ps(ptr, reg);
    }
}