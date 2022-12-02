#include "person.h"
#include "enemy.h"

Enemy* createWave(int numEnemies, Vector2f screenRes)
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

		float x, y;
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
			y = minY;
			break;
		}
		//Code for deciding enemy type to spawn
		srand((int)time(0) * i * 2);
		int type = (rand() % 4);
		enemies[i].spawn(x, y, type, i);
	}
	return enemies;
}