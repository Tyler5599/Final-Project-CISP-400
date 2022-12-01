#include "enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
    health = 100.00;
}

void Enemy::spawn(float startX, float startY, int type, int seed)
{
    switch (type)
    {
        case 0:
        //Light
        setSprite("graphics/Biker_idle.png");
        speed = 80;
        health = 80;
        break;

        case 1:
        //Normal
        setSprite("graphics/Biker_idle.png");
        speed = 65;
        health = 100;
        break;

        case 2:
        //Sniper
        setSprite("graphics/Punk_idle.png");
        speed = 55;
        health = 70;
        break;

        case 3:
        //Heavy
        setSprite("graphics/Cyborg_idle.png");
        speed = 40;
        health = 130;
        break;
    }

    //Makes speed set to a range, making every enemy unique
    srand((int)time(0) * seed);
    float modifier = (rand() % 30) + (101 - 30);
    modifier /= 100; 
    speed *= modifier;

    //Need to include SetPosition
}