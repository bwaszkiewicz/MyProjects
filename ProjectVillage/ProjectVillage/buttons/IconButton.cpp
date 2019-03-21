#include "IconButton.h"

IconButton::IconButton(sf::Vector2f offSet, std::string fileLocation): _offSet(offSet), _fileLocation(fileLocation), _scale(sf::Vector2f(1,1))
{
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconButtonTextureException();
	}
	_size = texture.getSize();
}

IconButton::IconButton(sf::Vector2f offSet, std::string fileLocation, sf::Vector2f scale): _offSet(offSet), _fileLocation(fileLocation), _scale(scale)
{
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconButtonTextureException();
	}
	_size = texture.getSize();
}

void IconButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Sprite icon;
	sf::Texture texture;
	if (!texture.loadFromFile(_fileLocation))
	{
		throw NoIconButtonTextureException();
	}

	icon.setTexture(texture);
	icon.setScale(_scale);
	icon.setPosition(_offSet);
	target.draw(icon);

}

sf::Vector2u IconButton::getSize() const
{
	return _size;
}

sf::Vector2f IconButton::getOffSet() const
{
	return _offSet;
}

sf::Vector2f IconButton::getScale() const
{
	return _scale;
}

bool IconButton::operator!=(const Input & other) const
{
	if ((*this) == other)
		return false;
	else
		return true;
}

bool IconButton::operator==(const Input & other) const
{
	if (this->getOffSet().x<other.getMousePosition().x && (this->getOffSet().x + float(this->getSize().x)*(this->getScale().x))>other.getMousePosition().x
		&& this->getOffSet().y < other.getMousePosition().y && (this->getOffSet().y + float(this->getSize().y)*(this->getScale().y)) > other.getMousePosition().y)
		return true;
	else
		return false;
}
