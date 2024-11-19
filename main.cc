#include "Constants.h"
#include "Window.h"
#include "Graphics.h"
#include "Solarsystem.h"
#include "FPSCounter.h"
#include <ctime>
#include <vector>
#include <iostream>
#include "imgui.h"
#include "collider_systeme.h"
#include "collider_solary_syteme.h"
#include "collider_quadtree_systeme.h"
#include "triger_systeme.h"
#include "collider_static_systeme.h"

#ifdef TRACY_ENABLE
#include <Tracy/Tracy.hpp>
#include <tracy/TracyC.h>
#endif



int main(int argc, char* argv[]) {
  int scene = 5;
  bool restart_scene = false;
  bool isPaused = false;

#ifdef TRACY_ENABLE
  TracyCZoneN(const main, "main", true)
#endif

  Window window("Namakemono", WIDTH, HEIGHT);
  if (!window.IsValid()) {
    return -1;
  }
  Graphics graphics(window.GetRenderer());
  Solarsystem solarsystem(graphics);
  ColliderSysteme collider_systeme(graphics);
  collider_solary_syteme collider_solary_systeme(graphics);
  ColliderQuadtreeSysteme collider_quadtree_systeme(graphics);
  triger_systeme triger_systeme_(graphics);
  collider_static_systeme collider_static_systeme_(graphics);


  ImGuiInterface* imgui_interface_ = new ImGuiInterface();
  imgui_interface_->Initialize(&window);

  FPSCounter fpsCounter;

  // Main loop
  bool running = true;
  bool show_imgui = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      imgui_interface_->PassEvents(event);

      if (event.type == SDL_QUIT) {
        running = false;
      } else if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_F4 && (event.key.keysym.mod & KMOD_ALT)) {
          continue;
        }
      }
    }
    if (!isPaused) {
      graphics.SetDrawColor(0, 0, 0, 255); // Noir
      window.Clear();
    }


    // Redémarrer la scène si nécessaire
    if (restart_scene) {
      // Réinitialiser l'état de la scène en fonction de la scène actuelle
      switch (scene) {
        case 1:
          solarsystem = Solarsystem(graphics);
          break;
        case 2:
          collider_systeme = ColliderSysteme(graphics);
          break;
        case 3:
          collider_solary_systeme = collider_solary_syteme(graphics);
          break;
        case 4:
          collider_quadtree_systeme = ColliderQuadtreeSysteme(graphics);
          break;
        case 5:
          triger_systeme_ = triger_systeme(graphics);
          break;
        case 6:
          collider_static_systeme_ = collider_static_systeme(graphics);
          break;
      }
      restart_scene = false;
    }


    if (!isPaused) {
      switch (scene) {
        case 1:
          solarsystem.Update(graphics);
          break;
        case 2:
          collider_systeme.Update(graphics);
          break;
        case 3:
          collider_solary_systeme.Update(graphics);
          break;
        case 4:
          collider_quadtree_systeme.Update(graphics);
          break;
        case 5:
          triger_systeme_.Update(graphics);
          break;
        case 6:
          collider_static_systeme_.Update(graphics);
      }
      fpsCounter.Update();

    }

    imgui_interface_->Update(show_imgui, scene, restart_scene,isPaused,fpsCounter);
    imgui_interface_->Render();

    window.Present();
  }

  delete imgui_interface_;
  return 0;

#ifdef TRACY_ENABLE
  TracyCZoneEnd(main)
#endif
}


