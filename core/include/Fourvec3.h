#ifndef FOURVEC3_H
#define FOURVEC3_H

#include <immintrin.h>
#include <array>
#include <iostream>

template<typename T>
class FourVec3 {
public:
    std::array<T, 4> x;
    std::array<T, 4> y;
    std::array<T, 4> z;


    FourVec3() {
        x.fill(0);
        y.fill(0);
        z.fill(0);
    }


    FourVec3(T x0, T y0, T z0, T x1, T y1, T z1, T x2, T y2, T z2, T x3, T y3, T z3) {
        x[0] = x0; y[0] = y0; z[0] = z0;
        x[1] = x1; y[1] = y1; z[1] = z1;
        x[2] = x2; y[2] = y2; z[2] = z2;
        x[3] = x3; y[3] = y3; z[3] = z3;
    }


    template<typename T>
    FourVec3<T> operator+(const FourVec3<T>& other) const {
        FourVec3<T> result;


        __m128i x1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(x.data()));
        __m128i x2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.x.data()));


        __m128i y1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(y.data()));
        __m128i y2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.y.data()));


        __m128i z1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(z.data()));
        __m128i z2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.z.data()));


        __m128i res_x = _mm_add_epi32(x1, x2);
        __m128i res_y = _mm_add_epi32(y1, y2);
        __m128i res_z = _mm_add_epi32(z1, z2);


        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.x.data()), res_x);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.y.data()), res_y);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.z.data()), res_z);

        return result;
    }


    template<typename T>
    FourVec3<T> operator-(const FourVec3<T>& other) const {
        FourVec3<T> result;


        __m128i x1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(x.data()));
        __m128i x2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.x.data()));


        __m128i y1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(y.data()));
        __m128i y2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.y.data()));


        __m128i z1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(z.data()));
        __m128i z2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.z.data()));


        __m128i res_x = _mm_sub_epi32(x1, x2);
        __m128i res_y = _mm_sub_epi32(y1, y2);
        __m128i res_z = _mm_sub_epi32(z1, z2);


        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.x.data()), res_x);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.y.data()), res_y);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.z.data()), res_z);

        return result;
    }

};

#endif // FOURVEC3_H
