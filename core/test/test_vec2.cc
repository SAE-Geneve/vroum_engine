#include <gtest/gtest.h>
#include <cmath>
#include "Vector2.h"

// Test de l'opérateur +
TEST(Vec2Test, AdditionF) {
    Vec2<float> v1{1.0f, 2.0f};
    Vec2<float> v2{3.0f, 4.0f};
    Vec2<float> result = v1 + v2;

    EXPECT_FLOAT_EQ(result.x, 4.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

// Test de l'opérateur -
TEST(Vec2Test, SubtractionF) {
    Vec2<float> v1{5.0f, 7.0f};
    Vec2<float> v2{2.0f, 3.0f};
    Vec2<float> result = v1 - v2;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

// Test de l'opérateur unaire -
TEST(Vec2Test, UnaryMinusF) {
    Vec2<float> v{3.0f, 4.0f};
    Vec2<float> result = -v;

    EXPECT_FLOAT_EQ(result.x, -3.0f);
    EXPECT_FLOAT_EQ(result.y, -4.0f);
}

// Test de l'opérateur *
TEST(Vec2Test, ScalarMultiplicationF) {
    Vec2<float> v{1.0f, 2.0f};
    float scalar = 3.0f;
    Vec2<float> result = v * scalar;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
}

// Test de l'opérateur /
TEST(Vec2Test, ScalarDivisionF) {
    Vec2<float> v{6.0f, 8.0f};
    float scalar = 2.0f;
    Vec2<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vec2Test, ScalarDivisionByZeroF) {
    Vec2<float> v{6.0f, 8.0f};
    float scalar = 0.0f;
    Vec2<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
}

// Test de la fonction lerp
TEST(Vec2Test, LerpF) {
    Vec2<float> v1{0.0f, 0.0f};
    Vec2<float> v2{10.0f, 10.0f};
    float t = 0.5f;
    Vec2<float> result = v1.lerp(v2, t);

    EXPECT_FLOAT_EQ(result.x, 5.0f);
    EXPECT_FLOAT_EQ(result.y, 5.0f);
}

// Test de la fonction squaredMagnitude
TEST(Vec2Test, SquaredMagnitudeF) {
    Vec2<float> v{3.0f, 4.0f};
    float result = v.squaredMagnitude();

    EXPECT_FLOAT_EQ(result, 25.0f);  // 3^2 + 4^2 = 9 + 16 = 25
}

// Test de la fonction Magnitude
TEST(Vec2Test, MagnitudeF) {
    Vec2<float> v{3.0f, 4.0f};
    float result = v.Magnitude();

    EXPECT_FLOAT_EQ(result, 5.0f);  // sqrt(9 + 16) = 5
}

// Test de la fonction Normalized
TEST(Vec2Test, NormalizedF) {
    Vec2<float> v{3.0f, 4.0f};
    Vec2<float> result = v.Normalized();

    EXPECT_NEAR(result.x, 0.6f, 1e-6);
    EXPECT_NEAR(result.y, 0.8f, 1e-6);
}

// Test de la fonction Normalized avec un vecteur nul
TEST(Vec2Test, NormalizedZeroVectorF) {
    Vec2<float> v{0.0f, 0.0f};
    Vec2<float> result = v.Normalized();

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
}

// Test de la fonction Dot
TEST(Vec2Test, DotProductF) {
    Vec2<float> v1{1.0f, 2.0f};
    Vec2<float> v2{3.0f, 4.0f};
    float result = Vec2<float>::Dot(v1, v2);

    EXPECT_FLOAT_EQ(result, 11.0f);  // 1*3 + 2*4 = 3 + 8 = 11
}

// Test de la fonction Perpendicular
TEST(Vec2Test, PerpendicularF) {
    Vec2<float> v{1.0f, 2.0f};
    Vec2<float> result = v.Perpendicular();

    EXPECT_FLOAT_EQ(result.x, -2.0f);
    EXPECT_FLOAT_EQ(result.y, 1.0f);
}

// Test de la fonction Perpendicular2
TEST(Vec2Test, Perpendicular2F) {
    Vec2<float> v{1.0f, 2.0f};
    Vec2<float> result = v.Perpendicular2();

    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, -1.0f);
}


TEST(Vec2IntTest, Addition) {
    Vec2<int> v1{1, 2};
    Vec2<int> v2{3, 4};
    Vec2<int> result = v1 + v2;

    EXPECT_EQ(result.x, 4);
    EXPECT_EQ(result.y, 6);
}

// Test de l'opérateur -
TEST(Vec2IntTest, Subtraction) {
    Vec2<int> v1{5, 7};
    Vec2<int> v2{2, 3};
    Vec2<int> result = v1 - v2;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 4);
}

// Test de l'opérateur unaire -
TEST(Vec2IntTest, UnaryMinus) {
    Vec2<int> v{3, 4};
    Vec2<int> result = -v;

    EXPECT_EQ(result.x, -3);
    EXPECT_EQ(result.y, -4);
}

// Test de l'opérateur *
TEST(Vec2IntTest, ScalarMultiplication) {
    Vec2<int> v{1, 2};
    int scalar = 3;
    Vec2<int> result = v * scalar;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 6);
}

// Test de l'opérateur /
TEST(Vec2IntTest, ScalarDivision) {
    Vec2<int> v{6, 8};
    int scalar = 2;
    Vec2<int> result = v / scalar;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 4);
}

TEST(Vec2IntTest, ScalarDivisionByZero) {
    Vec2<int> v{6, 8};
    int scalar = 0;
    Vec2<int> result = v / scalar;

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
}

// Test de la fonction squaredMagnitude
TEST(Vec2IntTest, SquaredMagnitude) {
    Vec2<int> v{3, 4};
    int result = v.squaredMagnitude();

    EXPECT_EQ(result, 25);  // 3^2 + 4^2 = 9 + 16 = 25
}

// Test de la fonction Magnitude (utilisée avec des int, donc cast en double)
TEST(Vec2IntTest, Magnitude) {
    Vec2<int> v{3, 4};
    double result = v.Magnitude();

    EXPECT_NEAR(result, 5.0, 1e-6);  // sqrt(9 + 16) = 5
}

// Test de la fonction Normalized
TEST(Vec2IntTest, Normalized) {
    Vec2<int> v{3, 4};
    Vec2<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);  // La normalisation d'un vecteur int ne produit pas de résultats flottants
    EXPECT_EQ(result.y, 0);
}

// Test de la fonction Normalized avec un vecteur nul
TEST(Vec2IntTest, NormalizedZeroVector) {
    Vec2<int> v{0, 0};
    Vec2<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
}

// Test de la fonction Dot (produit scalaire)
TEST(Vec2IntTest, DotProduct) {
    Vec2<int> v1{1, 2};
    Vec2<int> v2{3, 4};
    int result = Vec2<int>::Dot(v1, v2);

    EXPECT_EQ(result, 11);  // 1*3 + 2*4 = 3 + 8 = 11
}

// Test de la fonction Perpendicular
TEST(Vec2IntTest, Perpendicular) {
    Vec2<int> v{1, 2};
    Vec2<int> result = v.Perpendicular();

    EXPECT_EQ(result.x, -2);
    EXPECT_EQ(result.y, 1);
}

// Test de la fonction Perpendicular2
TEST(Vec2IntTest, Perpendicular2) {
    Vec2<int> v{1, 2};
    Vec2<int> result = v.Perpendicular2();

    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, -1);
}