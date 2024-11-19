
#ifndef GAMEENGINE_API_INCLUDE_COLLIDER_STATIC_SYSTEME_H_
#define GAMEENGINE_API_INCLUDE_COLLIDER_STATIC_SYSTEME_H_



#include <vector>
#include <iostream>
#include "Graphics.h"
#include "Shape.h"
#include "Vec2.h"
#include "Body.h"
#include "Constants.h"
#include "FPSCounter.h"
#include "Collider.h"

class collider_static_systeme {
 public:
  collider_static_systeme(Graphics &graphics);

  void CreateShape(Vec2<float> position, Graphics &graphics);
  void CreateStaticScene(Graphics &graphics);
  void CreateShapestatic(Vec2<float> position, Graphics &graphics, bool isStatic,int shape_Type_);
  void Draw(Graphics &graphics);
  void UpdatePosition();
  void Update(Graphics &graphics);

 private:
  std::vector<Shape> circle_obj_;
  Collider collider;
  FPSCounter deltatime;

};
#endif //GAMEENGINE_API_INCLUDE_COLLIDER_STATIC_SYSTEME_H_
