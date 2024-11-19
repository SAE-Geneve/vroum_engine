#include <imgui.h>
#include "Graphics.h"


void ImGuiInterface::Initialize(Window* window)
{
  //Setup ImGUI context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;


  ImGui_ImplSDL2_InitForSDLRenderer(window->GetSDLWindow() ,window->GetRenderer());
  ImGui_ImplSDLRenderer2_Init(window->GetRenderer());
}
void ImGuiInterface::Update(bool& show_imgui, int& scene, bool& restart_scene, bool& isPaused, FPSCounter& fpsCounter)
{
  // Start new ImGui frame
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  if (show_imgui) {
    ImGui::ShowDemoWindow();

    // Positionner la fenêtre "Scene Selector" à un endroit spécifique
    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver); // Position (10, 10)
    ImGui::Begin("Scene Selector");

    if (ImGui::RadioButton("Solarsystem", scene == 1)) { scene = 1; }
    if (ImGui::RadioButton("Collider Systeme", scene == 2)) { scene = 2; }
    if (ImGui::RadioButton("Collider Solary Systeme", scene == 3)) { scene = 3; }
    if (ImGui::RadioButton("Collider Quadtree Systeme", scene == 4)) { scene = 4; }
    if (ImGui::RadioButton("Triger Systeme", scene == 5)) { scene = 5; }
    if (ImGui::RadioButton("Collider static", scene == 6)) { scene = 6; }

    ImGui::End();

    // Positionner la fenêtre "Restart Scene" à un autre endroit
    ImGui::SetNextWindowPos(ImVec2(300, 10), ImGuiCond_FirstUseEver); // Position (300, 10)
    ImGui::Begin("Restart Scene");

    if (ImGui::Button("Restart Current Scene")) {
      restart_scene = true;
    }

    // Ajouter un bouton "Pause/Resume" dans la même fenêtre
    if (ImGui::Button(isPaused ? "Resume" : "Pause")) {
      isPaused = !isPaused; // Alterner l'état de la pause
    }

    ImGui::End();

    // Positionner la fenêtre "FPS Counter" à un autre endroit
    ImGui::SetNextWindowPos(ImVec2(10, 100), ImGuiCond_FirstUseEver); // Position (10, 100)
    ImGui::Begin("FPS Counter");

    // Afficher le FPS
    ImGui::Text("FPS: %.1f", fpsCounter.GetFPS());

    ImGui::End();
  }

  // Render ImGui
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}






void ImGuiInterface::Render()
{
  // Render ImGui on top of SDL renderer
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiInterface::PassEvents(SDL_Event& event)
{
  ImGui_ImplSDL2_ProcessEvent(&event);
}

ImGuiInterface::~ImGuiInterface()
{
  // Cleanup ImGui
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
}