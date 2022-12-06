#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "enemy.h"
#include "player.h"
using namespace sf;

class Engine
{
private:
	Player player;
	RenderWindow m_window;
	Vector2f resolution;
	Vector2i mousePosition;
	Clock clock;
	int wave = 1;
	int num_enemies = 20;
	int num_enemiesAlive = 20;
	Enemy* enemies;
	Sprite m_backgroundSprite;
	Texture m_backgroundTexture;
	Sprite playerSprite;
	Texture playerText;
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