#ifndef MATRICE2X2_H
#define MATRICE2X2_H

#include "Vector2.h"

template<typename T>

class Mat2x2
{
public:
    constexpr static std::size_t RowNbr = 3;
    constexpr static std::size_t ColNbr = 3;

    T Val[RowNbr][ColNbr] = {
        {1, 0},
        {0, 1}
    };

    constexpr Mat2x2() noexcept = default;

    /**
     * @note Vectors are added in column major order.
     */
    constexpr Mat2x2(Vec2<T> a, Vec2<T> b) noexcept
    {
        Val[0][0] = a.x;
        Val[0][1] = b.x;
        Val[1][0] = a.y;
        Val[1][1] = b.y;
    }

    [[nodiscard]] constexpr static Mat2x2<T> Identity() noexcept
    {
        return Mat2x2<T>({1, 0}, {0, 1});
    }

    [[nodiscard]] constexpr T Det() const noexcept
    {
        return (Val[0][0] * Val[1][1]) - (Val[0][1] * Val[1][0]);
    }

    std::optional<Mat2x2<T>> inverse() const
    {
        T det = Det();

        if (det == 0.0)
        {
            return std::nullopt;
        }

        Mat2x2<T> m({Val[1][1], Val[1][0] * -1}, {Val[0][1] * -1, Val[0][0]});

        return static_cast<Mat2x2<T>>(m) * (static_cast<T>(1) / static_cast<T>(Det()));
    }

    [[nodiscard]] constexpr Mat2x2<T> operator+(const Mat2x2<T> other) const noexcept
    {
        return Mat2x2<T>(
            {
                Val[0][0] + other.Val[0][0],
                Val[1][0] + other.Val[1][0]
            },
            {
                Val[0][1] + other.Val[0][1],
                Val[1][1] + other.Val[1][1]
            }
        );
    }

    [[nodiscard]] constexpr Mat2x2<T> operator-(const Mat2x2<T> other) const noexcept
    {
        return Mat2x2<T>(
            {
                Val[0][0] - other.Val[0][0],
                Val[0][1] - other.Val[0][1]
            },
            {
                Val[1][0] - other.Val[1][0],
                Val[1][1] - other.Val[1][1]
            }
        );
    }

    [[nodiscard]] constexpr Mat2x2<T> operator*(const T scalar) const noexcept
    {
        return Mat2x2<T>({Val[0][0] * scalar, Val[1][0] * scalar},
                         {Val[0][1] * scalar, Val[1][1] * scalar});
    }

    constexpr Mat2x2<T>& operator*=(const T scalar) noexcept
    {
        return *this = *this * scalar;
    }

    [[nodiscard]] constexpr Mat2x2<T> operator*(const Mat2x2<T> other) const noexcept
    {
        return Mat2x2<T>(
            {
                Val[0][0] * other.Val[0][0] + Val[0][1] * other.Val[1][0],
                Val[1][0] * other.Val[0][0] + Val[1][1] * other.Val[1][0]
            },
            {
                Val[0][0] * other.Val[0][1] + Val[0][1] * other.Val[1][1],
                Val[1][0] * other.Val[0][1] + Val[1][1] * other.Val[1][1]
            }
        );
    }

    [[nodiscard]] constexpr Vec2<T> operator*(const Vec2<T> vec) const noexcept
    {
        return Vec2<T>(
            Val[0][0] * vec.x + Val[0][1] * vec.y,
            Val[1][0] * vec.x + Val[1][1] * vec.y
        );
    }

    constexpr const T& operator()(std::size_t row, std::size_t col) const noexcept
    {
        return Val[row][col];
    }
};


#endif //MATRICE2X2_H
