#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
  
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");
  
  // run the program as long as the window is open
  while (window.isOpen()) {
    
    // check all the window's events that were triggered since the last iteration of the loop
    Event event;
    while (window.pollEvent(event)) {
      
      // "close requested" event: we close the window
      if (event.type == Event::Closed) window.close();
    }

    window.clear();
    window.display();
    
  }

  return 0;
}
