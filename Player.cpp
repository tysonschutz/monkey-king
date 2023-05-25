#include "Player.h"

#include <iostream>

#include "Dart.h"

class Dart;

Player::Player(int _health, float _movement_speed, float _x_pos, float _y_pos,
               int _height, int _width, std::string texture_name)
    : Character(_movement_speed, _x_pos, _y_pos, _height, _width,
                texture_name) {
  health = _health;
};

int Player::get_health() { return health; };

void Player::set_health(int _health) { health = _health; };

bool Player::on_coin() {
  if (((sprite.getPosition().x > 335) && ((sprite.getPosition().x < 365)) &&
       ((sprite.getPosition().y <= 757) && (sprite.getPosition().y >= 717)))) {
    return true;
  } else if (((sprite.getPosition().x > 185) &&
              (sprite.getPosition().x < 215)) &&
             ((sprite.getPosition().y <= 507) &&
              (sprite.getPosition().y >= 467))) {
    return true;
  } else if (((sprite.getPosition().x > 935) &&
              (sprite.getPosition().x < 965)) &&
             ((sprite.getPosition().y <= 507) &&
              (sprite.getPosition().y >= 467))) {
    return true;
  } else if (((sprite.getPosition().x > 985) &&
              (sprite.getPosition().x < 1015)) &&
             ((sprite.getPosition().y <= 257) &&
              (sprite.getPosition().y >= 217))) {
    return true;
  } else if (((sprite.getPosition().x > 335) &&
              (sprite.getPosition().x < 365)) &&
             ((sprite.getPosition().y <= 257) &&
              (sprite.getPosition().y >= 217))) {
    return true;
  }
  return false;
};

bool Player::on_finish() {
  if (((sprite.getPosition().x > 40) && ((sprite.getPosition().x < 160)) &&
       ((sprite.getPosition().y <= 217) && (sprite.getPosition().y >= 110)))) {
    return true;
  }
  return false;
};

bool Player::hit(Dart* dart) {
  if (((dart->get_sprite().getPosition().x >= (sprite.getPosition().x - 30)) &&
       (dart->get_sprite().getPosition().x <= (sprite.getPosition().x + 30))) &&
      ((dart->get_sprite().getPosition().y >= (sprite.getPosition().y - 80)) &&
       (dart->get_sprite().getPosition().y <= (sprite.getPosition().y)))) {
    return true;
  }
  return false;
};

bool Player::on_ladder() {
  if (((sprite.getPosition().x > 1252) && ((sprite.getPosition().x < 1348)) &&
       ((sprite.getPosition().y <= 967) && (sprite.getPosition().y >= 700)))) {
    return true;
  } else if (((sprite.getPosition().x > 152) &&
              (sprite.getPosition().x < 248)) &&
             ((sprite.getPosition().y <= 717) &&
              (sprite.getPosition().y >= 457))) {
    return true;
  } else if (((sprite.getPosition().x > 1152) &&
              (sprite.getPosition().x < 1248)) &&
             ((sprite.getPosition().y <= 467) &&
              (sprite.getPosition().y >= 207))) {
    return true;
  }
  return false;
};

bool Player::on_platform1() {
  if (sprite.getPosition().y == 967) {
    return true;
  }
  
  
  return false;
}

bool Player::on_platform2() {if (sprite.getPosition().y == 717) {
    return true;
  }
  return false;
  }
  


bool Player::on_platform3() {
  if (sprite.getPosition().y == 467) {
    return true;
  }
  return false;
}


void Player::jump() {
  // upward movement
  sprite.move(0,-40);
  sprite.move(0,-30);
  sprite.move(0,-20);
  sprite.move(0,-10);
  // downward movement
  sprite.move(0,10);
  sprite.move(0,20);
  sprite.move(0,30);
  sprite.move(0,40);
}


Player::~Player(){

};