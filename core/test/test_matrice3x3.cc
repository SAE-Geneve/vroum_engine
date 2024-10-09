#include "Matrice3x3.h"
#include <gtest/gtest.h>


TEST(Mat3x3Test, Determinant) {
    Mat3x3<double> mat(1, 2, 3, 0, 1, 4, 5, 6, 0);
    EXPECT_DOUBLE_EQ(mat.determinant(), 1);
}

TEST(Mat3x3Test, SolveSystem) {
    Mat3x3<double> mat(2, -1, 0, -1, 2, -1, 0, -1, 2);
    auto result = mat.SolveSystem(1, 0, 1);
    ASSERT_TRUE(result.has_value());
    auto [x, y, z] = result.value();
    EXPECT_DOUBLE_EQ(x, 1);
    EXPECT_DOUBLE_EQ(y, 1);
    EXPECT_DOUBLE_EQ(z, 1);
}

TEST(Mat3x3Test, Addition) {
    Mat3x3<double> mat1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat3x3<double> mat2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    Mat3x3<double> result = mat1 + mat2;
    EXPECT_DOUBLE_EQ(result.a11, 10);
    EXPECT_DOUBLE_EQ(result.a12, 10);
    EXPECT_DOUBLE_EQ(result.a13, 10);
    EXPECT_DOUBLE_EQ(result.a21, 10);
    EXPECT_DOUBLE_EQ(result.a22, 10);
    EXPECT_DOUBLE_EQ(result.a23, 10);
    EXPECT_DOUBLE_EQ(result.a31, 10);
    EXPECT_DOUBLE_EQ(result.a32, 10);
    EXPECT_DOUBLE_EQ(result.a33, 10);
}

TEST(Mat3x3Test, Subtraction) {
    Mat3x3<double> mat1(9, 8, 7, 6, 5, 4, 3, 2, 1);
    Mat3x3<double> mat2(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat3x3<double> result = mat1 - mat2;
    EXPECT_DOUBLE_EQ(result.a11, 8);
    EXPECT_DOUBLE_EQ(result.a12, 6);
    EXPECT_DOUBLE_EQ(result.a13, 4);
    EXPECT_DOUBLE_EQ(result.a21, 2);
    EXPECT_DOUBLE_EQ(result.a22, 0);
    EXPECT_DOUBLE_EQ(result.a23, -2);
    EXPECT_DOUBLE_EQ(result.a31, -4);
    EXPECT_DOUBLE_EQ(result.a32, -6);
    EXPECT_DOUBLE_EQ(result.a33, -8);
}

TEST(Mat3x3Test, Multiplication) {
    Mat3x3<double> mat1(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat3x3<double> mat2(9, 8, 7, 6, 5, 4, 3, 2, 1);
    Mat3x3<double> result = mat1 * mat2;
    EXPECT_DOUBLE_EQ(result.a11, 30);
    EXPECT_DOUBLE_EQ(result.a12, 24);
    EXPECT_DOUBLE_EQ(result.a13, 18);
    EXPECT_DOUBLE_EQ(result.a21, 84);
    EXPECT_DOUBLE_EQ(result.a22, 69);
    EXPECT_DOUBLE_EQ(result.a23, 54);
    EXPECT_DOUBLE_EQ(result.a31, 138);
    EXPECT_DOUBLE_EQ(result.a32, 114);
    EXPECT_DOUBLE_EQ(result.a33, 90);
}

TEST(Mat3x3Test, Inverse) {
    Mat3x3<double> mat(1, 2, 3, 0, 1, 4, 5, 6, 0);
    auto result = mat.inverse();
    ASSERT_TRUE(result.has_value());
    Mat3x3<double> inv = result.value();
    EXPECT_NEAR(inv.a11, -24, 1e-9);
    EXPECT_NEAR(inv.a12, 18, 1e-9);
    EXPECT_NEAR(inv.a13, 5, 1e-9);
    EXPECT_NEAR(inv.a21, 20, 1e-9);
    EXPECT_NEAR(inv.a22, -15, 1e-9);
    EXPECT_NEAR(inv.a23, -4, 1e-9);
    EXPECT_NEAR(inv.a31, -5, 1e-9);
    EXPECT_NEAR(inv.a32, 4, 1e-9);
    EXPECT_NEAR(inv.a33, 1, 1e-9);
}

TEST(Mat3x3Test, Transpose) {
    Mat3x3<double> mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Mat3x3<double> transposed = mat.transpose();
    EXPECT_DOUBLE_EQ(transposed.a11, 1);
    EXPECT_DOUBLE_EQ(transposed.a12, 4);
    EXPECT_DOUBLE_EQ(transposed.a13, 7);
    EXPECT_DOUBLE_EQ(transposed.a21, 2);
    EXPECT_DOUBLE_EQ(transposed.a22, 5);
    EXPECT_DOUBLE_EQ(transposed.a23, 8);
    EXPECT_DOUBLE_EQ(transposed.a31, 3);
    EXPECT_DOUBLE_EQ(transposed.a32, 6);
    EXPECT_DOUBLE_EQ(transposed.a33, 9);
}

TEST(Mat3x3Test, MultiplicationByVector) {
    Mat3x3<double> mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Vec3<double> vec(1, 2, 3);
    Vec3<double> result = mat * vec;
    EXPECT_DOUBLE_EQ(result.x, 14);
    EXPECT_DOUBLE_EQ(result.y, 32);
    EXPECT_DOUBLE_EQ(result.z, 50);
}

TEST(Mat3x3Test, ScalarMultiplication) {

    Mat3x3<double> mat(1.0, 2.0, 3.0,
                       4.0, 5.0, 6.0,
                       7.0, 8.0, 9.0);


    double scalar = 2.0;


    Mat3x3<double> result = mat * scalar;


    EXPECT_DOUBLE_EQ(result.a11, 1.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a12, 2.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a13, 3.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a21, 4.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a22, 5.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a23, 6.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a31, 7.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a32, 8.0 * scalar);
    EXPECT_DOUBLE_EQ(result.a33, 9.0 * scalar);
}