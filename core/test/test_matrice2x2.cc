#include <gtest/gtest.h>
#include "Matrice2x2.h"

// Test du constructeur et des valeurs initiales
TEST(Mat2x2Test, Constructor) {
    Mat2x2<double> mat(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(mat.a11, 1.0);
    EXPECT_DOUBLE_EQ(mat.a12, 2.0);
    EXPECT_DOUBLE_EQ(mat.a21, 3.0);
    EXPECT_DOUBLE_EQ(mat.a22, 4.0);
}

// Test du calcul du déterminant
TEST(Mat2x2Test, Determinant) {
    Mat2x2<double> mat(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(mat.determinant(), -2.0);
}

// Test de la résolution du système linéaire
TEST(Mat2x2Test, SolveSystem) {
    Mat2x2<double> mat(2.0, 1.0, 5.0, 3.0);
    auto result = mat.solveSystem(1.0, 4.0);
    ASSERT_TRUE(result.has_value());
    EXPECT_DOUBLE_EQ(std::get<0>(result.value()), -1.0);
    EXPECT_DOUBLE_EQ(std::get<1>(result.value()), 3.0);
}

// Test de l'addition de matrices
TEST(Mat2x2Test, Addition) {
    Mat2x2<double> mat1(1.0, 2.0, 3.0, 4.0);
    Mat2x2<double> mat2(5.0, 6.0, 7.0, 8.0);
    Mat2x2<double> result = mat1 + mat2;
    EXPECT_DOUBLE_EQ(result.a11, 6.0);
    EXPECT_DOUBLE_EQ(result.a12, 8.0);
    EXPECT_DOUBLE_EQ(result.a21, 10.0);
    EXPECT_DOUBLE_EQ(result.a22, 12.0);
}

// Test de la soustraction de matrices
TEST(Mat2x2Test, Subtraction) {
    Mat2x2<double> mat1(5.0, 6.0, 7.0, 8.0);
    Mat2x2<double> mat2(1.0, 2.0, 3.0, 4.0);
    Mat2x2<double> result = mat1 - mat2;
    EXPECT_DOUBLE_EQ(result.a11, 4.0);
    EXPECT_DOUBLE_EQ(result.a12, 4.0);
    EXPECT_DOUBLE_EQ(result.a21, 4.0);
    EXPECT_DOUBLE_EQ(result.a22, 4.0);
}

// Test de la multiplication de matrices
TEST(Mat2x2Test, Multiplication) {
    Mat2x2<double> mat1(1.0, 2.0, 3.0, 4.0);
    Mat2x2<double> mat2(2.0, 0.0, 1.0, 2.0);
    Mat2x2<double> result = mat1 * mat2;
    EXPECT_DOUBLE_EQ(result.a11, 4.0);
    EXPECT_DOUBLE_EQ(result.a12, 4.0);
    EXPECT_DOUBLE_EQ(result.a21, 10.0);
    EXPECT_DOUBLE_EQ(result.a22, 8.0);
}

// Test de la multiplication par un scalaire
TEST(Mat2x2Test, ScalarMultiplication) {
    Mat2x2<double> mat(1.0, 2.0, 3.0, 4.0);
    double scalar = 2.0;
    Mat2x2<double> result = mat * scalar;
    EXPECT_DOUBLE_EQ(result.a11, 2.0);
    EXPECT_DOUBLE_EQ(result.a12, 4.0);
    EXPECT_DOUBLE_EQ(result.a21, 6.0);
    EXPECT_DOUBLE_EQ(result.a22, 8.0);
}

// Test de la transposition de la matrice
TEST(Mat2x2Test, Transpose) {
    Mat2x2<double> mat(1.0, 2.0, 3.0, 4.0);
    Mat2x2<double> result = mat.transpose();
    EXPECT_DOUBLE_EQ(result.a11, 1.0);
    EXPECT_DOUBLE_EQ(result.a12, 3.0);
    EXPECT_DOUBLE_EQ(result.a21, 2.0);
    EXPECT_DOUBLE_EQ(result.a22, 4.0);
}

// Test de la multiplication par un vecteur
TEST(Mat2x2Test, VectorMultiplication) {
    Mat2x2<double> mat(1.0, 2.0, 3.0, 4.0);
    Vec2<double> vec(1.0, 1.0);
    Vec2<double> result = mat * vec;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
}

// Test de l'inverse de la matrice
TEST(Mat2x2Test, Inverse) {
    Mat2x2<double> mat(4.0, 7.0, 2.0, 6.0);
    auto result = mat.inverse();
    ASSERT_TRUE(result.has_value());
    Mat2x2<double> inv = result.value();
    EXPECT_DOUBLE_EQ(inv.a11, 0.6);
    EXPECT_DOUBLE_EQ(inv.a12, -0.7);
    EXPECT_DOUBLE_EQ(inv.a21, -0.2);
    EXPECT_DOUBLE_EQ(inv.a22, 0.4);
}