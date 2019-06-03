/*
  Games Development with C++ GAV1031-N
  Snake ICA start project

  Set up to use the SFML 2.5.1 64-bit API
	SFML documentation: https://www.sfml-dev.org/learn.php
*/

#include <iostream>

// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
	srand((int)time(0));

	const int screenWidth{ 800 };
	const int screenHeight{ 600 };

	sf::Font font;
	std::vector <sf::Text> mainMenu;

	if (!font.loadFromFile("font.ttf"))
	{
		std::cout << "Error. Font not available" << std::endl;
	}

	//Text for Main Menu
	sf::Text textTitle;
	textTitle.setString("HAPPY SUMO");
	textTitle.setCharacterSize(60);
	textTitle.setPosition(100, 75);
	textTitle.setFont(font);
	textTitle.setFillColor(sf::Color(238, 5, 242));
	mainMenu.push_back(textTitle);

	sf::Text text1Player;
	text1Player.setString("1 - NEW GAME");
	text1Player.setCharacterSize(35);
	text1Player.setPosition(150, 175);
	text1Player.setFont(font);
	text1Player.setFillColor(sf::Color(238, 5, 242));
	mainMenu.push_back(text1Player);

	sf::Text textQuit;
	textQuit.setString("Q - Quit");
	textQuit.setCharacterSize(35);
	textQuit.setPosition(150, 225);
	textQuit.setFont(font);
	textQuit.setFillColor(sf::Color(238, 5, 242));
	mainMenu.push_back(textQuit);

	// All SFML types and functions are contained in the sf namespace

	// Create an instance of the SFML RenderWindow type which represents the display
	// and initialise its size and title text
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "HAPPY SUMO");

	// We can still output to the console window
	std::cout << "HAPPY SUMO: Starting" << std::endl;

	// Main loop that continues until we call window.close()
	while (window.isOpen())
	{
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:

				switch (event.key.code)
				{
				case sf::Keyboard::Num1:
				{
					//Single Player, No Opponents.
					Game *game = new Game;
					game->PlayGame(window);
					delete game;
					break;
				}
				
				case sf::Keyboard::Q:
				{
					window.close();
					break;
				}

				}

			case sf::Event::Closed:

				break;
			default:
				break;
			}
		}

		// We must clear the window each time around the loop
		window.clear();

		

		// draw our circle shape to the window
		for (sf::Text text : mainMenu)
		{
			window.draw(text);
		}

		// Get the window to display its contents
		window.display();
	}

	std::cout << "HAPPY SUMO: Finished" << std::endl;

	return 0;
	
}

