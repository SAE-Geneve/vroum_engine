// Graphics.cpp
#include "Graphics.h"

Graphics::Graphics(SDL_Renderer* renderer) : renderer(renderer) {}

Graphics::Graphics() {}

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
    int x = circle.GetRadius();
    int y = 0;
    int radiusError = 1 - x;

    SetDrawColor(circle.r, circle.g, circle.b, 255);
    while (x >= y) {
        // Draw horizontal lines between the edges of the circle at each height
        SDL_RenderDrawLine(renderer, circle.getX() - x, circle.getY() + y, circle.getX() + x, circle.getY() + y);
        SDL_RenderDrawLine(renderer, circle.getX() - x, circle.getY() - y, circle.getX() + x, circle.getY() - y);
        SDL_RenderDrawLine(renderer, circle.getX() - y, circle.getY() + x, circle.getX() + y, circle.getY() + x);
        SDL_RenderDrawLine(renderer, circle.getX() - y, circle.getY() - x, circle.getX() + y, circle.getY() - x);

        y++;
        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}
