
#ifndef GAMEENGINE_API_INCLUDE_COLLIDER_QUADTREE_SYSTEME_H_
#define GAMEENGINE_API_INCLUDE_COLLIDER_QUADTREE_SYSTEME_H_

#include <vector>
#include <iostream>
#include "Graphics.h"
#include "Shape.h"
#include "Vec2.h"
#include "Body.h"
#include "Constants.h"
#include "FPSCounter.h"
#include "Collider.h"

class ColliderQuadtreeSysteme {
 public:

  ColliderQuadtreeSysteme(Graphics& graphics) {
    for (int i = 0; i < NUM_PLANETS; ++i) {
      CreateShape(generateRandomVec2(50, HEIGHT), graphics);
    }};

  void CreateShape(Vec2<float> position, Graphics& graphics);
  void Draw(Graphics& graphics);
  void UpdatePosition();
  void Update(Graphics& graphics);


 private:
  std::vector<Shape> circle_obj_;
  Collider collider;
  Quadtree quadtree_ = Quadtree(circle_obj_);
  std::vector<Shape *> obj_;
  FPSCounter deltatime;

};


#endif //GAMEENGINE_API_INCLUDE_COLLIDER_QUADTREE_SYSTEME_H_
