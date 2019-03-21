#include "TextInput.h"

TextInput::TextInput(sf::Vector2f size, sf::Vector2f offSet, sf::Color backgroundColor, sf::Vector2f textOffSet, std::string text, sf::Color textColor): _size(size), _offSet(offSet),
_backgroundColor(backgroundColor), _textOffSet(textOffSet), _text(text), _textColor(textColor)
{
}

TextInput::TextInput(const TextInput & other)
{
	this->_size = other._size;
	this->_offSet = other._offSet;
	this->_textOffSet = other._textOffSet;
	this->_textColor = other._textColor;
	this->_backgroundColor = other._backgroundColor;
	this->_text = other._text;
}

void TextInput::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle(_size);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		throw NoTextInputFontException();
	}
	sf::Text text;
	text.setFont(font);
	text.setFillColor(_textColor);
	text.setString(_text);
	text.setPosition(_offSet + _textOffSet);

	rectangle.setPosition(_offSet);
	rectangle.setFillColor(_backgroundColor);

	target.draw(rectangle);
	target.draw(text);
}

void TextInput::setText(std::string text)
{
	_text = text;
}

std::string TextInput::getText() const
{
	return _text;
}

sf::Vector2f TextInput::getSize() const
{
	return _size;
}

sf::Vector2f TextInput::getOffSet() const
{
	return _offSet;
}

bool TextInput::operator!=(const Input & other) const
{
	if ((*this) == other)
		return false;
	else
		return true;
}

bool TextInput::operator==(const Input & other) const
{
	if (this->getOffSet().x<other.getMousePosition().x && (this->getOffSet().x + this->getSize().x)>other.getMousePosition().x
		&& this->getOffSet().y < other.getMousePosition().y && (this->getOffSet().y + this->getSize().y) > other.getMousePosition().y)
		return true;
	else
		return false;
}
