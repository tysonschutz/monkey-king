#ifndef CHARACTER
#define CHARACTER

#include "Entity.h"

class Character : public Entity {
  private:
    float movement_speed;
  public:
    Character(float movement_speed, float x_pos, float y_pos, int height, int width, std::string texture_name);
    float get_movement_speed();
    void set_movement_speed(int movement_speed);
    void move_right();
    void move_left();
    void move_down();
    void move_up();
    bool on_platform(float x_pos, float y_pos);
    ~Character();
};

#endif