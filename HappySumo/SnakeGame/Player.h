#pragma once
#include "GameObject.h"
#include "Food.h"

class Player : public GameObject
{
private:

	
	int movementStep{ 0 };
	sf::Texture textures [16];
	sf::Sprite currentSprite;
	int score = 0;
	
	//Attempt to increase time if food has been eaten.
	bool hasEaten{ false };
	

public:

	Player(sf::Vector2f new_position, sf::Color new_color, float new_Size);

	void Update() override;
	void Render(sf::RenderWindow & window) override;
	void eatFood( std::vector <Food> &allFood);
	int getScore();

	//Attempt to increase time if food has been eaten.
	bool gethasEaten();
	void resetHasEaten();
	
	
};

