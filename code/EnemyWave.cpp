#include "person.h"
#include "Engine.h"
#include "enemy.h"
using namespace std;

Enemy* Engine::createWave(int numEnemies, Vector2f screenRes)
{
	//Create a new array of enemy object pointers
	Enemy* enemies = new Enemy[numEnemies];
	//Set max screen bounds
	int maxY = 50;
	int minY = screenRes.y - 50;
	int maxX = 50;
	int minX = screenRes.x - 50;
	//Loop through array and set enemy spawn/type
	for (int i = 0; i < numEnemies; i++)
	{
		//Use random int to help decide side to spawn enemies
		srand((int)time(0) * i);
		int side = (rand() % 2);

		float x = 0.0; 
		float y = 0.0;
		//Decides which side and coords to spawn enemies
		switch (side)
		{
		//left side of screen
		case 0:
			x = maxX;
			y = minY;
			break;
		//Right side of screen
		case 1:
			x = minX;
			y = maxY;
			break;
		}
		//Code for deciding enemy type to spawn
		srand((int)time(0) * i * 2);
		int type = (rand() % 3);
		m_window.draw(enemies[i].spawn(x, y, type, i));
	}
	//Return the array
	return enemies;
}