#include "Shape.h"
#include "Vec2.h"
#include "Body.h"
#include "Constants.h"
#include "FPSCounter.h"
#include "Collider.h"

#ifndef GAMEENGINE_API_INCLUDE_COLLIDER_SOLARY_SYTEME_H_
#define GAMEENGINE_API_INCLUDE_COLLIDER_SOLARY_SYTEME_H_

class collider_solary_syteme {
 public:
  collider_solary_syteme(Graphics& graphics) {
    for (int i = 0; i < NUM_PLANETS; ++i) {
      CreatePlanet(generateRandomVec2(-400, 400) + sun.position(), generateRandomVec2(5, 10).x, graphics);
    }
  }

  void CreatePlanet(Vec2<float> position, float mass, Graphics &graphics);
  void Draw(Graphics& graphics);
  void UpdatePosition();
  void Update(Graphics& graphics);

 private:
  std::vector<Shape> circle_obj_;
  Collider collider;
  Body sun = Body(Vec2<float>(CENTER_X, CENTER_Y), 2000);  // Le Soleil est à la position centrale
  FPSCounter deltatime;


  Vec2<float> calculateOrbitVelocity(const Vec2<float> &position);
};
#endif //GAMEENGINE_API_INCLUDE_COLLIDER_SOLARY_SYTEME_H_
