#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "Hud.h"
#include "enemy.h"
#include "player.h"
using namespace sf;

class Engine
{
private:
	Player player;
	TextureHolder th;
	RenderWindow m_window;
	View m_MainView;
	View m_hudView;

	Sprite m_backgroundSprite;
	Texture m_backgroundTexture;
	bool m_playing = false;
	Time m_GameTimeTotal;
	Enemy* createWave(int numEnemies, Vector2f screenRes);
	void input();
	void update(float dtAsSeconds, Enemy*, int num_enemies);
	void draw();
public:
	Engine();
	void run();

};

#endif