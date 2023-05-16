#include <SFML/Graphics.hpp>

#include "Entity.h"

using namespace sf;

int main() {
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");

  // create sprites here and set starting position, size and texture.
  Entity mario(500,800,30,40,"mario_right.png");
  
  
  

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

      if (Keyboard::isKeyPressed(Keyboard::Right)) {
        
      } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        
      }
    }

    window.clear();

    // draw sprites here
    window.draw(mario.get_sprite());

    window.display();
  }

  return 0;
}
