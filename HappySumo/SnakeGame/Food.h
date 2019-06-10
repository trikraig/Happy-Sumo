#pragma once
#include "GameObject.h"

class Food : public GameObject
{
private:

	float score;
	bool isBad;
	bool isAlive{ true };
	int spriteSelection;
	int screenWidth;
	int screenHeight;
	float offset{ 10 };

	sf::Texture texture;
	sf::Sprite currentSprite;

	
	sf::RectangleShape shape;

public:

	Food(sf::Vector2f new_position, sf::Color new_color, float new_Size, float new_score, bool is_bad, const int &screen_Width, const int &screen_Height);

	void Update();
	void Render(sf::RenderWindow & window) override;
	float getScore();
	void generateNewPosition();
	sf::Sprite getSprite();
	
};

