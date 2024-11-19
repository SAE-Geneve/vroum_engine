

#include "quadtree.h"

void Quadtree::Divide()
{
  // Si le quadtree n'a pas assez de formes, ne divise pas
  if (current_shapes_.size() <= QUAD_DIV) {
    return;  // Ne divise que si le nombre de formes dépasse 2
  }

  // Crée les enfants avec leurs propres limites
  Quadtree* child1 = new Quadtree(Vec2<float>(min_bound_.x + size_x_ / 4, min_bound_.y + size_y_ / 4), size_x_ / 2, size_y_ / 2, current_shapes_);
  Quadtree* child2 = new Quadtree(Vec2<float>(min_bound_.x + size_x_ / 4, max_bound_.y - size_y_ / 4), size_x_ / 2, size_y_ / 2, current_shapes_);
  Quadtree* child3 = new Quadtree(Vec2<float>(max_bound_.x - size_x_ / 4, max_bound_.y - size_y_ / 4), size_x_ / 2, size_y_ / 2, current_shapes_);
  Quadtree* child4 = new Quadtree(Vec2<float>(max_bound_.x - size_x_ / 4, min_bound_.y + size_y_ / 4), size_x_ / 2, size_y_ / 2, current_shapes_);

  // Ajoute les enfants au parent
  AddChild(child1);
  AddChild(child2);
  AddChild(child3);
  AddChild(child4);

  // Répartir les formes dans les enfants
  for (auto& shape : current_shapes_) {
    if (child1->Contains(shape.getBody().position())) child1->AddShape(shape);
    if (child2->Contains(shape.getBody().position())) child2->AddShape(shape);
    if (child3->Contains(shape.getBody().position())) child3->AddShape(shape);
    if (child4->Contains(shape.getBody().position())) child4->AddShape(shape);
  }
}

void Quadtree::Retrieve(std::vector<Shape*>& returnShapes){

  for ( auto& s : current_shapes_) {
    returnShapes.push_back(&s);
  }

  for (const auto& child : children_) {
    child->Retrieve(returnShapes);
  }
}

void Quadtree::AddShape(Shape& shape)
{
  current_shapes_.push_back(shape);
}

void Quadtree::AddChild(Quadtree* child)
{
  children_.push_back(child);
  last_child_= false;
}

void Quadtree::CountShape(std::vector<Shape> shape)
{
  for (int i = 0; i < shape.size(); i++) {
    if (Contains(shape[i].getBody().position())) {
      current_shapes_.push_back(shape[i]);
    }
  }
  if (shapes_.size()>QUAD_DIV){Divide();}
}



bool Quadtree::Contains(Vec2<float> position) const
{
  return position.x >= min_bound_.x && position.x <= max_bound_.x &&
      position.y >= min_bound_.y && position.y <= max_bound_.y;
}