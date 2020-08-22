#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

/*
 * This class will be used to easily place and reposition groupings
 * of text within the game window.
 * Functions required:
 * 	-hold text within an sf::Rectangle
 * 	-automatically enter a newline when text can no longer fit in the rectangle
 * 	-allow text to be written fully or one character at a time
 * 	-allow for size changes (text will need to be rewritten into the box)
 * 	-(optional) make text fill line (increase character spacing) (gonna need my own font for this)
 */

/*
 * The class will take a boolean value to say whether the text will be cascaded, as well as the
 * already positioned rectangle from the calling function. The method reformatText will be
 * used to fit the text into the box initially, as well as any other time this would need
 * to be performed.
 */
void reformatText(sf::Text, sf::RectangleShape);

sf::Text TextBox(sf::RectangleShape boxOutline, bool cascade) {

	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Assets/Fonts/Raleway-Regular.ttf")) {
		std::cout << "Couldn't load the font file." << std::endl;
		exit(1);
	}

	return text;
}

void reformatText(sf::Text text, sf::RectangleShape boxOutline) {

}
