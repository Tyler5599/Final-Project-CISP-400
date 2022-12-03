#include "Engine.h"
#include "person.h"
#include "enemy.h"
#include "player.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(resolution.x, resolution.y), "Cyber Punk Attack", Style::Default);
	m_MainView.setSize(resolution);
	m_hudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	m_backgroundTexture = TextureHolder::GetTexture("graphics/CyberPunkBack1920x1080p.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
}
void Engine::run()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	Clock clock;
	enum class STATE{PLAYING, PAUSED, GAME_OVER};
	STATE state = STATE::GAME_OVER;
	Enemy* enemies = nullptr;
	

	while (m_window.isOpen())
	{
		Time dt = clock.restart();
		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();
		
		player.spawn(resolution);
		
		int num_enemies = 20;
		delete[] enemies;
		enemies = createWave(num_enemies, resolution);

		input();
		update(dtAsSeconds, enemies, num_enemies);
		draw();
	}
}
void Engine::input()
{
	Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.move_left();		
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.move_right();
			}
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.move_up();
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.move_down();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_playing = true;
			}
		}
		if (event.type == Event::Closed)
		{
			m_window.close();
		}
		
	}
}
void Engine::update(float dtAsSeconds, Enemy* enemies, int num_enemies)
{

	Vector2i mousePosition = Mouse::getPosition();
	if (m_playing)
	{
		player.update(dtAsSeconds, mousePosition);
		Vector2f playerPosition(player.getCenter());
		for (int i = 0; i < num_enemies; i++)
		{
			if (enemies[i].isAlive())
			{
				enemies[i].update(dtAsSeconds, playerPosition);
			}
		}
	}
}
void Engine::draw()
{
	m_window.clear(Color::Black);
	m_window.draw(m_backgroundSprite);
	m_window.setView(m_MainView);
	m_window.setView(m_hudView);
	m_window.display();
}