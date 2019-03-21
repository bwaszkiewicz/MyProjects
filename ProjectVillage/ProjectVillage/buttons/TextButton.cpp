#include "TextButton.h"

TextButton::TextButton()
{
}

TextButton::TextButton(float width, float height, float offsetX, float offsetY, sf::Color color, float textOffsetX, float textOffsetY, std::string text, sf::Color textColor):
	Button(width, height,offsetX, offsetY,color), _text(text), _textOffSet(textOffsetX, textOffsetY), _textColor(textColor)
{
}

TextButton::~TextButton()
{
}

void TextButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle(_size);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		throw NoTextButtonFontException();
	}
	sf::Text text;
	text.setFont(font);
	text.setFillColor(_textColor);
	text.setString(_text);
	text.setPosition(_offSet+_textOffSet);

	rectangle.setPosition(_offSet);
	rectangle.setFillColor(_color);

	target.draw(rectangle);
	target.draw(text);
}

sf::Vector2f TextButton::getSize() const
{
	return _size;
}

sf::Vector2f TextButton::getOffSet() const
{
	return _offSet;
}

bool TextButton::operator!=(const Input & other) const
{
	if ((*this) == other)
		return false;
	else
		return true;
}

bool TextButton::operator==(const Input & other) const
{
	if (this->getOffSet().x<other.getMousePosition().x && (this->getOffSet().x + this->getSize().x)>other.getMousePosition().x
		&& this->getOffSet().y < other.getMousePosition().y && (this->getOffSet().y + this->getSize().y) > other.getMousePosition().y)
		return true;
	else
		return false;
}
