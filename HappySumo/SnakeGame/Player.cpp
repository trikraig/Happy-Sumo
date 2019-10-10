#include "Player.h"

Player::Player(sf::Vector2f new_position, sf::Color new_color, float new_Size) : GameObject(new_position, new_color, new_Size)
{
	std::string fileName;

	//If use to load more player sprites, increase tile00 to max array size
	for (int i = 0; i < 16; i++)
	{
		if (i < 10)
		{
			fileName = "Sprites/Player/tile00" + std::to_string(i) + ".png";
		}
		else if (i > 9 && i < 20)
		{
			fileName = "Sprites/Player/tile0" + std::to_string(i) + ".png";
		}

		if (!textures[i].loadFromFile(fileName))
		{
			//Error
		}
	};

}

void Player::Update()
{
	//Player Control

	//Idle - 000 South Face, 004 North Face, 008 East Face, 0012 West Face)

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
		prevDirection = currentDirection;
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eEast:
		movementStep++;
		currentPosition.x += (1 * movementSpeed);
		prevDirection = currentDirection;
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eSouth:
		movementStep++;
		currentPosition.y += (1 * movementSpeed);
		prevDirection = currentDirection;
		currentDirection = EDirection::eIdle;
		break;
	case GameObject::EDirection::eWest:
		movementStep++;
		currentPosition.x -= (1 * movementSpeed);
		prevDirection = currentDirection;
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

void Player::eatFood(std::vector <Food> &allFood)
{
	for (Food &food : allFood)
	{

		if (currentSprite.getGlobalBounds().intersects(food.getSprite().getGlobalBounds()))
		{
			if (food.getIsBad() == false)
			{
				//Change Player Size
				hasEaten = true;
				size += 0.1f;
			}
			else
			{
				//Reduce player size if bad food.
				size -= 0.1f;
				score = 0;
				hasEaten = false;
			}

			score += static_cast <int> (food.getScore());

			if (score < 0) {
				score = 0;
			}
			//Respawn Food
			food.generateNewPosition();
		}
	}
}

void Player::collideEnemies(std::vector<Enemy>& allEnemies)
{
	for (Enemy &enemy : allEnemies)
	{
		if (currentSprite.getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds()))
		{
			//MAKE BOUNCE OFF ENEMY???
			setMovementSpeed(0);
			enemy.setMovementSpeed(0);
			//??????????????????????????????
			
		}
	}
}

int Player::getScore()
{
	return score;
}

bool Player::gethasEaten()
{
	return hasEaten;
}

void Player::resetHasEaten()
{
	hasEaten = false;
}


