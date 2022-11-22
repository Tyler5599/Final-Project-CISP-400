#ifndef ENEMY_H
#define ENEMY_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class Enemy : public Person{
    public:
        Enemy();
        Vector2f setPostion();
        Vector2f getPostion();
        Vector2f movePlayer();
        double setHealth();
        double check_touch();
        double set_speed();
    private:
        double enemy_health;
        Vector2f enemy_postion;    

};

#endif