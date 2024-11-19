#include "Solarsystem.h"
#include <cmath>

#include "Constants.h"

void Solarsystem::UpdatePosition() {

  static constexpr float kGravitationConstant_ = 0.0667f;

  for (std::size_t i = 0; i < plantes_.size(); i++) {

    auto &planet = plantes_[i];

    Vec2 u = sun.position() - Vec2<float>(planet.getBody().getX(), planet.getBody().getY());
    float r = u.Magnitude();

    if (r > 0) {
      float force_magnitude = kGravitationConstant_ * (planet.getBody().mass() * sun.mass() / (r * r));
      Vec2 force = force_magnitude * u.Normalized();
      planet.getBody().ApplyForce(force);
    }

    planet.getBody().set_velocity(planet.getBody().velocity() + planet.getBody().acceleration());
    planet.getBody().set_position(planet.getBody().position() + planet.getBody().velocity());
    planet.getBody().ResetForce();
  }
}

void Solarsystem::Draw(Graphics &graphics) {

  for (Shape &planets : plantes_) {
    graphics.DrawShape(planets);
  }

}

void Solarsystem::test() {
  for (std::size_t i = 0; i < plantes_.size(); i++) {
    auto &planet = plantes_[i];

    planet.getBody().set_velocity(Vec2<float>(1000, 1000));
    planet.getBody().set_position(planet.getBody().position() + planet.getBody().velocity());
  }
}

void Solarsystem::Update(Graphics &graphics) {
  Solarsystem::UpdatePosition();
  Solarsystem::Draw(graphics);
}

void Solarsystem::CreatePlanet(Vec2<float> postiton, float size, Graphics &graphics) {
  static constexpr float kGravitationConstant_ = 0.0667f;

  auto body = Body(postiton, 3);

  Vec2 u = sun.position() - body.position();
  float r = u.Magnitude();

  Vec2 angular_velocity = std::sqrt(kGravitationConstant_ * (sun.mass() / r)) * Vec2(-u.y, u.x).Normalized();


  body.set_velocity(angular_velocity);

  auto cirle = Shape(SIZE_CIRCLE, body,KCirle);
  plantes_.push_back(cirle);

  graphics.initializeCircleVertices(plantes_[plantes_.size() - 1]);
}
