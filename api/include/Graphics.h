// Graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "Window.h"

struct Square {
    int x, y;   // Position of the center
    int size;   // Size of the square's side
};

class Graphics {
public:
    Graphics(SDL_Renderer* renderer);

    void DrawSquare(const Square& square) const;
    void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const;

private:
    SDL_Renderer* renderer;
};

#endif // GRAPHICS_H