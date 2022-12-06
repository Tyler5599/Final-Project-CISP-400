#include "Engine.h"
#include "person.h"
#include "enemy.h"
#include "player.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Engine::Engine()
{
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(resolution.x, resolution.y), "Cyberpunk Attack", Style::Fullscreen);
	m_backgroundTexture.loadFromFile("graphics/CyberPunkBack1920x1080p.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	enemies = nullptr;
	playerText.loadFromFile("graphics/Punk_idle.png");
	playerSprite.setTexture(playerText);
}
void Engine::run()
{

	player.spawn(resolution);

	while (m_window.isOpen())
	{
		Time dt = clock.restart();
		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();
		
		
		
		delete[] enemies;
		enemies = createWave(num_enemies, resolution);

		input();
		//cout << "Passed Input" << endl;
		update(dtAsSeconds, enemies, num_enemies);
		//cout << "Passed Update" << endl;
		draw();
		//cout << "Passed Draw" << endl;
	}
}
void Engine::input()
{
	Event event;
	enum class STATE{PLAYING, PAUSED, GAME_OVER, INCREASE};
	STATE state = STATE::PAUSED;

	while (m_window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.Left();
				playerSprite.setScale(-1.0f, 1.0f);
			}
			else if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.Right();
				playerSprite.setScale(1.0f, 1.0f);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.Up();
			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.Down();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_window.close();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Return) && state == STATE::PAUSED)
			{
				state = STATE::PLAYING;
				clock.restart();
			}
			else if (Keyboard::isKeyPressed(Keyboard::Return) && state == STATE::GAME_OVER)
			{
				state == STATE::INCREASE;
				player.resetStats();

			}
			if (state == STATE::PLAYING)
			{
				/* This is the if statement to handle Reload key!
				if (event.type == Keyboard::R)
				{
					//Plenty of bullets left when reloading
					if (spareRounds >= magazineSize)
					{
						bullet_in_mag = magazineSize;
						spareRounds -= magazineSize;
						reload.play() //Plays reload sound!!!
					}
					//Only a few bullets left
					else if (spareRounds > 0)
					{
						bullet_in_mag = spareRounds;
						spareRounds = 0;
						reload.play() //Plays reload sound!!!
					}
				*/

			}

		}
		if (event.type == Event::Closed)
		{
			m_window.close();
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		player.Up();
	}
	else
	{
		player.stop_up();
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		player.Down();
	}
	else
	{
		player.stop_down();
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		player.Left();
	}
	else
	{
		player.stop_left();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.Right();
	}
	else
	{
		player.stop_right();
	}
	if (state == STATE::PLAYING)
	{
		// Increase the wave number
		wave++;

		// Spawn the player in the middle of the arena
		player.spawn(resolution);

		// Configure the pick-ups
		//healthPickup.setArena(arena);
		//ammoPickup.setArena(arena);

		// Create a horde of zombies
		num_enemies = 5 * wave;

		// Delete the previously allocated memory (if it exists)
		delete[] enemies;
		enemies = createWave(num_enemies, resolution);
		num_enemiesAlive = num_enemies;

		// Play the powerup sound
		//powerup.play();

		// Reset the clock so there isn't a frame jump
		clock.restart();
	}
	if (state == STATE::PLAYING)
	{
		// Update the delta time
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction of 1 from the delta time
		float dtAsSeconds = dt.asSeconds();

		// Where is the mouse pointer
		mousePosition = Mouse::getPosition();

		// Convert mouse position to world coordinates of mainView
		//mousePosition = m_window.mapPixelToCoords(Mouse::getPosition(), m_window.getView());

		// Set the crosshair to the mouse world location
		//spriteCrosshair.setPosition(mouseWorldPosition);

		// Update the player
		//player.update(dtAsSeconds);
		playerSprite.setPosition(player.update(dtAsSeconds));

		// Make a note of the players new position
		Vector2f playerPosition(player.getCenter());

		// Make the view centre around the player				
		//mainView.setCenter(player.getCenter());

		// Loop through each Enemy and update them
		for (int i = 0; i < num_enemies; i++)
		{
			if (enemies[i].isAlive())
			{
				enemies[i].update(dt.asSeconds(), playerPosition);
			}
		}
	}
}
void Engine::update(float dtAsSeconds, Enemy* enemies, int num_enemies)
{

	Vector2i mousePosition = Mouse::getPosition();

	playerSprite.setPosition(player.update(dtAsSeconds));
	
	
}
void Engine::draw()
{
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	m_window.draw(playerSprite);
	m_window.display();
}