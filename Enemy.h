#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "Player.h"

class Enemy : public Character {
private:
  int damage;
public:
  Enemy(int damage, float movement_speed, float x_pos, float y_pos, int height, int width, std::string texture_name);
  Player damage_player(Player player, Enemy enemy);
  ~Enemy();
};

#endif