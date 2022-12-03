#include "player.h"
#include <SFML/Graphics.hpp>

Player::Player()
{
	player_speed = START_SPEED;
	player_HP = START_HP;
	player_MaxHP = START_HP;
	setSprite("graphics/Characters/2 Punk/Punk_idle.png");
	personSprite.setOrigin(50, 50);
}
void Player::spawn(Vector2f resolution)
{
	player_position.x = resolution.x / 2;
	player_position.y = resolution.y / 2;
	screen_res.x = resolution.x;
	screen_res.y = resolution.y;
}
void Player::resetStats()
{
	player_speed = START_SPEED;
	player_HP = START_HP;
	player_MaxHP = START_HP;
}
Time Player::getLastHitTime()
{
	return p_lastHit;
}
bool Player::check_hit(Time hitTime)
{
	if (hitTime.asMilliseconds() - p_lastHit.asMilliseconds() > 200)
	{
		p_lastHit = hitTime;
		player_HP -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

Vector2f Player::getCenter()
{
	return player_position;
}

//Movement functions
void Player::move_down()
{
	s_pressed = true;
}
void Player::move_up()
{
	w_pressed = true;
}
void Player::move_left()
{
	a_pressed = true;
}
void Player::move_right()
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
void Player::update(float runTime, Vector2i mousePosition)
{
	if (s_pressed)
	{
		player_position.y += player_speed * runTime;
	}
	if (w_pressed)
	{
		player_position.y -= player_speed * runTime;
	}
	if (a_pressed)
	{
		player_position.x -= player_speed * runTime;
	}
	if (d_pressed)
	{
		player_position.x += player_speed * runTime;
	}

	personSprite.setPosition(player_position);
	if (player_position.x > screen_res.x - 20)
	{
		player_position.x = screen_res.x - 20;
	}
	if (player_position.x < 20)
	{
		player_position.x = 20;
	}
	if (player_position.y > screen_res.y - 20)
	{
		player_position.y = screen_res.y - 20;
	}
	if (player_position.y < 20)
	{
		player_position.y = 20;
	}
}
void Player::increase_HP()
{
	player_MaxHP += (START_HP * 0.25);
}
void Player::increase_speed()
{
	player_speed += (START_SPEED * 0.2);
}
bool Player::handleInput()
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
