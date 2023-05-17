#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
protected:
  float x_pos;
  float y_pos;
  int height;
  int width;
  Sprite sprite;
  Texture entity_texture;
public:
  Entity(float x_pos, float y_pos, int height, int width, std::string texture_name);
  Sprite get_sprite();
  float get_x_pos();
  void set_x_pos(float x_pos);
  float get_y_pos();
  void set_y_pos(float y_pos);
  int get_height();
  void set_height(int height);
  int get_width();
  void set_width(int width);
  ~Entity();
};

#endif