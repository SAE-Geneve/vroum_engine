//
// Created by ROG on 16.10.2024.
//

#ifndef FOUR_VEC2_H
#define FOUR_VEC2_H

#include <immintrin.h>
#include <array>
#include <iostream>

template<typename T>
class FourVec2 {
public:
    std::array<T, 4> x;
    std::array<T, 4> y;


    FourVec2() {
        x.fill(0); // Initialise toutes les valeurs x à 0
        y.fill(0); // Initialise toutes les valeurs y à 0
    }


    FourVec2(T x0, T y0, T x1, T y1, T x2, T y2, T x3, T y3) {
        x[0] = x0; y[0] = y0;
        x[1] = x1; y[1] = y1;
        x[2] = x2; y[2] = y2;
        x[3] = x3; y[3] = y3;
    }

    template<typename U>
    FourVec2<T> operator+(const FourVec2<U>& other) const {
        FourVec2<T> result;


        __m128i x1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(x.data()));
        __m128i x2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.x.data()));
        __m128i y1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(y.data()));
        __m128i y2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.y.data()));

        // Additionner les composantes
        __m128i res_x = _mm_add_epi32(x1, x2);
        __m128i res_y = _mm_add_epi32(y1, y2);

        // Stocker le résultat
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.x.data()), res_x);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.y.data()), res_y);

        return result;
    }

    template<typename U>
    FourVec2<T> operator-(const FourVec2<U>& other) const {
        FourVec2<T> result;

        // Charger les données non alignées pour les vecteurs x et y
        __m128i x1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(x.data()));
        __m128i x2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.x.data()));
        __m128i y1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(y.data()));
        __m128i y2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(other.y.data()));

        // Soustraire les composantes
        __m128i res_x = _mm_sub_epi32(x1, x2);
        __m128i res_y = _mm_sub_epi32(y1, y2);

        // Stocker le résultat
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.x.data()), res_x);
        _mm_storeu_si128(reinterpret_cast<__m128i*>(result.y.data()), res_y);

        return result;
    }

    // Affichage des valeurs (pour vérification)
    void print() const {
        std::cout << "FourVec2: (" << x[0] << ", " << y[0] << "), ("
                  << x[1] << ", " << y[1] << "), ("
                  << x[2] << ", " << y[2] << "), ("
                  << x[3] << ", " << y[3] << ")" << std::endl;
    }
};

#endif //FOUR_VEC2_H
