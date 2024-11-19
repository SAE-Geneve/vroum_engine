//
// Created by Maintenant prêt on 09.11.2024.
//

#ifndef GAMEENGINE_API_INCLUDE_COLLIDER_H_
#define GAMEENGINE_API_INCLUDE_COLLIDER_H_

#include "FPSCounter.h"
#include "Shape.h"
#include "Graphics.h"

class Collider{
 public:
  void CheckCollideWindow(Shape& shape);
  bool CheckCollision(const Shape &shapeA, const Shape &shapeB) const;
  void CheckCollideShapes(std::vector<Shape> &circle_obj_);
  FPSCounter deltatime;
  bool isCircleCollidingWithSquare( Vec2<float> circleCenter, float circleRadius,
                                    Vec2<float> squareCenter, float squareHalfSize)const;

  void UpdateQuadtree(std::vector<Shape> &shapes);

  void QuadtreeCollider(Quadtree&,int);

  void CheckCollideShapesNoWindow(std::vector<Shape> &circle_obj_);
  void CheckTrigerShapes(std::vector<Shape> &circle_obj_);
};
#endif //GAMEENGINE_API_INCLUDE_COLLIDER_H_
