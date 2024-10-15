//
// Created by ROG on 14.10.2024.
//

#include "solar_system.h"
#include "Graphics.h"
#include "const.h"

// Constructeur
solar_system::solar_system(Graphics& graphics) : graphics_(graphics) {}

// Initialiser le système solaire avec une liste de cercles
void solar_system::StartSolarSystem(const std::vector<Circle>& circles) {
    this->circles = circles;
    angles.resize(circles.size(), 0.0); // Assurez-vous que les angles sont initialisés
}

// Faire tourner les cercles autour du centre de la fenêtre
void solar_system::RunSolarSystem() {
    for (size_t i = 0; i < circles.size(); ++i) {
        // Mise à jour de l'angle pour le cercle
        angles[i%8] += speeds[i%8]; // Incrémente l'angle basé sur la vitesse
        if (angles[i%8] >= 360.0) {
            angles[i%8] -= 360.0; // Réinitialiser l'angle si nécessaire
        }

        // Calculer la nouvelle position du cercle
        int x = static_cast<int>(CENTER_X + distances[i] * cos(angles[i%8] * PI / 180.0));
        int y = static_cast<int>(CENTER_Y + distances[i] * sin(angles[i%8] * PI / 180.0));

        // Mettre à jour la position du cercle
        circles[i].SetX(x);
        circles[i].SetY(y);

        // Dessiner le cercle
        graphics_.DrawCircle(circles[i]); // Vous devrez implémenter cette méthode dans Graphics
    }
}