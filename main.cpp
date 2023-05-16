#include <SFML/Graphics.hpp>

#include "Entity.h"

using namespace sf;

int main() {
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");

  // create entities here and set starting position, size and texture.
  // -- ENTITIES --
  //PLATFORMS
  Entity* platform1 = new Entity(40,600,33,70,"platform.png");

  //MEDKITS


  //BANDAGES


  //COINS


  //FINISH



  // -- CHARACTERS --







  
  

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

      
    }

    window.clear();

    // draw sprites here
    window.draw(platform1->get_sprite());

    window.display();
  }

  return 0;
}
