#ifndef CHARACTER.H
#define CHARACTER.H

#include "Entity.h"

class Character : protected Entity {
  private:
    int movement_speed;


  public:
    Character(int movement_speed);


};

#endif