#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Dart.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

using namespace sf;

int main()
{
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");
  window.setFramerateLimit(
      500); // Limit to 60 frames per second (or any desired frame rate)

  // create entities here and set starting position, size and texture.
  // -- ENTITIES --
  // PLATFORMS - create 5 platforms
  Entity *platform1 =
      new Entity(750, 1000, 33, 1400, "Textures/platform.png"); // position set
  Entity *platform2 =
      new Entity(750, 750, 33, 1400, "Textures/platform.png"); // position set
  Entity *platform3 =
      new Entity(750, 500, 33, 1400, "Textures/platform.png"); // position set
  Entity *platform4 =
      new Entity(750, 250, 33, 1400, "Textures/platform.png"); // position set

  // MEDKITS - create 1 medkit
  Entity *medkit =
      new Entity(750, 467, 50, 50, "Textures/medkit.png"); // position set

  // BANDAGES - create 2 bandages
  Entity *bandage1 =
      new Entity(750, 717, 45, 80, "Textures/bandages.png"); // position set
  Entity *bandage2 =
      new Entity(750, 217, 45, 80, "Textures/bandages.png"); // position set

  // COINS - 5 coins (changes each platform)
  Entity *coin1 =
      new Entity(350, 717, 40, 29, "Textures/coin.png"); // position set
  Entity *coin2 =
      new Entity(200, 467, 40, 29, "Textures/coin.png"); // position set
  Entity *coin3 =
      new Entity(950, 467, 40, 29, "Textures/coin.png"); // position set
  Entity *coin4 =
      new Entity(1000, 217, 40, 29, "Textures/coin.png"); // position set
  Entity *coin5 =
      new Entity(350, 217, 40, 29, "Textures/coin.png"); // position set

  // FINISH - create 1 finish
  Entity *finish =
      new Entity(100, 217, 107, 120, "Textures/finish.png"); // position set

  // VINES - creat 3 total
  Entity *ladder1 =
      new Entity(1300, 967, 250, 96, "Textures/ladder.png"); // position set
  Entity *ladder2 =
      new Entity(200, 717, 250, 96, "Textures/ladder.png"); // position set
  Entity *ladder3 =
      new Entity(1200, 467, 250, 96, "Textures/ladder.png"); // position set

  // -- CHARACTERS --
  // Player - 1 player
  Player *player = new Player(100, 1.5, 100, 967, 80, 60,
                              "Textures/mario_right.png"); // position set

  // -- Enemy --
  // DARTS - 6 total
  Dart *dart1 = new Dart(15, 1, 1400, 897, 10, 50, "Textures/dart_left.png");
  Dart *dart2 = new Dart(15, 1, 100, 647, 10, 50, "Textures/dart_right.png");
  Dart *dart3 = new Dart(15, 1, 1400, 647, 10, 50, "Textures/dart_left.png");
  Dart *dart4 = new Dart(15, 1, 100, 397, 10, 50, "Textures/dart_right.png");
  Dart *dart5 = new Dart(15, 1, 1400, 397, 10, 50, "Textures/dart_left.png");
  Dart *dart6 = new Dart(15, 1, 1400, 147, 10, 50, "Textures/dart_left.png");

  // Define the desired frame rate
  const int frameRate = 120;
  const Time frameTime = seconds(1.0f / frameRate);
  Clock clock;
  Time deltaTime;

  // run the program as long as the window is open
  while (window.isOpen())
  {
    Event event;
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed)
      {
        window.close();
      }
    }

    deltaTime += clock.restart();

    // Handle player movement
    while (deltaTime >= frameTime)
    {
      if (Keyboard::isKeyPressed(Keyboard::D))
      {
        player->move_right();
      }
      if (Keyboard::isKeyPressed(Keyboard::A))
      {
        player->move_left();
      }
      // jump

      if (player->on_ladder())
      {
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
          player->move_up();
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
          player->move_down();
        }
      }
      // dart rspawn
      if (dart1->get_sprite().getPosition().x <= 0)
      {
        dart1->respawn_right();
      }
      if (dart2->get_sprite().getPosition().x >= 1500)
      {
        dart2->respawn_left();
      }
      if (dart3->get_sprite().getPosition().x <= 0)
      {
        dart3->respawn_right();
      }
      if (dart4->get_sprite().getPosition().x >= 1500)
      {
        dart4->respawn_left();
      }
      if (dart5->get_sprite().getPosition().x <= 0)
      {
        dart5->respawn_right();
      }
      if (dart6->get_sprite().getPosition().x <= 0)
      {
        dart6->respawn_right();
      }
      dart1->move_left();
      dart2->move_right();
      dart3->move_left();
      dart4->move_right();
      dart5->move_left();
      dart6->move_left();

      player->get_sprite().move(Vector2f(1000, 300));

      deltaTime -= frameTime;

      std::cout << player->on_ladder() << std::endl;
    }

    window.clear();

    // draw sprites here
    // -- PLATFORMS --
    window.draw(platform1->get_sprite());
    window.draw(platform2->get_sprite());
    window.draw(platform3->get_sprite());
    window.draw(platform4->get_sprite());

    // // -- MEDKIT --
    // window.draw(medkit->get_sprite());

    // // -- BANDAGES --
    // window.draw(bandage1->get_sprite());
    // window.draw(bandage2->get_sprite());

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

    // -- DARTS --
    window.draw(dart1->get_sprite());
    window.draw(dart2->get_sprite());
    window.draw(dart3->get_sprite());
    window.draw(dart4->get_sprite());
    window.draw(dart5->get_sprite());
    window.draw(dart6->get_sprite());

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

  // -- DARTS --
  delete dart1;
  delete dart2;
  delete dart3;
  delete dart4;
  delete dart5;
  delete dart6;

  return 0;
}