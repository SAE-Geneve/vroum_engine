#ifndef SQUARE_H
#define SQUARE_H

#include "Body.h"
#include "Random.h"
#include "Constants.h"
enum type_enum
    {
  KDefault,
  KCirle,
  KSquare,
  KPolygon,
  KRectangle

};

class Shape
{
 public:
  Shape(int size, Body body,type_enum Type)
      : size_(size), body_(body),type_(Type), color_(MassToColor(body_.mass(),MIN_MASS,MAX_MASS)) {
    min_bound_.x = body.position().x-size/2;
    min_bound_.y = body.position().y-size/2;
    max_bound_.x = body.position().x+size/2;
    max_bound_.y = body.position().y+size/2;
  }

  Shape(int size,int sizeY, Body body)
      : size_(size), size_y_(sizeY), body_(body), type_(KRectangle) {
    min_bound_.x = body.position().x-size/2;
    min_bound_.y = body.position().y-sizeY/2;
    max_bound_.x = body.position().x+size/2;
    max_bound_.y = body.position().y+sizeY/2;
  }


  Body& getBody() { return body_; }
  int size() const { return size_; }
  int sizeY() const { return size_y_; }
  int sides() const { return num_sides_; }
  void setSize(int newRadius) { size_ = newRadius; }
  void setSides(int newsides) { num_sides_ = newsides; }
  bool GetInit() const { return init; }
  void IsInit()  { init = true;}
  bool Gettriger() const { return trigeur; }
  void Istrigger()  { trigeur = true;}
  void Isnottrigger()  { trigeur = false;}
  type_enum GetType() const {return type_;}
  SDL_Color getcolor() const { return color_; }
  void setcolor(SDL_Color newcolor) { color_ = newcolor; }
  Body body_;
  bool isStatic() const { return is_static_; }
  void setStatic(bool isStatic) { is_static_ = isStatic; }
  [[nodiscard]] constexpr Vec2<float> min_bound() const { return min_bound_; }
  [[nodiscard]] constexpr Vec2<float> max_bound() const { return max_bound_; }

  [[nodiscard]] constexpr bool Contains(const Vec2<float> point) const
  {
    if (type_ == KSquare || type_ == KRectangle)
    {
      if (point.x < min_bound_.x) return false;
      if (point.x > max_bound_.x) return false;
      if (point.y < min_bound_.y) return false;
      if (point.y > max_bound_.y) return false;
      return true;
    }
    if (type_ == KCirle)
    {
      return (point - body_.position()).SquaredMagnitude() <= size_ * size_;
    } else
    {
      return false;
    }
  }


 private:
  int size_;
  int size_y_;
  type_enum type_;
  SDL_Color color_;
  bool init = false;
  bool trigeur = false;
  bool is_static_ = false;
  int num_sides_ = 3;
  Vec2<float>min_bound_= Vec2<float>(0,0);
  Vec2<float>max_bound_= Vec2<float>(0,0);

  SDL_Color MassToColor(float mass, float min_mass, float max_mass) {
    mass = std::clamp(mass, min_mass, max_mass);
    float normalized_mass = (mass - min_mass) / (max_mass - min_mass);

    int r = static_cast<int>(normalized_mass * 255);
    int g = 0;
    int b = static_cast<int>((1 - normalized_mass) * 255);

    return SDL_Color(r, g, b,255);
  }




};

#endif // SQUARE_H
