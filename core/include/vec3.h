#ifndef VECTOR3_H
#define VECTOR3_H
#include "iostream"

template<typename T>
struct Vec3 {
    T x = 0, y = 0, z = 0;

    constexpr Vec3(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}

    constexpr Vec3<T> operator+(Vec3<T> other) const {
        return { x + other.x, y + other.y, z + other.z };
    }

    constexpr Vec3<T> operator-(Vec3<T> other) const {
        return { x - other.x, y - other.y, z - other.z };
    }

    constexpr Vec3<T> operator-() const {
        return { -x, -y, -z };
    }

    constexpr Vec3<T> operator*(T scalar) const {
        return { scalar * x, scalar * y, scalar * z };
    }

    constexpr Vec3<T> operator/(T scalar) const {
        if (scalar == 0) {
            return { 0, 0, 0 };
        }
        return { x / scalar, y / scalar, z / scalar };
    }

    constexpr Vec3<T> lerp(Vec3<T> b, T t) const {
        return { x + (b.x - x) * t, y + (b.y - y) * t, z + (b.z - z) * t };
    }

    [[nodiscard]] T squaredMagnitude() const {
        return (x * x + y * y + z * z);
    }

    [[nodiscard]] T Magnitude() const {
        return std::sqrt(squaredMagnitude());
    }

    [[nodiscard]] Vec3<T> Normalized() const {
        if (x == 0 && y == 0 && z == 0) {
            return { 0, 0, 0 };
        }
        return { x / Magnitude(), y / Magnitude(), z / Magnitude() };
    }

    static T Dot(const Vec3<T>& v1, const Vec3<T>& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }

    constexpr Vec3<T> Cross(const Vec3<T>& other) const {
        return {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }

    [[nodiscard]] const T& operator[](const int index) const
    {
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else if (index == 2) {
            return z;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }
};
#endif //VECTOR3_H
