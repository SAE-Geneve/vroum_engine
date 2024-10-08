#ifndef MATRICE3X3_H
#define MATRICE3X3_H

struct Mat3x3
{
    // Membres de la matrice 3x3
    double a11, a12, a13; // Première ligne
    double a21, a22, a23; // Deuxième ligne
    double a31, a32, a33; // Troisième ligne

    // Constructeur pour initialiser la matrice
    Mat3x3(double a11, double a12, double a13,
            double a21, double a22, double a23,
            double a31, double a32, double a33)
        : a11(a11), a12(a12), a13(a13),
          a21(a21), a22(a22), a23(a23),
          a31(a31), a32(a32), a33(a33) {}

    // Méthode pour calculer le déterminant de la matrice 3x3
    double determinant() const {
        return a11 * (a22 * a33 - a23 * a32) -
               a12 * (a21 * a33 - a23 * a31) +
               a13 * (a21 * a32 - a22 * a31);
    }

    // Méthode pour résoudre le système d'équations linéaires Ax = b
    std::optional<std::tuple<double, double, double>> SolveSystem(double b1, double b2, double b3) const {
        double det = determinant();

        // Vérifier si le déterminant est nul (système indéterminé ou impossible)
        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        // Calcul des valeurs de x, y et z en utilisant la méthode de Cramer

        double x = (b1 * (a22 * a33 - a32 * a23) - a12 * (b2 * a33 - a23 * b3) + a13 * (b2 * a32 - a22 * b3))  / det;
        double y = (a11 * (b2 * a33 - b3 * a23) - b1 * (a21 * a33 - a23 * a31) + a13 * (a21 * b3 - b2 * a31)) / det;
        double z = (a11 * (a22 * b3 - a32 * b2) - a12 * (a21 * b3 - b2 * a31) + b1 * (a21 * a32 - a22 * a31)) / det;


        return std::make_tuple(x, y, z);
    }
};

#endif //MATRICE3X3_H
