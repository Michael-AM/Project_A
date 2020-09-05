#ifndef TEXTBOX
#define TEXTBOX

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

struct TextBlock;
TextBlock TextBox(sf::Vector2f, sf::Text, short, bool, bool);
void reformatText(TextBlock);
void setPosition(TextBlock, float, float);
void resize(TextBlock, float, float);
sf::Text drawText(TextBlock);
short getSpeed(TextBlock);
sf::Text getText(TextBlock);

#endif
