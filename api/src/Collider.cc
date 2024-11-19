//
// Created by Maintenant prêt on 09.11.2024.
//

#include "Collider.h"
#include "Constants.h"
#include "Graphics.h"
#include <algorithm>

void Collider::CheckCollideShapes(std::vector<Shape> &circle_obj_) {
  for (std::size_t i = 0; i < circle_obj_.size(); ++i) {
    CheckCollideWindow(circle_obj_[i]);
    for (std::size_t j = i + 1; j < circle_obj_.size(); ++j) {
      if (CheckCollision(circle_obj_[i], circle_obj_[j])) {
        Vec2<float> pos_i = circle_obj_[i].getBody().position();
        Vec2<float> pos_j = circle_obj_[j].getBody().position();
        Vec2<float> vel_i = circle_obj_[i].getBody().velocity();
        Vec2<float> vel_j = circle_obj_[j].getBody().velocity();
        float mass_i = circle_obj_[i].getBody().mass();
        float mass_j = circle_obj_[j].getBody().mass();

        Vec2<float> collision_normal = (pos_j - pos_i).Normalized();
        float relative_velocity = Vec2<float>().Dot(( vel_j - vel_i),(collision_normal));

        // Only process if objects are moving towards each other
        if (relative_velocity > 0) continue;

        // Calculate new velocities using one-dimensional elastic collision equations
        float impulse = 2 * relative_velocity / (mass_i + mass_j);
        Vec2<float> new_vel_i = vel_i + (impulse * mass_j) * collision_normal;
        Vec2<float> new_vel_j = vel_j - (impulse * mass_i) * collision_normal;

        circle_obj_[i].getBody().set_velocity(new_vel_i);
        circle_obj_[j].getBody().set_velocity(new_vel_j);
      }
    }
  }
}

void Collider::CheckTrigerShapes(std::vector<Shape> &circle_obj_) {
  for (std::size_t i = 0; i < circle_obj_.size(); ++i) {
    CheckCollideWindow(circle_obj_[i]);
    for (std::size_t j = i + 1; j < circle_obj_.size(); ++j) {
      bool collisionDetected = CheckCollision(circle_obj_[i], circle_obj_[j]);
      if (collisionDetected) {
        circle_obj_[i].Istrigger();
        circle_obj_[j].Istrigger();
      }
    }
  }
}





void Collider::CheckCollideShapesNoWindow(std::vector<Shape> &circle_obj_) {
  for (std::size_t i = 0; i < circle_obj_.size(); ++i) {
    for (std::size_t j = i + 1; j < circle_obj_.size(); ++j) {
      if (CheckCollision(circle_obj_[i], circle_obj_[j])) {
        Vec2<float> pos_i = circle_obj_[i].getBody().position();
        Vec2<float> pos_j = circle_obj_[j].getBody().position();
        Vec2<float> vel_i = circle_obj_[i].getBody().velocity();
        Vec2<float> vel_j = circle_obj_[j].getBody().velocity();
        float mass_i = circle_obj_[i].getBody().mass();
        float mass_j = circle_obj_[j].getBody().mass();

        Vec2<float> collision_normal = (pos_j - pos_i).Normalized();
        float relative_velocity = Vec2<float>().Dot(( vel_j - vel_i),(collision_normal));

        // Only process if objects are moving towards each other
        if (relative_velocity > 0) continue;

        // Calculate new velocities using one-dimensional elastic collision equations
        float impulse = 2 * relative_velocity / (mass_i + mass_j);
        Vec2<float> new_vel_i = vel_i + (impulse * mass_j) * collision_normal;
        Vec2<float> new_vel_j = vel_j - (impulse * mass_i) * collision_normal;

        circle_obj_[i].getBody().set_velocity(new_vel_i);
        circle_obj_[j].getBody().set_velocity(new_vel_j);
      }
    }
  }
}






void Collider::CheckCollideWindow(Shape &shape)
{
  Body &body = shape.getBody();
  int shapeSize;

  if (shape.GetType() == KCirle){
    shapeSize = shape.size();
  } else if (shape.GetType() == KSquare){
    shapeSize = shape.size() / 2;
  } else{
    shapeSize = shape.size();
  }



  if (body.getX() - shapeSize < 0) {
    body.set_velocity({-body.velocity().x, body.velocity().y});
    body.set_position({static_cast<float>(shapeSize), body.getY()});
  } else if (body.getX() + shapeSize > WIDTH) {
    body.set_velocity({-body.velocity().x, body.velocity().y});
    body.set_position({static_cast<float>(WIDTH - shapeSize), body.getY()});
  }

  // Vérifier les collisions avec le bord supérieur et inférieur
  if (body.getY() - shapeSize < 0) {
    body.set_velocity({body.velocity().x, -body.velocity().y});
    body.set_position({body.getX(), static_cast<float>(shapeSize)});
  } else if (body.getY() + shapeSize > HEIGHT) {
    body.set_velocity({body.velocity().x, -body.velocity().y});
    body.set_position({body.getX(), static_cast<float>(HEIGHT - shapeSize)});
  }
}


void Collider::UpdateQuadtree(std::vector<Shape>& shapes)
{
  //quadtree_ = Quadtree(shapes);
}


bool Collider::CheckCollision(const Shape &shapeA, const Shape &shapeB) const {

  if (shapeA.GetType() == KSquare && shapeB.GetType() == KSquare){
    float halfSizeA = shapeA.size() / 2.0f;
    float halfSizeB = shapeB.size() / 2.0f;
    const auto &bodyA = shapeA.body_;
    const auto &bodyB = shapeB.body_;

    return std::abs(bodyA.getX() - bodyB.getX()) < halfSizeA + halfSizeB &&
        std::abs(bodyA.getY() - bodyB.getY()) < halfSizeA + halfSizeB;

  }
  else if (shapeA.GetType() == KCirle && shapeB.GetType() == KCirle)
  {
    float distance = Vec2<float>(shapeA.body_.position() - shapeB.body_.position()).SquaredMagnitude();
    return distance < (shapeA.size() + shapeB.size()) * (shapeA.size() + shapeB.size());
  }
  else if (shapeA.GetType() == KCirle && shapeB.GetType() == KSquare || shapeA.GetType() == KSquare && shapeB.GetType() == KCirle )
  {
    Shape circle = shapeA;
    Shape square = shapeB;
    if (shapeB.GetType() == KCirle){
      circle = shapeB;
      square = shapeA;
    }

    const auto center = circle.body_.position();
    //Check if the AABB contains the circle's center
    if(square.Contains(center)) return true;


    //If not, expand the AABB bounds by the radius and check if those contain the center
    const auto radius = circle.size();
    const auto min_bound = square.min_bound();
    const auto max_bound = square.max_bound();


    return isCircleCollidingWithSquare(circle.getBody().position(),circle.size(),square.getBody().position(),square.size()/2);
  }

  return false;

}

bool Collider::isCircleCollidingWithSquare( Vec2<float> circleCenter, float circleRadius,
                                  Vec2<float> squareCenter, float squareHalfSize)const {
  // Trouver les coordonnées du point le plus proche du centre du cercle sur le carré
  float closestX = std::max(squareCenter.x - squareHalfSize, std::min(circleCenter.x, squareCenter.x + squareHalfSize));
  float closestY = std::max(squareCenter.y - squareHalfSize, std::min(circleCenter.y, squareCenter.y + squareHalfSize));

  // Calculer la distance au carré entre le centre du cercle et le point le plus proche
  float dx = circleCenter.x - Vec2<float>(closestX, closestY).x;
  float dy = circleCenter.y - Vec2<float>(closestX, closestY).y;
  float distanceSq = dx * dx + dy * dy;

  // Vérifier si cette distance est inférieure ou égale au carré du rayon du cercle
  return distanceSq <= (circleRadius * circleRadius);
}
void Collider::QuadtreeCollider(Quadtree& quadtree,int depth) {
  if (quadtree.last_child_)
  {
    CheckCollideShapes(quadtree.current_shapes_);
  }
  for (auto& child : quadtree.children_)
  {
    QuadtreeCollider(*child, depth + 1);
  }
}
