#include "collider_static_systeme.h"
#include "Constants.h"

collider_static_systeme::collider_static_systeme(Graphics &graphics) {
  CreateStaticScene(graphics);
}


void collider_static_systeme::CreateShape(Vec2<float> position, Graphics &graphics) {
  auto body = Body(position, Range(MIN_MASS, MAX_MASS));
  body.set_position(position);
  body.set_velocity(Vec2<float>(0, 0));

  int shapeType = Range(1, 2);
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


void collider_static_systeme::CreateShapestatic(Vec2<float> position, Graphics &graphics, bool isStatic,int shape_Type_) {
  auto body = Body(position, Range(MIN_MASS, MAX_MASS));
  body.set_position(position);
  body.set_velocity(Vec2<float>(0, 0));

  int shapeType = shape_Type_;
  if (shapeType == KSquare) {
    auto shape = Shape(100, body, KSquare);
    shape.setStatic(true);
    circle_obj_.push_back(shape);
  } else if (shapeType == KCirle) {
    auto shape = Shape(100, body, KCirle);
    shape.setStatic(true);
    circle_obj_.push_back(shape);
  } else if (shapeType == KRectangle) {
    auto shape = Shape(200,200, body);
    shape.setStatic(true);
    circle_obj_.push_back(shape);
  }
}

void collider_static_systeme::CreateStaticScene(Graphics &graphics)
{

  CreateShapestatic(Vec2<float>(WIDTH / 2, HEIGHT - 250), graphics, true,1);

  for (int i = 0; i < 10; ++i) {
    CreateShape(Vec2<float>(generateRandomVec2(HEIGHT / 2 -100, HEIGHT / 2  + 100).x,generateRandomVec2(WIDTH / 2 -300  ,WIDTH / 2 - 350).y) , graphics);
  }
}

void collider_static_systeme::Draw(Graphics &graphics) {
  for (Shape &shape : circle_obj_) {
    graphics.DrawShape(shape);
  }
}

void collider_static_systeme::UpdatePosition() {
  const Vec2<float> gravity(0, 0.001f); // Gravity force

  collider.CheckCollideShapes(circle_obj_);
  for (std::size_t i = 0; i < circle_obj_.size(); i++) {
    auto &shape = circle_obj_[i];
    if (!shape.isStatic()) {
      shape.getBody().set_velocity(
          shape.getBody().velocity() + gravity );
      shape.getBody().set_position(shape.getBody().position() + shape.getBody().velocity());

      shape.getBody().ResetForce();
    }
  }
}

void collider_static_systeme::Update(Graphics &graphics) {
  collider_static_systeme::UpdatePosition();
  collider_static_systeme::Draw(graphics);
}
