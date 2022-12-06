#pragma once
#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "person.h"
#include "enemy.h"
#include "player.h"
using namespace sf;

class Engine
{
private:
	//Player object for game loop
	Player player;
	//Render window for launching game
	RenderWindow m_window;
	//Screen resolution
	Vector2f resolution;
	//Current mouse position
	Vector2i mousePosition;
	//Used for updating game time
	Clock clock;
	int wave = 1;
	//Number of enemies per wave
	int num_enemies = 20;
	//Number of enemies alive initialized to 20 at game start
	int num_enemiesAlive = 20;
	//Array of enemy objects for createWave function
	Enemy* enemies;
	//Sprite for background
	Sprite m_backgroundSprite;
	//Texture of background
	Texture m_backgroundTexture;
	//Player sprite/texture
	Sprite playerSprite;
	Texture playerText;
	//Game time total for runTime
	Time m_GameTimeTotal;
	//Creates wave of enemies w/ sprites loaded
	Enemy* createWave(int numEnemies, Vector2f screenRes);
	//Capture player input
	void input();
	//Update player/enemies
	void update(float dtAsSeconds, Enemy*, int num_enemies);
	//Draw player/enemies/projectiles
	void draw();
	float dtAsSeconds;
public:
	Engine();
	//Runs the input,update,draw functions
	void run();

};

#endif