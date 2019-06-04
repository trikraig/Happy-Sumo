#include "Player.h"

Player::Player(sf::Vector2f new_position, sf::Color new_color, int new_Size) : GameObject (new_position, new_color, new_Size)
{
	//If use to load more player sprites, increase tile00 to max array size
	for (int i = 0; i < 4; i++)
	{
		std::string fileName = "Sprites/tile00" + std::to_string(i) + ".png";
		if (!textures[i].loadFromFile(fileName))
		{
			//Error
		}
	};
	
}

void Player::Update()
{
	//Player Control

	if (movementStep >= 3)
	{
		movementStep = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (currentDirection != EDirection::eEast)
		{
			currentDirection = EDirection::eWest;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (currentDirection != EDirection::eWest)
		{
			currentDirection = EDirection::eEast;
		}

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (currentDirection != EDirection::eSouth)
		{
			currentDirection = EDirection::eNorth;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (currentDirection != EDirection::eNorth)
		{
			currentDirection = EDirection::eSouth;
		}

	}


	switch (currentDirection)
	{
	case GameObject::EDirection::eNorth:
		movementStep++;
		currentPosition.y -= (1 * movementSpeed);
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eEast:
		movementStep++;
		currentPosition.x += (1 * movementSpeed);
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eSouth:
		movementStep++;
		currentPosition.y += (1 * movementSpeed);
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eWest:
		movementStep++;
		currentPosition.x -= (1 * movementSpeed);
		currentDirection = EDirection::eIdle;
		break;
	default:
		break;
	}

}

void Player::Render(sf::RenderWindow & window)
{
	currentSprite.setTexture(textures[movementStep]);
	currentSprite.setScale(size, size);
	currentSprite.setPosition(currentPosition);
	window.draw(currentSprite);
	/*sf::RectangleShape shape(sf::Vector2f((float)size, (float) size));
	shape.setFillColor(color);
	shape.setPosition(currentPosition);
	shape.setOrigin(sf::Vector2f((float)(size / 2), (float)(size / 2)));
	window.draw(shape);*/
}


