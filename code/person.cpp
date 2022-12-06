#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//MAKE SURE TO #INCLUDE SET_POSTION FUNCTION FOR PERSON CONSTRUCTOR
using namespace sf;

Person::Person()
{
    //Set screen res for class use
    screen_res = Vector2f(1920, 1080);
}

void Person::setSprite(string texture)
{
    //Set the sprite of the personSprite variable
    Texture spriteTexture;
    spriteTexture.loadFromFile(texture);
    personSprite.setTexture(spriteTexture);
}

bool Person::check_touch(Sprite person1_position, Sprite person2_position)
{
    //Check if person is in hitbox
    if(person1_position.getGlobalBounds() == person2_position.getGlobalBounds())
    {
        return true;
    }
    return false;
}

bool Person::check_hit(Sprite person_position, Sprite projectile_position)
{
    //check if projectile is hitting person
    if(person_position.getPosition() == projectile_position.getPosition())
    {
        //Return true only if person is hit
        return true;
    }
    //Returns false if no hit detected
    return false;
}

Sprite Person::getSprite() const
{
    //return the sprite of person
    return personSprite;
}







