#include "TextHandler.h"

void TextHandler::setText(sf::Text text)
{
	_handledText = text;
}

void TextHandler::modifyText(std::string toChange)
{
	_handledText.setString(toChange);
}
sf::Text TextHandler::getText()
{
	return _handledText;
}
