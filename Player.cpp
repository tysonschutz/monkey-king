#include "Player.h"

Player::Player(int _health, float _movement_speed, float _x_pos, float _y_pos,
               int _height, int _width, std::string texture_name)
    : Character(_movement_speed, _x_pos, _y_pos, _height, _width,
                texture_name) {
  health = _health;
};

int Player::get_health() { return health; };

void Player::set_health(int _health) { health = _health; };

// finish implementing logic
bool Player::on_coin(Player player, Entity coin) {
  if ((player.get_x_pos() == coin.get_x_pos()) ) {

  }
};

bool Player::on_finish(Player player, Entity finish) {

};

bool Player::on_medkit(Player player, Entity medkit) {

};

bool Player::on_bandage(Player player, Entity bandage) {

};

// until here


Player::~Player(){

};