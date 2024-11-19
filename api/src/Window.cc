#include "Window.h"

Window::Window(const char* title, int width, int height)
    : width(width), height(height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        window = nullptr;
        renderer = nullptr;
    } else {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            renderer = nullptr;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            }
        }
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Window::GetRenderer() const {
    return renderer;
}

SDL_Window* Window::GetSDLWindow() const
{
  return window;
}

bool Window::IsValid() const {
    return window != nullptr && renderer != nullptr;
}

void Window::Clear() const {
    SDL_RenderClear(renderer);
}

void Window::Present() const {
    SDL_RenderPresent(renderer);
}
