#include "Food.h"



Food::Food(sf::Vector2f new_position, sf::Color new_color, float new_Size, float new_score, bool is_bad, const int &screen_Width, const int &screen_Height) : GameObject (new_position, new_color, new_Size)
{
	screenWidth = screen_Width;
	screenHeight = screen_Height;
	isBad = is_bad;

	if (!isBad)
	{

		spriteSelection = rand() % 4;

		std::string fileName = "Sprites/Food/food" + std::to_string(spriteSelection) + ".png";

		if (!texture.loadFromFile(fileName))
		{
			//Error
		}

		score = new_score;
	}
	else
	{
		spriteSelection = rand() % 2;

		std::string fileName = "Sprites/Food/food" + std::to_string(spriteSelection) + ".png";

		if (!texture.loadFromFile(fileName))
		{
			//Error
		}

		score = - new_score;
	}
	
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
		if (currentPosition.y < -10)
		{
			generateNewPosition();
		}
		
		break;
	case GameObject::EDirection::eEast:
		
		currentPosition.x += (1 * movementSpeed);

		if (currentPosition.x > 810)
		{
			generateNewPosition();
		}
		
		break;
	case GameObject::EDirection::eSouth:
		
		currentPosition.y += (1 * movementSpeed);

		if (currentPosition.y > 610)
		{
			generateNewPosition();
		}
		
		break;
	case GameObject::EDirection::eWest:
		
		currentPosition.x -= (1 * movementSpeed);
		
		if (currentPosition.x < -10)
		{
			generateNewPosition();
		}
		
		break;
	default:
		break;
	}

}

void Food::Render(sf::RenderWindow & window)
{
	currentSprite.setTexture(texture);
	//currentSprite.setScale(size, size);
	currentSprite.setPosition(currentPosition);
	window.draw(currentSprite);

	/*shape.setSize(sf::Vector2f((float)size, (float)size));
	shape.setFillColor(color);
	shape.setPosition(currentPosition);
	shape.setOrigin(sf::Vector2f((float)(size / 2), (float)(size / 2)));
	window.draw(shape);*/
}

float Food::getScore()
{
	return score;
}

void Food::generateNewPosition()
{
	int selection = rand() % 4 + 1;

	//Generate off screen position. To make a ranged random position later on.

	switch (selection)
	{
	case 1: 
		currentPosition.x = static_cast <float> (rand() % screenWidth);
		currentPosition.y = - offset;
		currentDirection = EDirection::eSouth;
		break;
	case 2:
		currentPosition.x = static_cast <float> (screenWidth + offset);
		currentPosition.y = static_cast <float> (rand() % screenHeight);
		currentDirection = EDirection::eWest;
		break;
	case 3:
		currentPosition.x = static_cast <float> (rand() % screenWidth);
		currentPosition.y = static_cast <float> (screenHeight + offset);
		currentDirection = EDirection::eNorth;
		break;
	case 4:
		currentPosition.x = -offset;
		currentPosition.y = static_cast <float> (rand() % screenHeight);
		currentDirection = EDirection::eEast;
		break;
	
		
	default:
		break;
	}
}

sf::Sprite Food::getSprite()
{
	return currentSprite;
}
