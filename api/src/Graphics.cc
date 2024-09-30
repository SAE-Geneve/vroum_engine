// Graphics.cpp
#include "Graphics.h"

Graphics::Graphics(SDL_Renderer* renderer) : renderer(renderer) {}

void Graphics::DrawSquare(const Square& square) const {
    SDL_Rect rect;
    rect.x = square.x - square.size / 2;
    rect.y = square.y - square.size / 2;
    rect.w = square.size;
    rect.h = square.size;

    SDL_RenderFillRect(renderer, &rect);
}

void Graphics::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}