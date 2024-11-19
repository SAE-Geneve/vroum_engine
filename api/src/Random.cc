#include "Random.h"

#include <random>

// Générateur de nombres aléatoires et distribution uniforme
static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_int_distribution<> dis(0, 255);

// Définition de la fonction pour générer une couleur aléatoire
SDL_Color generateRandomColor() {
  SDL_Color color;
  color.r = static_cast<Uint8>(dis(gen));
  color.g = static_cast<Uint8>(dis(gen));
  color.b = static_cast<Uint8>(dis(gen));
  color.a = 255; // Alpha à 255 pour une couleur opaque

  return color;
}

Vec2<float> generateRandomVec2(int min,int max)
{
  return Vec2<float>(min + std::rand() % (max - min + 1),min + std::rand() % (max - min + 1) );
}



