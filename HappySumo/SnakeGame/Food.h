#pragma once
#include "GameObject.h"

class Food : public GameObject
{
private:

	float score;
	bool isBad;
	bool isAlive{ true };

	

public:

	Food(sf::Vector2f new_position, sf::Color new_color, float new_Size, float new_score, bool is_bad);

	void Update() override;
	void Render(sf::RenderWindow & window) override;

	void generateNewPosition();
};

