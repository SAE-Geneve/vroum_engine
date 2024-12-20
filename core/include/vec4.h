﻿
#ifndef VECTOR4_H
#define VECTOR4_H
template<typename T>
struct Vec4 {
    T x = 0, y = 0, z = 0, w = 0;

    template<typename Other_type>
    explicit Vec4(Vec4<Other_type> v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w)) {}

    constexpr Vec4(T x = 0, T y = 0, T z = 0, T w = 0) : x(x), y(y), z(z), w(w) {}

    constexpr Vec4<T> operator+(Vec4<T> other) const {
        return { x + other.x, y + other.y, z + other.z, w + other.w };
    }

    constexpr Vec4<T> operator-(Vec4<T> other) const {
        return { x - other.x, y - other.y, z - other.z, w - other.w };
    }

    constexpr Vec4<T> operator-() const {
        return { -x, -y, -z, -w };
    }

    constexpr Vec4<T> operator*(T scalar) const {
        return { scalar * x, scalar * y, scalar * z, scalar * w };
    }

    constexpr Vec4<T> operator/(T scalar) const {
        if (scalar == 0) {
            return { 0, 0, 0, 0 };
        }
        return { x / scalar, y / scalar, z / scalar, w / scalar };
    }

    constexpr Vec4<T> lerp(Vec4<T> b, T t) const {
        return { x + (b.x - x) * t, y + (b.y - y) * t, z + (b.z - z) * t, w + (b.w - w) * t };
    }

    [[nodiscard]] T squaredMagnitude() const {
        return (x * x + y * y + z * z + w * w);
    }

    [[nodiscard]] T Magnitude() const {
        return std::sqrt(squaredMagnitude());
    }

    [[nodiscard]] Vec4<T> Normalized() const {
        if (x == 0 && y == 0 && z == 0 && w == 0) {
            return { 0, 0, 0, 0 };
        }
        return { x / Magnitude(), y / Magnitude(), z / Magnitude(), w / Magnitude() };
    }

    static T Dot(const Vec4<T>& v1, const Vec4<T>& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
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
        else if (index == 2)
        {
            return z;
        }
        else if (index == 3)
        {
            return w;
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }
};
#endif //VECTOR4_H