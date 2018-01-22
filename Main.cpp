#pragma once

#include "LibsAndDeclarations.h"

#include "GGameStage.h"
#include "GGameplay.h"
#include "GMenu.h"

int main()
{
//Create the mWindow of the application
	sf::RenderWindow mWindow(sf::VideoMode(windowWidth, windowHeight, 32), "SFML AgarioClone", sf::Style::Titlebar | sf::Style::Close);
	mWindow.setVerticalSyncEnabled(true);

	std::unique_ptr<GGameStage> gameStage = std::make_unique<GMenu>();
	if (!gameStage->init(mWindow)) return false;

	sf::Clock clock;
	bool isPlaying = false;
	while (mWindow.isOpen())
	{
		// EVENTS
		{
		sf::Event event;
			while (mWindow.pollEvent(event))
			{
				// mWindow closed or escape key pressed: exit
				if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				{
					gameStage.reset();
					mWindow.close();
					break;
				}
			}
		}

		// UPDATE
		{
			auto start = ::clock();
			float delta_time = clock.restart().asSeconds();
			if (!isPlaying)
			{
				if (gameStage && !gameStage->update(delta_time))
				{
					isPlaying = true;

					gameStage.reset();
					gameStage = std::make_unique<GGameplay>();
					gameStage->init(mWindow);
				}
			}
			else
			{
				if (gameStage && !gameStage->update(delta_time))
				{
					gameStage.reset();
					mWindow.close();
					break;
				}
			}
			start = ::clock() - start;
		}

		// DRAW
		{
			mWindow.clear(sf::Color(0, 0, 0));

			if (gameStage) gameStage->draw(mWindow);

			mWindow.display();
		}
	}
	return 0;
}
