#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
protected:

	sf::Vector2f currentPosition;
	sf::Color color;

	//All objects are going to be squares so one int size required.
	int size;
	
	enum class EDirection
	{
		eNorth, eEast, eSouth, eWest
	};

	EDirection currentDirection;
public:

	GameObject(sf::Vector2f new_position, sf::Color new_color, int new_Size);

	//Controls movement
	virtual void Update();
	//To review later.
	virtual void Render(sf::RenderWindow & window) ;
	
};

