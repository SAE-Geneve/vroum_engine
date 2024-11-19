#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

template<typename T>
struct Vec2
{
    T x{}, y{};

    constexpr Vec2(T x = 0, T y = 0) : x(x), y(y) {}

    constexpr Vec2 operator+(Vec2 other) const;
    constexpr Vec2 operator+=(Vec2 other) const;
    constexpr Vec2 operator-(Vec2 other) const;
    constexpr Vec2 operator-() const;
    constexpr Vec2 operator*(T scalar) const;
    constexpr Vec2 operator/(T scalar) const;
    constexpr Vec2 lerp(Vec2 b, T t) const;
    [[nodiscard]] T SquaredMagnitude() const;
    [[nodiscard]] T Magnitude() const;
    [[nodiscard]] Vec2 Normalized() const;
    static T Dot(const Vec2& v1, const Vec2& v2);
    constexpr Vec2 Perpendicular() const;
    constexpr Vec2 Perpendicular2() const;
    T Getx(){return x;}
    T Gety(){return y;}
};

template<typename T>
constexpr Vec2<T> operator*(T scalar, const Vec2<T>& vec);


template<typename T>
constexpr Vec2<T> Vec2<T>::operator+(Vec2 other) const
{
    return { x + other.x, y + other.y };
}



template<typename T>
constexpr Vec2<T> Vec2<T>::operator+=(const Vec2<T> vec) const
{
  x += vec.x;
  y += vec.y;

  return *this;
}

template<typename T>
constexpr Vec2<T> Vec2<T>::operator-(Vec2 other) const
{
    return { x - other.x, y - other.y };
}

template<typename T>
constexpr Vec2<T> Vec2<T>::operator-() const
{
    return { -x, -y };
}

template<typename T>
constexpr Vec2<T> Vec2<T>::operator*(T scalar) const
{
    return { scalar * x, scalar * y };
}

template<typename T>
constexpr Vec2<T> Vec2<T>::operator/(T scalar) const
{
    if (scalar == 0) {
        return { 0, 0 };
    } else {
        return { x / scalar, y / scalar };
    }
}

template<typename T>
constexpr Vec2<T> Vec2<T>::lerp(Vec2 b, T t) const
{
    return { x + (b.x - x) * t, y + (b.y - y) * t };
}

template<typename T>
T Vec2<T>::SquaredMagnitude() const
{
    return (x * x + y * y);
}

template<typename T>
T Vec2<T>::Magnitude() const
{
    if constexpr (std::is_floating_point_v<T>) {
        return std::sqrt(SquaredMagnitude());
    } else {
        return static_cast<T>(std::sqrt(static_cast<double>(SquaredMagnitude())));
    }
}

template<typename T>
Vec2<T> Vec2<T>::Normalized() const
{
    if (x == 0 && y == 0) {
        return { 0, 0 };
    } else {
        T mag = Magnitude();
        return { x / mag, y / mag };
    }
}

template<typename T>
T Vec2<T>::Dot(const Vec2& v1, const Vec2& v2)
{
  return (v1.x * v2.x) + (v1.y * v2.y);
}

template<typename T>
constexpr Vec2<T> Vec2<T>::Perpendicular() const
{
    return { -y, x };
}

template<typename T>
constexpr Vec2<T> Vec2<T>::Perpendicular2() const
{
    return { y, -x };
}

template<typename T>
constexpr Vec2<T> operator*(T scalar, const Vec2<T>& vec)
{
    return { scalar * vec.x, scalar * vec.y };
}



#endif // VEC2_H
