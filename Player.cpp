#include "Player.h"

Player::Player(int _health, float _movement_speed, float _x_pos, float _y_pos,
               int _height, int _width, std::string texture_name)
    : Character(_movement_speed, _x_pos, _y_pos, _height, _width, texture_name){
      health = _health;
      };

int Player::get_health() { return health; };

void Player::set_health(int _health){
  health = _health;
};

Player::~Player() {

};