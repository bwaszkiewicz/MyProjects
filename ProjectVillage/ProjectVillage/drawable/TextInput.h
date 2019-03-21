#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "../Input.h"

#include "../exceptions/NoTextInputFontException.h"

class TextInput: public sf::Drawable
{
sf::Vector2f _size;
sf::Vector2f _offSet;
sf::Vector2f _textOffSet;
sf::Color _textColor;
sf::Color _backgroundColor;
std::string _text;
public:
	TextInput()=default;

	/**
	*\brief Constructor of TextInput.
	*/
	TextInput(sf::Vector2f size, sf::Vector2f offSet, sf::Color backgroundColor,
		sf::Vector2f textOffSet, std::string text, sf::Color textColor);
	TextInput(const TextInput &other);
	~TextInput()=default;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setText(std::string text);
	std::string getText() const;

	sf::Vector2f getSize() const;
	sf::Vector2f getOffSet() const;
	bool TextInput::operator!=(const Input & other) const;
	bool TextInput::operator==(const Input & other) const;
};