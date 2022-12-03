#include "person.h"
#include "Engine.h"
#include "enemy.h"
using namespace std;

Enemy* Engine::createWave(int numEnemies, Vector2f screenRes)
{
	Enemy* enemies = new Enemy[numEnemies];
	int maxY = 0;
	int minY = screenRes.y - 200;
	int maxX = 20;
	int minX = screenRes.x - 20;
	for (int i = 0; i < numEnemies; i++)
	{
		srand((int)time(0) * i);
		int side = (rand() % 2);

		float x = 0.0; 
		float y = 0.0;
		//Decides which side and coords to spawn enemies
		switch (side)
		{
		//left side
		case 0:
			x = maxX;
			y = minY;
			break;
		//Right side
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
	return enemies;
}