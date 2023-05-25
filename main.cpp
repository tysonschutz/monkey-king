#include <SFML/Graphics.hpp>
#include <iostream>

#include "Character.h"
#include "Dart.h"
#include "Entity.h"
#include "Player.h"

using namespace sf;

int main() {
  int count = 0;
  // create the window with size "n x m" pixels
  RenderWindow window(VideoMode(1500, 1000), "Monkey King");
  window.setFramerateLimit(
      500);  // Limit to 60 frames per second (or any desired frame rate)

  // create entities here and set starting position, size and texture.
  // -- ENTITIES --
  // PLATFORMS - create 5 platforms
  Entity *platform1 =
      new Entity(750, 1000, 33, 1400, "Textures/platform.png");  // position set
  Entity *platform2 =
      new Entity(750, 750, 33, 1400, "Textures/platform.png");  // position set
  Entity *platform3 =
      new Entity(750, 500, 33, 1400, "Textures/platform.png");  // position set
  Entity *platform4 =
      new Entity(750, 250, 33, 1400, "Textures/platform.png");  // position set

  // FINISH - create 1 finish
  Entity *finish =
      new Entity(100, 217, 107, 120, "Textures/finish.png");  // position set

  // VINES - creat 3 total
  Entity *ladder1 =
      new Entity(1300, 967, 250, 96, "Textures/ladder.png");  // position set
  Entity *ladder2 =
      new Entity(200, 717, 250, 96, "Textures/ladder.png");  // position set
  Entity *ladder3 =
      new Entity(1200, 467, 250, 96, "Textures/ladder.png");  // position set

  // -- CHARACTERS --
  // Player - 1 player
  Player *player = new Player(100, 1.5, 100, 967, 80, 60,
                              "Textures/mario_right.png");  // position set

  // -- Enemy --
  // DARTS - 6 total
  Dart *dart1 = new Dart(15, 1, 1400, 917, 10, 50, "Textures/dart_left.png");
  Dart *dart2 = new Dart(15, 1, 100, 667, 10, 50, "Textures/dart_right.png");
  Dart *dart3 = new Dart(15, 1, 1400, 667, 10, 50, "Textures/dart_left.png");
  Dart *dart4 = new Dart(15, 1, 100, 417, 10, 50, "Textures/dart_right.png");
  Dart *dart5 = new Dart(15, 1, 1400, 417, 10, 50, "Textures/dart_left.png");
  Dart *dart6 = new Dart(15, 1, 1400, 167, 10, 50, "Textures/dart_left.png");

  // Define the desired frame rate
  const int frameRate = 120;
  const Time frameTime = seconds(1.0f / frameRate);
  Clock clock;
  Time deltaTime;

  // run the program as long as the window is open
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
    }

    deltaTime += clock.restart();

    // Handle player movement
    while (deltaTime >= frameTime) {
      if (Keyboard::isKeyPressed(Keyboard::D)) {
        Texture player_right;
        player_right.loadFromFile("Textures/mario_right.png");
        player->get_sprite().setTexture(player_right);
        window.draw(player->get_sprite());
        player->move_right();
      }
      if (Keyboard::isKeyPressed(Keyboard::A)) {
        Texture player_left;
        player_left.loadFromFile("Textures/mario_left.png");
        player->get_sprite().setTexture(player_left);
        window.draw(player->get_sprite());
        player->move_left();
      }
      if (!player->on_platform()) {
                 
          player->move_down();
        
      }
      

      if (Keyboard::isKeyPressed(Keyboard::W)) {
        

        player->jump();
      }

      if (player->on_ladder()) {
        if (Keyboard::isKeyPressed(Keyboard::W)) {
          player->move_up();
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
          player->move_down();
        }
      }

      // dart respawn
      if (dart1->get_sprite().getPosition().x <= 0) {
        dart1->respawn_right();
      }
      if (dart2->get_sprite().getPosition().x >= 1500) {
        dart2->respawn_left();
      }
      if (dart3->get_sprite().getPosition().x <= 0) {
        dart3->respawn_right();
      }
      if (dart4->get_sprite().getPosition().x >= 1500) {
        dart4->respawn_left();
      }
      if (dart5->get_sprite().getPosition().x <= 0) {
        dart5->respawn_right();
      }
      if (dart6->get_sprite().getPosition().x <= 0) {
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

      if (player->hit(dart1)) {
        window.close();
      }
      if (player->hit(dart2)) {
        window.close();
      }
      if (player->hit(dart3)) {
        window.close();
      }
      if (player->hit(dart4)) {
        window.close();
      }
      if (player->hit(dart5)) {
        window.close();
      }
      if (player->hit(dart6)) {
        window.close();
      }

      if (player->on_finish()) {
        window.close();
      }
    }

    // if (!player->on_ladder() && player->on_platform()) {
    //   if (Keyboard::isKeyPressed(Keyboard::W)) {
    //     // upward movement
    //     player->get_sprite().move(0, -40);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, -30);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, -20);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, -10);
    //     window.draw(player->get_sprite());
    //     if (Event::KeyReleased) player->get_sprite().move(0, 10);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, 20);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, 30);
    //     window.draw(player->get_sprite());
    //     player->get_sprite().move(0, 40);
    //     window.draw(player->get_sprite());
    //   }
    // }

    window.clear();

    // draw sprites here
    // -- PLATFORMS --
    window.draw(platform1->get_sprite());
    window.draw(platform2->get_sprite());
    window.draw(platform3->get_sprite());
    window.draw(platform4->get_sprite());

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