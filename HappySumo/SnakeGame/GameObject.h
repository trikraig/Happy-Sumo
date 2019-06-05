#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
protected:

	sf::Vector2f currentPosition;
	sf::Color color;

	//All objects are going to be squares so one int size required.
	float size;
	
	enum class EDirection
	{
		eNorth, eEast, eSouth, eWest, eIdle
	};

	EDirection currentDirection{ EDirection::eIdle };
	EDirection prevDirection;

public:

	GameObject(sf::Vector2f new_position, sf::Color new_color, float new_Size);

	//Controls movement
	virtual void Update();
	//To review later.
	virtual void Render(sf::RenderWindow & window) ;
	
};

