// Graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "circle.h"

struct Square {
    int x, y;   // Position of the center
    int size;   // Size of the square's side
};

// struct Circle {
//     int x, y;   // Position of the center
//     int radius; // Radius of the circle
// };

class Graphics {
public:
	explicit Graphics(SDL_Renderer* renderer);
    Graphics();
    void DrawSquare(const Square& square) const;
    void DrawCircle(const Circle& circle) const;
    void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const;
	[[nodiscard]] SDL_Renderer* GetRenderer() const { return renderer_;}

private:
    SDL_Renderer* renderer_;
};

#endif // GRAPHICS_H