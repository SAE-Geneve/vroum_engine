#ifndef MATRICE3X3_H
#define MATRICE3X3_H

#include "Vector3.h"
#include <optional>

template<typename T>

struct Mat3x3
{
    T a11, a12, a13;
    T a21, a22, a23;
    T a31, a32, a33;


    Mat3x3(T a11, T a12, T a13,
            T a21, T a22, T a23,
            T a31, T a32, T a33)
        : a11(a11), a12(a12), a13(a13),
          a21(a21), a22(a22), a23(a23),
          a31(a31), a32(a32), a33(a33) {}

    [[nodiscard]] constexpr double determinant() const {
        return a11 * (a22 * a33 - a23 * a32) -
               a12 * (a21 * a33 - a23 * a31) +
               a13 * (a21 * a32 - a22 * a31);
    }

    [[nodiscard]] constexpr std::optional<std::tuple<T, T, T>> SolveSystem(T b1, T b2, T b3) const noexcept{
        double det = determinant();

        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        T x = (b1 * (a22 * a33 - a32 * a23) - a12 * (b2 * a33 - a23 * b3) + a13 * (b2 * a32 - a22 * b3)) / det;
        T y = (a11 * (b2 * a33 - b3 * a23) - b1 * (a21 * a33 - a23 * a31) + a13 * (a21 * b3 - b2 * a31)) / det;
        T z = (a11 * (a22 * b3 - a32 * b2) - a12 * (a21 * b3 - b2 * a31) + b1 * (a21 * a32 - a22 * a31)) / det;

        return std::make_tuple(x, y, z);
    }

    Mat3x3 operator+(const Mat3x3& other) const {
        return Mat3x3(a11 + other.a11, a12 + other.a12, a13 + other.a13,
                      a21 + other.a21, a22 + other.a22, a23 + other.a23,
                      a31 + other.a31, a32 + other.a32, a33 + other.a33);
    }

    Mat3x3 operator-(const Mat3x3& other) const {
        return Mat3x3(a11 - other.a11, a12 - other.a12, a13 - other.a13,
                      a21 - other.a21, a22 - other.a22, a23 - other.a23,
                      a31 - other.a31, a32 - other.a32, a33 - other.a33);
    }

    Mat3x3 operator*(const Mat3x3& other) const {
        return Mat3x3(
            a11 * other.a11 + a12 * other.a21 + a13 * other.a31,
            a11 * other.a12 + a12 * other.a22 + a13 * other.a32,
            a11 * other.a13 + a12 * other.a23 + a13 * other.a33,
            a21 * other.a11 + a22 * other.a21 + a23 * other.a31,
            a21 * other.a12 + a22 * other.a22 + a23 * other.a32,
            a21 * other.a13 + a22 * other.a23 + a23 * other.a33,
            a31 * other.a11 + a32 * other.a21 + a33 * other.a31,
            a31 * other.a12 + a32 * other.a22 + a33 * other.a32,
            a31 * other.a13 + a32 * other.a23 + a33 * other.a33
        );
    }

    // Multiplication par un scalaire
    Mat3x3 operator*(const T scalar) const {
        return Mat3x3(
            a11 * scalar, a12 * scalar, a13 * scalar,
            a21 * scalar, a22 * scalar, a23 * scalar,
            a31 * scalar, a32 * scalar, a33 * scalar
        );
    }

    constexpr Mat3x3<T>& operator*=(const T scalar) noexcept
    {
        return *this = *this * scalar;
    }

    std::optional<Mat3x3> inverse() const {
        T det = determinant();

        if (det == 0.0) {
            return std::nullopt;
        }

        return Mat3x3(
            (a22 * a33 - a23 * a32) / det, (a13 * a32 - a12 * a33) / det, (a12 * a23 - a13 * a22) / det,
            (a23 * a31 - a21 * a33) / det, (a11 * a33 - a13 * a31) / det, (a13 * a21 - a11 * a23) / det,
            (a21 * a32 - a22 * a31) / det, (a12 * a31 - a11 * a32) / det, (a11 * a22 - a12 * a21) / det
        );
    }


    [[nodiscard]] constexpr T determinantSarrus() const {
        return a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32
             - a13 * a22 * a31 - a11 * a23 * a32 - a12 * a21 * a33;
    }

    // Méthode pour la transposition de la matrice
    [[nodiscard]] constexpr Mat3x3 transpose() const noexcept {
        return Mat3x3(a11, a21, a31,
                      a12, a22, a32,
                      a13, a23, a33);
    }

    // Multiplication par un vecteur 3D
    [[nodiscard]] constexpr Vec3<T> operator*(const Vec3<T>& vec) const {
        return Vec3<T>(
            a11 * vec.x + a12 * vec.y + a13 * vec.z,
            a21 * vec.x + a22 * vec.y + a23 * vec.z,
            a31 * vec.x + a32 * vec.y + a33 * vec.z
        );
    }

};

#endif //MATRICE3X3_H

/* add
 * soustraction
 * mult scalaire et inversement
 * mult par vec similaire
 * determinat methode de sarus
 * transposition
 * inversse
 * rotation??
*/