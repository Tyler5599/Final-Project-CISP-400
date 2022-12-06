#include "projectile.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Projectile::Projectile()
{
	//Set size of the projectile
	m_projectileShape.setSize(Vector2f(2, 2));
}
void Projectile::shoot(float startX, float startY, float xTarget, float yTarget)
{
	//Initialize projectile in flight to true when first shooting
	m_inFlight = true;
	//Initialize the startx,starty corrds of projectile position
	m_Position.x = startX;
	m_Position.y = startY;
	//Set gradient of projectile to enemy location
	float gradient = (startX - xTarget) / (startY - yTarget);
	if (gradient < 0)
	{
		gradient *= -1;
	}
	//creates the projectile speed
	float ratioXY = m_projectileSpeed / (1 + gradient);
	m_projectileDistY = ratioXY;
	m_projectileDistX = ratioXY * gradient;
	if (xTarget < startX)
	{
		m_projectileDistX *= -1;
	}
	if (yTarget < startY)
	{
		m_projectileDistY *= -1;
	}
	//Sets bounds of projectile/sets position of projectile
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
	m_projectileShape.setPosition(m_Position);
}
void Projectile::stop()
{
	//Returns that projectile is no longer in flight
	m_inFlight = false;
}
bool Projectile::isInFlight()
{
	//Returns that projectile is in flight
	return m_inFlight;
}
FloatRect Projectile::getPosition()
{
	//Gathers position of projectile in air
	return m_projectileShape.getGlobalBounds();
}
RectangleShape Projectile::getShape()
{
	//Get the projectile shape
	return m_projectileShape;
}
void Projectile::update(float runTime)
{
	//Update projectile in flight
	m_Position.x += m_projectileDistX * runTime;
	m_Position.y += m_projectileDistY * runTime;
	//Set projectile position to new coords
	m_projectileShape.setPosition(m_Position);

	if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		//If projectile hits bounds, projectile is no longer in flight
		m_inFlight = false;
	}
}