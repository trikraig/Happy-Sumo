#include "Game.h"


void Game::PlayGame(sf::RenderWindow & window)
{
	Player *player = new Player(sf::Vector2f((float)(screenWidth / 2), (float)(screenHeight) / 2), sf::Color(255, 0, 0, 255), 2);
	allGameObjects.push_back(*player);

	/*for (int i = 0; i < 6; i++)
	{
		Food newFood(sf::Vector2f(0, 0), sf::Color(255,0,0,255), 10, 10, false);
		allFood.push_back(newFood);
	}*/

	Food newFood(sf::Vector2f(0, 0), sf::Color(255, 0, 0, 255), 20, 10, false);
	allFood.push_back(newFood);

	while (window.isOpen())
	{
		switch (state)
		{

		case EGameState::ePlay:
		{
			window.clear();
			player->Update();
			for (Food food : allFood)
			{
				food.Update();
				food.Render(window);
			}
			player->Render(window);
			/*for (GameObject &object : allGameObjects)
			{
				object.Render(window);
			}*/
			//Game clock to add delay to refresh rate of window. 						
			static sf::Clock gameClock;

			while (gameClock.getElapsedTime().asMilliseconds() < gameDelay);
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
