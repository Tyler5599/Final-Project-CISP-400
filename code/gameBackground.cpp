#include "gameBackground.h"
using namespace sf;

Background::Background()
{
	back_texture.loadFromFile("graphics/CyberPunkBack.png");
	back_sprite.setTexture(back_texture);
	back_sprite.setPosition(0,0);
}