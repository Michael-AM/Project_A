#ifndef TEXTBOX
#define TEXTBOX

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

//confusing naming due to late changes
/*
 * box is the container for the text
 * text is the string contained in the box
 * speed is the speed at which text will cascade (0 means text instantly appears)
 * textStyle will be for flush left or centered text
 * menuText is for menu text
 * font is the font used
 */
struct TextBlock{
	sf::RectangleShape box;
	sf::Text text;
	short speed;
	bool centered;
	bool menuText;
};
TextBlock TextBox(sf::Vector2f, sf::Text, short, bool, bool);
void reformatText(TextBlock);
void setPosition(TextBlock, float, float);
void resize(TextBlock, float, float);
sf::Text drawText(TextBlock);
short getSpeed(TextBlock);
sf::Text getText(TextBlock);

#endif
