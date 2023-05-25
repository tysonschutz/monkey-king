#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Dart.h"

class Dart;

class Player : public Character {
  private:
    int health;
  public:
    Player(int _health, float _movement_speed, float _x_pos, float _y_pos,
                     int _height, int _width, std::string texture_name);
    int get_health();
    void set_health(int health);
    
    bool on_coin();
    bool on_finish();
    bool hit(Dart* dart);
    bool on_ladder();
    bool on_platform1();
    bool on_platform2();
    bool on_platform3();
    void jump();

    ~Player();
};

#endif 