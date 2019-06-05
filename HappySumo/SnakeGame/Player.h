#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:

	int movementSpeed{ 5 };
	int movementStep{ 0 };
	sf::Texture textures [16];
	sf::Sprite currentSprite;

public:

	Player(sf::Vector2f new_position, sf::Color new_color, float new_Size);

	void Update() override;
	void Render(sf::RenderWindow & window) override;
	
};

