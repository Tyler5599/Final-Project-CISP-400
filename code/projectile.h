#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile
{
private:
	Vector2f m_Position;
	RectangleShape m_projectileShape;
	bool m_inFlight = false;
	float m_projectileSpeed = 1000;
	float m_projectileDistX;
	float m_projectileDistY;

	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;
public:
	Projectile();
	void stop();
	bool isInFlight();
	void shoot(float startX, float startY, float xTarget, float yTarget);
	FloatRect getPosition();
	RectangleShape getShape();
	void update(float runTime);
};

#endif
