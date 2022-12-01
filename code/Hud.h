#pragma once
#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Hud
{
private:
	Font m_font;
	Text m_startText;
	Text m_projectileText;
	Text m_healthText;
public:
	Hud();
	Text getMessage();
	Text getProjectileCount();
	Text getHealth();
	//void setText();
	void setHealth(String text);
	void setProjectileCount(String text);
};

#endif