#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdexcept>
#include "cmath"

template <typename T>
struct Vec2 {
    T x = 0, y = 0;

    [[nodiscard]] constexpr Vec2<T> operator+(Vec2<T> other) const
    {
        return { x + other.x, y + other.y };
    }

    [[nodiscard]] constexpr Vec2<T> operator-(Vec2<T> other) const
    {
        return { x - other.x, y - other.y };
    }

    [[nodiscard]] constexpr Vec2<T> operator-() const
    {
        return { -x, -y };
    }

    [[nodiscard]] constexpr Vec2<T> operator*(T scalar) const
    {
        return { scalar * x ,y * scalar };
    }

    [[nodiscard]] constexpr Vec2<T> operator/(T scalar) const
    {
        if (scalar == 0)
        {
            return { 0, 0 };
        }
        return { x / scalar , y / scalar };
    }

    [[nodiscard]] constexpr Vec2<T> lerp(Vec2<T> b, T t) const
    {
        return {
            static_cast<T>(x + (b.x - x) * t),
            static_cast<T>(y + (b.y - y) * t)
        };
    }

    [[nodiscard]] T squaredMagnitude() const
    {
        return  (x * x + y * y);
    }

    [[nodiscard]] T Magnitude() const
    {
        return  std::sqrt(squaredMagnitude());
    }

    [[nodiscard]] Vec2<T> Normalized() const
    {
        if (x == 0 || y == 0)
        {
            return { 0, 0 };
        }
        return  { x / Magnitude() , y / Magnitude() };

    }

    [[nodiscard]] static T Dot(const Vec2<T>& v1, const Vec2<T>& v2)
    {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    [[nodiscard]] constexpr Vec2<T> Perpendicular() const
    {
        return { -y, x };
    }

    [[nodiscard]] constexpr Vec2<T> Perpendicular2() const
    {
        return { y, -x };
    }

    [[nodiscard]] T& operator[](const int index)
    {
        if (index == 0)
        {
            return x;
        }
        else if (index == 1)
        {
            return y;
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }
};

#endif //VECTOR2_H
