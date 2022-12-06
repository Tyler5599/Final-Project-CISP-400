#include "player.h"
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
}
void Player::spawn(Vector2f resolution)
{
	m_position.x = resolution.x / 2;
	m_position.y = resolution.y * 0.85;
	screen_res.x = resolution.x;
	screen_res.y = resolution.y;
	personSprite.setPosition(m_position);
}
void Player::resetStats()
{
	//Reset the player's stats to base values
	m_speed = START_SPEED;
	m_HP = START_HP;
	m_MaxHP = START_HP;
}
Time Player::getLastHitTime()
{
	//Return time of the last hit so player isn't drained of life
	return m_lastHit;
}
bool Player::check_hit(Time hitTime)
{
	//Check if player hit each 200 milliseconds
	if (hitTime.asMilliseconds() - m_lastHit.asMilliseconds() > 200)
	{
		//If hit after 200 milliseconds since last hit, reset lastHit time, take off HP, return true
		m_lastHit = hitTime;
		m_HP -= 10;
		return true;
	}
	//Else player isn't hit
	else
	{
		return false;
	}
}

Vector2f Player::getCenter()
{
	//Return player position
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
//Bounds functions to stop player from moving off screen
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
Vector2f Player::update(float runTime)
{
	//If button is pressed, move player onscreen by base speed and runtime 
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
	//Set player's sprite location to new location
	personSprite.setPosition(m_position);

	//If new location is off screen bounds, returns sprite to screen bound
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
	//Finally return the player's position
	return m_position;
}
void Player::increase_HP()
{
	m_MaxHP += (START_HP * 0.25);
}
void Player::increase_speed()
{
	m_speed += (START_SPEED * 0.2);
}
void Player::Jump()
{
	gravity = 100.0f;
	start_jump = true;
	
	if (start_jump) 
	{
		velocity = -20.0f;
		start_jump = false;
	}
}
void Player::endJump()
{
	if (velocity < -20.0f)
	{
		velocity = -20.0f;
	}
}
