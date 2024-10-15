//
// Created by ROG on 15.10.2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    int x = 0;
    int y = 0;
    int radius = 0;

public:
    int r = 0;
    int g = 0;
    int b = 0;

    Circle(int x, int y, int radius)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
        randomizeColor();
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int GetRadius() const { return radius; }
    void SetX(int n_x) { x = n_x; }
    void SetY(int n_y) { y = n_y; }
    void SetRadius(int n_radius) { radius = n_radius; }


    void randomizeColor();
    void randomizeSize(int maxSize);
    void SetPosition(int x, int y);
};


#endif //CIRCLE_H
