#include "Game.h"


void Game::PlayGame(sf::RenderWindow & window)
{
	const int screenWidth = window.getSize().x;
	const int screenHeight = window.getSize().y;



	Player *player = new Player(sf::Vector2f((float)(screenWidth / 2), (float)(screenHeight) / 2), sf::Color(255, 0, 0, 255), 2);
	allGameObjects.push_back(*player);

	gameTimeClock.restart();


	generateNewFood(screenWidth, screenHeight);

	
	for (int i = 0; i < 3; i++)
	{
		//Enemies
		Enemy newEnemy(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255), 2, screenWidth, screenHeight);
		allEnemies.push_back(newEnemy);
	}



	while (window.isOpen())
	{
		switch (state)
		{

		case EGameState::ePlay:
		{
			window.clear();

			timeRemaining = timeLimitAsSeconds - static_cast <int> (gameTimeClock.getElapsedTime().asSeconds());

			if (timeRemaining <= 0) {
				state = EGameState::eGameOver;
			}

			player->Update();
			player->eatFood(allFood);
			increaseTime(player->gethasEaten(), *player);

			for (Food &food : allFood)
			{
				food.Update();
				food.Render(window);
			}



			for (Enemy &enemy : allEnemies)
			{
				enemy.Update();
				enemy.Render(window);
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
			//TO DO
			//Record and display high score?

			window.clear();
			sf::Text textScore;
			textScore.setString("Final Score: " + std::to_string(player->getScore()));
			textScore.setFont(font);
			textScore.setCharacterSize(30);
			textScore.setFillColor(sf::Color(255, 0, 0, 255));
			textScore.setPosition(300, 300);
			window.draw(textScore);

			textScore.setString("Game Over!");
			textScore.setFont(font);
			textScore.setCharacterSize(50);
			textScore.setFillColor(sf::Color(255, 0, 0, 255));
			textScore.setPosition(250, 150);
			window.draw(textScore);

			textScore.setString("Press Spacebar to Play Again!");
			textScore.setFont(font);
			textScore.setCharacterSize(30);
			textScore.setFillColor(sf::Color(255, 0, 0, 255));
			textScore.setPosition(175, 450);
			window.draw(textScore);

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyPressed:

					switch (event.key.code)
					{
					case sf::Keyboard::Space:
						{
							//Single Player, No Opponents.
							Game *game = new Game;
							game->PlayGame(window);
							delete game;
							break;
						}

					case sf::Keyboard::Q:
					{
						window.close();
						break;
					}

					}

				case sf::Event::Closed:

					break;
				default:
					break;
				}
			}

		}
		break;
		}

		window.display();
	}

	std::cout << "HAPPY SUMO: Finished" << std::endl;

	delete player;

	return;


}

void Game::generateNewFood(const int &screenWidth, const int &screenHeight)
{
	allFood.clear();

	for (int i = 0; i < totalEachGoodFoodCreate; i++)
	{
		//Good Food
		Food newFood(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255), foodSize, 10, false, screenWidth, screenHeight);
		allFood.push_back(newFood);


	}

	for (int i = 0; i < totalEachGoodFoodCreate; i++)
	{
		//Bad Food
		Food newBadFood(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255), 2, 10, true, screenWidth, screenHeight);
		allFood.push_back(newBadFood);


	}
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
	textScore.setFillColor(sf::Color(255, 0, 0, 255));
	textScore.setPosition(50, 50);

	sf::Text timeRemaining;
	timeRemaining.setString("Time: " + std::to_string(timeLimitAsSeconds - static_cast <int> (gameTimeClock.getElapsedTime().asSeconds())));
	timeRemaining.setFont(font);
	timeRemaining.setCharacterSize(30);
	timeRemaining.setFillColor(sf::Color(255, 0, 0, 255));
	timeRemaining.setPosition(600, 50);

	window.draw(textScore);
	window.draw(timeRemaining);
}

void Game::increaseTime(bool hasEaten, Player &player)
{
	if (hasEaten)
	{
		//		timeLimitAsSeconds = maxTimeLimit;
		gameTimeClock.restart();
		player.resetHasEaten();
	}
}
