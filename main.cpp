#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Entity.h"
#include "Player.h"

using namespace sf;

int main() {
  const float fps = 60.0f;

  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");
  window.setFramerateLimit(fps);

  // For when characters change direction or rotate


  // create entities here and set starting position, size and texture.
  // -- ENTITIES --
  // PLATFORMS - create 4 platforms
  

  // MEDKITS - create 1 medkit

  // BANDAGES - create 2 bandages

  // COINS - 5 coins (1 2nd platform, 2 3rd and 4th platform)

  // FINISH - create 1 finish

  // DART SHOOTER ENTITIES (no. changes depending on each level. 6 total)

  // -- CHARACTERS --
 
  // -- Player -- (1 player)
  Player* player = new Player(100, 3, 40, 560, 40, 30, "mario_right.png");

  // -- Enemy -- 
  // DARTS (6 Total)


  // BOULDERS (8 Total) 



  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == Event::Closed) {
        window.close();
      }
      
      // movement and logic
      switch (event.key.code) {
        case Keyboard::D:

        
          
        case Keyboard::A:
          
        case Keyboard::W:
          
        case Keyboard::S:      
          
        default:
          break;
      }
    }

    window.clear();

    // draw sprites here
    
    window.draw(player->get_sprite());
    window.display();
  }

  // delete memory used by objects
  delete player;

  return 0;
}
