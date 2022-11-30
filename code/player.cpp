#include "player.h"
#include <SFML/Graphics.hpp>

Player::Player()
{
	player_speed = start_speed;
	player_HP = start_HP;
	player_MaxHP = start_HP;
	player_texture.loadFromFile("graphics/Characters/2 Punk/Punk_idle.png");
	player_sprite.setTexture(player_texture);
	player_sprite.setOrigin(50, 50);
}
void Player::spawn(IntRect room, Vector2f resolution, int tile_size)
{
	player_position.x = room.width / 2;
	player_position.y = room.height / 2;
	play_room.left = room.left;
	play_room.width = room.width;
	play_room.top = room.top;
	play_room.height = room.height;
	room_size = tile_size;
	screen_res.x = resolution.x;
	screen_res.y = resolution.y;
}
void Player::resetStats()
{
	player_speed = start_speed;
	player_HP = start_HP;
	player_MaxHP = start_HP;
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
FloatRect Player::getPosition()
{
	return player_sprite.getGlobalBounds();
}
Vector2f Player::getCenter()
{
	return player_position;
}
Sprite Player::getSprite()
{
	return player_sprite;
}
int Player::getHP()
{
	return player_HP;
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

	player_sprite.setPosition(player_position);
	if (player_position.x > play_room.width - room_size)
	{
		player_position.x = play_room.width - room_size;
	}
	if (player_position.x < play_room.left + room_size)
	{
		player_position.x = play_room.left + room_size;
	}
	if (player_position.y > play_room.height - room_size)
	{
		player_position.y = play_room.height - room_size;
	}
	if (player_position.y < play_room.top + room_size)
	{
		player_position.y = play_room.top + room_size;
	}
}
void Player::increase_HP()
{
	player_MaxHP += (start_HP * 0.25);
}
void Player::increase_speed()
{
	player_speed += (start_speed * 0.2);
}
