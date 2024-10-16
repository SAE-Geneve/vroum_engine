// Window.h
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    [[nodiscard]] SDL_Renderer* GetRenderer() const;
    [[nodiscard]] bool IsValid() const;

    void Clear() const;
    void Present() const;

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    int width_;
    int height_;
};

#endif // WINDOW_H