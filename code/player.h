#ifndef PLAYER_H
#define PLAYER_H
#include "person.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


class Player : public Person {
public:
    Player();
    FloatRect getPosition()override;
    Vector2f getCenter();
    void update(float runTime, Vector2i mousePosition);
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    Sprite getSprite()override;
    void stop_up()override;
    void stop_down()override;
    void stop_left()override;
    void stop_right()override;
    int getHP()override;
    void spawn(IntRect room, Vector2f resolution, int room_size)override;
    bool check_hit(Time hitTime);
    Time getLastHitTime();
    void resetStats();
    void increase_HP();
    void increase_speed();
private:
    Vector2f player_position;
    const float start_speed = 200;
    const float start_HP = 100;
    bool w_pressed, s_pressed, a_pressed, d_pressed;
    //Gather player directional input
    int player_HP;
    int player_MaxHP;
    float player_speed;
    Time p_lastHit;
    Sprite player_sprite;
    Texture player_texture;
};


#endif