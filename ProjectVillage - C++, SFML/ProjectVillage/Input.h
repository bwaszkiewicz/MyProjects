#pragma once
#include <SFML/Window.hpp>

class Input {
	sf::Keyboard::Key _key;
	sf::Vector2i _mousePosition;
public:
	Input();
	Input(sf::Keyboard::Key key);
	Input(sf::Vector2i mousePosition);
	~Input();
	void setKey(sf::Keyboard::Key key);
	void setMousePosition(sf::Vector2i mousePosition);
	sf::Keyboard::Key getKey() const;
	sf::Vector2i getMousePosition() const;
};