#include "Engine.h"
Engine::Engine()
{
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(resolution.x, resolution.y), "Cyber Punk Attack", Style::Fullscreen);
	m_MainView.setSize(resolution);
	m_hudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
	m_backgroundTexture = TextureHolder::GetTexture("graphics/background.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
}
void Engine::run()
{
	Clock clock;
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
	if (event.type == Event::KeyPressed)
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			m_playing = true;
		}
	}
}
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{
	m_window.clear(Color::White);
	m_window.draw(m_backgroundSprite);
	m_window.setView(m_MainView);
	m_window.setView(m_hudView);
	m_window.display();
}