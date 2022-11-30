#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Person{
    public:
        Person();
        virtual FloatRect getPosition();
        virtual void stop_up();
        virtual void stop_down();
        virtual void stop_left();
        virtual void stop_right();
        virtual int getHealth();
        virtual void spawn(IntRect room, Vector2f resolution, int tile_size);
        virtual Sprite getSprite();
        virtual int getHP();
    protected:
        //Screen res, room size, and size of each tile for platforms
        Vector2f screen_res;
        IntRect play_room;
        int room_size;     
};

#endif