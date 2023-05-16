#include "Entity.h"


Entity::Entity(int _x_pos, int _y_pos, int _height, int _width, std::string texture_name) {
  entity_texture.loadFromFile(texture_name);
  sprite.setTexture(entity_texture);
  sprite.setPosition(Vector2f(_x_pos,_y_pos));
}

Sprite Entity::get_sprite() {
  return sprite;
}