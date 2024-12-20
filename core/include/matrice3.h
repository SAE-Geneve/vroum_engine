﻿#ifndef MATRICE3X3_H
#define MATRICE3X3_H

#include "Vec3.h"
#include <optional>
#include "Matrice2.h"

template <typename T>
class Mat3x3
{
public:
    constexpr static std::size_t RowNbr = 3;
    constexpr static std::size_t ColNbr = 3;

    T Val[RowNbr][ColNbr]{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    constexpr Mat3x3() noexcept = default;

    constexpr Mat3x3(Vec3<T> a, Vec3<T> b, Vec3<T> c) noexcept
    {
        Val[0][0] = a.x; Val[0][1] = b.x; Val[0][2] = c.x;
        Val[1][0] = a.y; Val[1][1] = b.y; Val[1][2] = c.y;
        Val[2][0] = a.z; Val[2][1] = b.z; Val[2][2] = c.z;
    }

    [[nodiscard]] constexpr static Mat3x3<T> Identity() noexcept
    {
        return Mat3x3<T>(Vec3<T>(1, 0, 0), Vec3<T>(0, 1, 0), Vec3<T>(0, 0, 1));
    }

    [[nodiscard]] constexpr Mat3x3<T> operator+(const Mat3x3<T>& m) const noexcept
    {
        Mat3x3<T> mResult;
        for (std::size_t row = 0; row < RowNbr; ++row)
            for (std::size_t col = 0; col < ColNbr; ++col)
                mResult.Val[row][col] = Val[row][col] + m.Val[row][col];
        return mResult;
    }

    [[nodiscard]] constexpr Mat3x3<T> operator-(const Mat3x3<T>& m) const noexcept
    {
        Mat3x3<T> mResult;
        for (std::size_t row = 0; row < RowNbr; ++row)
            for (std::size_t col = 0; col < ColNbr; ++col)
                mResult.Val[row][col] = Val[row][col] - m.Val[row][col];
        return mResult;
    }

    [[nodiscard]] constexpr Mat3x3<T> operator*(const T scalar) const noexcept
    {
        Mat3x3<T> mResult;
        for (std::size_t row = 0; row < RowNbr; ++row)
            for (std::size_t col = 0; col < ColNbr; ++col)
                mResult.Val[row][col] = Val[row][col] * scalar;
        return mResult;
    }

    [[nodiscard]] constexpr friend Mat3x3<T> operator*(const T scalar, const Mat3x3<T>& m) noexcept
    {
        return m * scalar;
    }

    constexpr Mat3x3<T>& operator*=(const T scalar) noexcept
    {
        return *this = *this * scalar;
    }

    [[nodiscard]] constexpr Mat3x3<T> operator*(const Mat3x3<T>& m) const noexcept
    {
        Mat3x3<T> mResult;
        for (std::size_t row = 0; row < RowNbr; ++row)
        {
            for (std::size_t col = 0; col < ColNbr; ++col)
            {
                T sum = 0;
                for (std::size_t k = 0; k < 3; ++k)
                    sum += Val[row][k] * m.Val[k][col];
                mResult.Val[row][col] = sum;
            }
        }
        return mResult;
    }

    [[nodiscard]] constexpr Vec3<T> operator*(const Vec3<T>& v) const noexcept
    {
        Vec3<T> vResult;
        for (std::size_t row = 0; row < RowNbr; ++row)
        {
            T internResult = 0;
            for (std::size_t j = 0; j < ColNbr; ++j)
                internResult += Val[row][j] * v[j];
            if (row == 0) vResult.x = internResult;
            if (row == 1) vResult.y = internResult;
            if (row == 2) vResult.z = internResult;
        }
        return vResult;
    }

    [[nodiscard]] constexpr T Det() const noexcept
    {
        return Val[0][0] * Val[1][1] * Val[2][2] + Val[0][1] * Val[1][2] * Val[2][0]
             + Val[0][2] * Val[1][0] * Val[2][1] - Val[2][0] * Val[1][1] * Val[0][2]
             - Val[2][1] * Val[1][2] * Val[0][0] - Val[2][2] * Val[1][0] * Val[0][1];
    }

    std::optional<Mat3x3<T>> Inverted() const
    {
        T det = Det();
        if (det == 0.0)
            return std::nullopt;

        Mat3x3<T> coFactorMatrix;
        for (std::size_t row = 0; row < RowNbr; ++row)
        {
            for (std::size_t col = 0; col < ColNbr; ++col)
            {
                T sign = ((col + row) % 2 == 0) ? 1 : -1;

                Mat2x2<T> subMat;
                std::size_t subMatRow = 0, subMatCol = 0;
                for (std::size_t subRow = 0; subRow < RowNbr; ++subRow)
                {
                    if (subRow == row) continue;
                    for (std::size_t subCol = 0; subCol < ColNbr; ++subCol)
                    {
                        if (subCol == col) continue;
                        subMat.Val[subMatRow][subMatCol] = Val[subRow][subCol];
                        ++subMatCol;
                    }
                    ++subMatRow;
                    subMatCol = 0;
                }
                coFactorMatrix.Val[row][col] = subMat.Det() * sign;
            }
        }
        return coFactorMatrix.Transposed() * (static_cast<T>(1) / det);
    }

    [[nodiscard]] constexpr Mat3x3<T> Transposed() const noexcept
    {
        Mat3x3<T> transposed;
        for (std::size_t row = 0; row < RowNbr; ++row)
            for (std::size_t col = 0; col < ColNbr; ++col)
                transposed.Val[row][col] = Val[col][row];
        return transposed;
    }

    constexpr const T& operator()(std::size_t row, std::size_t col) const noexcept
    {
        return Val[row][col];
    }
};

#endif //MATRICE3X3_H
