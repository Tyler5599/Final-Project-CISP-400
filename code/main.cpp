#include "player.h"
#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Engine engine;
    engine.run();
    /*
    enum class STATE { PAUSED, INCREASE, GAME_OVER, PLAYING };
    STATE state = STATE::GAME_OVER;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "Cyber Punk Attack", Style::Default);
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));
    Clock clock;
    Time gameTime;
    Vector2f mouseGamePosition;
    Vector2i mouseScreenPosition;
    Player player;
    IntRect room;
    std::cout << "hello" << std::endl;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Keyboard::Return && state == STATE::PLAYING)
            {
                state = STATE::PAUSED;
            }
            else if (event.key.code == Keyboard::Return && state == STATE::PAUSED)
            {
                state = STATE::PLAYING;
                clock.restart();
            }
            else if (event.key.code == Keyboard::Return && state == STATE::GAME_OVER)
            {
                state = STATE::INCREASE;
            }
            if (state == STATE::PLAYING)
            {

            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close(); 
        }
        if (state == STATE::PLAYING)
        {
            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                player.move_down();
            }
            else
            {
                player.stop_down();
            }
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                player.move_up();
            }
            else
            {
                player.stop_up();
            }
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                player.move_left();
            }
            else
            {
                player.stop_left();
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                player.move_right();
            }
            else
            {
                player.stop_right();
            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                
            }
        
        }
        */
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