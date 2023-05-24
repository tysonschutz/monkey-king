#ifndef DART_H
#define DART_H

#include "Character.h"

class Dart : public Character {
  private:
    int damage;
  
  public:
    Dart(int damage, float movement_speed, float x_pos, float y_pos, int height, int width, std::string texture_name);
    void move_left();
    void move_right();
    void respawn_right();
    void respawn_left();
    ~Dart();

};

#endif