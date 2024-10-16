
#include "Matrice4x4.h" // Assurez-vous que ce fichier existe et contient votre définition de Mat4x4
#include <gtest/gtest.h>
/*
TEST(Mat4x4Test, Determinant) {
    Mat4x4<double> mat(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
    EXPECT_DOUBLE_EQ(mat.determinant(), 0);
}

TEST(Mat4x4Test, SolveSystem) {
    Mat4x4 mat(1.0, 2.0, 3.0, 4.0,
               5.0, 6.0, 7.0, 8.0,
               9.0, 10.0, 11.0, 12.0,
               13.0, 14.0, 15.0, 16.0);

    auto solution = mat.SolveSysteme(1.0, 2.0, 3.0, 4.0);

    EXPECT_FALSE(solution.has_value()); // Il ne devrait pas y avoir de solution unique
}

TEST(Mat4x4Test, Addition) {
    Mat4x4<double> mat1(1, 2, 3, 4,
                        5, 6, 7, 8,
                        9, 10, 11, 12,
                        13, 14, 15, 16);
    Mat4x4<double> mat2(16, 15, 14, 13,
                        12, 11, 10, 9,
                        8, 7, 6, 5,
                        4, 3, 2, 1);
    Mat4x4<double> result = mat1 + mat2;
    EXPECT_DOUBLE_EQ(result.m00, 17);
    EXPECT_DOUBLE_EQ(result.m01, 17);
    EXPECT_DOUBLE_EQ(result.m02, 17);
    EXPECT_DOUBLE_EQ(result.m03, 17);
    EXPECT_DOUBLE_EQ(result.m10, 17);
    EXPECT_DOUBLE_EQ(result.m11, 17);
    EXPECT_DOUBLE_EQ(result.m12, 17);
    EXPECT_DOUBLE_EQ(result.m13, 17);
    EXPECT_DOUBLE_EQ(result.m20, 17);
    EXPECT_DOUBLE_EQ(result.m21, 17);
    EXPECT_DOUBLE_EQ(result.m22, 17);
    EXPECT_DOUBLE_EQ(result.m23, 17);
    EXPECT_DOUBLE_EQ(result.m30, 17);
    EXPECT_DOUBLE_EQ(result.m31, 17);
    EXPECT_DOUBLE_EQ(result.m32, 17);
    EXPECT_DOUBLE_EQ(result.m33, 17);
}

TEST(Mat4x4Test, Subtraction) {
    Mat4x4<double> mat1(16, 15, 14, 13,
                        12, 11, 10, 9,
                        8, 7, 6, 5,
                        4, 3, 2, 1);
    Mat4x4<double> mat2(1, 2, 3, 4,
                        5, 6, 7, 8,
                        9, 10, 11, 12,
                        13, 14, 15, 16);
    Mat4x4<double> result = mat1 - mat2;
    EXPECT_DOUBLE_EQ(result.m00, 15);
    EXPECT_DOUBLE_EQ(result.m01, 13);
    EXPECT_DOUBLE_EQ(result.m02, 11);
    EXPECT_DOUBLE_EQ(result.m03, 9);
    EXPECT_DOUBLE_EQ(result.m10, 7);
    EXPECT_DOUBLE_EQ(result.m11, 5);
    EXPECT_DOUBLE_EQ(result.m12, 3);
    EXPECT_DOUBLE_EQ(result.m13, 1);
    EXPECT_DOUBLE_EQ(result.m20, -1);
    EXPECT_DOUBLE_EQ(result.m21, -3);
    EXPECT_DOUBLE_EQ(result.m22, -5);
    EXPECT_DOUBLE_EQ(result.m23, -7);
    EXPECT_DOUBLE_EQ(result.m30, -9);
    EXPECT_DOUBLE_EQ(result.m31, -11);
    EXPECT_DOUBLE_EQ(result.m32, -13);
    EXPECT_DOUBLE_EQ(result.m33, -15);
}

TEST(Mat4x4Test, Multiplication) {
    Mat4x4<double> mat1(1, 2, 3, 4,
                        5, 6, 7, 8,
                        9, 10, 11, 12,
                        13, 14, 15, 16);
    Mat4x4<double> mat2(16, 15, 14, 13,
                        12, 11, 10, 9,
                        8, 7, 6, 5,
                        4, 3, 2, 1);
    Mat4x4<double> result = mat1 * mat2;
    EXPECT_DOUBLE_EQ(result.m00, 80);
    EXPECT_DOUBLE_EQ(result.m01, 70);
    EXPECT_DOUBLE_EQ(result.m02, 60);
    EXPECT_DOUBLE_EQ(result.m03, 50);
    EXPECT_DOUBLE_EQ(result.m10, 240);
    EXPECT_DOUBLE_EQ(result.m11, 214);
    EXPECT_DOUBLE_EQ(result.m12, 188);
    EXPECT_DOUBLE_EQ(result.m13, 162);
    EXPECT_DOUBLE_EQ(result.m20, 400);
    EXPECT_DOUBLE_EQ(result.m21, 358);
    EXPECT_DOUBLE_EQ(result.m22, 316);
    EXPECT_DOUBLE_EQ(result.m23, 274);
    EXPECT_DOUBLE_EQ(result.m30, 560);
    EXPECT_DOUBLE_EQ(result.m31, 502);
    EXPECT_DOUBLE_EQ(result.m32, 444);
    EXPECT_DOUBLE_EQ(result.m33, 386);
}

TEST(Mat4x4Test, Inverse) {
    Mat4x4<double> mat(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
    auto result = mat.inverse();
    ASSERT_TRUE(result.has_value());
    Mat4x4<double> inv = result.value();
    EXPECT_NEAR(inv.m00, 1, 1e-9);
    EXPECT_NEAR(inv.m01, 0, 1e-9);
    EXPECT_NEAR(inv.m02, 0, 1e-9);
    EXPECT_NEAR(inv.m03, 0, 1e-9);
    EXPECT_NEAR(inv.m10, 0, 1e-9);
    EXPECT_NEAR(inv.m11, 1, 1e-9);
    EXPECT_NEAR(inv.m12, 0, 1e-9);
    EXPECT_NEAR(inv.m13, 0, 1e-9);
    EXPECT_NEAR(inv.m20, 0, 1e-9);
    EXPECT_NEAR(inv.m21, 0, 1e-9);
    EXPECT_NEAR(inv.m22, 1, 1e-9);
    EXPECT_NEAR(inv.m23, 0, 1e-9);
    EXPECT_NEAR(inv.m30, 0, 1e-9);
    EXPECT_NEAR(inv.m31, 0, 1e-9);
    EXPECT_NEAR(inv.m32, 0, 1e-9);
    EXPECT_NEAR(inv.m33, 1, 1e-9);
}

TEST(Mat4x4Test, Transpose) {
    Mat4x4<double> mat(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
    Mat4x4<double> transposed = mat.transpose();
    EXPECT_DOUBLE_EQ(transposed.m00, 1);
    EXPECT_DOUBLE_EQ(transposed.m01, 5);
    EXPECT_DOUBLE_EQ(transposed.m02, 9);
    EXPECT_DOUBLE_EQ(transposed.m03, 13);
    EXPECT_DOUBLE_EQ(transposed.m10, 2);
    EXPECT_DOUBLE_EQ(transposed.m11, 6);
    EXPECT_DOUBLE_EQ(transposed.m12, 10);
    EXPECT_DOUBLE_EQ(transposed.m13, 14);
    EXPECT_DOUBLE_EQ(transposed.m20, 3);
    EXPECT_DOUBLE_EQ(transposed.m21, 7);
    EXPECT_DOUBLE_EQ(transposed.m22, 11);
    EXPECT_DOUBLE_EQ(transposed.m23, 15);
    EXPECT_DOUBLE_EQ(transposed.m30, 4);
    EXPECT_DOUBLE_EQ(transposed.m31, 8);
    EXPECT_DOUBLE_EQ(transposed.m32, 12);
    EXPECT_DOUBLE_EQ(transposed.m33, 16);
}

TEST(Mat4x4Test, MultiplicationByVector) {
    Mat4x4<double> mat(1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16);
    Vec4<double> vec(1, 2, 3, 4); // Assurez-vous que Vec4 est défini
    Vec4<double> result = mat * vec; // Vérifiez que l'opérateur * est surchargé correctement
    EXPECT_DOUBLE_EQ(result.x, 70);
    EXPECT_DOUBLE_EQ(result.y, 158);
    EXPECT_DOUBLE_EQ(result.z, 246);
    EXPECT_DOUBLE_EQ(result.w, 334);
}*/