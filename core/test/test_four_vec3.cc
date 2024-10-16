//
// Created by ROG on 16.10.2024.
//

#include <gtest/gtest.h>
#include "four_vec3.h"


    TEST(FourVec3Test, Addition) {
        FourVec3<int> vec1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
        FourVec3<int> vec2(9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2);

        FourVec3<int> result = vec1 + vec2;

        EXPECT_EQ(result.x[0], 10);  // 1 + 9
        EXPECT_EQ(result.y[0], 10);  // 2 + 8
        EXPECT_EQ(result.z[0], 10);  // 3 + 7
        EXPECT_EQ(result.x[1], 10);  // 4 + 6
        EXPECT_EQ(result.y[1], 10);  // 5 + 5
        EXPECT_EQ(result.z[1], 10);  // 6 + 4
        EXPECT_EQ(result.x[2], 10);  // 7 + 3
        EXPECT_EQ(result.y[2], 10);  // 8 + 2
        EXPECT_EQ(result.z[2], 10);  // 9 + 1
        EXPECT_EQ(result.x[3], 10);  // 10 + 0
        EXPECT_EQ(result.y[3], 10);  // 11 - 1
        EXPECT_EQ(result.z[3], 10);  // 12 - 2
    }

TEST(FourVec3Test, Subtraction) {
        FourVec3<int> vec1(10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
        FourVec3<int> vec2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

        FourVec3<int> result = vec1 - vec2;

        EXPECT_EQ(result.x[0], 9);   // 10 - 1
        EXPECT_EQ(result.y[0], 10);  // 12 - 2
        EXPECT_EQ(result.z[0], 11);  // 14 - 3
        EXPECT_EQ(result.x[1], 12);  // 16 - 4
        EXPECT_EQ(result.y[1], 13);  // 18 - 5
        EXPECT_EQ(result.z[1], 14);  // 20 - 6
        EXPECT_EQ(result.x[2], 15);  // 22 - 7
        EXPECT_EQ(result.y[2], 16);  // 24 - 8
        EXPECT_EQ(result.z[2], 17);  // 26 - 9
        EXPECT_EQ(result.x[3], 18);  // 28 - 10
        EXPECT_EQ(result.y[3], 19);  // 30 - 11
        EXPECT_EQ(result.z[3], 20);  // 32 - 12
    }

TEST(FourVec3Test, DefaultConstructor) {
        FourVec3<int> vec;

        // Test si les valeurs par défaut sont à zéro
        for (int i = 0; i < 4; ++i) {
            EXPECT_EQ(vec.x[i], 0);
            EXPECT_EQ(vec.y[i], 0);
            EXPECT_EQ(vec.z[i], 0);
        }
    }

