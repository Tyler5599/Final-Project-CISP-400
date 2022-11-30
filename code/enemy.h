#ifndef ENEMY_H
#define ENEMY_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class Enemy : public Person{
    public:
        Enemy();
        FloatRect getPosition()override;
        Sprite getSprite()override;
        void stop_up()override;
        void stop_down()override;
        void stop_left()override;
        void stop_right()override;
        int getHealth()override;
        int set_EnemyType(int enemy_type);
    private:
        int enemy_HP;
        int enemy_MaxHP;
        Vector2f enemy_postion;
        int enemy_type;
};

#endif