#include "window.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void windowStart() {
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Project A");
	window.setFramerateLimit(60);

	/*	Window variables:
	 *		0: starting window
	 *		1: options
	 *		2: new game window
	 *		3: load game window
	 *		4: dev testing window (temporary)
	 */
	int currentWindow = 0;

	/*
	 * NEED TO SET ALL CONSTANTS HERE
	 * EXAMPLE: BUTTON INITIALIZATIONS, FONT LOADING, ETC*
	 */

	//font to be used
	sf::Font font;
	if (!font.loadFromFile("Assets/Fonts/Raleway-Regular.ttf")) {
		std::cout << "Couldn't load the font file." << std::endl;
		exit(1);
	}

	//assets for exit button
	const sf::Vector2f buttonSize(200, 50);
	sf::RectangleShape myExitButton(buttonSize);
	myExitButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	myExitButton.setPosition(window.getSize().x / 2, 400);
	myExitButton.setFillColor(sf::Color(255, 255, 255, 128));
	const sf::Vector2f buttonShadeSize(190, 40);
	sf::RectangleShape myExitButtonShade(buttonShadeSize);
	myExitButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	myExitButtonShade.setPosition(window.getSize().x / 2, 400);
	myExitButtonShade.setFillColor(sf::Color::Black);
	sf::Text exitButtonText("Exit Game", font, 30);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2,
			exitButtonText.getLocalBounds().height / 2 + 8);
	exitButtonText.setPosition(window.getSize().x / 2, 400);

	//assets for options button
	sf::RectangleShape optionsButton(buttonSize);
	optionsButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	optionsButton.setPosition(window.getSize().x / 2, 500);
	optionsButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape optionsButtonShade(buttonShadeSize);
	optionsButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	optionsButtonShade.setPosition(window.getSize().x / 2, 500);
	optionsButtonShade.setFillColor(sf::Color::Black);
	sf::Text optionsButtonText("Options", font, 30);
	optionsButtonText.setOrigin(optionsButtonText.getLocalBounds().width / 2,
			optionsButtonText.getLocalBounds().height / 2 + 6);
	optionsButtonText.setPosition(window.getSize().x / 2, 500);

	//temp assets for yaboi
	sf::Texture yaBoi;
	if (!yaBoi.loadFromFile("Assets/Sprites/yaboi(nobg).png",
			sf::IntRect(90, 20, 200, 400)))
		std::cout << "Couldn't load image from file." << std::endl;
	sf::Sprite yaBoiS;
	yaBoiS.setTexture(yaBoi, true);
	yaBoiS.setPosition(0, 0);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//All window set-ups will go in this switch block
		switch (currentWindow) {
		case 0: {	//Main Menu Window

			//refactor working mouse click behavior
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2f mousePos = window.mapPixelToCoords(
						sf::Mouse::getPosition(window));
				//exit button held down
				while (myExitButton.getGlobalBounds().contains(mousePos)) {
					window.clear();
					window.draw(myExitButton);
					window.draw(myExitButtonShade);
					window.draw(exitButtonText);
					window.draw(yaBoiS);
					window.draw(optionsButton);
					window.draw(optionsButtonText);
					window.display();
					mousePos = window.mapPixelToCoords(
							sf::Mouse::getPosition(window));
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased)
						window.close();
				}
				//options button held down
				while (optionsButton.getGlobalBounds().contains(mousePos)) {
					window.clear();
					window.draw(myExitButton);
					window.draw(exitButtonText);
					window.draw(yaBoiS);
					window.draw(optionsButton);
					window.draw(optionsButtonShade);
					window.draw(optionsButtonText);
					window.display();
					mousePos = window.mapPixelToCoords(
							sf::Mouse::getPosition(window));
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						currentWindow = 1;
						break;
					}
				}
			}

			window.clear();
			window.draw(myExitButton);
			window.draw(exitButtonText);
			window.draw(yaBoiS);
			window.draw(optionsButton);
			window.draw(optionsButtonText);

			break;
		}
////////////////////////////////////////////////////////////////////////// NEXT WINDOW /////////////////////////////////////////////////////
		case 1: {
			std::cout << "BEEG SUCCESS" << std::endl;
			window.close();
			break;
		}
		}

		window.display();
	}
}
