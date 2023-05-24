#ifndef PLAYER
#define PLAYER

#include "Character.h"
#include "Enemy.h"

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
    // bool hit(Dart* dart);
    bool on_ladder();

    ~Player();
};

#endif 