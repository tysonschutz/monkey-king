#include "Character.h"

Character::Character(float _movement_speed, float _x_pos, float _y_pos,
                     int _height, int _width, std::string texture_name)
    : Entity(_x_pos, _y_pos, _height, _width, texture_name) {
  movement_speed = _movement_speed;
};

float Character::get_movement_speed() {return movement_speed;};

void Character::set_movement_speed(int _movement_speed) {
  movement_speed = _movement_speed;
};
void Character::move_right() {
  sprite.move(movement_speed,0);
};
void Character::move_left() {
  sprite.move(-movement_speed,0);
};
void Character::move_down() {
  sprite.move(0,movement_speed);
};
void Character::move_up() {
  sprite.move(0,-movement_speed);
};
Character::~Character() {

};