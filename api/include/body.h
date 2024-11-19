#ifndef BODY_H
#define BODY_H
#include "vec2.h"
#include "Shape.h"

class Body
{
 private:
  Vec2<float> position_ = Vec2<float>(0,0);
  Vec2<float> velocity_ = Vec2<float>(0,0);
  Vec2<float> acceleration_ = Vec2<float>(0,0);
  float mass_ = 1.0f;

  // Ajout de l'angle et de la vitesse angulaire pour simuler l'orbite
  float angle_ = 0.0f; // Angle en radians
  float angular_velocity_ = 0.0f; // Vitesse angulaire (rad/s)

 public:

  Body(const Vec2<float> position, const Vec2<float> velocity, const float mass)
  {
    position_ = position;
    velocity_ = velocity;
    mass_ = mass;
  };

  Body(const Vec2<float> position)
  {
    position_ = position;
    velocity_ = Vec2<float>(0,0);
    mass_ = 1;
  };

  Body(const Vec2<float> position, const Vec2<float> velocity)
  {
    position_ = position;
    velocity_ = velocity;
    mass_ = 1;
  };

  Body(const Vec2<float> position,  const float mass)
  {
    position_ = position;
    velocity_ = Vec2<float>(0,0);
    mass_ = mass;
  };

  // Accesseurs pour la position, la vitesse, l'accélération, et la masse
  float getX() const { return position_.x; }
  float getY() const { return position_.y; }
  [[nodiscard]] Vec2<float> position() const { return position_; }
  [[nodiscard]] Vec2<float> velocity() const { return velocity_; }
  [[nodiscard]] Vec2<float> acceleration() const { return acceleration_; }
  [[nodiscard]] float mass() const { return mass_; }

  // Nouvelles méthodes pour l'angle et la vitesse angulaire
  float get_angle() const { return angle_; }
  float get_angular_velocity() const { return angular_velocity_; }
  void set_angle(float angle) { angle_ = angle; }
  void set_angular_velocity(float angular_velocity) { angular_velocity_ = angular_velocity; }

  void set_position(const Vec2<float> new_position) { position_ = new_position; }
  void set_velocity(const Vec2<float> new_velocity) { velocity_ = new_velocity; }
  void set_mass(const float new_mass) { mass_ = new_mass; }

  // Applique une force pour calculer l'accélération
  void ApplyForce(const Vec2<float> force) { acceleration_ = acceleration_ + force  / mass_; }
  void ResetForce() { acceleration_ = Vec2<float>(0,0); }

  // Mise à jour de la position en fonction de la vitesse
  void update_position(float delta_time)
  {
    position_ = position_ + velocity_ * delta_time;
  }

  // Mise à jour de l'angle en fonction de la vitesse angulaire
  void update_angle(float delta_time)
  {
    angle_ += angular_velocity_ * delta_time;
  }
};

#endif //BODY_H

