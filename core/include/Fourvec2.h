﻿#ifndef LIBS_MATHS_FOUR_VEC2_H_
#define LIBS_MATHS_FOUR_VEC2_H_

#include <array>
#include <emmintrin.h>
#include <cassert>

#include "vec2.h"

namespace math
{
template <typename T>
struct FourVec2
{
  std::array<T, 4> x{};
  std::array<T, 4> y{};

  FourVec2() = default;
//
//        constexpr FourVec2(std::initializer_list<Vec2<T>> vectors) {
//          assert(vectors.size() == 4 && "FourVec2 requires 4 vectors");
//          auto it = vectors.begin();
//          // TODO: finish this
//        }

  explicit constexpr FourVec2(const std::array<Vec2<T>, 4>& vec)
  {
    for (int i = 0; i < 4; i++)
    {
      x[i] = vec[i].x;
      y[i] = vec[i].y;
    }
  }

  FourVec2<T> operator+(const FourVec2<T>& other) const;
  FourVec2<T> operator-(const FourVec2<T>& other) const;
  FourVec2<T> operator-() const; //Opposite
  FourVec2<T> operator*(const float scalar) const; //Multiply by scalar
  FourVec2<T> operator/(const float scalar) const; //Divide by scalar
  std::array<float, 4> Dot(const FourVec2<T>& other) const; //Dot
  std::array<float, 4> SquareMagnitude() const; //SquareMagnitude
  std::array<float, 4> Magnitude() const;//Magnitude/Sqrroot
  FourVec2<T> Normalize() const;//Normalize
};
using FourVec2i = FourVec2<int32_t>;
using FourVec2f = FourVec2<float>;

//TODO + Activer LTO, nodiscard, constexpr si besoin

//Specialization for float
template<>
FourVec2f FourVec2<float>::operator+(const FourVec2f& other) const;
template<>
FourVec2f FourVec2<float>::operator-(const FourVec2f& other) const;
template<>
FourVec2f FourVec2<float>::operator-() const;
template<>
FourVec2f FourVec2<float>::operator*(const float scalar) const;
template<>
FourVec2f FourVec2<float>::operator/(const float scalar) const;
template<>
std::array<float, 4> FourVec2<float>::Dot(const FourVec2f& other) const;
template<>
std::array<float, 4> FourVec2<float>::SquareMagnitude() const;
template<>
std::array<float, 4> FourVec2<float>::Magnitude() const;
template<>
FourVec2f FourVec2<float>::Normalize() const;

}

#endif //LIBS_MATHS_FOUR_VEC2_H_
