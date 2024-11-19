#ifndef QUATERNIONS_H
#define QUATERNIONS_H

#include <Constants.h>
#include <cmath> // Assurez-vous d'inclure cmath pour les fonctions mathématiques

template<typename T>
struct Quaternion
{
    T W, X, Y, Z;

    // Constructeur par défaut
    constexpr Quaternion() noexcept : W(1), X(0), Y(0), Z(0) {}

    // Constructeur avec des composants
    constexpr Quaternion(T w, T x, T y, T z) noexcept : W(w), X(x), Y(y), Z(z) {}

    // Constructeur à partir d'un angle et d'un axe
    template<typename U>
    constexpr Quaternion(U angle, T x, T y, T z) noexcept {
        T halfAngle = angle * static_cast<T>(0.5) * (PI / 180);
        W = std::cos(halfAngle);
        T s = std::sin(halfAngle);
        X = x * s;
        Y = y * s;
        Z = z * s;
    }

    // Conversion d'angles d'Euler (en degrés) en quaternion
    [[nodiscard]] static Quaternion<T> FromEulerAngles(T pitch, T yaw, T roll) noexcept
    {
        // Convertir les degrés en radians
        T halfPitch = pitch * (PI / 360);
        T halfYaw = yaw * (PI / 360);
        T halfRoll = roll * (PI / 360);

        // Calculer le cosinus et le sinus des angles
        T cp = std::cos(halfPitch);
        T sp = std::sin(halfPitch);
        T cy = std::cos(halfYaw);
        T sy = std::sin(halfYaw);
        T cr = std::cos(halfRoll);
        T sr = std::sin(halfRoll);

        // Calculer les composants du quaternion
        return Quaternion<T>(
            cp * cy * cr + sp * sy * sr,  // W
            sp * cy * cr - cp * sy * sr,  // X
            cp * sy * cr + sp * cy * sr,  // Y
            cp * cy * sr - sp * sy * cr   // Z
        );
    }
};

#endif //QUATERNIONS_H
