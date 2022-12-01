#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Hud.h"
using namespace sf;

class Engine
{
private:
	TextureHolder th;
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	RenderWindow m_window;
	View m_MainView;
	View m_hudView;

	Sprite m_backgroundSprite;
	Texture m_backgroundTexture;
	bool m_playing = false;
	Time m_GameTimeTotal;
	void input();
	void update(float dtAsSeconds);
	void draw();
public:
	Engine();
	void run();

};

#endif