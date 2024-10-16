// Graphics.cpp
#include "Graphics.h"

Graphics::Graphics(SDL_Renderer* renderer) : renderer_(renderer) {}

Graphics::Graphics(): renderer_(nullptr)
{
}

void Graphics::DrawSquare(const Square& square) const {
    SDL_Rect rect;
    rect.x = square.x - square.size / 2;
    rect.y = square.y - square.size / 2;
    rect.w = square.size;
    rect.h = square.size;

    SDL_RenderFillRect(renderer_, &rect);
}

void Graphics::SetDrawColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) const {
    SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}


void Graphics::DrawCircle(const Circle& circle) const
{
    int x = circle.GetRadius();
    int y = 0;
    int radius_error = 1 - x;

    SetDrawColor(circle.r_, circle.g_, circle.b_, 255);
    while (x >= y) {
        // Draw horizontal lines between the edges of the circle at each height
        SDL_RenderDrawLine(renderer_, circle.GetX() - x, circle.GetY() + y, circle.GetX() + x, circle.GetY() + y);
        SDL_RenderDrawLine(renderer_, circle.GetX() - x, circle.GetY() - y, circle.GetX() + x, circle.GetY() - y);
        SDL_RenderDrawLine(renderer_, circle.GetX() - y, circle.GetY() + x, circle.GetX() + y, circle.GetY() + x);
        SDL_RenderDrawLine(renderer_, circle.GetX() - y, circle.GetY() - x, circle.GetX() + y, circle.GetY() - x);

        y++;
        if (radius_error < 0) {
            radius_error += 2 * y + 1;
        } else {
            x--;
            radius_error += 2 * (y - x + 1);
        }
    }
}
