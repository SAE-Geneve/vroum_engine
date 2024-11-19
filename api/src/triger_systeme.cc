//
// Created by Maintenant prêt on 17.11.2024.
//

#include "triger_systeme.h"
#include "vec2.h"
#include "Constants.h"

void triger_systeme::CreateShape(Vec2<float> postiton, Graphics &graphics) {
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
}

void triger_systeme::Draw(Graphics &graphics)
{
  for (Shape &circle : circle_obj_) {
    graphics.DrawShape(circle);
  }
}

void triger_systeme::UpdatePosition() {
  collider.CheckTrigerShapes(circle_obj_);
  for (std::size_t i = 0; i < circle_obj_.size(); i++)
  {
    auto &shape = circle_obj_[i];
    shape.getBody().set_velocity(
        shape.getBody().velocity() + shape.getBody().acceleration() * deltatime.GetDeltatime());
    shape.getBody().set_position(shape.getBody().position() + shape.getBody().velocity());
    shape.getBody().ResetForce();
    if (shape.Gettriger()){
      shape.setcolor(SDL_Color(255,0,0,255));
      shape.Isnottrigger();
    } else{
      shape.Isnottrigger();
      shape.setcolor(SDL_Color(0,255,0,255));
    }
  }
}

void triger_systeme::Update(Graphics &graphics)
{
  triger_systeme::UpdatePosition();
  triger_systeme::Draw(graphics);
}







