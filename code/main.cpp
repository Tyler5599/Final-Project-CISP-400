#include "player.h"
#include "Engine.h"
#include "enemy.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Player player;
    Engine engine;
    engine.run();
   /*
        if (state == STATE::INCREASE)
        {
            if (event.key.code == Keyboard::Num1)
            {
                state = STATE::PLAYING;
            }
            if (event.key.code == Keyboard::Num2)
            {
                state = STATE::PLAYING;
            }
            if (event.key.code == Keyboard::Num3)
            {
                state = STATE::PLAYING;
            }

            if (state == STATE::PLAYING)
            {
                room.width = resolution.x;
                room.height = resolution.y;
                room.left = 0;
                room.top = 0;
                int tile_size = 20;
                player.spawn(room, resolution, tile_size);
                clock.restart();
            }
        }
        if (state == STATE::PLAYING)
        {
            Time delta = clock.restart();
            gameTime += delta;
            float deltaInSecs = delta.asSeconds();
            mouseScreenPosition = Mouse::getPosition();
            mouseGamePosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);
            player.update(deltaInSecs, Mouse::getPosition());
            Vector2f player_position(player.getCenter());
            mainView.setCenter(player.getCenter());
        }
        if (state == STATE::PLAYING)
        {
            window.clear();
            window.setView(mainView);
            window.draw(player.getSprite());
        }
        if (state == STATE::INCREASE)
        {

        }
        if (state == STATE::PAUSED)
        {

        }
        if (state == STATE::GAME_OVER)
        {

        }
        window.display();
    }
    */

    return 0;

}