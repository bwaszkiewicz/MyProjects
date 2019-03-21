#include "Input.h"

Input::Input(): _key(sf::Keyboard::Unknown), _mousePosition(-1, -1)
{
}

Input::Input(sf::Keyboard::Key key): _key(key), _mousePosition(-1,-1)
{
}

Input::Input(sf::Vector2i mousePosition): _mousePosition(mousePosition), _key(sf::Keyboard::Unknown)
{
}

Input::~Input()
{
}

void Input::setKey(sf::Keyboard::Key key)
{
	_key=key;
}

void Input::setMousePosition(sf::Vector2i mousePosition)
{
	_mousePosition = mousePosition;
}

sf::Keyboard::Key Input::getKey() const
{
	return _key;
}

sf::Vector2i Input::getMousePosition() const
{
	return _mousePosition;
}

