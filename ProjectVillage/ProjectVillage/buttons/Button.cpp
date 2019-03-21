#include "Button.h"

Button::Button()
{
}

Button::Button(float width, float height, float offsetX, float offsetY, sf::Color color) :
	_size(width,height), _offSet(offsetX, offsetY), _color(color)
{
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape rectangle(_size);
	rectangle.setPosition(_offSet);
	rectangle.setFillColor(_color); 

	target.draw(rectangle);
}

sf::Vector2f Button::getSize() const
{
	return _size;
}

sf::Vector2f Button::getOffSet() const
{
	return _offSet;
}

bool Button::operator!=(const Input & other) const
{
	if ((*this) == other)
		return false;
	else
		return true;
}

bool Button::operator==(const Input & other) const
{
	if (this->getOffSet().x<other.getMousePosition().x && (this->getOffSet().x + this->getSize().x)>other.getMousePosition().x
		&& this->getOffSet().y < other.getMousePosition().y && (this->getOffSet().y + this->getSize().y) > other.getMousePosition().y)
		return true;
	else
		return false;
}


