#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "buttons/Button.h"
#include "buttons/TextButton.h"
#include "buttons/IconButton.h"
#include "drawable/Icon.h"
#include "drawable/BuildingsWindowFrame.h"
#include "drawable/TextInput.h"
#include "drawable/EventBar.h"

#include "exceptions/NoShapeMapLoadFontException.h"

class ShapeMap{
	std::map<std::string, sf::RectangleShape> _RectangleShapes;
	std::map<std::string, sf::CircleShape> _CircleShapes;
	std::map<std::string, sf::ConvexShape> _ConvexShapes;
	std::map<std::string, Button> _Buttons;
	std::map<std::string, TextButton> _TextButtons;
	std::map<std::string, sf::Text> _Text;
	std::map<std::string, Icon> _Icons;
	std::map<std::string, IconButton> _IconButtons;
	std::map<std::string, BuildingsWindowFrame> _BuildingsWindowFrame;
	std::map<std::string, TextInput> _TextInput;
	std::map<std::string, EventBar> _EventBar;


	sf::Font *loadFont(short int);
public:
	ShapeMap() = default;
	~ShapeMap() = default;
	void addRectangleShape(std::string name, sf::RectangleShape shape);
	void addCircleShape(std::string name, sf::CircleShape shape);
	void addConvexShape(std::string name, sf::ConvexShape shape);
	void addButton(std::string name, Button button);
	void addTextButton(std::string name, TextButton button);
	void addText(std::string name, sf::Text text, short int fontNumber);
	void addIcon(std::string name, Icon sprite);
	void addIconButton(std::string name, IconButton button);
	void addBuildingsWindowFrame(std::string name, BuildingsWindowFrame frame);
	void addTextInput(std::string name, TextInput textInput);
	void addEventBar(std::string name, EventBar eventBar);

	void setText(std::string name, sf::Text text);

	sf::RectangleShape getRectangleShape(std::string name);
	sf::CircleShape getCircleShape(std::string name);
	sf::ConvexShape getConvexShape(std::string name);
	Button getButton(std::string name);
	TextButton getTextButton(std::string name);
	sf::Text getText(std::string name);
	Icon getIcon(std::string name);
	IconButton getIconButton(std::string name);
	BuildingsWindowFrame getBuildingsWindowFrame(std::string name);
	TextInput getTextInput(std::string name);
	EventBar getEventBar(std::string name);
};