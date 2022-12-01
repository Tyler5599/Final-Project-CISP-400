#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//MAKE SURE TO #INCLUDE SET_POSTION FUNCTION FOR PERSON CONSTRUCTOR
using namespace sf;

Person::Person()
{
    screen_res = Vector2f(1920, 1080);
}

void Person::setSprite(string texture)
{
    Texture spriteTexture;
    spriteTexture.loadFromFile(texture);
    personSprite.setTexture(spriteTexture);
}

FloatRect Person::getPosition(Sprite person)
{
    return person.getGlobalBounds();
}

Sprite Person::getSprite() const
{
    return personSprite;
}

double Person::getHealth()
{
    return health;
}

bool Person::check_touch(Sprite person1_position, Sprite person2_position)
{
    if(getPosition(person1_position) == getPosition(person2_position))
    {
        return true;
    }
    return false;
}

bool Person::check_hit(Sprite person_position, Sprite projectile_position)
{
    if(getPosition(person_position) == getPosition(projectile_position))
    {
        return true;
    }
    return false;
}



