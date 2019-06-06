#include "Food.h"



Food::Food(sf::Vector2f new_position, sf::Color new_color, float new_Size, float new_score, bool is_bad) : GameObject (new_position, new_color, new_Size)
{
	isBad = is_bad;
	score = new_score;
	generateNewPosition();
}

void Food::Update()
{
	//Random spawn position , 1 of 4 off screen, movement then in direction of opposite screen,
	//Collision between player and food, add or minus score if isBad

	switch (currentDirection)
	{
	case GameObject::EDirection::eNorth:
		
		currentPosition.y -= (1 * movementSpeed);
		
		break;
	case GameObject::EDirection::eEast:
		
		currentPosition.x += (1 * movementSpeed);
		
		break;
	case GameObject::EDirection::eSouth:
		
		currentPosition.y += (1 * movementSpeed);
		
		break;
	case GameObject::EDirection::eWest:
		
		currentPosition.x -= (1 * movementSpeed);
		
		break;
	default:
		break;
	}

}

void Food::Render(sf::RenderWindow & window)
{
	sf::RectangleShape shape(sf::Vector2f((float)size, (float) size));
	shape.setFillColor(color);
	shape.setPosition(currentPosition);
	shape.setOrigin(sf::Vector2f((float)(size / 2), (float)(size / 2)));
	window.draw(shape);
}

void Food::generateNewPosition()
{
	int selection = rand() % 3 + 1;

	//Generate off screen position. To make a ranged random position later on.

	switch (selection)
	{
	case 1: 
		currentPosition.x = 400;
		currentPosition.y = -10;
		currentDirection = EDirection::eSouth;
		break;
	case 2:
		currentPosition.x = 810;
		currentPosition.y = 300;
		currentDirection = EDirection::eWest;
		break;
	case 3:
		currentPosition.x = 400;
		currentPosition.y = 610;
		currentDirection = EDirection::eNorth;
		break;
	case 4:
		currentPosition.x = -10;
		currentPosition.y = 300;
		currentDirection = EDirection::eEast;
		break;
	
		
	default:
		break;
	}
}
