//
// Created by ROG on 16.10.2024.
//

#include <gtest/gtest.h>
#include "four_vec2.h"

TEST(FourVec2Test, Addition) {
    FourVec2<int> vec1(1, 2, 3, 4, 5, 6, 7, 8);
    FourVec2<int> vec2(9, 10, 11, 12, 13, 14, 15, 16);

    FourVec2<int> result = vec1 + vec2;

    EXPECT_EQ(result.x[0], 10);
    EXPECT_EQ(result.y[0], 12);
    EXPECT_EQ(result.x[1], 14);
    EXPECT_EQ(result.y[1], 16);
    EXPECT_EQ(result.x[2], 18);
    EXPECT_EQ(result.y[2], 20);
    EXPECT_EQ(result.x[3], 22);
    EXPECT_EQ(result.y[3], 24);
}

TEST(FourVec2Test, Subtraction) {
    FourVec2<int> vec1(10, 12, 14, 16, 18, 20, 22, 24);
    FourVec2<int> vec2(1, 2, 3, 4, 5, 6, 7, 8);

    FourVec2<int> result = vec1 - vec2;

    EXPECT_EQ(result.x[0], 9);   // 10 - 1
    EXPECT_EQ(result.y[0], 10);  // 12 - 2
    EXPECT_EQ(result.x[1], 11);  // 14 - 3
    EXPECT_EQ(result.y[1], 12);  // 16 - 4
    EXPECT_EQ(result.x[2], 13);  // 18 - 5
    EXPECT_EQ(result.y[2], 14);  // 20 - 6
    EXPECT_EQ(result.x[3], 15);  // 22 - 7
    EXPECT_EQ(result.y[3], 16);  // 24 - 8
}

TEST(FourVec2Test, DefaultConstructor)
{
    FourVec2<int> vec;

    // Test si les valeurs par défaut sont à zéro
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(vec.x[i], 0);
        EXPECT_EQ(vec.y[i], 0);
    }
}

