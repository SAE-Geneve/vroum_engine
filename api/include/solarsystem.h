#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <vector>
#include "Circle.h"
#include "Graphics.h"
#include "Constants.h"
#include "Random.h"

class Solarsystem
{
public:
  Solarsystem(Graphics& graphics)
  {
    for (int i = 0; i < NUM_PLANETS; ++i) {
      CreatePlanet(generateRandomVec2(-400,400) + sun.position(), generateRandomVec2(5 ,10).x,graphics); // the best hack
    }

  };

    void UpdatePosition();
    void Draw(Graphics& graphics);
    void CreatePlanet(Vec2<float> postiton, float size,Graphics& graphics);
    void test();
    void Update(Graphics &graphics);

private:


    std::vector<Shape> plantes_;

    Body sun = Body(Vec2<float>(CENTER_X,CENTER_Y),10);


};

#endif // SOLARSYSTEM_H
