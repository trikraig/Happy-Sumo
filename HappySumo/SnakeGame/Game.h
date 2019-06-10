#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Food.h"

class Game
{
private:

	const int screenWidth{ 800 };
	const int screenHeight{ 600 };
	const int gameDelay{ 50 };

	std::vector <GameObject> allGameObjects;

	std::vector  <Food> allFood;

	enum class EGameState
	{
		ePlay, eGameOver
	};

	EGameState state{ EGameState::ePlay };

public:

	void PlayGame(sf::RenderWindow & window);
};

