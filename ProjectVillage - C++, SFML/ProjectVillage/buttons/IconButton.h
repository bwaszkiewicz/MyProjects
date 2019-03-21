#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Input.h"
#include "../exceptions/NoIconButtonTextureException.h"

class IconButton : public sf::Drawable
{
protected:
	sf::Vector2f _offSet;
	sf::Vector2u _size;
	sf::Vector2f _scale;
	std::string _fileLocation;

public:
	IconButton()=default;
	IconButton(sf::Vector2f offSet, std::string fileLocation);
	IconButton(sf::Vector2f offSet, std::string fileLocation,sf::Vector2f scale);
	~IconButton()=default;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2u getSize() const;
	sf::Vector2f getOffSet() const;
	sf::Vector2f getScale() const;
	bool IconButton::operator!=(const Input & other) const;
	bool IconButton::operator==(const Input & other) const;
};