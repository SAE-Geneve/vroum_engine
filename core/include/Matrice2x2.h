#ifndef MATRICE2X2_H
#define MATRICE2X2_H

#include "Vector2.h"

template<typename T>

struct Mat2x2
{

    T a11, a12; // First line
    T a21, a22; // Second line

    Mat2x2(T a11, T a12, T a21, T a22)
           : a11(a11), a12(a12), a21(a21), a22(a22) {}

    double determinant() const {
        return a11 * a22 - a12 * a21;
    }


    std::optional<std::tuple<T, T>> solveSystem(T b1, T b2) const {
        T det = determinant();

        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        T x = (b1 * a22 - b2 * a12) / det;
        T y = (a11 * b2 - a21 * b1) / det;

        return std::make_tuple(x, y);
    }

    Mat2x2 operator+(const Mat2x2& other) const {
        return Mat2x2(a11 + other.a11, a12 + other.a12, a21 + other.a21, a22 + other.a22);
    }

    Mat2x2 operator-(const Mat2x2& other) const {
        return Mat2x2(a11 - other.a11, a12 - other.a12, a21 - other.a21, a22 - other.a22);
    }

    Mat2x2 operator*(const Mat2x2& other) const {
        return Mat2x2(
            a11 * other.a11 + a12 * other.a21,
            a11 * other.a12 + a12 * other.a22,
            a21 * other.a11 + a22 * other.a21,
            a21 * other.a12 + a22 * other.a22
        );
    }

    constexpr Mat2x2<T>& operator*=(const T scalar) noexcept
    {
        return *this = *this * scalar;
    }

    Mat2x2 operator*(const T scalar) const {
        return Mat2x2(
            a11 * scalar, a12 * scalar,
            a21 * scalar, a22 * scalar
        );
    }

    std::optional<Mat2x2> inverse() const {
        T det = determinant();

        if (det == 0.0) {
            return std::nullopt;
        }

        return Mat2x2(
            a22 / det, -a12 / det,
            -a21 / det, a11 / det
        );
    }

    // Transposition de la matrice
    Mat2x2 transpose() const {
        return Mat2x2(a11, a21, a12, a22);
    }

    // Multiplication par un vecteur 2D
    Vec2<T> operator*(const Vec2<T>& vec) const {
        return Vec2<T>(
            a11 * vec.x + a12 * vec.y,
            a21 * vec.x + a22 * vec.y
        );
    }

};


#endif //MATRICE2X2_H
