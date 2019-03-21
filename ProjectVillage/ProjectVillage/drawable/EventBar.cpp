#include "EventBar.h"

EventBar::EventBar(sf::Vector2f size, sf::Vector2f position, std::string iconFilePath, std::string caption): _size(size), _position(position), _iconFilePath(iconFilePath), _caption(caption)
{
}

void EventBar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	sf::Color const defaultTextColor(100, 100, 100);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		throw NoEventBarFontException();
	}

	sf::RectangleShape EventBar(_size);
	EventBar.setPosition(_position);
	EventBar.setFillColor(sf::Color(74, 46, 17));
	target.draw(EventBar);

	Icon EventIcon(sf::Vector2f(_position.x+10.0f,_position.y+10.0f), _iconFilePath);
	target.draw(EventIcon);

	sf::Text EventCaption;
	EventCaption.setFillColor(defaultTextColor);
	EventCaption.setString(_caption);
	EventCaption.setPosition(_position.x+60.0f, _position.y+15.0f);
	EventCaption.setFont(font);
	target.draw(EventCaption);
}

sf::Vector2f EventBar::getSize() const
{
	return _size;
}

sf::Vector2f EventBar::getPosition() const
{
	return _position;
}

bool EventBar::operator!=(const Input & other) const
{
	if ((*this) == other)
		return false;
	else
		return true;
}

bool EventBar::operator==(const Input & other) const
{
	if (this->getPosition().x<other.getMousePosition().x && (this->getPosition().x + float(this->getSize().x))>other.getMousePosition().x
		&& this->getPosition().y < other.getMousePosition().y && (this->getPosition().y + float(this->getSize().y)) > other.getMousePosition().y)
		return true;
	else
		return false;
}
