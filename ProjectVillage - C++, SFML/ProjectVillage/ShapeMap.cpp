#include "ShapeMap.h"

sf::Font * ShapeMap::loadFont(short int fontNumber)
{
	static sf::Font font;
	switch (fontNumber) 
	{
	default:
		if (!font.loadFromFile("arial.ttf"))
		{
			throw NoShapeMapLoadFontException();
		}
		break;
	}

	
	return &font;
}

void ShapeMap::addRectangleShape(std::string name, sf::RectangleShape shape)
{
	_RectangleShapes[name] = shape;
}

void ShapeMap::addCircleShape(std::string name, sf::CircleShape shape)
{
	_CircleShapes[name] = shape;
}

void ShapeMap::addConvexShape(std::string name, sf::ConvexShape shape)
{
	_ConvexShapes[name] = shape;
}

void ShapeMap::addButton(std::string name, Button button)
{
	_Buttons[name] = button;
}

void ShapeMap::addTextButton(std::string name, TextButton button)
{
	_TextButtons[name] = button;
}

void ShapeMap::addText(std::string name, sf::Text text, short int fontNumber)
{
	text.setFont(*(loadFont(fontNumber)));
	_Text[name] = text;
}

void ShapeMap::addIcon(std::string name, Icon icon)
{
	_Icons[name] = icon;
}

void ShapeMap::addIconButton(std::string name, IconButton button)
{
	_IconButtons[name] = button;
}

void ShapeMap::addBuildingsWindowFrame(std::string name, BuildingsWindowFrame frame)
{
	_BuildingsWindowFrame[name] = frame;
}

void ShapeMap::addTextInput(std::string name, TextInput textInput)
{
	_TextInput[name] = textInput;
}

void ShapeMap::addEventBar(std::string name, EventBar eventBar)
{
	_EventBar[name] = eventBar;
}




void ShapeMap::setText(std::string name, sf::Text text)
{
	_Text[name] = text;
}

sf::RectangleShape ShapeMap::getRectangleShape(std::string name)
{
	return _RectangleShapes[name];
}

sf::CircleShape ShapeMap::getCircleShape(std::string name)
{
	return _CircleShapes[name];
}

sf::ConvexShape ShapeMap::getConvexShape(std::string name)
{
	return _ConvexShapes[name];
}

Button ShapeMap::getButton(std::string name)
{
	return _Buttons[name];
}

TextButton ShapeMap::getTextButton(std::string name)
{
	return _TextButtons[name];
}

sf::Text ShapeMap::getText(std::string name)
{
	return _Text[name];
}

Icon ShapeMap::getIcon(std::string name)
{
	return _Icons[name];
}

IconButton ShapeMap::getIconButton(std::string name)
{
	return _IconButtons[name];
}

BuildingsWindowFrame ShapeMap::getBuildingsWindowFrame(std::string name)
{
	return _BuildingsWindowFrame[name];
}

TextInput ShapeMap::getTextInput(std::string name)
{
	return _TextInput[name];
}

EventBar ShapeMap::getEventBar(std::string name)
{
	return _EventBar[name];
}

