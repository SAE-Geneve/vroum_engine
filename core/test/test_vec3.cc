#include <gtest/gtest.h>
#include <gtest/gtest.h>
#include <cmath>
#include "Vector3.h"

// Test of the + operator
TEST(Vec3Test, AdditionF) {
    Vec3<float> v1{1.0f, 2.0f, 3.0f};
    Vec3<float> v2{4.0f, 5.0f, 6.0f};
    Vec3<float> result = v1 + v2;

    EXPECT_FLOAT_EQ(result.x, 5.0f);
    EXPECT_FLOAT_EQ(result.y, 7.0f);
    EXPECT_FLOAT_EQ(result.z, 9.0f);
}

// Test of the - operator
TEST(Vec3Test, SubtractionF) {
    Vec3<float> v1{5.0f, 7.0f, 9.0f};
    Vec3<float> v2{2.0f, 3.0f, 4.0f};
    Vec3<float> result = v1 - v2;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 4.0f);
    EXPECT_FLOAT_EQ(result.z, 5.0f);
}

// Test of the unary - operator
TEST(Vec3Test, UnaryMinusF) {
    Vec3<float> v{3.0f, 4.0f, 5.0f};
    Vec3<float> result = -v;

    EXPECT_FLOAT_EQ(result.x, -3.0f);
    EXPECT_FLOAT_EQ(result.y, -4.0f);
    EXPECT_FLOAT_EQ(result.z, -5.0f);
}

// Test of the * operator (scalar multiplication)
TEST(Vec3Test, ScalarMultiplicationF) {
    Vec3<float> v{1.0f, 2.0f, 3.0f};
    float scalar = 3.0f;
    Vec3<float> result = v * scalar;

    EXPECT_FLOAT_EQ(result.x, 3.0f);
    EXPECT_FLOAT_EQ(result.y, 6.0f);
    EXPECT_FLOAT_EQ(result.z, 9.0f);
}

// Test of the / operator (scalar division)
TEST(Vec3Test, ScalarDivisionF) {
    Vec3<float> v{6.0f, 9.0f, 12.0f};
    float scalar = 3.0f;
    Vec3<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 2.0f);
    EXPECT_FLOAT_EQ(result.y, 3.0f);
    EXPECT_FLOAT_EQ(result.z, 4.0f);
}

// Test of division by zero
TEST(Vec3Test, ScalarDivisionByZeroF) {
    Vec3<float> v{6.0f, 9.0f, 12.0f};
    float scalar = 0.0f;
    Vec3<float> result = v / scalar;

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
}

// Test of the lerp function
TEST(Vec3Test, LerpF) {
    Vec3<float> v1{0.0f, 0.0f, 0.0f};
    Vec3<float> v2{10.0f, 10.0f, 10.0f};
    float t = 0.5f;
    Vec3<float> result = v1.lerp(v2, t);

    EXPECT_FLOAT_EQ(result.x, 5.0f);
    EXPECT_FLOAT_EQ(result.y, 5.0f);
    EXPECT_FLOAT_EQ(result.z, 5.0f);
}

// Test of the squaredMagnitude function
TEST(Vec3Test, SquaredMagnitudeF) {
    Vec3<float> v{3.0f, 4.0f, 0.0f};
    float result = v.squaredMagnitude();

    EXPECT_FLOAT_EQ(result, 25.0f);  // 3^2 + 4^2 + 0^2 = 25
}

// Test of the Magnitude function
TEST(Vec3Test, MagnitudeF) {
    Vec3<float> v{3.0f, 4.0f, 0.0f};
    float result = v.Magnitude();

    EXPECT_FLOAT_EQ(result, 5.0f);  // sqrt(25) = 5
}

// Test of the Normalized function
TEST(Vec3Test, NormalizedF) {
    Vec3<float> v{3.0f, 4.0f, 0.0f};
    Vec3<float> result = v.Normalized();

    EXPECT_NEAR(result.x, 0.6f, 1e-6);
    EXPECT_NEAR(result.y, 0.8f, 1e-6);
    EXPECT_NEAR(result.z, 0.0f, 1e-6);
}

// Test of normalization with a zero vector
TEST(Vec3Test, NormalizedZeroVectorF) {
    Vec3<float> v{0.0f, 0.0f, 0.0f};
    Vec3<float> result = v.Normalized();

    EXPECT_FLOAT_EQ(result.x, 0.0f);
    EXPECT_FLOAT_EQ(result.y, 0.0f);
    EXPECT_FLOAT_EQ(result.z, 0.0f);
}

// Test of the Dot function
TEST(Vec3Test, DotProductF) {
    Vec3<float> v1{1.0f, 2.0f, 3.0f};
    Vec3<float> v2{4.0f, 5.0f, 6.0f};
    float result = Vec3<float>::Dot(v1, v2);

    EXPECT_FLOAT_EQ(result, 32.0f);  // 1*4 + 2*5 + 3*6 = 32
}

// Test of the + operator (integer)
TEST(Vec3IntTest, Addition) {
    Vec3<int> v1{1, 2, 3};
    Vec3<int> v2{4, 5, 6};
    Vec3<int> result = v1 + v2;

    EXPECT_EQ(result.x, 5);
    EXPECT_EQ(result.y, 7);
    EXPECT_EQ(result.z, 9);
}

// Test of the - operator (integer)
TEST(Vec3IntTest, Subtraction) {
    Vec3<int> v1{5, 7, 9};
    Vec3<int> v2{2, 3, 4};
    Vec3<int> result = v1 - v2;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 4);
    EXPECT_EQ(result.z, 5);
}

// Test of the unary - operator (integer)
TEST(Vec3IntTest, UnaryMinus) {
    Vec3<int> v{3, 4, 5};
    Vec3<int> result = -v;

    EXPECT_EQ(result.x, -3);
    EXPECT_EQ(result.y, -4);
    EXPECT_EQ(result.z, -5);
}

// Test of the * operator (scalar multiplication, integer)
TEST(Vec3IntTest, ScalarMultiplication) {
    Vec3<int> v{1, 2, 3};
    int scalar = 3;
    Vec3<int> result = v * scalar;

    EXPECT_EQ(result.x, 3);
    EXPECT_EQ(result.y, 6);
    EXPECT_EQ(result.z, 9);
}

// Test of the / operator (scalar division, integer)
TEST(Vec3IntTest, ScalarDivision) {
    Vec3<int> v{6, 9, 12};
    int scalar = 3;
    Vec3<int> result = v / scalar;

    EXPECT_EQ(result.x, 2);
    EXPECT_EQ(result.y, 3);
    EXPECT_EQ(result.z, 4);
}

// Test of division by zero (integer)
TEST(Vec3IntTest, ScalarDivisionByZero) {
    Vec3<int> v{6, 9, 12};
    int scalar = 0;
    Vec3<int> result = v / scalar;

    EXPECT_EQ(result.x, 0);
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 0);
}

// Test of the squaredMagnitude function (integer)
TEST(Vec3IntTest, SquaredMagnitude) {
    Vec3<int> v{3, 4, 0};
    int result = v.squaredMagnitude();

    EXPECT_EQ(result, 25);  // 3^2 + 4^2 + 0^2 = 25
}

// Test of the Magnitude function (integer)
TEST(Vec3IntTest, Magnitude) {
    Vec3<int> v{3, 4, 0};
    double result = v.Magnitude();

    EXPECT_NEAR(result, 5.0, 1e-6);  // sqrt(25) = 5
}

// Test of the Normalized function (integer)
TEST(Vec3IntTest, Normalized) {
    Vec3<int> v{3, 4, 0};
    Vec3<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);  // Normalizing an integer vector doesn't produce float results
    EXPECT_EQ(result.y, 0);
    EXPECT_EQ(result.z, 0);
}

// Test of normalization with a zero vector (integer)
TEST(Vec3IntTest, NormalizedZeroVector)
{
    Vec3<int> v{0, 0, 0};
    Vec3<int> result = v.Normalized();

    EXPECT_EQ(result.x, 0);
}