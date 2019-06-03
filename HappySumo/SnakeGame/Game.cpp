#include "Game.h"


void Game::PlayGame(sf::RenderWindow & window)
{
	Player *player = new Player(sf::Vector2f((float)(screenWidth / 2), (float)(screenHeight) / 2), sf::Color(255, 0, 0, 255), 5);
	allGameObjects.push_back(*player);

	

	while (window.isOpen())
	{
		switch (state)
		{

		case EGameState::ePlay:
		{
			window.clear();

			player->Render(window);
			/*for (GameObject &object : allGameObjects)
			{
				object.Render(window);
			}*/
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
