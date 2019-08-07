#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "Food.h"
#include "Enemy.h"

class Game
{
private:

	sf::Font font;
	
	const int gameDelayInMilliseconds{ 50 };
	
	float foodSize{ 2 };

	std::vector <GameObject> allGameObjects;
		
	std::vector  <Food> allFood;

	std::vector <Enemy> allEnemies;

	

	enum class EGameState
	{
		ePlay, eGameOver
	};

	EGameState state{ EGameState::ePlay };

public:

	void PlayGame(sf::RenderWindow & window);
	void DisplayUI(sf::RenderWindow & window, Player *player);
};

