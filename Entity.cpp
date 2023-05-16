#include "Entity.h"

Entity::Entity(float _x_pos, float _y_pos, int _height, int _width, std::string texture_name) {
  x_pos = _x_pos;
  y_pos = _y_pos;
  height = _height;
  width = _width;  
  entity_texture.loadFromFile(texture_name);
  sprite.setTexture(entity_texture);
  sprite.setPosition(Vector2f(_x_pos, _y_pos));
  sprite.setOrigin(Vector2f(height/2, width/2));
}

Sprite Entity::get_sprite() { return sprite; }

int Entity::get_height() {return height;};

void Entity::set_height(int _height) {
  height = _height;
};

int Entity::get_width() {return width;};

void Entity::set_width(int _width) {
  width = _width;
};

Entity::~Entity() {}