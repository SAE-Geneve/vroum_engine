#ifndef MATRICE4X4_H
#define MATRICE4X4_H
//#include <array>
#include <Matrice3x3.h>
#include "Vector4.h"

template<typename T>

struct Mat4x4 {

    T m00, m01, m02, m03;
    T m10, m11, m12, m13;
    T m20, m21, m22, m23;
    T m30, m31, m32, m33;


    Mat4x4(T m00, T m01, T m02, T m03,
           T m10, T m11, T m12, T m13,
           T m20, T m21, T m22, T m23,
           T m30, T m31, T m32, T m33)
        : m00(m00), m01(m01), m02(m02), m03(m03),
          m10(m10), m11(m11), m12(m12), m13(m13),
          m20(m20), m21(m21), m22(m22), m23(m23),
          m30(m30), m31(m31), m32(m32), m33(m33) {}


    double determinant() const {
        Mat3x3 mat(m11, m12, m13,
               m21, m22, m23,
               m31, m32, m33);
        Mat3x3 mat2(m10, m12, m13,
               m20, m22, m23,
               m30, m32, m33);
        Mat3x3 mat3(m10, m11, m13,
               m20, m21, m23,
               m30, m31, m33);
        Mat3x3 mat4(m10, m11, m12,
               m20, m21, m22,
               m30, m31, m32);

        return m00 * mat.determinant() - m01 * mat2.determinant() - m02 * mat3.determinant() - m03 * mat4.determinant();
    }


    std::optional<std::tuple<T, T, T, T>> resoudreSysteme(T w,T x,T y,T z) const {
        T det = determinant();
        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        Mat4x4 mat1(w, m01, m02, m03,
        x, m11, m12, m13,
        y, m21, m22, m23,
        z, m31, m32, m33);

        Mat4x4 mat2(m00, w, m02, m03,
        m10, x, m12, m13,
        m20, y, m22, m23,
        m30, z, m32, m33);

        Mat4x4 mat3(m00, m01, w, m03,
        m10, m11, x, m13,
        m20, m21, y, m23,
        m30, m31, z, m33);

        Mat4x4 mat4(m00, m01, m02, w,
        m10, m11, m12, x,
        m20, m21, m22, y,
        m30, m31, m32, z);

        T result_w = mat1.determinant()/det;
        T result_x = mat2.determinant()/det;
        T result_y = mat3.determinant()/det;
        T result_z = mat4.determinant()/det;

        return std::make_tuple(result_w, result_x, result_y, result_z);
    }


     Mat4x4 operator+(const Mat4x4& other) const {
        return Mat4x4(
            m00 + other.m00, m01 + other.m01, m02 + other.m02, m03 + other.m03,
            m10 + other.m10, m11 + other.m11, m12 + other.m12, m13 + other.m13,
            m20 + other.m20, m21 + other.m21, m22 + other.m22, m23 + other.m23,
            m30 + other.m30, m31 + other.m31, m32 + other.m32, m33 + other.m33
        );
    }

    Mat4x4 operator-(const Mat4x4& other) const {
        return Mat4x4(
            m00 - other.m00, m01 - other.m01, m02 - other.m02, m03 - other.m03,
            m10 - other.m10, m11 - other.m11, m12 - other.m12, m13 - other.m13,
            m20 - other.m20, m21 - other.m21, m22 - other.m22, m23 - other.m23,
            m30 - other.m30, m31 - other.m31, m32 - other.m32, m33 - other.m33
        );
    }

    Mat4x4 operator*(const Mat4x4& other) const {
        return Mat4x4(
            m00 * other.m00 + m01 * other.m10 + m02 * other.m20 + m03 * other.m30,
            m00 * other.m01 + m01 * other.m11 + m02 * other.m21 + m03 * other.m31,
            m00 * other.m02 + m01 * other.m12 + m02 * other.m22 + m03 * other.m32,
            m00 * other.m03 + m01 * other.m13 + m02 * other.m23 + m03 * other.m33,
            m10 * other.m00 + m11 * other.m10 + m12 * other.m20 + m13 * other.m30,
            m10 * other.m01 + m11 * other.m11 + m12 * other.m21 + m13 * other.m31,
            m10 * other.m02 + m11 * other.m12 + m12 * other.m22 + m13 * other.m32,
            m10 * other.m03 + m11 * other.m13 + m12 * other.m23 + m13 * other.m33,
            m20 * other.m00 + m21 * other.m10 + m22 * other.m20 + m23 * other.m30,
            m20 * other.m01 + m21 * other.m11 + m22 * other.m21 + m23 * other.m31,
            m20 * other.m02 + m21 * other.m12 + m22 * other.m22 + m23 * other.m32,
            m20 * other.m03 + m21 * other.m13 + m22 * other.m23 + m23 * other.m33,
            m30 * other.m00 + m31 * other.m10 + m32 * other.m20 + m33 * other.m30,
            m30 * other.m01 + m31 * other.m11 + m32 * other.m21 + m33 * other.m31,
            m30 * other.m02 + m31 * other.m12 + m32 * other.m22 + m33 * other.m32,
            m30 * other.m03 + m31 * other.m13 + m32 * other.m23 + m33 * other.m33
        );
    }


    Mat4x4 operator*(const T scalar) const {
        return Mat4x4(
            m00 * scalar, m01 * scalar, m02 * scalar, m03 * scalar,
            m10 * scalar, m11 * scalar, m12 * scalar, m13 * scalar,
            m20 * scalar, m21 * scalar, m22 * scalar, m23 * scalar,
            m30 * scalar, m31 * scalar, m32 * scalar, m33 * scalar
        );
    }

    constexpr Mat3x3<T>& operator*=(const T scalar) noexcept
    {
        return *this = *this * scalar;
    }

    // Transposition de la matrice
    Mat4x4 transpose() const {
        return Mat4x4(
            m00, m10, m20, m30,
            m01, m11, m21, m31,
            m02, m12, m22, m32,
            m03, m13, m23, m33
        );
    }

    // Multiplication par un vecteur 4D
    Vec4<T> operator*(const Vec4<T>& vec) const {
        return Vec4<T>(
            m00 * vec.x + m01 * vec.y + m02 * vec.z + m03 * vec.w,
            m10 * vec.x + m11 * vec.y + m12 * vec.z + m13 * vec.w,
            m20 * vec.x + m21 * vec.y + m22 * vec.z + m23 * vec.w,
            m30 * vec.x + m31 * vec.y + m32 * vec.z + m33 * vec.w
        );
    }

    std::optional<Mat4x4<T>> inverse() const {
        T det = determinant();
        if (det == 0.0) {
            return std::nullopt; // Pas d'inverse si le déterminant est zéro
        }

        // Matrice des cofacteurs
        Mat3x3<T> m00(m11, m12, m13, m21, m22, m23, m31, m32, m33);
        Mat3x3<T> m01(m10, m12, m13, m20, m22, m23, m30, m32, m33);
        Mat3x3<T> m02(m10, m11, m13, m20, m21, m23, m30, m31, m33);
        Mat3x3<T> m03(m10, m11, m12, m20, m21, m22, m30, m31, m32);

        // Calcul des cofacteurs
        T c00 = m00.determinant();
        T c01 = -m01.determinant();
        T c02 = m02.determinant();
        T c03 = -m03.determinant();

        T c10 = -Mat3x3<T>(m01).determinant();  // Autres cofacteurs...
        T c11 = Mat3x3<T>(m00).determinant();
        T c12 = -Mat3x3<T>(m02).determinant();
        T c13 = Mat3x3<T>(m03).determinant();

        T c20 = Mat3x3<T>(m02).determinant();
        T c21 = -Mat3x3<T>(m03).determinant();
        T c22 = Mat3x3<T>(m00).determinant();
        T c23 = -Mat3x3<T>(m01).determinant();

        T c30 = -Mat3x3<T>(m03).determinant();
        T c31 = Mat3x3<T>(m02).determinant();
        T c32 = -Mat3x3<T>(m01).determinant();
        T c33 = Mat3x3<T>(m00).determinant();

        // Construire la matrice des cofacteurs
        Mat4x4<T> cofactorMatrix(c00, c01, c02, c03,
                                 c10, c11, c12, c13,
                                 c20, c21, c22, c23,
                                 c30, c31, c32, c33);

        // Transposer la matrice des cofacteurs
        Mat4x4<T> adjugate = cofactorMatrix.transpose();

        // Diviser chaque élément par le déterminant
        return adjugate * (1.0 / det);
    }
};

#endif //MATRICE4X4_H
