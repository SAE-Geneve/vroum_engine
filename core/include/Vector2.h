//
// Created by ROG on 01.10.2024.
//

#ifndef VECTOR2_H
#define VECTOR2_H

template <typename T>
struct Vec2 {
    T x = 0, y = 0;

    constexpr Vec2<T> operator+(Vec2<T> other) const
    {
        return { x + other.x, y + other.y };
    }

    constexpr Vec2<T> operator-(Vec2<T> other) const
    {
        return { x - other.x, y - other.y };
    }

    constexpr Vec2<T> operator-() const
    {
        return { -x, -y };
    }

    constexpr Vec2<T> operator*(T scalar) const
    {
        return { scalar * x ,y * scalar };
    }

    constexpr Vec2<T> operator/(T scalar) const
    {
        if (scalar == 0)
        {
            return { 0, 0 };
        }
        return { x / scalar , y / scalar };
    }

    constexpr Vec2<T> lerp(Vec2<T> b, T t) const
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

    static T Dot(const Vec2<T>& v1, const Vec2<T>& v2)
    {
        return (v1.x * v2.x) + (v1.y * v2.y);
    }

    constexpr Vec2<T> Perpendicular() const
    {
        return { -y, x };
    }

    constexpr Vec2<T> Perpendicular2() const
    {
        return { y, -x };
    }
};

#endif //VECTOR2_H
