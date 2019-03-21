#include "InGameExit.h"

State * InGameExit::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (Map.getTextButton("ExitButton") == in)
	{
		evHandler.setCleanDataLocker(false);
		return new MainMenu;
	}
	else
		if (Map.getTextButton("SaveButon") == in)
			return nullptr;
		else if (Map.getTextButton("ReturnButton") == in)
			return new GameWindow;
		else
			return nullptr;
}

void InGameExit::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
}

ShapeMap InGameExit::render(const Data & MainData)
{
	ShapeMap Map;

	// Rectangles
	sf::RectangleShape ExitMenuBackground(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.5f));
	ExitMenuBackground.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.25f));
	ExitMenuBackground.setFillColor(sf::Color(100, 100, 100));

	Map.addRectangleShape("ExitMenuBackground", ExitMenuBackground);

	//Text
	sf::Text ExitAsk;
	ExitAsk.setFillColor(sf::Color(255,255,255));
	ExitAsk.setString("Do you want to leave without saving?");
	ExitAsk.setPosition(WIDTH*0.3f, HEIGHT*0.33f);

	Map.addText("ExitAsk", ExitAsk, defaultFont);

	//Buttons

	TextButton ExitButton(WIDTH*0.13f, HEIGHT*0.1f, WIDTH*0.27f, HEIGHT*0.55f, sf::Color(80, 80, 80), WIDTH*0.27f*0.14f, HEIGHT*0.4f*0.08f, "Exit", sf::Color(255, 255, 255));
	TextButton SaveButton(WIDTH*0.13f, HEIGHT*0.1f, WIDTH*0.44f, HEIGHT*0.55f, sf::Color(80, 80, 80), WIDTH*0.44f*0.08f, HEIGHT*0.4f*0.08f, "Save", sf::Color(255, 255, 255));
	TextButton ReturnButton(WIDTH*0.13f, HEIGHT*0.1f, WIDTH*0.6f, HEIGHT*0.55f, sf::Color(80, 80, 80), WIDTH*0.6f*0.04f, HEIGHT*0.4f*0.08f, "Cancel", sf::Color(255, 255, 255));

	Map.addTextButton("ExitButton", ExitButton);
	Map.addTextButton("SaveButton", SaveButton);
	Map.addTextButton("ReturnButton", ReturnButton);


	return Map;
}

void InGameExit::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getRectangleShape("ExitMenuBackground"));
	window.draw(Map.getText("ExitAsk"));
	window.draw(Map.getTextButton("ExitButton"));
	window.draw(Map.getTextButton("SaveButton"));
	window.draw(Map.getTextButton("ReturnButton"));
	window.display();
}
