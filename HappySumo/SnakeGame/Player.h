#pragma once
#include "GameObject.h"
class Player : public GameObject
{

public:

	Player(sf::Vector2f new_position, sf::Color new_color, int new_Size);

	void Update() override;
	void Render(sf::RenderWindow & window) override;
	
};

