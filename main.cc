
// main.cpp
#include "Window.h"
#include "Graphics.h"
#include <vector>

int time1 = 0;

int main(int argc, char* argv[]) {
    // Initialize Window
    Window window("SDL2 Window with Physics Square", 800, 600);
    if (!window.IsValid()) {
        return -1;
    }

    // Initialize Graphics with the window's renderer
    Graphics graphics(window.GetRenderer());

    // Create a vector to store multiple squares
    std::vector<Square> squares = {
        {400, 300, 40},
        {200, 150, 40},
        {600, 450, 40},
        {300, 400, 40}
    };

    Uint32 lastTime = SDL_GetTicks(); // Start time of the main loop
    Uint32 currentTime, deltaTime;

    // Main loop
    bool running = true;
    SDL_Event event;
    while (running) {
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Convert deltaTime to seconds
        float deltaTimeSec = deltaTime / 1000.0f;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen
        window.Clear();

        // Set the drawing color to red
        graphics.SetDrawColor(255, 0, 0, 255);

        // Draw each square
        for (const auto& square : squares) {
            graphics.DrawSquare(square);
        }

        // Present the render
        window.Present();

        time1++;
    }

    return 0;
}