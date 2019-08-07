#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
private:

	int screenWidth;
	int screenHeight;
	int movementStep{ 0 };
	float movementDistance{ 10 };

	sf::Texture textures[16];
	sf::Sprite currentSprite;

public:

	Enemy(sf::Vector2f new_position, sf::Color new_color, float new_Size, const int &screen_Width, const int &screen_Height);
	void Update();
	void Render(sf::RenderWindow & window) override;
	void generateNewPosition();





};