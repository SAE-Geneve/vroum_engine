//
// Created by ROG on 14.10.2024.
//

#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include "Graphics.h"
#include "Vector"
#include "circle.h"

class SolarSystem {
public:
		explicit SolarSystem(Graphics& graphics);

        // Initialiser le système solaire avec une liste de cercles
        void StartSolarSystem(std::vector<Circle>&& circles);

        // Faire tourner les cercles autour du centre de la fenêtre
        void RunSolarSystem();

private:
        Graphics graphics_;
        std::vector<float> angles_; // Angles pour chaque cercle
        std::vector<float> distances_ = { 50, 100, 150, 200, 250, 300, 350, 400 }; // Distances du centre
        std::vector<float> speeds_ = { 0.04, 0.018, 0.006, 0.014, 0.012, 0.01, 0.008, 0.006 }; // Vitesses de rotation
        std::vector<Circle> circles_; // Vecteur de cercles
};



#endif //SOLAR_SYSTEM_H
