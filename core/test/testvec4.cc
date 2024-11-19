#include <gtest/gtest.h>
#include <cmath>
#include "Vec4.h"


// Test de l'opérateur +
TEST(Vec4Test, AdditionF)
{
    Vec4<float> v1{1.0f, 2.0f, 3.0f, 4.0f};
    Vec4<float> v2{5.0f, 6.0f, 7.0f, 8.0f};
    Vec4<float> result = v1 + v2;

    EXPECT_FLOAT_EQ(result.x, 6.0f);
    EXPECT_FLOAT_EQ(result.y, 8.0f);
    EXPECT_FLOAT_EQ(result.z, 10.0f);
    EXPECT_FLOAT_EQ(result.w, 12.0f);
}

// Test de l'opérateur -
TEST(Vec4Test, SubtractionF)
{
    Vec4<float> v1{5.0f, 7.0f, 9.0f, 11.0f};
    Vec4<float> v2{2.0f, 3.0f, 4.0f, 5.0f};
    Vec4<float> result = v1 - v2;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 5.0f);
    EXPECT_FLOAT_EQ(result.w, 6.0f);
}

// Test de l'opérateur unaire -
TEST(Vec4Test, UnaryMinusF)
{
    Vec4<float> v{3.0f, 4.0f, 5.0f, 6.0f};
    Vec4<float> result = -v;

    EXPECT_FLOAT_EQ(result.x, -3.0f);
    EXPECT_FLOAT_EQ(result.y, -4.0f);
    EXPECT_FLOAT_EQ(result.z, -5.0f);
    EXPECT_FLOAT_EQ(result.w, -6.0f);
}

// Test de l'opérateur *
TEST(Vec4Test, ScalarMultiplicationF) {
    Vec4<float> v{1.0f, 2.0f, 3.0f, 4.0f};
    float scalar = 3.0f;
    Vec4<float> result = v * scalar;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
    EXPECT_FLOAT_EQ(result.z, 9.0f);
    EXPECT_FLOAT_EQ(result.w, 12.0f);
}

// Test de l'opérateur /
TEST(Vec4Test, ScalarDivisionF) {
    Vec4<float> v{6.0f, 8.0f, 10.0f, 12.0f};
    float scalar = 2.0f;
    Vec4<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 5.0f);
    EXPECT_FLOAT_EQ(result.w, 6.0f);
}

// Test de la division par zéro
TEST(Vec4Test, ScalarDivisionByZeroF) {
    Vec4<float> v{6.0f, 8.0f, 10.0f, 12.0f};
    float scalar = 0.0f;
    Vec4<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
    EXPECT_FLOAT_EQ(result.w, 0.0f);
}

// Test de la fonction lerp
TEST(Vec4Test, LerpF) {
    Vec4<float> v1{0.0f, 0.0f, 0.0f, 0.0f};
    Vec4<float> v2{10.0f, 10.0f, 10.0f, 10.0f};
    float t = 0.5f;
    Vec4<float> result = v1.lerp(v2, t);

    EXPECT_FLOAT_EQ(result.x, 5.0f);
    EXPECT_FLOAT_EQ(result.y, 5.0f);
    EXPECT_FLOAT_EQ(result.z, 5.0f);
    EXPECT_FLOAT_EQ(result.w, 5.0f);
}

// Test de la fonction SquaredMagnitude
TEST(Vec4Test, SquaredMagnitudeF) {
    Vec4<float> v{3.0f, 4.0f, 0.0f, 0.0f};
    float result = v.squaredMagnitude();

    EXPECT_FLOAT_EQ(result, 25.0f);  // 3^2 + 4^2 + 0^2 + 0^2 = 25
}

// Test de la fonction Magnitude
TEST(Vec4Test, MagnitudeF) {
    Vec4<float> v{3.0f, 4.0f, 0.0f, 0.0f};
    float result = v.Magnitude();

    EXPECT_FLOAT_EQ(result, 5.0f);  // sqrt(25) = 5
}

// Test de la fonction Normalized
TEST(Vec4Test, NormalizedF) {
    Vec4<float> v{3.0f, 4.0f, 0.0f, 0.0f};
    Vec4<float> result = v.Normalized();

    EXPECT_NEAR(result.x, 0.6f, 1e-6);
    EXPECT_NEAR(result.y, 0.8f, 1e-6);
    EXPECT_NEAR(result.z, 0.0f, 1e-6);
    EXPECT_NEAR(result.w, 0.0f, 1e-6);
}

// Test de la normalisation avec un vecteur nul
TEST(Vec4Test, NormalizedZeroVectorF) {
    Vec4<float> v{0.0f, 0.0f, 0.0f, 0.0f};
    Vec4<float> result = v.Normalized();

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
    EXPECT_FLOAT_EQ(result.w, 0.0f);
}

// Test de la fonction Dot
TEST(Vec4Test, DotProductF) {
    Vec4<float> v1{1.0f, 2.0f, 3.0f, 4.0f};
    Vec4<float> v2{5.0f, 6.0f, 7.0f, 8.0f};
    float result = Vec4<float>::Dot(v1, v2);

    EXPECT_FLOAT_EQ(result, 70.0f);  // 1*5 + 2*6 + 3*7 + 4*8 = 70
}

// Test de l'opérateur +
TEST(Vec4IntTest, Addition) {
    Vec4<int> v1{1, 2, 3, 4};
    Vec4<int> v2{5, 6, 7, 8};
    Vec4<int> result = v1 + v2;

    EXPECT_EQ(result.x, 6);
    EXPECT_EQ(result.y, 8);
    EXPECT_EQ(result.z, 10);
    EXPECT_EQ(result.w, 12);
}

// Test de l'opérateur -
TEST(Vec4IntTest, Subtraction) {
    Vec4<int> v1{5, 7, 9, 11};
    Vec4<int> v2{2, 3, 4, 5};
    Vec4<int> result = v1 - v2;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 4);
    EXPECT_EQ(result.z, 5);
    EXPECT_EQ(result.w, 6);
}

// Test de l'opérateur unaire -
TEST(Vec4IntTest, UnaryMinus) {
    Vec4<int> v{3, 4, 5, 6};
    Vec4<int> result = -v;

    EXPECT_EQ(result.x, -3);
    EXPECT_EQ(result.y, -4);
    EXPECT_EQ(result.z, -5);
    EXPECT_EQ(result.w, -6);
}

// Test de l'opérateur *
TEST(Vec4IntTest, ScalarMultiplication) {
    Vec4<int> v{1, 2, 3, 4};
    int scalar = 3;
    Vec4<int> result = v * scalar;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 6);
    EXPECT_EQ(result.z, 9);
    EXPECT_EQ(result.w, 12);
}

// Test de l'opérateur /
TEST(Vec4IntTest, ScalarDivision) {
    Vec4<int> v{6, 8, 10, 12};
    int scalar = 2;
    Vec4<int> result = v / scalar;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 4);
    EXPECT_EQ(result.z, 5);
    EXPECT_EQ(result.w, 6);
}

// Test de la division par zéro
TEST(Vec4IntTest, ScalarDivisionByZero) {
    Vec4<int> v{6, 8, 10, 12};
    int scalar = 0;
    Vec4<int> result = v / scalar;

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 0);
    EXPECT_EQ(result.w, 0);
}

// Test de la fonction SquaredMagnitude
TEST(Vec4IntTest, SquaredMagnitude) {
    Vec4<int> v{3, 4, 0, 0};
    int result = v.squaredMagnitude();

    EXPECT_EQ(result, 25);  // 3^2 + 4^2 + 0^2 + 0^2 = 25
}

// Test de la fonction Magnitude (utilisée avec des int, donc cast en double)
TEST(Vec4IntTest, Magnitude) {
    Vec4<int> v{3, 4, 0, 0};
    double result = v.Magnitude();

    EXPECT_NEAR(result, 5.0, 1e-6);  // sqrt(25) = 5
}

// Test de la fonction Normalized
TEST(Vec4IntTest, Normalized) {
    Vec4<int> v{3, 4, 0, 0};
    Vec4<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);  // La normalisation d'un vecteur int ne produit pas de résultats flottants
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 0);
    EXPECT_EQ(result.w, 0);
}

// Test de la fonction Normalized avec un vecteur nul
TEST(Vec4IntTest, NormalizedZeroVector) {
    Vec4<int> v{0, 0, 0, 0};
    Vec4<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 0);
    EXPECT_EQ(result.w, 0);
}

// Test de la fonction Dot (produit scalaire)
TEST(Vec4IntTest, DotProduct) {
    Vec4<int> v1{1, 2, 3, 4};
    Vec4<int> v2{5, 6, 7, 8};
    int result = Vec4<int>::Dot(v1, v2);

    EXPECT_EQ(result, 70);  // 1*5 + 2*6 + 3*7 + 4*8 = 70
}