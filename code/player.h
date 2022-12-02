#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


class Player : public Person 
{
    private:
        Vector2f player_position;
        const float START_SPEED = 200;
        const float START_HP = 100;
        bool w_pressed, s_pressed, a_pressed, d_pressed;
        //Gather player directional input
        int player_HP;
        int player_MaxHP;
        float player_speed;
        Time p_lastHit;
        bool is_shooting;
        bool is_moving;
        bool is_jumping;
        bool start_jump;
        bool is_falling;
        float jump_duration;
        float jump_time;
        Sprite playerSprite;
    public:
        Player();
        FloatRect getPosition() { return playerSprite.getGlobalBounds(); };
        Vector2f getCenter();
        void update(float runTime, Vector2i mousePosition);
        void move_up();
        void move_down();
        void move_left();
        void move_right();
        bool handleInput();
        bool handleShooting();
        void stop_up();
        void stop_down();
        void stop_left();
        void stop_right();
        void spawn(IntRect room, Vector2f resolution, int room_size);
        bool check_hit(Time hitTime);
        Time getLastHitTime();
        void resetStats();
        void increase_HP();
        void decrease_HP();
        void increase_speed();
};


#endif