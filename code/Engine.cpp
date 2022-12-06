#include "Engine.h"
#include "person.h"
#include "enemy.h"
#include "player.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Engine::Engine()
{
	//Gather screen resolution, create window
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(resolution.x, resolution.y), "Cyberpunk Attack", Style::Fullscreen);
	//Set background for the game
	m_backgroundTexture.loadFromFile("graphics/CyberPunkBack1920x1080p.png");
	m_backgroundSprite.setTexture(m_backgroundTexture);
	//Set enemies to nullptr prior to aloocating memory
	enemies = nullptr;
	//Load player sprite
	playerText.loadFromFile("graphics/Punk_idle.png");
	playerSprite.setTexture(playerText);
}
void Engine::run()
{
	//Spawn the player on screen
	player.spawn(resolution);

	while (m_window.isOpen())
	{
		//Restart delta time
		Time dt = clock.restart();
		//Add new time to total game time
		m_GameTimeTotal += dt;
		//Convert delta time into seconds
		dtAsSeconds = dt.asSeconds();
		
		
		//delete enemies pointer
		delete[] enemies;
		//Create the enemy wave
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
	//Create events for input gathering
	Event event;
	//Create enum class for deciding the game time
	enum class STATE{PLAYING, PAUSED, GAME_OVER, INCREASE};
	//Initialize enum variable to paused so the game doesn't start right away
	STATE state = STATE::PAUSED;

	while (m_window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{

			//When player hits escape, close the window
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_window.close();
			}
			//Restart game clock when continuing to play
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
	//Handle movement of player
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
		//Flips the sprite of player when moving left
		playerSprite.setScale(-1.0f, 1.0f);
	}
	else
	{
		player.stop_left();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		player.Right();
		//If player sprite is flipped already, flip it back!
		playerSprite.setScale(1.0f, 1.0f);
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
		playerSprite.setPosition(player.update(dtAsSeconds));

		// Make a note of the players new position
		Vector2f playerPosition(player.getCenter());

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
	//Update the player's sprite
	playerSprite.setPosition(player.update(dtAsSeconds));	
	
}
void Engine::draw()
{
	//Draw sprites!
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	m_window.draw(playerSprite);
	m_window.display();
}