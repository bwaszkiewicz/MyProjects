#include "InGameMenu.h"

State * InGameWindow::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (Map.getTextButton("ReturnToGame") == in)
	{
		return new GameWindow;
	}
	else
		if (Map.getTextButton("ToMainMenu") == in)
			return new InGameExit;
		else
			if (in.getKey() == sf::Keyboard::Escape)
				return new GameWindow;
			else
		return nullptr;
}

void InGameWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
}

ShapeMap InGameWindow::render(const Data& MainData)
{
	ShapeMap Map;

	// RECTANGLES
	sf::RectangleShape Background(sf::Vector2f(WIDTH, HEIGHT));
	Background.setFillColor(sf::Color(50, 50, 50, 20));

	sf::RectangleShape MenuBackground(sf::Vector2f(WIDTH*0.40, HEIGHT*0.80));
	MenuBackground.setPosition(sf::Vector2f(WIDTH*0.3, HEIGHT*0.1));
	MenuBackground.setFillColor(sf::Color(100, 100, 100));

	// Adds Rectangles to ShapeMap
	
	Map.addRectangleShape("Background", Background);
	Map.addRectangleShape("MenuBackground", MenuBackground);

	// TextButtons

	TextButton ReturnToGame(WIDTH*0.2f, HEIGHT*0.1f, WIDTH*0.4f, HEIGHT*0.2f, sf::Color(200, 200, 200), WIDTH*0.2f*0.05f, HEIGHT*0.1f*0.25f, "Return to game", sf::Color(100, 100, 100));
	TextButton LoadGame(WIDTH*0.2f, HEIGHT*0.1f, WIDTH*0.4f, HEIGHT*0.35f, sf::Color(200, 200, 200), WIDTH*0.2f*0.2f, HEIGHT*0.35f*0.08f, "Load save", sf::Color(100, 100, 100));
	TextButton ToMainMenu(WIDTH*0.2f, HEIGHT*0.1f, WIDTH*0.4f, HEIGHT*0.5f, sf::Color(200, 200, 200), WIDTH*0.2f*0.15f, HEIGHT*0.5f*0.06f, "Leave game", sf::Color(100, 100, 100));

	Map.addTextButton("ReturnToGame", ReturnToGame);
	Map.addTextButton("LoadGame", LoadGame);
	Map.addTextButton("ToMainMenu", ToMainMenu);
	return Map;
}

void InGameWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.draw(Map.getRectangleShape("Background"));
	window.draw(Map.getRectangleShape("MenuBackground"));
	window.draw(Map.getTextButton("ReturnToGame"));
	window.draw(Map.getTextButton("LoadGame"));
	window.draw(Map.getTextButton("ToMainMenu"));
	window.display();
}
