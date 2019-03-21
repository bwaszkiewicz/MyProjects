#include "Icon.h"

Icon::Icon(sf::Vector2f offSet, std::string fileLocation) : _offSet(offSet), _fileLocation(fileLocation), _scale(sf::Vector2f(1, 1))
{
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconTextureException();
	}
	_size = texture.getSize();
}

Icon::Icon(sf::Vector2f offSet, std::string fileLocation, sf::Vector2f scale) : _offSet(offSet), _fileLocation(fileLocation), _scale(scale)
{
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconTextureException();
	}
	_size = texture.getSize();
}

void Icon::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Sprite icon;
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconTextureException();
	}

	icon.setTexture(texture);
	icon.setScale(_scale);
	icon.setPosition(_offSet);
	target.draw(icon);

}
