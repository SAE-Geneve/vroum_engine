#ifndef GAMEENGINE_CORE_INCLUDE_COMMUN_H_
#define GAMEENGINE_CORE_INCLUDE_COMMUN_H_

#include "Constants.h"


inline float ToPixels(const float &value) {
  return value * 100.0f;
}

// Converts a radian value to degrees
inline float ToDegree(const float &rad_value) {
  return rad_value * 180 / PI;
}

// Converts a degree value to radians
inline float ToRadians(const float &degrees_value) {
  return degrees_value * PI / 180;
}

inline float ToKilo(const float &Mass) {
  return Mass * 1;
}


#endif //GAMEENGINE_CORE_INCLUDE_COMMUN_H_
