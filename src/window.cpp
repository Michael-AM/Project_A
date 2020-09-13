#include "window.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void windowStart() {
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Project A", sf::Style::Close);
	window.setFramerateLimit(60);

	/*	Window variables:
	 *		0: starting window
	 *		1: options
	 *		2: new game window
	 *		3: load game window
	 *		4: dev testing window (temporary)
	 *		5: controls window
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

	////////////////////////////////////////////////////////MAIN MENU COMPONENTS******************

	const sf::Vector2f buttonSize(200, 50);
	const sf::Vector2f smallerButtonSize(130, 30);
	const sf::Vector2f buttonShadeSize(190, 40);

	//assets for exit button
	sf::RectangleShape myExitButton(buttonSize);
	myExitButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	myExitButton.setPosition(window.getSize().x / 2, window.getSize().y - 100);
	myExitButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape myExitButtonShade(buttonShadeSize);
	myExitButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	myExitButtonShade.setPosition(window.getSize().x / 2,  window.getSize().y - 100);
	myExitButtonShade.setFillColor(sf::Color::Black);
	sf::Text exitButtonText("Exit Game", font, 30);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2,
			exitButtonText.getLocalBounds().height / 2 + 8);
	exitButtonText.setPosition(window.getSize().x / 2,  window.getSize().y - 100);

	//assets for options button
	sf::RectangleShape optionsButton(buttonSize);
	optionsButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	optionsButton.setPosition(window.getSize().x / 2, window.getSize().y - 190);
	optionsButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape optionsButtonShade(buttonShadeSize);
	optionsButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	optionsButtonShade.setPosition(window.getSize().x / 2, window.getSize().y - 190);
	optionsButtonShade.setFillColor(sf::Color::Black);
	sf::Text optionsButtonText("Options", font, 30);
	optionsButtonText.setOrigin(optionsButtonText.getLocalBounds().width / 2,
			optionsButtonText.getLocalBounds().height / 2 + 6);
	optionsButtonText.setPosition(window.getSize().x / 2, window.getSize().y - 190);

	//temp assets for yaboi
	sf::Texture yaBoi;
	if (!yaBoi.loadFromFile("Assets/Sprites/yaboi(nobg).png",
			sf::IntRect(90, 20, 200, 400)))
		std::cout << "Couldn't load image from file." << std::endl;
	sf::Sprite yaBoiS;
	yaBoiS.setTexture(yaBoi, true);
	yaBoiS.setPosition(25, 25);

	////////////////////////////////////////////////OPTIONS MENU COMPONENTS********************
	//return to main menu button
	sf::RectangleShape optionsBackButton(buttonSize);
	optionsBackButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	optionsBackButton.setPosition(window.getSize().x -200,
			window.getSize().y - 100);
	optionsBackButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape optionsBackButtonShade(buttonShadeSize);
	optionsBackButtonShade.setOrigin(buttonShadeSize.x -200,
			buttonShadeSize.y / 2);
	optionsBackButtonShade.setPosition(window.getSize().x / 2,
			window.getSize().y - 100);
	optionsBackButtonShade.setFillColor(sf::Color::Black);
	sf::Text optionsBackButtonText("Back", font, 30);
	optionsBackButtonText.setOrigin(
			optionsBackButtonText.getLocalBounds().width / 2,
			optionsBackButtonText.getLocalBounds().height / 2 + 8);
	optionsBackButtonText.setPosition(window.getSize().x -200,
			window.getSize().y - 100);

	//window mode change bar (MULTIPLE COMPONENTS)
	sf::RectangleShape windowModeBar(smallerButtonSize);
	windowModeBar.setOrigin(smallerButtonSize.x/2, smallerButtonSize.y/2);
	windowModeBar.setPosition(250, 150);
	windowModeBar.setFillColor(sf::Color(255, 255, 240, 128));
	sf::ConvexShape smallInvertedTriangle(3);
	smallInvertedTriangle.setPoint(0, sf::Vector2f (0, 0));
	smallInvertedTriangle.setPoint(1, sf::Vector2f (16, 0));
	smallInvertedTriangle.setPoint(2, sf::Vector2f (8, 12));
	smallInvertedTriangle.setPosition(295, 144);
	smallInvertedTriangle.setFillColor(sf::Color::Black);
	sf::Text windowModeText("", font, 20);



	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//All window set-ups will go in this switch block
		switch (currentWindow) {
		////////////////////////////////////////////////////////////// MAIN MENU WINDOW ////////////////////////////////////////////////////////////////
		/*
		 * TODO
		 * new game
		 * load game
		 */
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
			///////////////////////////////////////////////////////////////// OPTIONS WINDOW /////////////////////////////////////////////////////
			/*
			 * TODO
			 * a lot
			 * DONE back to menu
			 * fullscreen/windowed borderless
			 * controls (new window)
			 * resolution
			 * framerate
			 * music/sound (new window?)
			 * CONFIRMATION PROMPT FOR CERTAIN OPTIONS
			 * visuals, would only know later on if needed (separate window)
			 */
		case 1: {

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2f mousePos = window.mapPixelToCoords(
						sf::Mouse::getPosition(window));

				//back button held down
				while (optionsBackButton.getGlobalBounds().contains(mousePos)) {
					window.clear();
					window.draw(optionsBackButton);
					window.draw(optionsBackButtonShade);
					window.draw(optionsBackButtonText);

					window.display();

					mousePos = window.mapPixelToCoords(
							sf::Mouse::getPosition(window));
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						currentWindow = 0;
						break;
					}
				}
			}
			window.clear();
			window.draw(optionsBackButton);
			window.draw(optionsBackButtonText);

			break;
		}
		case 5: {

			break;
		}
		}

		window.display();
	}
}
