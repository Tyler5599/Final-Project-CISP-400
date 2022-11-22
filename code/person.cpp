#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//MAKE SURE TO #INCLUDE SET_POSTION FUNCTION FOR PERSON CONSTRUCTOR
using namespace sf;

Person::Person()
{
    health = 100;
}
Vector2f Person::getPosition(Vector2f person_position)
{
    Vector2f position = person_position;
    return position;
}
double Person::getHealth()
{
    return health;
}
bool Person::check_touch(Vector2f person1_position, Vector2f person2_position)
{
    if(getPosition(person1_position) == getPosition(person2_position))
    {
        return true;
    }
    return false;
}
bool Person::check_hit(Vector2f person_position, Vector2f projectile_position)
{
    if(getPosition(person_position) == getPosition(projectile_position))
    {
        return true;
    }
    return false;
}



