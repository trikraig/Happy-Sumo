#include "Player.h"

Player::Player(sf::Vector2f new_position, sf::Color new_color, int new_Size) : GameObject (new_position, new_color, new_Size)
{
}

void Player::Update()
{
}

void Player::Render(sf::RenderWindow & window)
{
	sf::RectangleShape shape(sf::Vector2f((float)size, (float) size));
	shape.setFillColor(color);
	shape.setPosition(currentPosition);
	shape.setOrigin(sf::Vector2f((float)(size / 2), (float)(size / 2)));
	window.draw(shape);
}


