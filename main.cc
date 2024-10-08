
// main.cpp
#include "Window.h"
#include "Graphics.h"
#include <vector>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <imgui_internal.h>

int time1 = 0;

int main(int argc, char* argv[]) {



    // Initialize Window
    Window window("SDL2 Window with Physics Square and Circle", 800, 600);
    if (!window.IsValid()) {
        return -1;
    }



    // Initialize Graphics with the window's renderer
    Graphics graphics(window.GetRenderer());

    // Create a vector to store multiple squares and circles
    std::vector<Square> squares = {
        {400, 300, 40},
        {200, 150, 50},
        {600, 450, 80},
        {300, 400, 20}
    };

    std::vector<Circle> circles = {
        {500, 300, 50},
        {100, 70, 60},
        {300, 250, 45},
        {400, 500, 30}
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

        // Set the drawing color to red and draw squares
        graphics.SetDrawColor(255, 0, 0, 255);
        for (const auto& square : squares) {
            graphics.DrawSquare(square);
        }

        // Set the drawing color to blue and draw circles
        graphics.SetDrawColor(0, 0, 255, 255);
        for (const auto& circle : circles) {
            graphics.DrawCircle(circle);
        }

        // Present the render
        window.Present();

        time1++;
    }

    return 0;
}