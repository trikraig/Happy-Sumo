#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

class Game
{
private:

	const int screenWidth{ 800 };
	const int screenHeight{ 600 };

	std::vector <GameObject> allGameObjects;

	enum class EGameState
	{
		ePlay, eGameOver
	};

	EGameState state{ EGameState::ePlay };

public:

	void PlayGame(sf::RenderWindow & window);
};

