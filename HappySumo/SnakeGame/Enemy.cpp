#include "Enemy.h"

Enemy::Enemy(sf::Vector2f new_position, sf::Color new_color, float new_Size, const int & screen_Width, const int & screen_Height) : GameObject(new_position, new_color, new_Size)
{
	screenWidth = screen_Width;
	screenHeight = screen_Height;
	std::string fileName;

	for (int i = 0; i < 16; i++)
	{
		if (i < 10)
		{
			fileName = "Sprites/Enemy/tile00" + std::to_string(i) + ".png";
		}
		else if (i > 9 && i < 20)
		{
			fileName = "Sprites/Enemy/tile0" + std::to_string(i) + ".png";
		}

		if (!textures[i].loadFromFile(fileName))
		{
			//Error
		}
	};

	generateNewPosition();

}

void Enemy::Update()
{
	if (prevDirection == EDirection::eNorth && movementStep > 6)
	{
		movementStep = 4;
	}

	else if (prevDirection == EDirection::eEast && movementStep > 10)
	{
		movementStep = 8;
	}

	else if (prevDirection == EDirection::eSouth && movementStep > 2)
	{
		movementStep = 0;
	}

	else if (prevDirection == EDirection::eWest && movementStep > 14)
	{
		movementStep = 12;
	}

	switch (currentDirection)
	{
	case GameObject::EDirection::eNorth:
		movementStep++;
		currentPosition.y -= (1 * movementSpeed);
		prevDirection = currentDirection;
		if (currentPosition.y < -10)
		{
			generateNewPosition();
		}

		break;
	case GameObject::EDirection::eEast:
		movementStep++;
		currentPosition.x += (1 * movementSpeed);
		prevDirection = currentDirection;

		if (currentPosition.x > 810)
		{
			generateNewPosition();
		}

		break;
	case GameObject::EDirection::eSouth:
		movementStep++;
		currentPosition.y += (1 * movementSpeed);
		prevDirection = currentDirection;
		if (currentPosition.y > 610)
		{
			generateNewPosition();
		}

		break;
	case GameObject::EDirection::eWest:
		movementStep++;
		currentPosition.x -= (1 * movementSpeed);
		prevDirection = currentDirection;
		if (currentPosition.x < -10)
		{
			generateNewPosition();
		}

		break;
	default:
		break;
	}

	


}

void Enemy::Render(sf::RenderWindow & window)
{
	currentSprite.setTexture(textures[movementStep]);
	currentSprite.setScale(size, size);
	currentSprite.setPosition(currentPosition);
	window.draw(currentSprite);
}

void Enemy::generateNewPosition()
{
	int selection = rand() % 4 + 1;
	
	//Generate off screen position. To make a ranged random position later on.

	switch (selection)
	{
	case 1:

		//movementStep++;
		currentPosition.x = static_cast <float> (rand() % screenWidth);
		currentPosition.y = -movementDistance;
		currentDirection = EDirection::eSouth;
		break;

	case 2:

		//movementStep++;
		currentPosition.x = static_cast <float> (screenWidth + movementDistance);
		currentPosition.y = static_cast <float> (rand() % screenHeight);
		currentDirection = EDirection::eWest;
		break;

	case 3:

		//movementStep++;
		currentPosition.x = static_cast <float> (rand() % screenWidth);
		currentPosition.y = static_cast <float> (screenHeight + movementDistance);
		currentDirection = EDirection::eNorth;
		break;

	case 4:

		//movementStep++;
		currentPosition.x = -movementDistance;
		currentPosition.y = static_cast <float> (rand() % screenHeight);
		currentDirection = EDirection::eEast;
		break;
		
	default:
		break;
	}

}

sf::Sprite Enemy::getSprite()
{
	return currentSprite;
}
