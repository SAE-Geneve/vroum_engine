//
// Created by ROG on 15.10.2024.
//

#include <gtest/gtest.h>
#include "quatetrions.h"

// Test de la construction par défaut
TEST(QuaternionTest, DefaultConstructor) {
    Quaternion<double> q;
    EXPECT_DOUBLE_EQ(q.W, 1.0);
    EXPECT_DOUBLE_EQ(q.X, 0.0);
    EXPECT_DOUBLE_EQ(q.Y, 0.0);
    EXPECT_DOUBLE_EQ(q.Z, 0.0);
}

// Test de la construction avec des composants
TEST(QuaternionTest, ConstructorWithComponents) {
    Quaternion<double> q(1.0, 0.5, 0.5, 0.5);
    EXPECT_DOUBLE_EQ(q.W, 1.0);
    EXPECT_DOUBLE_EQ(q.X, 0.5);
    EXPECT_DOUBLE_EQ(q.Y, 0.5);
    EXPECT_DOUBLE_EQ(q.Z, 0.5);
}

// Test de la construction à partir d'un angle et d'un axe
TEST(QuaternionTest, ConstructorFromAngle) {
    Quaternion<double> q(PI / 2, 0, 1, 0);  // Rotation de 90 degrés autour de l'axe Y
    EXPECT_NEAR(q.W, std::cos(PI / 4), 1); // 0.70710678118
    EXPECT_NEAR(q.X, 0.0, 1e-5);              // 0.0
    EXPECT_NEAR(q.Y, std::sin(PI / 4), 1); // 0.70710678118
    EXPECT_NEAR(q.Z, 0.0, 1e-5);              // 0.0
}

// Test de la conversion d'angles d'Euler en quaternion
TEST(QuaternionTest, FromEulerAngles) {
    Quaternion<double> q = Quaternion<double>::FromEulerAngles(90, 0, 0);  // 90 degrés autour de X
    EXPECT_NEAR(q.W, 0.70710678118, 1e-5); // cos(45°)
    EXPECT_NEAR(q.X, 0.70710678118, 1e-5); // sin(45°)
    EXPECT_NEAR(q.Y, 0.0, 1e-5);
    EXPECT_NEAR(q.Z, 0.0, 1e-5);
}

// Test de la conversion d'angles d'Euler en quaternion pour un autre axe
TEST(QuaternionTest, FromEulerAngles_Yaw) {
    Quaternion<double> q = Quaternion<double>::FromEulerAngles(0, 90, 0);  // 90 degrés autour de Y
    EXPECT_NEAR(q.W, 0.70710678118, 1e-5); // cos(45°)
    EXPECT_NEAR(q.X, 0.0, 1e-5);
    EXPECT_NEAR(q.Y, 0.70710678118, 1e-5); // sin(45°)
    EXPECT_NEAR(q.Z, 0.0, 1e-5);
}

// Test de la conversion d'angles d'Euler en quaternion pour un axe Z
TEST(QuaternionTest, FromEulerAngles_Roll) {
    Quaternion<double> q = Quaternion<double>::FromEulerAngles(0, 0, 90);  // 90 degrés autour de Z
    EXPECT_NEAR(q.W, 0.70710678118, 1e-5); // cos(45°)
    EXPECT_NEAR(q.X, 0.0, 1e-5);
    EXPECT_NEAR(q.Y, 0.0, 1e-5);
    EXPECT_NEAR(q.Z, 0.70710678118, 1e-5); // sin(45°)
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
