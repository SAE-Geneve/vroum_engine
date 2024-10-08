#ifndef MATRICE4X4_H
#define MATRICE4X4_H
#include <array>
#include <Matrice3x3.h>

struct Mat4x4 {
    // Membres de la matrice 4x4
    double m00, m01, m02, m03;
    double m10, m11, m12, m13;
    double m20, m21, m22, m23;
    double m30, m31, m32, m33;

    // Constructeur pour initialiser la matrice
    Mat4x4(double m00, double m01, double m02, double m03,
           double m10, double m11, double m12, double m13,
           double m20, double m21, double m22, double m23,
           double m30, double m31, double m32, double m33)
        : m00(m00), m01(m01), m02(m02), m03(m03),
          m10(m10), m11(m11), m12(m12), m13(m13),
          m20(m20), m21(m21), m22(m22), m23(m23),
          m30(m30), m31(m31), m32(m32), m33(m33) {}

    // Méthode pour calculer le déterminant de la matrice 4x4
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

        return m00 * mat.determinant() - m11 * mat2.determinant() + m12 * mat3.determinant() - m13 * mat4.determinant();
    }


    // Méthode pour résoudre le système d'équations linéaires Ax = b
    std::optional<std::tuple<double, double, double, double>> resoudreSysteme(double w,double x,double y,double z) const {
        double det = determinant();
        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

//complete

        return std::make_tuple(w, x, y, z);
    }

};

#endif //MATRICE4X4_H
