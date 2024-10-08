#include <gtest/gtest.h>
#include "Matrice2x2.h"

// Test pour une solution unique avec un déterminant non nul
TEST(Mat2x2Test, SolutionUnique) {
    Mat2x2 mat(2.0, 3.0, 4.0, 5.0);
    auto solution = mat.solveSystem(5.0, 1.0);

    ASSERT_TRUE(solution.has_value()) << "Le système devrait avoir une solution unique.";
    auto [x, y] = solution.value();
    EXPECT_NEAR(x, -11, 1e-9) << "La valeur de x est incorrecte.";
    EXPECT_NEAR(y, 9, 1e-9) << "La valeur de y est incorrecte.";
}

// Test pour une matrice avec un déterminant nul (pas de solution unique)
TEST(Mat2x2Test, DeterminantNul) {
    Mat2x2 mat(1.0, 2.0, 2.0, 4.0);
    auto solution = mat.solveSystem(3.0, 6.0);

    ASSERT_FALSE(solution.has_value()) << "Le système ne devrait pas avoir de solution unique (déterminant nul).";
}

// Test pour une solution unique avec une matrice identité
TEST(Mat2x2Test, MatriceIdentite) {
    Mat2x2 mat(1.0, 0.0, 0.0, 1.0);
    auto solution = mat.solveSystem(3.0, 4.0);

    ASSERT_TRUE(solution.has_value()) << "Le système devrait avoir une solution unique.";
    auto [x, y] = solution.value();
    EXPECT_NEAR(x, 3.0, 1e-9) << "La valeur de x est incorrecte.";
    EXPECT_NEAR(y, 4.0, 1e-9) << "La valeur de y est incorrecte.";
}
