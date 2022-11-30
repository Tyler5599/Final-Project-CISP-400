#include "projectile.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Projectile::Projectile()
{
	m_projectileShape.setSize(Vector2f(2, 2));
}
void Projectile::shoot(float startX, float startY, float xTarget, float yTarget)
{
	m_inFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;
	float gradient = (startX - xTarget) / (startY - yTarget);
	if (gradient < 0)
	{
		gradient *= -1;
	}

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

	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
	m_projectileShape.setPosition(m_Position);
}
void Projectile::stop()
{
	m_inFlight = false;
}
bool Projectile::isInFlight()
{
	return m_inFlight;
}
FloatRect Projectile::getPosition()
{
	return m_projectileShape.getGlobalBounds();
}
RectangleShape Projectile::getShape()
{
	return m_projectileShape;
}
void Projectile::update(float runTime)
{
	m_Position.x += m_projectileDistX * runTime;
	m_Position.y += m_projectileDistY * runTime;

	m_projectileShape.setPosition(m_Position);

	if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		m_inFlight = false;
	}
}