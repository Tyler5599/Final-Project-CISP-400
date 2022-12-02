#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//MAKE SURE TO #INCLUDE SET_POSTION FUNCTION FOR PERSON CONSTRUCTOR
using namespace sf;

Person::Person()
{
    screen_res = Vector2f(1920, 1080);
    health = 100.00;
}

void Person::setSprite(string texture)
{
    Texture spriteTexture;
    spriteTexture.loadFromFile(texture);
    personSprite.setTexture(spriteTexture);
}

bool Person::check_touch(Sprite person1_position, Sprite person2_position)
{
    if(person1_position.getPosition() == person2_position.getPosition())
    {
        return true;
    }
    return false;
}

bool Person::check_hit(Sprite person_position, Sprite projectile_position)
{
    if(person_position.getPosition() == projectile_position.getPosition())
    {
        //Return true only if person is hit
        return true;
    }
    //Returns false if no hit detected
    return false;
}

double Person::getHealth()
{
    return health;
}

Sprite Person::getSprite() const
{
    return personSprite;
}







