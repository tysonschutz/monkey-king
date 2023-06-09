#include "Dart.h"

Dart::Dart(int _damage, float movement_speed, float x_pos, float y_pos, int height, int width, std::string texture_name) : Character(movement_speed, x_pos, y_pos, height, width, texture_name) {
  damage = _damage;
};
void Dart::move_left() {
  sprite.move(Vector2f(-get_movement_speed(),0));
};

void Dart::move_right() {
  sprite.move(Vector2f(get_movement_speed(),0));
};

void Dart::respawn_right() {
    sprite.move(Vector2f(1500,0));
}

void Dart::respawn_left() {
    sprite.move(Vector2f(-1500,0));
}

Dart::~Dart() {};