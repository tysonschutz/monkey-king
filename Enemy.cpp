#include "Enemy.h"

Enemy::Enemy(int _damage, float movement_speed, float x_pos, float y_pos,
             int height, int width, std::string texture_name)
    : Character(movement_speed, x_pos, y_pos, height, width, texture_name) {
      damage = _damage;
};

Enemy::~Enemy(){

};