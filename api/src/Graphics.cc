#include "Graphics.h"
#include <vector>
#include <cstdlib>
#include "Constants.h"
#include "Random.h"
#include "quadtree.h"

#ifdef TRACY_ENABLE
#include <Tracy/Tracy.hpp>
#include <tracy/TracyC.h>
#endif

Graphics::Graphics(SDL_Renderer* renderer) : renderer(renderer) {}

void Graphics::initializeCircleVertices(const Shape& circle) {
  float angle_step = 2.0f * PI / num_segments;
  float centerX = circle.body_.getX();
  float centerY = circle.body_.getY();
  float radius = circle.size();

  // Réinitialise les vecteurs de vertices et d'indices
  vertices_.clear();
  indices_.clear();

  // Ajoute le centre du cercle
  vertices_.push_back({ {centerX, centerY}, circle.getcolor(), {0, 0} });

  for (int i = 0; i <= num_segments; ++i) {
    float angle = i * angle_step;
    float x = centerX + radius * cosf(angle);
    float y = centerY + radius * sinf(angle);
    vertices_.push_back({ {x, y}, circle.getcolor(), {0, 0} });
  }

  // Génère les indices
  for (int i = 0; i < num_segments; ++i) {
    indices_.push_back(0);
    indices_.push_back(i + 1);
    indices_.push_back(i + 2);
  }
  // Connecte le dernier segment au premier point du cercle
  indices_.back() = 1;
}

void Graphics::initializePolygonVertices(const Shape& polygon) {
  int num_sides = polygon.sides();
  if (num_sides < 3) return; // Un polygone doit avoir au moins 3 côtés

  float angle_step = 2.0f * PI / num_sides;
  float centerX = polygon.body_.getX();
  float centerY = polygon.body_.getY();
  float radius = polygon.size();

  // Réinitialise les vecteurs de vertices et d'indices
  vertices_.clear();
  indices_.clear();

  // Ajoute le centre du polygone
  vertices_.push_back({ {centerX, centerY}, polygon.getcolor(), {0, 0} });

  // Initialise les sommets du polygone
  for (int i = 0; i <= num_sides; ++i) {
    float angle = i * angle_step;
    float x = centerX + radius * cosf(angle);
    float y = centerY + radius * sinf(angle);
    vertices_.push_back({ {x, y}, polygon.getcolor(), {0, 0} });
  }

  // Génère les indices pour les triangles
  for (int i = 0; i < num_sides; ++i) {
    indices_.push_back(0);
    indices_.push_back(i + 1);
    indices_.push_back(i + 2);
  }
  // Connecte le dernier segment au premier point du polygone
  indices_.back() = 1;
}

void Graphics::updateCirclePosition(const Shape& circle) {
  float centerX = circle.body_.getX();
  float centerY = circle.body_.getY();
  float radius = circle.size();
  float angle_step = 2.0f * PI / num_segments;

  // Récupérer la couleur du cercle
  SDL_Color color = circle.getcolor();

  // Met à jour le centre du cercle
  vertices_[0].position.x = centerX;
  vertices_[0].position.y = centerY;

  // Met à jour les sommets du cercle
  for (int i = 0; i <= num_segments; ++i) {
    float angle = i * angle_step;
    float x = centerX + radius * cosf(angle);
    float y = centerY + radius * sinf(angle);
    vertices_[i + 1].position.x = x;
    vertices_[i + 1].position.y = y;

    // Met à jour la couleur de chaque sommet du cercle
    vertices_[i + 1].color = color;
  }
}

void Graphics::updatePolygonPosition(const Shape& polygon) {
  int num_sides = polygon.sides();
  if (num_sides < 3) return;

  float centerX = polygon.body_.getX();
  float centerY = polygon.body_.getY();
  float radius = polygon.size();
  float angle_step = 2.0f * PI / num_sides;

  // Met à jour le centre du polygone
  vertices_[0].position.x = centerX;
  vertices_[0].position.y = centerY;

  // Met à jour les sommets du polygone
  for (int i = 0; i <= num_sides; ++i) {
    float angle = i * angle_step;
    float x = centerX + radius * cosf(angle);
    float y = centerY + radius * sinf(angle);
    vertices_[i + 1].position.x = x;
    vertices_[i + 1].position.y = y;
  }
}

void Graphics::render() {
  SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
  if (SDL_RenderGeometry(renderer, nullptr,
                         vertices_.data(), static_cast<int>(vertices_.size()),
                         indices_.data(), static_cast<int>(indices_.size()))) {
    SDL_Log("%s\n", SDL_GetError());
  }
}

void Graphics::DrawSquare(const Shape& square) {
  SDL_Color color = square.getcolor();
  SDL_Rect rect;
  rect.x = square.body_.getX() - square.size() / 2;
  rect.y = square.body_.getY() - square.size() / 2;
  rect.w = square.size();
  rect.h = square.size();
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}

void Graphics::DrawQuadtree(const Quadtree& quadtree, int depth)
{

  SDL_Rect rect;
  rect.x = quadtree.get_position().x - quadtree.get_size_x() / 2;
  rect.y = quadtree.get_position().y - quadtree.get_size_y() / 2;
  rect.w = quadtree.get_size_x();
  rect.h = quadtree.get_size_y();

  int colorValue = 255 - (depth * 40);
  if (colorValue < 0) colorValue = 0;

  SDL_SetRenderDrawColor(renderer, colorValue, 0, 255 - colorValue, 255);
  SDL_RenderDrawRect(renderer, &rect);

  if (quadtree.last_child_)
  {
    for (Shape shape : quadtree.current_shapes_) {
      DrawShape(shape);
    }
  }

  for (auto& child : quadtree.children_)
  {
    DrawQuadtree(*child, depth + 1);
  }
}


void Graphics::DrawRec(const Shape& rectangle) {
  SDL_Rect rect;
  rect.x = rectangle.body_.getX() - rectangle.size() / 2;
  rect.y = rectangle.body_.getY() - rectangle.sizeY() / 2;
  rect.w = rectangle.size();
  rect.h = rectangle.sizeY();
  SDL_SetRenderDrawColor(renderer, rectangle.getcolor().r, rectangle.getcolor().g, rectangle.getcolor().b, rectangle.getcolor().a);
  SDL_RenderFillRect(renderer, &rect);
}

void Graphics::DrawShape(Shape& shape) {
  switch (shape.GetType()) {
    case KSquare:
      DrawSquare(shape);
      break;
    case KCirle:
      if (!shape.GetInit()) {
        initializeCircleVertices(shape);
        shape.IsInit();
      }
      updateCirclePosition(shape);
      render();
      break;
    case KPolygon:
      if (!shape.GetInit()) {
        initializePolygonVertices(shape);
        shape.IsInit();
      }
      updatePolygonPosition(shape);
      render();
      break;
    case KRectangle:
      DrawRec(shape);
      break;


  }
}

void Graphics::SetDrawColor(int r, int g, int b, int a) const {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}
