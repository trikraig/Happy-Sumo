#pragma once
#include "GameObject.h"

class Food : public GameObject
{
private:

	float score;
	bool isBad;
	bool isAlive{ true };
	int currentSelectedSprite;
	int screenWidth;
	int screenHeight;
	float movementDistance{ 10 };

	sf::Texture currentTexture;
	sf::Sprite currentSprite;



public:

	Food(sf::Vector2f new_position, sf::Color new_color, float new_Size, float new_score, bool is_bad, const int &screen_Width, const int &screen_Height);

	void Update();
	void Render(sf::RenderWindow & window) override;
	float getScore();
	void generateNewPosition();
	sf::Sprite getSprite();
	
};

