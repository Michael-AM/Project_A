#include "window.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

void windowStart() {
	std::vector<sf::VideoMode> screenSizes =
			sf::VideoMode::getFullscreenModes();
	sf::RenderWindow window(
			sf::VideoMode(screenSizes[1].width, screenSizes[1].height, 32),
			"Project A");
	window.setFramerateLimit(60);

	/*	Window variables:
	 *		0: starting window
	 *		1: options
	 *		2: new game window
	 *		3: load game window
	 *		4: dev testing window (temporary)
	 *		5: controls window
	 */
	int currentWindow = 0; //SET TO 4 FOR DEV WINDOW

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

	//dev "fun room" test map to get used to functions
	sf::View testMap;

	////////////////////////////////////////////////////////MAIN MENU COMPONENTS******************

	const sf::Vector2f buttonSize(200, 50);
	const sf::Vector2f smallerButtonSize(160, 30);
	const sf::Vector2f buttonShadeSize(190, 40);

	//assets for exit button
	sf::RectangleShape myExitButton(buttonSize);
	myExitButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	myExitButton.setPosition(window.getSize().x / 2, window.getSize().y - 100);
	myExitButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape myExitButtonShade(buttonShadeSize);
	myExitButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	myExitButtonShade.setPosition(window.getSize().x / 2,
			window.getSize().y - 100);
	myExitButtonShade.setFillColor(sf::Color::Black);
	sf::Text exitButtonText("Exit Game", font, 30);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2,
			exitButtonText.getLocalBounds().height / 2 + 8);
	exitButtonText.setPosition(window.getSize().x / 2,
			window.getSize().y - 100);

	//assets for options button
	sf::RectangleShape optionsButton(buttonSize);
	optionsButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	optionsButton.setPosition(window.getSize().x / 2, window.getSize().y - 190);
	optionsButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape optionsButtonShade(buttonShadeSize);
	optionsButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	optionsButtonShade.setPosition(window.getSize().x / 2,
			window.getSize().y - 190);
	optionsButtonShade.setFillColor(sf::Color::Black);
	sf::Text optionsButtonText("Options", font, 30);
	optionsButtonText.setOrigin(optionsButtonText.getLocalBounds().width / 2,
			optionsButtonText.getLocalBounds().height / 2 + 6);
	optionsButtonText.setPosition(window.getSize().x / 2,
			window.getSize().y - 190);

	//assets for dev button
	sf::RectangleShape devButton(buttonSize);
	devButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	devButton.setPosition(window.getSize().x / 4 * 3, window.getSize().y - 190);
	devButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape devButtonShade(buttonShadeSize);
	devButtonShade.setOrigin(buttonShadeSize.x / 2, buttonShadeSize.y / 2);
	devButtonShade.setPosition(window.getSize().x / 4 * 3,
			window.getSize().y - 190);
	devButtonShade.setFillColor(sf::Color::Black);
	sf::Text devButtonText("Fun Room", font, 30);
	devButtonText.setOrigin(devButtonText.getLocalBounds().width / 2,
			devButtonText.getLocalBounds().height / 2 + 7);
	devButtonText.setPosition(window.getSize().x / 4 * 3,
			window.getSize().y - 190);

	////////////////////////////////////////////////OPTIONS MENU COMPONENTS********************
	//return to main menu button
	sf::RectangleShape optionsBackButton(buttonSize);
	optionsBackButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
	optionsBackButton.setPosition(window.getSize().x - 200,
			window.getSize().y - 100);
	optionsBackButton.setFillColor(sf::Color(255, 255, 255, 128));
	sf::RectangleShape optionsBackButtonShade(buttonShadeSize);
	optionsBackButtonShade.setOrigin(buttonShadeSize.x - 200,
			buttonShadeSize.y / 2);
	optionsBackButtonShade.setPosition(window.getSize().x / 2,
			window.getSize().y - 100);
	optionsBackButtonShade.setFillColor(sf::Color::Black);
	sf::Text optionsBackButtonText("Back", font, 30);
	optionsBackButtonText.setOrigin(
			optionsBackButtonText.getLocalBounds().width / 2,
			optionsBackButtonText.getLocalBounds().height / 2 + 8);
	optionsBackButtonText.setPosition(window.getSize().x - 200,
			window.getSize().y - 100);

	//resolution change bar (MULTIPLE COMPONENTS)
	sf::RectangleShape resolutionBar(smallerButtonSize);
	resolutionBar.setOrigin(smallerButtonSize.x / 2, smallerButtonSize.y / 2);
	resolutionBar.setPosition(250, 150);
	resolutionBar.setFillColor(sf::Color(255, 255, 240, 128));
	sf::ConvexShape smallInvertedTriangle(3);
	smallInvertedTriangle.setPoint(0, sf::Vector2f(0, 0));
	smallInvertedTriangle.setPoint(1, sf::Vector2f(16, 0));
	smallInvertedTriangle.setPoint(2, sf::Vector2f(8, 12));
	smallInvertedTriangle.setPosition(305, 144);
	smallInvertedTriangle.setFillColor(sf::Color::Black);
	sf::Text resolutionText("Resolution", font, 20);
	resolutionText.setOrigin(resolutionText.getLocalBounds().width / 2,
			resolutionText.getLocalBounds().height / 2 + 6);
	resolutionText.setPosition(250, 120);
	sf::Text resolutionList[screenSizes.size()];
	for (unsigned int i = 0; i < screenSizes.size(); i++) {
		resolutionList[i].setString(
				std::to_string(screenSizes[i].width) + " x "
						+ std::to_string(screenSizes[i].height));
		resolutionList[i].setFont(font);
		resolutionList[i].setCharacterSize(20);
	}

	////////////////////////////////////////////////////////DEV WINDOW COMPONENTS******************
	/*
	 * Gonna load the map graphics here, but the actual collision will need to be implemented
	 * in a separate file (check the doc for my project setup)
	 * gonna work on character movement to start, need to link character graphics to the body in a separate file
	 */

	//temp assets for yaboi
	sf::Texture yaBoi;
	if (!yaBoi.loadFromFile("Assets/Sprites/yaboi(nobg).png",
			sf::IntRect(90, 20, 200, 400)))
		std::cout << "Couldn't load image from file." << std::endl;
	sf::Sprite yaBoiS;
	yaBoiS.setTexture(yaBoi, true);
	yaBoiS.setPosition(25, 25);

	/////////////////////////////////////////////////////////START OF DISPLAY LOOP//////////////////////////////////////////////////////
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
					window.draw(optionsButton);
					window.draw(optionsButtonText);
					window.draw(devButton);
					window.draw(devButtonText);
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
					window.draw(optionsButton);
					window.draw(optionsButtonShade);
					window.draw(optionsButtonText);
					window.draw(devButton);
					window.draw(devButtonText);
					window.display();
					mousePos = window.mapPixelToCoords(
							sf::Mouse::getPosition(window));
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						currentWindow = 1;
						break;
					}
				}
				//dev button held down
				while (devButton.getGlobalBounds().contains(mousePos)) {
					window.clear();
					window.draw(myExitButton);
					window.draw(exitButtonText);
					window.draw(optionsButton);
					window.draw(optionsButtonText);
					window.draw(devButton);
					window.draw(devButtonShade);
					window.draw(devButtonText);
					window.display();
					mousePos = window.mapPixelToCoords(
							sf::Mouse::getPosition(window));
					window.pollEvent(event);
					if (event.type == sf::Event::MouseButtonReleased) {
						currentWindow = 4;
						break;
					}
				}
			}

			window.clear();
			window.draw(myExitButton);
			window.draw(exitButtonText);
			window.draw(optionsButton);
			window.draw(optionsButtonText);
			window.draw(devButton);
			window.draw(devButtonText);

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
			 *
			 * likely going to change this into a VIEW rather than a WINDOW (need to research more on this topic)
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
					window.draw(resolutionBar);
					window.draw(resolutionText);
					window.draw(smallInvertedTriangle);

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
			window.draw(resolutionBar);
			window.draw(resolutionText);
			window.draw(smallInvertedTriangle);

			break;
		}
		case 4: {

			std::cout << "i made it!" << std::endl;
			break;
		}

		case 5: {

			break;
		}
		}

		window.display();
	}
}
