// Graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include "Shape.h"
#include "Circle.h"
#include "array"
#include "quadtree.h"

class Graphics
{
public:
    Graphics(SDL_Renderer* renderer);
    void DrawSquare(const Shape& square);
    void initializeCircleVertices(const Shape& circle);
    void updateCirclePosition(const Shape& circle);
    void SetDrawColor(int r, int g, int b, int a) const;
    void render();
    void DrawShape(Shape& shape);
    void DrawRec(const Shape &rectangle);
    SDL_Renderer& get_rendere() { return *renderer; }



  void DrawQuadtree(const Quadtree &quadtree, int depth);





 private:
  SDL_Renderer* renderer;
  std::vector<SDL_Vertex> vertices_;
  std::vector<int> indices_;

  int num_segments = 12;
  void updatePolygonPosition(const Shape &polygon);
  void initializePolygonVertices(const Shape &polygon);


};

#endif // GRAPHICS_H