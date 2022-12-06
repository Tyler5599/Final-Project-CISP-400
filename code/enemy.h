#ifndef ENEMY_H
#define ENEMY_H
#include "person.h"
#include <SFML/Graphics.hpp>


class Enemy : public Person
{
    public:
        //Spawns the enemies given the start coords, enemy type, and random seed for type to spawn
        Sprite spawn(float startX, float startY, int type, int seed);
        //Checks if the enemy is hit by a projectile
        bool hit(Sprite person_position, Sprite projectile_position);
        //Gets the sprite position of enemy
        FloatRect getPosition()override{ return personSprite.getGlobalBounds(); }
        //Used to check if enemy is alive
        bool isAlive();
        //Updates the enemy location
        void update(float runTime, Vector2f playerLocation);
    private:
        //Enemy Hp
        int enemy_HP;
        //Enemy type Hp
        const int heavy_unitHP = 10;
        const int sniper_unitHP = 3;
        const int melee_unitHP = 2;
        const int regular_unitHP = 5;
        //Enemy type speed
        const int heavy_speed = 100;
        const int sniper_speed = 150;
        const int melee_speed = 250;
        const int regular_speed = 200;
        //Used to gather enemy location on screen
        Vector2f enemy_position;
        //Used to determine enemy speed
        float m_speed;
        //Used to determine enemy HP
        float m_HP;
        //Used to determine if enemy is alive still
        bool m_Alive;

};

#endif