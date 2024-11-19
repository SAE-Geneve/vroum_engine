
#ifndef GAMEENGINE_API_INCLUDE_QUADTREE_H_
#define GAMEENGINE_API_INCLUDE_QUADTREE_H_


#include <vector>
#include <memory>
#include "SDL_render.h"
#include "vec2.h"
#include "Constants.h"
#include "Shape.h"

class Quadtree{

 public:
  Quadtree(std::vector<Shape> shapes):shapes_(shapes){
    min_bound_.x = 0;
    min_bound_.y = 0;
    max_bound_.x = WIDTH;
    max_bound_.y = HEIGHT;
    CountShape(shapes_);
    current_shapes_.reserve(shapes_.size());
  };
  Quadtree(Vec2<float> pos, float size_x, float size_y,std::vector<Shape> shapes): pos_(pos), size_x_(size_x),size_y_(size_y),shapes_(shapes){
    min_bound_.x = pos.x - size_x / 2;
    min_bound_.y = pos.y - size_y / 2;
    max_bound_.x = pos.x + size_x / 2;
    max_bound_.y = pos.y + size_y / 2;
    CountShape(shapes_);
  }


  void AddChild(Quadtree* child);

  std::vector<Quadtree*> children_;

  Vec2<float> get_position() const { return pos_; }
  float get_size_x() const { return size_x_; }
  float get_size_y() const { return size_y_; }
  void CountShape(std::vector<Shape> shape);
  bool Contains(Vec2<float> position) const;
  void AddShape(Shape &shape);
  void Retrieve(std::vector<Shape *> &returnShapes);
  bool last_child_ = true;
  std::vector<Shape> current_shapes_;
  std::vector<Shape> shapes_;

 private:
  Vec2<float> pos_ = Vec2<float>(CENTER_X,CENTER_Y);


  float size_x_ = WIDTH;
  float size_y_ = HEIGHT;
  std::vector<Shape*> shapes_1;

  Vec2<float>min_bound_= Vec2<float>(0,0);
  Vec2<float>max_bound_= Vec2<float>(0,0);


  void Divide();
  void Divide_1();


};




#endif //GAMEENGINE_API_INCLUDE_QUADTREE_H_
