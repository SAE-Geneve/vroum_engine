//
// Created by ROG on 01.10.2024.
//

#ifndef VECTOR4_H
#define VECTOR4_H
template<typename T>
struct Vec4 {
    T x = 0, y = 0, z = 0, w = 0;

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
};
#endif //VECTOR4_H
