#ifndef PERSON_H
#define PERSON_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Person{
    public:
        Person();
        //Sets the sprite of the personSprite
        virtual void setSprite(string texture);
        //Checks if the person/enemy is touching one another
        virtual bool check_touch(Sprite person1_position, Sprite person2_position);
        //Checks if the person/enemy is hit with a projectile
        virtual bool check_hit(Sprite person_position, Sprite projectile_position);
        //Returns the position of the player/enemy
        virtual FloatRect getPosition(){return personSprite.getGlobalBounds(); };
        //Returns the sprite of the person/enemy
        Sprite getSprite() const;
        // Creates sound
        virtual void makeSound() const = 0;
    protected:
        //Screen res, room size, and size of each tile for platforms
        Vector2f screen_res; 
        Sprite personSprite;   
};

#endif