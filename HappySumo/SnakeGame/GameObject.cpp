#include "GameObject.h"

GameObject::GameObject(sf::Vector2f new_position, sf::Color new_color, float new_Size) : currentPosition (new_position), color (new_color), size (new_Size)
{
}

void GameObject::Update()
{
}

void GameObject::Render(sf::RenderWindow & window)
{
}

void GameObject::setMovementSpeed(int newSpeed)
{
	movementSpeed = newSpeed;
}

sf::Vector2f GameObject::getCurrentPosition()
{
	return currentPosition;
}



//void GameObject::Render(sf::RenderWindow & window)
//{
//}

