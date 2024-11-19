#include <gtest/gtest.h>
#include "Matrice2.h"
#include "Vec2.h"

TEST(Mat2x2Test, Constructor) {
    Vec2<int> a = {1, 2};
    Vec2<int> b = {3, 4};
    Mat2x2<int> mat(a, b);

    EXPECT_EQ(mat(0, 0), 1);
    EXPECT_EQ(mat(1, 0), 2);
    EXPECT_EQ(mat(0, 1), 3);
    EXPECT_EQ(mat(1, 1), 4);
}

// Test du calcul du dÃ©terminant
TEST(Mat2x2Test, Determinant) {
    Mat2x2<double> mat({1.0, 2.0}, {3.0, 4.0});
    EXPECT_DOUBLE_EQ(mat.Det(), -2.0);
}

// Test de l'addition de matrices
TEST(Mat2x2Test, Addition) {
    Mat2x2<double> mat1({1.0, 3.0}, {2.0, 4.0});
    Mat2x2<double> mat2({5.0, 7.0}, {6.0, 8.0});
    Mat2x2<double> result = mat1 + mat2;
    EXPECT_DOUBLE_EQ(result(0, 0), 6.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 8.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 12.0);
}

// Test de la soustraction de matrices
TEST(Mat2x2Test, Subtraction) {
    Mat2x2<double> mat1({5.0, 7.0}, {6.0, 8.0});
    Mat2x2<double> mat2({1.0, 3.0}, {2.0, 4.0});
    Mat2x2<double> result = mat1 - mat2;
    EXPECT_DOUBLE_EQ(result(0, 0), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 4.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

// Test de la multiplication de matrices
TEST(Mat2x2Test, Multiplication) {
    Mat2x2<double> mat1({1.0, 3.0}, {2.0, 4.0});
    Mat2x2<double> mat2({2.0, 1.0}, {0.0, 2.0});
    Mat2x2<double> result = mat1 * mat2;
    EXPECT_DOUBLE_EQ(result(0, 0), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}

// Test de la multiplication par un scalaire
TEST(Mat2x2Test, ScalarMultiplication) {
    Mat2x2<double> mat({1.0, 3.0}, {2.0, 4.0});
    double scalar = 2.0;
    Mat2x2<double> result = mat * scalar;
    EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}
/*
// Test de la transposition de la matrice
TEST(Mat2x2Test, Transpose) {
    Mat2x2<double> mat({1.0, 3.0}, {2.0, 4.0});
    Mat2x2<double> result = mat.transpose();
    EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
    EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
    EXPECT_DOUBLE_EQ(result(0, 1), 3.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}*/

// Test de la multiplication par un vecteur
TEST(Mat2x2Test, VectorMultiplication) {
    Mat2x2<double> mat({1.0, 3.0}, {2.0, 4.0});
    Vec2<double> vec(1.0, 1.0);
    Vec2<double> result = mat * vec;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
}

// Test de l'inverse de la matrice
TEST(Mat2x2Test, Inverse) {
    Mat2x2<double> mat({4.0, 2.0}, {7.0, 6.0});
    auto result = mat.inverse();
    ASSERT_TRUE(result.has_value());
    Mat2x2<double> inv = result.value();
    EXPECT_DOUBLE_EQ(inv(0, 0), 0.6);
    EXPECT_DOUBLE_EQ(inv(1, 0), -0.2);
    EXPECT_DOUBLE_EQ(inv(0, 1), -0.7);
    EXPECT_DOUBLE_EQ(inv(1, 1), 0.4);
}