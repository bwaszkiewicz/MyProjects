#pragma once
#include "Button.h"
#include "../exceptions/NoTextButtonFontException.h"
class TextButton : public Button
{
	sf::Vector2f _textOffSet;
	sf::Color _textColor;
	std::string _text;
public:
	TextButton();

	/**
	*\brief Constructor of TextButton.
	*\param width: width of button
	*\param height: height of button
	*\param offsetX: displacement of button from window edge in X axis
	*\param offsetY: displacement of button from window edge in Y axis
	*\param color: color of button background (r,g,b)
	*\param textOffsetX: displacement of text from button edge in X axis
	*\param textOffsetY: displacement of text from button edge in Y axis
	*\param text: content of button
	*\param textColor: color of text (r,g,b)
	*/
	TextButton(float width, float height, float offsetX, float offsetY, sf::Color color, 
		float textOffsetX, float textOffsetY, std::string text, sf::Color textColor);
	~TextButton();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f getSize() const;
	sf::Vector2f getOffSet() const;
	bool TextButton::operator!=(const Input & other) const;
	bool TextButton::operator==(const Input & other) const;
};