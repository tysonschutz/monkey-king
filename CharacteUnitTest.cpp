#include "Character.h"
#include "Entity.h"
#include <iostream>

// Simple test function to check if two floating-point values are approximately equal
bool FloatEquals(float a, float b, float epsilon = 0.0001f)
{
    return std::abs(a - b) < epsilon;
}

int main()
{
    // Create a Character object with some initial values
    Character character(10.0f, 0.0f, 0.0f, 10, 10, "Textures/character.png");

    // Test get_movement_speed() method
    if (FloatEquals(character.get_movement_speed(), 10.0f))
    {
        std::cout << "get_movement_speed() test passed." << std::endl;
    }
    else
    {
        std::cout << "get_movement_speed() test failed." << std::endl;
    }

    // Test set_movement_speed() method
    character.set_movement_speed(20.0f);
    if (FloatEquals(character.get_movement_speed(), 20.0f))
    {
        std::cout << "set_movement_speed() test passed." << std::endl;
    }
    else
    {
        std::cout << "set_movement_speed() test failed." << std::endl;
    }

    // float XCharMove = 5

    // Test move_right() method
    float initialX = character.get_x_pos();
    character.move_right();
    float newX = character.get_x_pos();
    if (FloatEquals(newX, initialX + character.get_x_pos()))
    {
        std::cout << "move_right() test passed." << std::endl;
    }
    else
    {
        std::cout << "move_right() test failed." << std::endl;
    }

    // Test move_left() method
    initialX = character.get_x_pos();
    character.move_left();
    newX = character.get_x_pos();
    if (FloatEquals(newX, initialX - character.get_x_pos()))
    {
        std::cout << "move_left() test passed." << std::endl;
    }
    else
    {
        std::cout << "move_left() test failed." << std::endl;
    }

    // Test move_down() method
    float initialY = character.get_y_pos();
    character.move_down();
    float newY = character.get_y_pos();
    if (FloatEquals(newY, initialY + character.get_y_pos()))
    {
        std::cout << "move_down() test passed." << std::endl;
    }
    else
    {
        std::cout << "move_down() test failed." << std::endl;
    }

    // Test move_up() method
    initialY = character.get_y_pos();
    character.move_up();
    newY = character.get_y_pos();
    if (FloatEquals(newY, initialY - character.get_y_pos()))
    {
        std::cout << "move_up() test passed." << std::endl;
    }
    else
    {
        std::cout << "move_up() test failed." << std::endl;
    }

    return 0;
}