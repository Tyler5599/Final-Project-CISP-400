#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile
{
private:
	//Position of projectile
	Vector2f m_Position;
	//Shape of projectile
	RectangleShape m_projectileShape;
	//Boolean variable used to show if in air or not
	bool m_inFlight = false;
	//Speed per frame of projectile
	float m_projectileSpeed = 1000;
	//The x,y distance values
	float m_projectileDistX;
	float m_projectileDistY;
	//Stops bullet from going too far
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
