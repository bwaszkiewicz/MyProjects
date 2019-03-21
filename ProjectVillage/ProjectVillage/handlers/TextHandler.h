#pragma once
#include <SFML/Graphics.hpp>
#include <regex>
/**
*\brief Changing String value in Text elements in ShapeMap
*/
class TextHandler {
	sf::Text _handledText;
	std::regex _pattern;
public:
	void setText(sf::Text text);
	//void modifyText(std::string toChange);
	//void modifyTextOld(int Amount);
	void modifyText(std::string change);
	sf::Text getText();
	
};

