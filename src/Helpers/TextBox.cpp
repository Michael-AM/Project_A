#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "TextBox.h"

/*
 * This class will be used to easily place and reposition groupings
 * of text within the game window.
 * Functions required:
 * 	-hold text within a rectangle
 * 	-automatically enter a newline when text can no longer fit in the rectangle
 * 	-allow text to be written fully or one character at a time
 * 	-allow for size changes (text will need to be rewritten into the box)
 * 	-(optional) make text fill line (increase character spacing) (gonna need my own font for this)
 * 	-allow for flush left or square text
 * 	-currently, box outline is invisible, only text is shown (this class used to position text easily only)
 */

/*
 * The class will take a short value for cascade speed, as well as the
 * already positioned rectangle from the calling function. The method reformatText will be
 * used to fit the text into the box initially, as well as any other time this would need
 * to be performed.
 */

TextBlock TextBox(sf::Vector2f boxOutline, sf::Text inputText, short inputSpeed,
		bool isCentered, bool textIsMenu) {

	TextBlock textBox;
	textBox.box.setSize(boxOutline);
	textBox.text.setString(inputText.getString());
	textBox.speed = inputSpeed;
	textBox.centered = isCentered;
	textBox.menuText = textIsMenu;

	textBox.box.setOrigin(textBox.box.getSize().x / 2,
			textBox.box.getSize().y / 2);

	reformatText(textBox);

	return textBox;
}

//reformat the text (done on initialization as well as whenever required)
void reformatText(TextBlock textBox) {

	sf::Text *text = &textBox.text;
	textBox.box.getGlobalBounds();
	sf::FloatRect workArea = textBox.box.getGlobalBounds();
	unsigned int i = 0, killswitch = 0;
	const sf::String poop = "\\n";
	while (workArea.width < text->getLocalBounds().width) {
		/*
		 * TODO
		 * set origin to center of TOP line of text IF CENTERED
		 * decrease size of font by predetermined value if whole thing is too big
		 */

		unsigned int lastSpace = 0;
		while (text->getString().getSize() > i
				&& workArea.contains(text->findCharacterPos(i))) {
			if ((char) text->getString()[i] == ' ')
				lastSpace = i;
			i++;
		}
		if (lastSpace != 0){
			sf::String tmp = text->getString();
			tmp.replace(lastSpace, 1, "\n");
			text->setString(tmp);
		}
		killswitch++;
		if(killswitch>10){
			std::cout << "somethings wrong" <<std::endl;
			exit(1);
		}
	}

}

//set the position of the box (will need to reposition and possibly reformat text as well)
void setPosition(TextBlock textBox, float x, float y) {

	textBox.box.setPosition(x, y);
	reformatText(textBox);
}

//in case a textbox needs to be resized (not sure if will be needed)
void resize(TextBlock textBox, float x, float y) {

	textBox.box.setSize(sf::Vector2f(x, y));
	textBox.box.setOrigin(x / 2, y / 2);
	reformatText(textBox);
}

//method that will type out the text when called (based on speed)
//TODO finish
sf::Text drawText(TextBlock textBox) {
	if (textBox.speed == 0) {
		return textBox.text;
	}

	return textBox.text;
}

short getSpeed(TextBlock textBox) {
	return textBox.speed;
}

sf::Text getText(TextBlock textBox) {
	return textBox.text;
}

