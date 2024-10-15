//
// Created by ROG on 15.10.2024.
//

#include "circle.h"

#include <algorithm>
#include <cstdlib>


void Circle::randomizeColor()
{
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;
}


void Circle::randomizeSize(int maxSize)
{
    SetRadius(std::clamp(rand() % (maxSize + 1), 10, maxSize));
}


void Circle::SetPosition(int n_x, int n_y)
{
    x = n_x;
    y = n_y;
}
