#include "player.h"
//#include "Textures.h"
#include <SFML/Graphics.hpp>

Player::Player()
{
	m_speed = START_SPEED;
	m_HP = START_HP;
	m_MaxHP = START_HP;
	Texture texture;
	texture.loadFromFile("graphics/Punk_idle.png");
	personSprite.setTexture(texture);
	personSprite.setOrigin(15, 15);
	cout << "Made Player Constructor" << endl;
}
void Player::spawn(Vector2f resolution)
{
	m_position.x = resolution.x / 2;
	m_position.y = resolution.y / 2;
	screen_res.x = resolution.x;
	screen_res.y = resolution.y;
	personSprite.setPosition(m_position);
}
void Player::resetStats()
{
	m_speed = START_SPEED;
	m_HP = START_HP;
	m_MaxHP = START_HP;
}
Time Player::getLastHitTime()
{
	return m_lastHit;
}
bool Player::check_hit(Time hitTime)
{
	if (hitTime.asMilliseconds() - m_lastHit.asMilliseconds() > 200)
	{
		m_lastHit = hitTime;
		m_HP -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

Vector2f Player::getCenter()
{
	return m_position;
}

//Movement functions
void Player::Down()
{
	s_pressed = true;
}
void Player::Up()
{
	w_pressed = true;
}
void Player::Left()
{
	a_pressed = true;
}
void Player::Right()
{
	d_pressed = true;
}
//Bounds functions
void Player::stop_down()
{
	s_pressed = false;
}
void Player::stop_up() 
{
	w_pressed = false;
}
void Player::stop_left()
{
	a_pressed = false;
}
void Player::stop_right()
{
	d_pressed = false;
}
void Player::update(float runTime)
{
	if (s_pressed)
	{
		m_position.y += m_speed * runTime;
	}
	if (w_pressed)
	{
		m_position.y -= m_speed * runTime;
	}
	if (a_pressed)
	{
		m_position.x -= m_speed * runTime;
	}
	if (d_pressed)
	{
		m_position.x += m_speed * runTime;
	}

	personSprite.setPosition(m_position);
	if (m_position.x > screen_res.x - 20)
	{
		m_position.x = screen_res.x - 20;
	}
	if (m_position.x < 20)
	{
		m_position.x = 20;
	}
	if (m_position.y > screen_res.y - 20)
	{
		m_position.y = screen_res.y - 20;
	}
	if (m_position.y < 20)
	{
		m_position.y = 20;
	}
}
void Player::increase_HP()
{
	m_MaxHP += (START_HP * 0.25);
}
void Player::increase_speed()
{
	m_speed += (START_SPEED * 0.2);
}
/*bool Player::handleInput()
{
	start_jump = false;
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		//starts the jump
		if (!is_jumping && !is_falling)
		{
			is_jumping = true;
			jump_time = 0;
			start_jump = true;
		}
			
	}
	else
	{
		is_jumping = false;
		is_falling = true;
	}
	return start_jump;
}
*/
