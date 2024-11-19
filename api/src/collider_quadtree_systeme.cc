#include "collider_quadtree_systeme.h"
#include "vec2.h"
#include "Constants.h"

void ColliderQuadtreeSysteme::CreateShape(Vec2<float> postiton, Graphics &graphics) {
  auto body = Body(postiton, Range(MIN_MASS, MAX_MASS));
  body.set_position(postiton);
  body.set_velocity(Vec2<float>(Range(MIN_SPEED, MAX_SPEED), Range(MIN_SPEED, MAX_SPEED)));

  int shapeType = Range(1, 2); // 1: Square, 2: Circle, 3: Polygon
  if (shapeType == KSquare) {
    auto shape = Shape(SIZE_SQUARE, body, KSquare);
    circle_obj_.push_back(shape);
  } else if (shapeType == KCirle) {
    auto shape = Shape(SIZE_CIRCLE, body, KCirle);
    circle_obj_.push_back(shape);
  } else if (shapeType == KPolygon) {
    int numSides = Range(3, 7);
    auto shape = Shape(SIZE_CIRCLE, body, KPolygon);
    shape.setSides(numSides);
    circle_obj_.push_back(shape);
  }
  //static_cast<type_enum>(Range(1, 2))


}

void ColliderQuadtreeSysteme::Draw(Graphics &graphics) {
//  for (int i = 0; i < circle_obj_.size(); i++) {
//    graphics.DrawShape(circle_obj_[i]);
//  }
//quadtree_.Retrieve(obj_);
  graphics.DrawQuadtree(quadtree_,1);

}

void ColliderQuadtreeSysteme::UpdatePosition() {
  collider.QuadtreeCollider(quadtree_,1);
  collider.CheckCollideShapes(circle_obj_);
  for (std::size_t i = 0; i < circle_obj_.size(); i++)
  {
    auto &shape = circle_obj_[i];
    shape.getBody().set_velocity(
        shape.getBody().velocity() + shape.getBody().acceleration() * deltatime.GetDeltatime());
    shape.getBody().set_position(shape.getBody().position() + shape.getBody().velocity());
    shape.getBody().ResetForce();
  }
}

void ColliderQuadtreeSysteme::Update(Graphics &graphics)
{
  quadtree_ = Quadtree(circle_obj_);
  ColliderQuadtreeSysteme::UpdatePosition();
  ColliderQuadtreeSysteme::Draw(graphics);
}


