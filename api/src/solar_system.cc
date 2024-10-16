//
// Created by ROG on 14.10.2024.
//

#include "solar_system.h"
#include "Graphics.h"
#include "const.h"

// Constructeur
SolarSystem::SolarSystem(Graphics& graphics) : graphics_(graphics) {}

// Initialiser le système solaire avec une liste de cercles
void SolarSystem::StartSolarSystem( std::vector<Circle>&& circles) {
    this->circles_ = std::move(circles);
    angles_.resize(this->circles_.size(), 0.0); // Assurez-vous que les angles sont initialisés
}

// Faire tourner les cercles autour du centre de la fenêtre
void SolarSystem::RunSolarSystem() {
    for (size_t i = 0; i < circles_.size(); ++i) {
        // Mise à jour de l'angle pour le cercle
        angles_[i%8] += speeds_[i%8]; // Incrémente l'angle basé sur la vitesse
        if (angles_[i%8] >= 360.0) {
            angles_[i%8] -= 360.0; // Réinitialiser l'angle si nécessaire
        }

        // Calculer la nouvelle position du cercle
        int x = static_cast<int>(CENTER_X + distances_[i] * std::cos(angles_[i%8] * PI / 180.0));
        int y = static_cast<int>(CENTER_Y + distances_[i] * std::sin(angles_[i%8] * PI / 180.0));

        // Mettre à jour la position du cercle
        circles_[i].SetX(x);
        circles_[i].SetY(y);

        // Dessiner le cercle
        graphics_.DrawCircle(circles_[i]); // Vous devrez implémenter cette méthode dans Graphics
    }
}