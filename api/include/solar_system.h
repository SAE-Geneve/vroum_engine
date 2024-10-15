//
// Created by ROG on 14.10.2024.
//

#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "Graphics.h"
#include "Vector"
#include "circle.h"


class solar_system {




public:
        solar_system();
        Graphics graphics_;
        std::vector<double> angles = std::vector<double>(8, 0.0); // Angles initiaux pour chaque cercles
        std::vector<double> distances = { 50, 100, 150, 200, 250, 300, 350, 400 }; // Distances du centre
        std::vector<double> speeds = { 8.02, 0.018, 0.016, 0.014, 0.012, 0.01, 0.008, 0.006 }; // Vitesses de rotat
        std::vector<Circle> circle;


        void StartSolarSystem(std::vector<Circle> circles);
        void RunSolarSystem(std::vector<Circle> circles);
};



#endif //SOLAR_SYSTEM_H
