#include "player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    enum class STATE {PAUSED, INCREASE, GAME_OVER, PLAYING};
    STATE state = STATE::GAME_OVER;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "Cyber Punk Attack", Style::Fullscreen);
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



        window.clear();
        // Draw our game scene here
        // Show everything we just drew
        window.display();
    }
    return 0;

}