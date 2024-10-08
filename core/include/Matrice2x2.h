#ifndef MATRICE2X2_H
#define MATRICE2X2_H

struct Mat2x2
{

    double a11, a12; // First line
    double a21, a22; // Second line

    Mat2x2(double a11, double a12, double a21, double a22)
           : a11(a11), a12(a12), a21(a21), a22(a22) {}

    double determinant() const {
        return a11 * a22 - a12 * a21;
    }


    std::optional<std::tuple<double, double>> solveSystem(double b1, double b2) const {
        double det = determinant();

        if (det == 0.0) {
            return std::nullopt; // Pas de solution unique
        }

        double x = (b1 * a22 - b2 * a12) / det;
        double y = (a11 * b2 - a21 * b1) / det;

        return std::make_tuple(x, y);
    }

};


#endif //MATRICE2X2_H
