//
// Created by ROG on 15.10.2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    int x_ = 0;
    int y_ = 0;
    int radius_ = 0;

public:
    int r_ = 0;
    int g_ = 0;
    int b_ = 0;

    Circle(const int x, const int y, const int radius)
    {
        this->x_ = x;
        this->y_ = y;
        this->radius_ = radius;
        RandomizeColor();
    }

    [[nodiscard]] int GetX() const { return x_; }
    [[nodiscard]] int GetY() const { return y_; }
    [[nodiscard]] int GetRadius() const { return radius_; }
    void SetX(const int n_x) { x_ = n_x; }
    void SetY(const int n_y) { y_ = n_y; }
    void SetRadius(const int n_radius) { radius_ = n_radius; }


    void RandomizeColor();
    void RandomizeSize(int max_size);
    void SetPosition(int x, int y);
};


#endif //CIRCLE_H
