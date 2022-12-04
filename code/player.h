#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


class Player : public Person 
{
    private:
        Vector2f m_position;
        //Basic player stats
        const float START_SPEED = 200;
        const float START_HP = 100;
        //Gather player directional input
        bool w_pressed, s_pressed, a_pressed, d_pressed;
        //Player stats
        int m_HP;
        int m_MaxHP;
        float m_speed;
        //Time last hit
        Time m_lastHit;
        //Is the player shooting/moving?
        bool is_shooting;
        bool is_moving;
        bool is_jumping;
        bool start_jump;
        bool is_falling;
        float jump_duration;
        float jump_time;
    public:
        Player();
        Vector2f getCenter();
        void update(float runTime);
        void Up();
        void Down();
        void Left();
        void Right();
        //bool handleInput();
        //bool handleShooting();
        //Stops player from moving out of area
        void stop_up();
        void stop_down();
        void stop_left();
        void stop_right();
        void spawn(Vector2f resolution);
        bool check_hit(Time hitTime);
        Time getLastHitTime();
        void resetStats();
        void increase_HP();
        void decrease_HP();
        void increase_speed();
};


#endif