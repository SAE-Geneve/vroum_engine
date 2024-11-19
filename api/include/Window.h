#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <iostream>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    SDL_Renderer* GetRenderer() const;
    SDL_Window* GetSDLWindow() const;
    bool IsValid() const;

    void Clear() const;
    void Present() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width, height;

};

#endif // WINDOW_H
