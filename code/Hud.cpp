#include "Hud.h"

Hud::Hud()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_font.loadFromFile("CyberPunkF.ttf");
	m_startText.setFont(m_font);
	m_startText.setFillColor(Color::Blue);
	m_startText.setString("Press Enter to begin!");

	FloatRect textRect = m_startText.getLocalBounds();
	m_startText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_startText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);
	
	m_projectileText.setFont(m_font);
	m_projectileText.setCharacterSize(30);
	m_projectileText.setFillColor(Color::Blue);
	m_projectileText.setPosition(resolution.x - 150, 0);
	m_projectileText.setString("30");

	m_healthText.setFont(m_font);
	m_healthText.setCharacterSize(30);
	m_healthText.setFillColor(Color::Blue);
	m_healthText.setPosition(150, resolution.y - 150);
	m_healthText.setString("100");
}
Text Hud::getMessage()
{
	return m_startText;
}
Text Hud::getProjectileCount()
{
	return m_projectileText;
}
Text Hud::getHealth()
{
	return m_healthText;
}
void Hud::setProjectileCount(String text)
{
	m_projectileText.setString(text);
}
void Hud::setHealth(String text)
{
	m_healthText.setString(text);
}
