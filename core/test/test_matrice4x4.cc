


#include <gtest/gtest.h>
#include "Matrice4x4.h"


TEST(Mat4x4Test, SolveSystem) {
    Mat4x4 mat(1.0, 2.0, 3.0, 4.0,
               5.0, 6.0, 7.0, 8.0,
               9.0, 10.0, 11.0, 12.0,
               13.0, 14.0, 15.0, 16.0);

    auto solution = mat.resoudreSysteme(1.0, 2.0, 3.0, 4.0);

    EXPECT_FALSE(solution.has_value()); // Il ne devrait pas y avoir de solution unique
}

// Test d'une matrice 4x4 avec une solution unique
TEST(Mat4x4Test, UniqueSolution) {
    Mat4x4 mat(1.0, 2.0, 3.0, 4.0,
               0.0, 1.0, 2.0, 3.0,
               0.0, 0.0, 1.0, 2.0,
               0.0, 0.0, 0.0, 1.0);

    auto solution = mat.resoudreSysteme(10.0, 9.0, 6.0, 2.0);

    ASSERT_TRUE(solution.has_value()); // Vérifiez qu'une solution existe

    auto [x, y, z, w] = solution.value();
    EXPECT_NEAR(x, 2/7, 1e-9);
    EXPECT_NEAR(y, -(15/7), 1e-9);
    EXPECT_NEAR(z, 2.0, 1e-9);
    EXPECT_NEAR(w, 2.0, 1e-9);
}