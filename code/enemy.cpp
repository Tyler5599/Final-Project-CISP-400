#include "enemy.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Sprite Enemy::spawn(float startX, float startY, int type, int seed)
{
    Texture texture;

    switch (type)
    {
        case 0:
        //Melee
        texture.loadFromFile("graphics/Characters/1 Biker/Biker_idle.png");
        personSprite.setTexture(texture);
        m_speed = melee_speed;
        m_HP = melee_unitHP;
        break;

        case 1:
        //Regular
        texture.loadFromFile("graphics/Characters/1 Biker/Biker_idle.png");
        personSprite.setTexture(texture);
        m_speed = regular_speed;
        m_HP = regular_unitHP;
        break;

        case 2:
        //Sniper
        texture.loadFromFile("graphics/Characters/2 Punk/Punk_idle.png");
        personSprite.setTexture(texture);
        m_speed = sniper_speed;
        m_HP = regular_unitHP;
        break;

        case 3:
        //Heavy
        texture.loadFromFile("graphics/Characters/3 Cyborg/Cyborg_idle.png");
        personSprite.setTexture(texture);
        m_speed = heavy_speed;
        m_HP = regular_unitHP;
        break;
    }

    //Makes speed set to a range, making every enemy unique
    srand((int)time(0) * seed);
    float modifier = (rand() % 30) + (101 - 30);
    modifier /= 100; 
    m_speed *= modifier;

    //SetOrigin of enemy sprite
    personSprite.setOrigin(25, 25);
    //SetPosition of enemy sprite
    personSprite.setPosition(startX, startY);
    return personSprite;
}
bool Enemy::hit(Sprite person_position, Sprite projectile_position)
{
    enemy_HP--;
    if (enemy_HP < 0)
    {
        //Switch m_Alive to false (dead)
        m_Alive = false;
        //Commented line below meant to display enemy death animations (currently not able to do so)
        //enemy_sprite.setTexture(TextureHolder::GetTexture("graphics/put_enemy_type_here");
        return true;
    }
    //Returning false unless dead, still decreasing enemy HP
    return false;
}
bool Enemy::isAlive()
{
    return m_Alive;
}
void Enemy::update(float runTime, Vector2f playerLocation)
{
    //Gather player's location
    float player_x = playerLocation.x;
    float player_y = playerLocation.y;

    //Code below allows for enemy tracking to player's location
    if (player_x > enemy_position.x)
    {
        enemy_position.x = enemy_position.x + m_speed * runTime;
    }
    if (player_y > enemy_position.y)
    {
        enemy_position.y = enemy_position.y + m_speed * runTime;
    }
    if (player_x < enemy_position.x)
    {
        enemy_position.x = enemy_position.x - m_speed * runTime;
    }
    if (player_y < enemy_position.y)
    {
        enemy_position.y = enemy_position.y - m_speed * runTime;
    }

    //Moving enemy sprite to location of player
    personSprite.setPosition(enemy_position);

}