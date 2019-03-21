#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../Defines.h"
#include "../Input.h"
#include "Icon.h"

#include "../exceptions/NoEventBarFontException.h"

class EventBar : public sf::Drawable {
	sf::Vector2f _position;
	sf::Vector2f _size;
	std::string _iconFilePath;
	std::string _caption;

	int _order;
	
public:
	EventBar() = default;
	EventBar(sf::Vector2f size, sf::Vector2f position, std::string iconFilePath, std::string caption);
	~EventBar() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f getSize() const;
	sf::Vector2f getPosition() const;
	bool EventBar::operator!=(const Input & other) const;
	bool EventBar::operator==(const Input & other) const;
};