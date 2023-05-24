#include "Player.h"
#include <iostream>
#include "Dart.h"
#include "Enemy.h"

Player::Player(int _health, float _movement_speed, float _x_pos, float _y_pos,
               int _height, int _width, std::string texture_name)
    : Character(_movement_speed, _x_pos, _y_pos, _height, _width,
                texture_name) {
  health = _health;
};

int Player::get_health() { return health; };

void Player::set_health(int _health) { health = _health; };

bool Player::on_coin() {
  if (((sprite.getPosition().x > 1252) && ((sprite.getPosition().x < 1348)) && ((sprite.getPosition().y <= 967) && (sprite.getPosition().y >= 717)))) {
    return true;
  } else if (((sprite.getPosition().x > 152) && (sprite.getPosition().x < 248)) && ((sprite.getPosition().y <= 717) && (sprite.getPosition().y >= 467))) {
    return true;
  } else if (((sprite.getPosition().x > 1152) && (sprite.getPosition().x < 1248)) && ((sprite.getPosition().y <= 467) && (sprite.getPosition().y >= 217))) {
    return true;
  } else if (((sprite.getPosition().x > 1152) && (sprite.getPosition().x < 1248)) && ((sprite.getPosition().y <= 467) && (sprite.getPosition().y >= 217))) {
    return true;
  } else if (((sprite.getPosition().x > 1152) && (sprite.getPosition().x < 1248)) && ((sprite.getPosition().y <= 467) && (sprite.getPosition().y >= 217))) {
    return true;
  }
  return false;
};

bool Player::on_finish() {
  if (((sprite.getPosition().x > 1252) && ((sprite.getPosition().x < 1348)) && ((sprite.getPosition().y <= 967) && (sprite.getPosition().y >= 717)))) {
    return true;
  }
  return false;
};

// bool Player::hit(Dart* dart) {
//   if (((sprite.getPosition().x == dart->get_sprite().getPosition().x) && (((sprite.getPosition().y + 80) == dart->get_sprite().getPosition().y)))) {
//     return true;
//   }
// };

bool Player::on_ladder() {
  if (((sprite.getPosition().x > 1252) && ((sprite.getPosition().x < 1348)) && ((sprite.getPosition().y <= 967) && (sprite.getPosition().y >= 717)))) {
    return true;
  } else if (((sprite.getPosition().x > 152) && (sprite.getPosition().x < 248)) && ((sprite.getPosition().y <= 717) && (sprite.getPosition().y >= 467))) {
    return true;
  } else if (((sprite.getPosition().x > 1152) && (sprite.getPosition().x < 1248)) && ((sprite.getPosition().y <= 467) && (sprite.getPosition().y >= 217))) {
    return true;
  }
  return false;
}


Player::~Player(){

};