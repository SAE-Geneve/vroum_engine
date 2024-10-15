//
// Created by ROG on 14.10.2024.
//

#include "solar_system.h"
#include "Graphics.h"
#include "const.h"

solar_system::solar_system() {}

void solar_system::StartSolarSystem(std::vector<Circle> circles)
{
    this->circle = circles;
}

void solar_system::RunSolarSystem(std::vector<Circle> circles)
{

    for (size_t i = 0; i < circles.size(); ++i) {
        int x = CENTER_X + static_cast<int>(solar_system().distances[i] * cos(solar_system().angles[i]));
        int y = CENTER_Y + static_cast<int>(solar_system().distances[i] * sin(solar_system().angles[i]));
        circles[i].SetPosition(x, y);
        solar_system().graphics_.SetDrawColor(circles[i].r, circles[i].g, circles[i].b, 255);
        solar_system().graphics_.DrawCircle(circles[i]);

        // Update angle for next frame
        solar_system().angles[i] += solar_system().speeds[i];
        if (solar_system().angles[i] >= 2 * PI) {
            solar_system().angles[i] -= 2 * PI; // Keep angle within 0 to 2*PI
        }
    }
}