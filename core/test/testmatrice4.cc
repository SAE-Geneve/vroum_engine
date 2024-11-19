// #include <gtest/gtest.h>
// #include "Matrice4.h"
//
// // Test de l'initialisation de la matrice identité
// TEST(Mat4x4Test, IdentityMatrix) {
//     Mat4x4<float> identity = Mat4x4<float>::Identity();
//
//     EXPECT_FLOAT_EQ(identity.Val[0][0], 1);
//     EXPECT_FLOAT_EQ(identity.Val[1][1], 1);
//     EXPECT_FLOAT_EQ(identity.Val[2][2], 1);
//     EXPECT_FLOAT_EQ(identity.Val[3][3], 1);
// }
//
// // Test de l'addition de matrices
// TEST(Mat4x4Test, MatrixAddition) {
//     Mat4x4<float> matA;
//     Mat4x4<float> matB;
//
//     matB = Mat4x4<float>(Vec4<float>(1, 2, 3, 4),
//                          Vec4<float>(5, 6, 7, 8),
//                          Vec4<float>(9, 10, 11, 12),
//                          Vec4<float>(13, 14, 15, 16));
//
//     Mat4x4<float> result = matA + matB;
//
//     EXPECT_FLOAT_EQ(result.Val[0][0], 1);
//     EXPECT_FLOAT_EQ(result.Val[1][1], 6);
//     EXPECT_FLOAT_EQ(result.Val[2][2], 11);
//     EXPECT_FLOAT_EQ(result.Val[3][3], 17);
// }
//
// // Test de la soustraction de matrices
// TEST(Mat4x4Test, MatrixSubtraction) {
//     Mat4x4<float> matA = Mat4x4<float>(Vec4<float>(1, 2, 3, 4),
//                                         Vec4<float>(5, 6, 7, 8),
//                                         Vec4<float>(9, 10, 11, 12),
//                                         Vec4<float>(13, 14, 15, 16));
//
//     Mat4x4<float> matB = Mat4x4<float>::Identity();
//
//     Mat4x4<float> result = matA - matB;
//
//     EXPECT_FLOAT_EQ(result.Val[0][0], 0);
//     EXPECT_FLOAT_EQ(result.Val[1][1], 5);
//     EXPECT_FLOAT_EQ(result.Val[2][2], 10);
//     EXPECT_FLOAT_EQ(result.Val[3][3], 15);
// }
//
// // Test de la multiplication par un scalaire
// TEST(Mat4x4Test, ScalarMultiplication) {
//     Mat4x4<float> matA = Mat4x4<float>::Identity();
//     float scalar = 2.0f;
//
//     Mat4x4<float> result = matA * scalar;
//
//     EXPECT_FLOAT_EQ(result.Val[0][0], 2);
//     EXPECT_FLOAT_EQ(result.Val[1][1], 2);
//     EXPECT_FLOAT_EQ(result.Val[2][2], 2);
//     EXPECT_FLOAT_EQ(result.Val[3][3], 2);
// }
//
// // Test de la multiplication de matrices
// TEST(Mat4x4Test, MatrixMultiplication) {
//     Mat4x4<float> matA = Mat4x4<float>::Identity();
//     Mat4x4<float> matB = Mat4x4<float>(Vec4<float>(1, 2, 3, 4),
//                                         Vec4<float>(5, 6, 7, 8),
//                                         Vec4<float>(9, 10, 11, 12),
//                                         Vec4<float>(13, 14, 15, 16));
//
//     Mat4x4<float> result = matA * matB;
//
//     EXPECT_FLOAT_EQ(result.Val[0][0], 1);
//     EXPECT_FLOAT_EQ(result.Val[1][1], 6);
//     EXPECT_FLOAT_EQ(result.Val[2][2], 11);
//     EXPECT_FLOAT_EQ(result.Val[3][3], 16);
// }
//
// // Test du déterminant
// TEST(Mat4x4Test, Determinant) {
//     Mat4x4<float> matA = Mat4x4<float>(Vec4<float>(1, 0, 0, 0),
//                                         Vec4<float>(0, 1, 0, 0),
//                                         Vec4<float>(0, 0, 1, 0),
//                                         Vec4<float>(0, 0, 0, 1));
//
//     EXPECT_FLOAT_EQ(matA.Det(), 1);
// }
//
// // Test de l'inversion de la matrice
// TEST(Mat4x4Test, Inverse) {
//     // Matrice identité
//     Mat4x4<float> matA = Mat4x4<float>(Vec4<float>(1, 0, 0, 0),
//                                         Vec4<float>(0, 1, 0, 0),
//                                         Vec4<float>(0, 0, 1, 0),
//                                         Vec4<float>(0, 0, 0, 1));
//
//     auto result = matA.inverse<float>();
//
//     // Vérifie que le résultat existe
//     ASSERT_TRUE(result.has_value());
//
//     // Vérifie que la matrice inverse est aussi la matrice identité
//     for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 4; ++j) {
//             if (i == j) {
//                 EXPECT_FLOAT_EQ(result.value().Val[i][j], 1); // Diagonale
//             } else {
//                 EXPECT_FLOAT_EQ(result.value().Val[i][j], 0); // Hors diagonale
//             }
//         }
//     }
// }
// // Test de l'inversion d'une matrice non inversible
// TEST(Mat4x4Test, InverseNonInvertible) {
//     Mat4x4<float> matA = Mat4x4<float>(Vec4<float>(1, 2, 3, 4),
//                                         Vec4<float>(2, 4, 6, 8),
//                                         Vec4<float>(3, 6, 9, 12),
//                                         Vec4<float>(4, 8, 12, 16)); // Matrice singulière
//
//     auto result = matA.inverse<float>();
//     EXPECT_FALSE(result.has_value());
// }
//
