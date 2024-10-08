#include <gtest/gtest.h>
#include "Matrice3x3.h" // Assurez-vous que le chemin vers votre fichier Mat3x3 est correct

// Test pour une solution unique avec un déterminant non nul
TEST(Mat3x3Test, SolutionUnique) {
    Mat3x3 mat(2.0, 3.0, 1.0,
               4.0, 5.0, 2.0,
               1.0, 1.0, 1.0);
    auto solution = mat.SolveSystem(1.0, 2.0, 3.0);

    ASSERT_TRUE(solution.has_value()) << "Le système devrait avoir une solution unique.";
    auto [x, y, z] = solution.value();
    EXPECT_NEAR(x, -2.0, 1e-5) << "La valeur de x est incorrecte.";
    EXPECT_NEAR(y, 0.0, 1e-5) << "La valeur de y est incorrecte.";
    EXPECT_NEAR(z, 5.0, 1e-5) << "La valeur de z est incorrecte.";
}

// Test pour une matrice avec un déterminant nul (pas de solution unique)
TEST(Mat3x3Test, DeterminantNul) {
    Mat3x3 mat(1.0, 2.0, 3.0,
               4.0, 5.0, 6.0,
               7.0, 8.0, 9.0);
    auto solution = mat.SolveSystem(1.0, 2.0, 3.0);

    ASSERT_FALSE(solution.has_value()) << "Le système ne devrait pas avoir de solution unique (déterminant nul).";
}

// Test pour une matrice identité
TEST(Mat3x3Test, MatriceIdentite) {
    Mat3x3 mat(1.0, 0.0, 0.0,
               0.0, 1.0, 0.0,
               0.0, 0.0, 1.0);
    auto solution = mat.SolveSystem(3.0, 4.0, 5.0);

    ASSERT_TRUE(solution.has_value()) << "Le système devrait avoir une solution unique.";
    auto [x, y, z] = solution.value();
    EXPECT_NEAR(x, 3.0, 1e-5) << "La valeur de x est incorrecte.";
    EXPECT_NEAR(y, 4.0, 1e-5) << "La valeur de y est incorrecte.";
    EXPECT_NEAR(z, 5.0, 1e-5) << "La valeur de z est incorrecte.";
}

// Test pour un système indéterminé
TEST(Mat3x3Test, SystemeIndetermine) {
    Mat3x3 mat(1.0, 2.0, 3.0,
               2.0, 4.0, 6.0,
               3.0, 6.0, 9.0);
    auto solution = mat.SolveSystem(3.0, 6.0, 9.0);

    ASSERT_FALSE(solution.has_value()) << "Le système devrait être indéterminé (pas de solution unique).";
}
