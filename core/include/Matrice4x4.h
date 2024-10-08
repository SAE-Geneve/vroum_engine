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
        return m00 * determinant3x3(m10, m11, m12, m13,
                                      m20, m21, m22, m23,
                                      m30, m31, m32, m33) -
               m01 * determinant3x3(m10, m11, m12, m13,
                                    m20, m21, m22, m23,
                                    m30, m31, m32, m33) +
               m02 * determinant3x3(m10, m11, m12, m13,
                                    m20, m21, m22, m23,
                                    m30, m31, m32, m33) -
               m03 * determinant3x3(m10, m11, m12, m13,
                                    m20, m21, m22, m23,
                                    m30, m31, m32, m33);
    }

    // Méthode pour calculer le déterminant d'une matrice 3x3
    double determinant3x3(double a00, double a01, double a02, double a03,
                           double a10, double a11, double a12, double a13,
                           double a20, double a21, double a22, double a23) const {
        return a00 * (a11 * a22 - a12 * a21) -
               a01 * (a10 * a22 - a12 * a20) +
               a02 * (a10 * a21 - a11 * a20);
    }

    // Méthode pour résoudre le système d'équations linéaires Ax = b
    std::optional<std::tuple<double, double, double, double>> resoudreSysteme(const std::array<double, 4>& b) const {
        double det = determinant();
        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        // Calcul des solutions
        double x = (b[0] * determinant3x3(m10, m11, m12, m13,
                                           m20, m21, m22, m23,
                                           m30, m31, m32, m33)) / det;

        double y = (b[1] * determinant3x3(m00, m01, m02, m03,
                                           m20, m21, m22, m23,
                                           m30, m31, m32, m33)) / det;

        double z = (b[2] * determinant3x3(m00, m01, m02, m03,
                                           m10, m11, m12, m13,
                                           m30, m31, m32, m33)) / det;

        double w = (b[3] * determinant3x3(m00, m01, m02, m03,
                                           m10, m11, m12, m13,
                                           m20, m21, m22, m23)) / det;

        return std::make_tuple(x, y, z, w);
    }

    // Méthode pour afficher la matrice
    void afficher() const {
        std::cout << "[[" << m00 << ", " << m01 << ", " << m02 << ", " << m03 << "],\n"
                  << " [" << m10 << ", " << m11 << ", " << m12 << ", " << m13 << "],\n"
                  << " [" << m20 << ", " << m21 << ", " << m22 << ", " << m23 << "],\n"
                  << " [" << m30 << ", " << m31 << ", " << m32 << ", " << m33 << "]]" << std::endl;
    }
};

#endif //MATRICE4X4_H
