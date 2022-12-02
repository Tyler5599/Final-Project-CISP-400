#include "Engine.h"
#include "person.h"
#include "player.h"
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
	Enemy* enemies = nullptr;
}
void Engine::run()
{
	Clock clock;
	enum class STATE{PLAYING, PAUSED, GAME_OVER};
	STATE state = STATE::GAME_OVER;
	while (m_window.isOpen())
	{
		Time dt = clock.restart();
		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();
		input();
		update(dtAsSeconds);
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
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{
	m_window.clear(Color::Black);
	m_window.draw(m_backgroundSprite);
	m_window.setView(m_MainView);
	m_window.setView(m_hudView);
	m_window.display();
}