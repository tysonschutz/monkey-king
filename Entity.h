#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
private:
  float x_pos;
  float y_pos;
  int height;
  int width;
  Sprite sprite;
  Texture entity_texture;
public:
  Entity(float x_pos, float y_pos, int height, int width, std::string texture_name);
  Sprite get_sprite();
  int get_height();
  void set_height(int height);
  int get_width();
  void set_width(int width);
  ~Entity();
};







#endif