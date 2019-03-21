#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../exceptions/NoIconTextureException.h"

class Icon : public sf::Drawable
{
protected:
	sf::Vector2f _offSet;
	sf::Vector2u _size;
	sf::Vector2f _scale;
	std::string _fileLocation;

public:
	Icon() = default;
	Icon(sf::Vector2f offSet, std::string fileLocation);
	Icon(sf::Vector2f offSet, std::string fileLocation, sf::Vector2f scale);
	~Icon() = default;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};