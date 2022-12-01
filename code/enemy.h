#ifndef ENEMY_H
#define ENEMY_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class Enemy : public Person
{
    public:
        Enemy();
        void spawn(float startX, float startY, int type, int seed);
    private:
        int enemy_MaxHP;
        int speed;
        Vector2f enemy_postion;
};

#endif