#include "Matrice3x3.h"
#include <gtest/gtest.h>

// Test pour le déterminant
TEST(Mat3x3Test, Determinant) {
    Mat3x3<double> mat(Vec3<double>(1, 2, 3), Vec3<double>(0, 1, 4), Vec3<double>(5, 6, 0));
    EXPECT_DOUBLE_EQ(mat.Det(), 1);
}

TEST(Mat3x3Test, SolveSystem) {
    Mat3x3<double> mat(Vec3<double>(2, -1, 0), Vec3<double>(-1, 2, -1), Vec3<double>(0, -1, 2));
    auto result = mat.Inverted();
    ASSERT_TRUE(result.has_value());
    auto invMat = result.value();
    EXPECT_DOUBLE_EQ(invMat(0, 0), 0.75);
    EXPECT_DOUBLE_EQ(invMat(1, 1), 1);  // Garde la valeur correcte
    EXPECT_DOUBLE_EQ(invMat(2, 2), 0.75);
}

// Test pour l'addition de matrices
TEST(Mat3x3Test, Addition) {
    Mat3x3<double> mat1(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    Mat3x3<double> mat2(Vec3<double>(9, 8, 7), Vec3<double>(6, 5, 4), Vec3<double>(3, 2, 1));
    Mat3x3<double> result = mat1 + mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 10);
    EXPECT_DOUBLE_EQ(result(0, 1), 10);
    EXPECT_DOUBLE_EQ(result(0, 2), 10);
    EXPECT_DOUBLE_EQ(result(1, 0), 10);
    EXPECT_DOUBLE_EQ(result(1, 1), 10);
    EXPECT_DOUBLE_EQ(result(1, 2), 10);
    EXPECT_DOUBLE_EQ(result(2, 0), 10);
    EXPECT_DOUBLE_EQ(result(2, 1), 10);
    EXPECT_DOUBLE_EQ(result(2, 2), 10);
}

// Test pour la soustraction de matrices
TEST(Mat3x3Test, Subtraction) {
    Mat3x3<double> mat1(Vec3<double>(9, 8, 7), Vec3<double>(6, 5, 4), Vec3<double>(3, 2, 1));
    Mat3x3<double> mat2(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    Mat3x3<double> result = mat1 - mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 8);
    EXPECT_DOUBLE_EQ(result(0, 1), 2);
    EXPECT_DOUBLE_EQ(result(0, 2), -4);
    EXPECT_DOUBLE_EQ(result(1, 0), 6);
    EXPECT_DOUBLE_EQ(result(1, 1), 0);
    EXPECT_DOUBLE_EQ(result(1, 2), -6);
    EXPECT_DOUBLE_EQ(result(2, 0), 4);
    EXPECT_DOUBLE_EQ(result(2, 1), -2);
    EXPECT_DOUBLE_EQ(result(2, 2), -8);
}

TEST(Mat3x3Test, Multiplication) {
    Mat3x3<double> mat1(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    Mat3x3<double> mat2(Vec3<double>(9, 8, 7), Vec3<double>(6, 5, 4), Vec3<double>(3, 2, 1));
    Mat3x3<double> result = mat1 * mat2;

    EXPECT_DOUBLE_EQ(result(0, 0), 90);
    EXPECT_DOUBLE_EQ(result(0, 1), 54);
    EXPECT_DOUBLE_EQ(result(0, 2), 18);
    EXPECT_DOUBLE_EQ(result(1, 0), 114);
    EXPECT_DOUBLE_EQ(result(1, 1), 69);
    EXPECT_DOUBLE_EQ(result(1, 2), 24);
    EXPECT_DOUBLE_EQ(result(2, 0), 138);
    EXPECT_DOUBLE_EQ(result(2, 1), 84);
    EXPECT_DOUBLE_EQ(result(2, 2), 30);
}

TEST(Mat3x3Test, Transpose) {
    Mat3x3<double> mat(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    Mat3x3<double> transposed = mat.Transposed();

    EXPECT_DOUBLE_EQ(transposed(0, 0), 1);
    EXPECT_DOUBLE_EQ(transposed(0, 1), 2);
    EXPECT_DOUBLE_EQ(transposed(0, 2), 3);
    EXPECT_DOUBLE_EQ(transposed(1, 0), 4);
    EXPECT_DOUBLE_EQ(transposed(1, 1), 5);
    EXPECT_DOUBLE_EQ(transposed(1, 2), 6);
    EXPECT_DOUBLE_EQ(transposed(2, 0), 7);
    EXPECT_DOUBLE_EQ(transposed(2, 1), 8);
    EXPECT_DOUBLE_EQ(transposed(2, 2), 9);
}

TEST(Mat3x3Test, MultiplicationByVector) {
    Mat3x3<double> mat(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    Vec3<double> vec(1, 2, 3);
    Vec3<double> result = mat * vec;

    EXPECT_DOUBLE_EQ(result[0], 30);
    EXPECT_DOUBLE_EQ(result[1], 36);
    EXPECT_DOUBLE_EQ(result[2], 42);
}

TEST(Mat3x3Test, ScalarMultiplication) {
    Mat3x3<double> mat(Vec3<double>(1, 2, 3), Vec3<double>(4, 5, 6), Vec3<double>(7, 8, 9));
    double scalar = 2.0;
    Mat3x3<double> result = mat * scalar;

    EXPECT_DOUBLE_EQ(result(0, 0), 2);
    EXPECT_DOUBLE_EQ(result(0, 1), 8);
    EXPECT_DOUBLE_EQ(result(0, 2), 14);
    EXPECT_DOUBLE_EQ(result(1, 0), 4);
    EXPECT_DOUBLE_EQ(result(1, 1), 10);
    EXPECT_DOUBLE_EQ(result(1, 2), 16);
    EXPECT_DOUBLE_EQ(result(2, 0), 6);
    EXPECT_DOUBLE_EQ(result(2, 1), 12);
    EXPECT_DOUBLE_EQ(result(2, 2), 18);
}


// Test pour l'inverse d'une matrice
TEST(Mat3x3Test, Inverse) {
    Mat3x3<double> mat(Vec3<double>(1, 2, 3), Vec3<double>(0, 1, 4), Vec3<double>(5, 6, 0));
    auto result = mat.Inverted();
    ASSERT_TRUE(result.has_value());
    Mat3x3<double> inv = result.value();

    EXPECT_NEAR(inv(0, 0), -24, 1e-9);
    EXPECT_NEAR(inv(0, 1), 20, 1e-9);
    EXPECT_NEAR(inv(0, 2), -5, 1e-9);
    EXPECT_NEAR(inv(1, 0), 18, 1e-9);
    EXPECT_NEAR(inv(1, 1), -15, 1e-9);
    EXPECT_NEAR(inv(1, 2), 4, 1e-9);
    EXPECT_NEAR(inv(2, 0), 5, 1e-9);
    EXPECT_NEAR(inv(2, 1), -4, 1e-9);
    EXPECT_NEAR(inv(2, 2), 1, 1e-9);
}