#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Entity.h"
#include "Player.h"

using namespace sf;





int main() {
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");
  
  // create entities here and set starting position, size and texture.
  // -- ENTITIES --
  // PLATFORMS - create 5 platforms
  Entity* platform1 = new Entity(750, 1000, 33, 1400, "rockPlatform.png"); // position set
  Entity* platform2 = new Entity(750, 750, 33, 1400, "rockPlatform.png"); // position set
  Entity* platform3 = new Entity(750, 500, 33, 1400, "rockPlatform.png"); // position set
  Entity* platform4 = new Entity(750, 250, 33, 1400, "rockPlatform.png"); // position set
  
  // MEDKITS - create 1 medkit
  Entity* medkit = new Entity(750, 467, 50, 50, "medkit.png"); // position set

  // BANDAGES - create 2 bandages
  Entity* bandage1 = new Entity(750, 717, 45, 80, "bandages.png"); // position set
  Entity* bandage2 = new Entity(750, 217, 45, 80, "bandages.png"); // position set

  // COINS - 5 coins (changes each platform)
  Entity* coin1 = new Entity(350, 717, 40, 29, "coin.png"); // position set
  Entity* coin2 = new Entity(200, 467, 40, 29, "coin.png"); // position set
  Entity* coin3 = new Entity(950, 467, 40, 29, "coin.png"); // position set
  Entity* coin4 = new Entity(1000, 217, 40, 29, "coin.png"); // position set
  Entity* coin5 = new Entity(350, 217, 40, 29, "coin.png"); // position set

  // FINISH - create 1 finish
  Entity* finish = new Entity(100, 217, 107, 120, "finishFlag.png"); // position set

  // VINES - creat 3 total
  Entity* ladder1 = new Entity(1300, 967, 250, 96, "ladder.png"); // position set
  Entity* ladder2 = new Entity(200, 717, 250, 96, "ladder.png"); // position set
  Entity* ladder3 = new Entity(1200, 467, 250, 96, "ladder.png"); // position set

  // -- CHARACTERS --
  // Player - 1 player
  Player* player = new Player(100, 3, 100, 967, 80, 60, "mario_right.png"); // position set

  // -- Enemy --
  // DARTS - 6 total
  Entity* dart1 = new Entity(1400, 897, 10, 50, "dartRight.png"); 
  Entity* dart2 = new Entity(100, 647, 10, 50, "dartLeft.png"); 

  // BOULDERS - 8 total
  Entity* boulder1 = new Entity(150, 217, 91, 101, "boulder.png"); 

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
      // switch (event.key.code) {
      //   case Keyboard::D:
      //     current_entity_texture.loadFromFile("mario_right.png");
      //     player->get_sprite().setTexture(current_entity_texture);
      //     player->move_right();
      //     break;
      //   case Keyboard::A:
      //     current_entity_texture.loadFromFile("mario_left.png");
      //     player->get_sprite().setTexture(current_entity_texture);          
      //     player->move_left();
      //     break;
      //   case Keyboard::W:
      //     player->move_up();
      //     break;
      //   case Keyboard::S:      
      //     player->move_down();
      //     break;

      //   default:
      //     break;
      // }

      
    }

    window.clear();

    // draw sprites here
    // -- PLATFORMS --
    window.draw(platform1->get_sprite());
    window.draw(platform2->get_sprite());
    window.draw(platform3->get_sprite());
    window.draw(platform4->get_sprite());

    // -- MEDKIT --
    window.draw(medkit->get_sprite());

    // -- BANDAGES -- 
    window.draw(bandage1->get_sprite());
    window.draw(bandage2->get_sprite());

    // -- COINS --
    window.draw(coin1->get_sprite());
    window.draw(coin2->get_sprite());
    window.draw(coin3->get_sprite());
    window.draw(coin4->get_sprite());
    window.draw(coin5->get_sprite());

    // -- FINISH FLAG --
    window.draw(finish->get_sprite());

    // -- LADDERS --
    window.draw(ladder1->get_sprite());
    window.draw(ladder2->get_sprite());
    window.draw(ladder3->get_sprite());

    // -- CHARACTERS --
    // -- PLAYER --
    window.draw(player->get_sprite());

    // -- ENEMIES --
    // -- BOULDERS --
    window.draw(boulder1->get_sprite());

    // -- DARTS --
    window.draw(dart1->get_sprite());
    window.draw(dart2->get_sprite());



    window.display();
  }

  // deleting variables from heap
  // -- PLATFORMS --
  delete platform1;
  delete platform2;
  delete platform3;
  delete platform4;

  // -- COINS --
  delete coin1;
  delete coin2;
  delete coin3;
  delete coin4;
  delete coin5;

  // -- MEDKIT --
  delete medkit;

  // -- BANDAGES --
  delete bandage1;
  delete bandage2;

  // -- FINISH FLAG --
  delete finish;

  // -- LADDER --
  delete ladder1;
  delete ladder2;
  delete ladder3;

  // -- PLAYER --
  delete player;
  
  // -- BOULDERS --
  delete boulder1;

  // -- DARTS --
  delete dart1;
  delete dart2;


  return 0;
}
