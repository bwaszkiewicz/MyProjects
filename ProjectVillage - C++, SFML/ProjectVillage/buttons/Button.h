#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Input.h"

class Button : public sf::Drawable
{
protected:
	sf::Vector2f _size;
	sf::Vector2f _offSet;
	sf::Color _color;
public:
	Button();
	Button(float width, float height, float offsetX, float offsetY, sf::Color color);
	~Button();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f getSize() const;
	sf::Vector2f getOffSet() const;
	bool Button::operator!=(const Input & other) const;
	bool Button::operator==(const Input & other) const;
};