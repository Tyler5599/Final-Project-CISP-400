#ifndef GAMEBACKROUND_H
#define GAMEBACKGROUND_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Background
{
    public:
        Background();
    private:
        Sprite back_sprite;
        Texture back_texture;
};
#endif