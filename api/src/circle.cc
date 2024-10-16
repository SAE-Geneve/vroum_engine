//
// Created by ROG on 15.10.2024.
//

#include "circle.h"

#include <algorithm>
#include <cstdlib>


void Circle::RandomizeColor()
{
    r_ = rand() % 256;
    g_ = rand() % 256;
    b_ = rand() % 256;
}


void Circle::RandomizeSize(const int max_size)
{
    SetRadius(std::clamp(rand() % (max_size + 1), 10, max_size));
}


void Circle::SetPosition(const int x, const int y)
{
    x_ = x;
    y_ = y;
}
