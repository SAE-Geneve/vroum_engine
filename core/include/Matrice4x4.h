#ifndef MATRICE4X4_H
#define MATRICE4X4_H
#include <array>
#include <Matrice3x3.h>

struct Mat4x4 {

    double m00, m01, m02, m03;
    double m10, m11, m12, m13;
    double m20, m21, m22, m23;
    double m30, m31, m32, m33;


    Mat4x4(double m00, double m01, double m02, double m03,
           double m10, double m11, double m12, double m13,
           double m20, double m21, double m22, double m23,
           double m30, double m31, double m32, double m33)
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

        return m00 * mat.determinant() - m01 * mat2.determinant() + m02 * mat3.determinant() - m03 * mat4.determinant();
    }


    std::optional<std::tuple<double, double, double, double>> resoudreSysteme(double w,double x,double y,double z) const {
        double det = determinant();
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

        double result_w = mat1.determinant()/det;
        double result_x = mat2.determinant()/det;
        double result_y = mat3.determinant()/det;
        double result_z = mat4.determinant()/det;

        return std::make_tuple(result_w, result_x, result_y, result_z);
    }

};

#endif //MATRICE4X4_H
