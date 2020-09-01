#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

/*
 * This class will be used to easily place and reposition groupings
 * of text within the game window.
 * Functions required:
 * 	-hold text within a rectangle
 * 	-automatically enter a newline when text can no longer fit in the rectangle
 * 	-allow text to be written fully or one character at a time
 * 	-allow for size changes (text will need to be rewritten into the box)
 * 	-(optional) make text fill line (increase character spacing) (gonna need my own font for this)
 * 	-allow for flush left, centered or square text
 */

/*
 * The class will take a short value for cascade speed, as well as the
 * already positioned rectangle from the calling function. The method reformatText will be
 * used to fit the text into the box initially, as well as any other time this would need
 * to be performed.
 */

//confusing naming due to late changes
/*
 * box is the container for the text
 * text is the string contained in the box
 * speed is the speed at which text will cascade (0 means text instantly appears)
 * textStyle will be for flush left, centered or squared text
 * font is the font used
 */
struct TextBlock {
	sf::RectangleShape box;
	sf::Text text;
	short speed;
	short textStyle;
	sf::Font font;
};

void reformatText(TextBlock);
void setPosition(TextBlock, int, int);
void resize(TextBlock, float, float);
void changeSpeed(TextBlock, short);
void instaText(TextBlock);
short getSpeed(TextBlock);

TextBlock TextBox(sf::Vector2f boxOutline, sf::Text inputText, short inputSpeed,
		short inputStyle, sf::Font inputFont) {

	TextBlock textBox;
	textBox.box.setSize(boxOutline);
	textBox.text.setString(inputText.getString());
	textBox.speed = inputSpeed;
	textBox.textStyle = inputStyle;
	textBox.font = inputFont;

	textBox.box.setOrigin(textBox.box.getSize().x / 2,
			textBox.box.getSize().y / 2);

	return textBox;
}

//reformat the text (done on initialization as well as whenever required)
void reformatText(TextBlock textBox) {

}

//set the position of the box (will need to reposition and possibly reformat text as well)
void setPosition(TextBlock textBox, int x, int y) {

	reformatText(textBox);
}

//in case a textbox needs to be resized (not sure if will be needed)
void resize(TextBlock textBox, float x, float y) {

	textBox.box.setOrigin(textBox.box.getSize().x / 2,
			textBox.box.getSize().y / 2);
}

//change text cascade speed (probably 3 different speeds)
void changeSpeed(TextBlock textBox, short speedChange) {
	textBox.speed = speedChange;
}

//method to instantly finish writing text in box (ie. to quickly move through dialogue)
void instaText(TextBlock textBox) {

}

short getSpeed(TextBlock textBox) {
	return textBox.speed;
}

