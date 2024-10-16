// Window.cpp
#include "Window.h"

Window::Window(const char* title, int width, int height)
    : window_(nullptr), renderer_(nullptr), width_(width), height_(height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization error: " << SDL_GetError() << std::endl;
        return;
    }

    window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window_) {
        std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cerr << "Renderer creation error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window_);
        SDL_Quit();
        return;
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

SDL_Renderer* Window::GetRenderer() const {
    return renderer_;
}

bool Window::IsValid() const {
    return window_ != nullptr && renderer_ != nullptr;
}

void Window::Clear() const {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}

void Window::Present() const {
    SDL_RenderPresent(renderer_);
}