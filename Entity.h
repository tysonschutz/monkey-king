#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>

using namespace sf;

class Entity {
private:
  int x_pos;
  int y_pos;
  int height;
  int width;
  Sprite sprite;
  Texture entity_texture;
public:
  Entity(int x_pos, int y_pos, int height, int width, std::string texture_name);
  Sprite get_sprite();
  

  

};







#endif