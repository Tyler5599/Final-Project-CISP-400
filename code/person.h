#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Person{
    public:
        Person();
        void setSprite(string texture);
        virtual void spawn(IntRect room, Vector2f resolution, int tile_size);
        virtual bool check_touch(Sprite person1_position, Sprite person2_position);
        virtual bool check_hit(Sprite person_position, Sprite projectile_position);
        FloatRect getPosition(Sprite person);
        double getHealth();
        Sprite getSprite() const;
    protected:
        //Screen res, room size, and size of each tile for platforms
        Vector2f screen_res;
        IntRect play_room;
        int room_size;  
        double health;
        Sprite personSprite;   
};

#endif