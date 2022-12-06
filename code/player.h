#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <SFML/Graphics.hpp>

using namespace sf;


class Player : public Person 
{
    private:
        //Player position
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
        float velocity;
        float gravity;
    public:
        Player();
        //Returns player's position
        Vector2f getCenter();
        //Updates the player on screen
        Vector2f update(float runTime);
        //Movement
        void Jump();
        void endJump();
        void Up();
        void Down();
        void Left();
        void Right();
        //Stops from going off screen
        void stop_up();
        void stop_down();
        void stop_left();
        void stop_right();
        //Spawns the player
        void spawn(Vector2f resolution);
        //Checks if player is hit by enemy
        bool check_hit(Time hitTime);
        //Returns last hit on player
        Time getLastHitTime();
        //Resets player stats to starting values
        void resetStats();
        void increase_HP();
        void increase_speed();
};


#endif