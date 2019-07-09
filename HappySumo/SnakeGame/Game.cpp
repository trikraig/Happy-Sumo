#include "Game.h"


void Game::PlayGame(sf::RenderWindow & window)
{
	const int screenWidth = window.getSize().x;
	const int screenHeight = window.getSize().y;

	Player *player = new Player(sf::Vector2f((float)(screenWidth / 2), (float)(screenHeight) / 2), sf::Color(255, 0, 0, 255), 2);
	allGameObjects.push_back(*player);

	for (int i = 0; i < 3; i++)
	{
		Food newFood(sf::Vector2f(0, 0), sf::Color(255,0,0,255), 10, 10, false, screenWidth, screenHeight);
		allFood.push_back(newFood);
	}

	while (window.isOpen())
	{
		switch (state)
		{

		case EGameState::ePlay:
		{
			window.clear();

			player->Update();
			player->eatFood(allFood);
			
			for (Food &food : allFood)
			{
				food.Update();
				food.Render(window);
			}
			
			player->Render(window);

			/*for (GameObject &object : allGameObjects)
			{
				object.Render(window);
			}*/

			DisplayUI(window, player);

			//Game clock to add delay to refresh rate of window. 
			static sf::Clock gameClock;
			while (gameClock.getElapsedTime().asMilliseconds() < gameDelayInMilliseconds);
			gameClock.restart();
		}
			break;
		case EGameState::eGameOver:
		{
			window.clear();
		}
			break;
		}

		window.display();
	}

	std::cout << "HAPPY SUMO: Finished" << std::endl;

	delete player;

	return;

	
}

void Game::DisplayUI(sf::RenderWindow & window, Player * player)
{
	//Error if font could not be loaded/
	if (!font.loadFromFile("font.ttf"))
	{
		std::cout << "Error. Font not available" << std::endl;
	}

	sf::Text textScore;
	textScore.setString("Score: " + std::to_string(player->getScore()));
	textScore.setFont(font);
	textScore.setCharacterSize(30);
	textScore.setFillColor(sf::Color(255,0,0,255));
	textScore.setPosition(50, 50);

	window.draw(textScore);
}
