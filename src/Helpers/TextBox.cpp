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
void reformatText(sf::RectangleShape, sf::Text);
void changeSpeed(short);

short speed;

//confusing naming due to late changes
struct TextBlock
{
	sf::RectangleShape box;
	sf::Text text;
	bool cascade;
	sf::Font font;
};

//no bool will instantiate to false
TextBlock TextBox(sf::Vector2f boxOutline, sf::Text inputText, sf::Font inputFont) {

	TextBlock textBox;
	textBox.box.setSize(boxOutline);
	textBox.text.setString(inputText.getString());
	textBox.cascade = false;
	textBox.font = inputFont;


	return textBox;
}

sf::Text TextBox(sf::RectangleShape boxOutline, sf::Text inputText, bool cascade) {

	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Assets/Fonts/Raleway-Regular.ttf")) {
		std::cout << "Couldn't load the font file." << std::endl;
		exit(1);
	}

	speed = 2;

	return text;
}

//reformat the text (done on initialization as well as whenever required)
void reformatText(sf::RectangleShape boxOutline, sf::Text text) {

}

//change text cascade speed (probably 3 different speeds)
void changeSpeed(short speedChange){
	speed = speedChange;
}

short getSpeed(){
	return speed;
}




