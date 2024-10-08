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


void Graphics::DrawCircle(const Circle& circle) const
{
    int x = circle.radius;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        // Draw horizontal lines between the edges of the circle at each height
        SDL_RenderDrawLine(renderer, circle.x - x, circle.y + y, circle.x + x, circle.y + y);
        SDL_RenderDrawLine(renderer, circle.x - x, circle.y - y, circle.x + x, circle.y - y);
        SDL_RenderDrawLine(renderer, circle.x - y, circle.y + x, circle.x + y, circle.y + x);
        SDL_RenderDrawLine(renderer, circle.x - y, circle.y - x, circle.x + y, circle.y - x);

        y++;
        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}
