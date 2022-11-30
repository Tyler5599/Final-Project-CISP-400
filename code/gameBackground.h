#ifndef GAMEBACKROUND_H
#define GAMEBACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Background
{
    public:
        Background(Vector2f resolution);
    private:
        Sprite back_sprite;
        Texture back_texture;
};
#endif