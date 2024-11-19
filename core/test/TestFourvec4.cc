#include <gtest/gtest.h>
#include "FourVec4.h"

namespace math {
    TEST(FourVec4Test, Addition) {
        FourVec4<int> vec1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
        FourVec4<int> vec2(9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6);

        FourVec4<int> result = vec1 + vec2;

        EXPECT_EQ(result.x[0], 10);  // 1 + 9
        EXPECT_EQ(result.y[0], 10);  // 2 + 8
        EXPECT_EQ(result.z[0], 10);  // 3 + 7
        EXPECT_EQ(result.w[0], 10);  // 4 + 6
        EXPECT_EQ(result.x[1], 10);  // 5 + 5
        EXPECT_EQ(result.y[1], 10);  // 6 + 4
        EXPECT_EQ(result.z[1], 10);  // 7 + 3
        EXPECT_EQ(result.w[1], 10);  // 8 + 2
        EXPECT_EQ(result.x[2], 10);  // 9 + 1
        EXPECT_EQ(result.y[2], 10);  // 10 + 0
        EXPECT_EQ(result.z[2], 10);  // 11 - 1
        EXPECT_EQ(result.w[2], 10);  // 12 - 2
        EXPECT_EQ(result.x[3], 10);  // 13 - 3
        EXPECT_EQ(result.y[3], 10);  // 14 - 4
        EXPECT_EQ(result.z[3], 10);  // 15 - 5
        EXPECT_EQ(result.w[3], 10);  // 16 - 6
    }

    TEST(FourVec4Test, Subtraction) {
        FourVec4<int> vec1(10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40);
        FourVec4<int> vec2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

        FourVec4<int> result = vec1 - vec2;

        EXPECT_EQ(result.x[0], 9);   // 10 - 1
        EXPECT_EQ(result.y[0], 10);  // 12 - 2
        EXPECT_EQ(result.z[0], 11);  // 14 - 3
        EXPECT_EQ(result.w[0], 12);  // 16 - 4
        EXPECT_EQ(result.x[1], 13);  // 18 - 5
        EXPECT_EQ(result.y[1], 14);  // 20 - 6
        EXPECT_EQ(result.z[1], 15);  // 22 - 7
        EXPECT_EQ(result.w[1], 16);  // 24 - 8
        EXPECT_EQ(result.x[2], 17);  // 26 - 9
        EXPECT_EQ(result.y[2], 18);  // 28 - 10
        EXPECT_EQ(result.z[2], 19);  // 30 - 11
        EXPECT_EQ(result.w[2], 20);  // 32 - 12
        EXPECT_EQ(result.x[3], 21);  // 34 - 13
        EXPECT_EQ(result.y[3], 22);  // 36 - 14
        EXPECT_EQ(result.z[3], 23);  // 38 - 15
        EXPECT_EQ(result.w[3], 24);  // 40 - 16
    }

    TEST(FourVec4Test, DefaultConstructor) {
        FourVec4<int> vec;

        // Test si les valeurs par défaut sont à zéro
        for (int i = 0; i < 4; ++i) {
            EXPECT_EQ(vec.x[i], 0);
            EXPECT_EQ(vec.y[i], 0);
            EXPECT_EQ(vec.z[i], 0);
            EXPECT_EQ(vec.w[i], 0);
        }
    }
}
