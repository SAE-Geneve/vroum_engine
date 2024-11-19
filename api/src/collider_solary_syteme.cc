#include "collider_solary_syteme.h"
#include "vec2.h"
#include "Constants.h"



void collider_solary_syteme::CreatePlanet(Vec2<float> position, float mass, Graphics& graphics) {
  // Crée une planète avec des vitesses et des positions calculées
  Vec2<float> velocity = calculateOrbitVelocity(position);
  Body planet = Body(position, mass);
  planet.set_velocity(velocity);
  Shape planetShape(SIZE_CIRCLE, planet,KCirle);
  circle_obj_.push_back(planetShape);
}

Vec2<float> collider_solary_syteme::calculateOrbitVelocity(const Vec2<float>& position)
{
  // Calcul de la distance entre la planète et le soleil
  Vec2<float> sunPosition = sun.position();  // Position du soleil
  Vec2<float> deltaPosition = position - sunPosition;  // Vecteur de position relatif planète-soleil
  float distance = deltaPosition.Magnitude();  // Distance entre la planète et le soleil

  // Calcul de la vitesse orbitale
  float velocityMagnitude = sqrt(KGRAVITATION_CONSTANT * sun.mass() / distance);

  // Direction de la vitesse est perpendiculaire au vecteur position (donnée par un produit vectoriel en 3D, mais ici simplement une rotation dans le plan 2D)
  Vec2<float> velocity = Vec2<float>(-deltaPosition.y, deltaPosition.x).Normalized() * velocityMagnitude;

  return velocity;
}


void collider_solary_syteme::UpdatePosition() {

  static constexpr float kGravitationConstant_ = 0.0667f;

  for (std::size_t i = 0; i < circle_obj_.size(); i++) {

    auto &planet = circle_obj_[i];

    // Calculer la direction du vecteur gravitationnel
    Vec2 u = sun.position() - Vec2<float>(planet.getBody().getX(), planet.getBody().getY());
    float r = u.Magnitude();

    // Appliquer la force gravitationnelle si la distance est non nulle
    if (r > 0) {
      float force_magnitude = kGravitationConstant_ * (planet.getBody().mass() * sun.mass() / (r * r));
      Vec2 force = force_magnitude * u.Normalized();
      planet.getBody().ApplyForce(force);
    }

    // Mettre à jour la vitesse et la position en fonction des forces appliquées
    planet.getBody().set_velocity(planet.getBody().velocity() + planet.getBody().acceleration());
    planet.getBody().set_position(planet.getBody().position() + planet.getBody().velocity());

    // Réinitialiser les forces pour la prochaine itération
    planet.getBody().ResetForce();
  }

  // Ajouter la gestion des collisions après la mise à jour des positions
  collider.CheckCollideShapesNoWindow(circle_obj_);
}

void collider_solary_syteme::Draw(Graphics &graphics)
{
  for (Shape shape : circle_obj_)
  {
    graphics.DrawShape(shape);
  }
}

void collider_solary_syteme::Update(Graphics &graphics)
{
  UpdatePosition();
  Draw(graphics);
}

