#include "MainMenu.h"

State * MainMenu::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (Map.getTextButton("NewGame")==in)
	{
		evHandler.setEventHandlerLocker(false);
		return new GameWindow;
	}
	else
		if (Map.getTextButton("Exit") == in)
		{
			return new ExitWindow;
		}
		else
	return nullptr;
}

void MainMenu::update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case ENDGAME_UPDATE:
	{
		MainData.clearData();
	}
	break;
	default:
		break;
	}
}

ShapeMap MainMenu::render(const Data& MainData)
{
	ShapeMap Map;
	TextButton NewGame(400, 75, 400, 200, sf::Color(100, 100, 100), 140, 20, "Nowa gra", sf::Color(250, 250, 250));
	TextButton LoadGame(400, 75, 400, 300, sf::Color(100, 100, 100), 130, 20, "Wczytaj gre", sf::Color(250, 250, 250));
	TextButton Exit(400, 75, 400, 400, sf::Color(100, 100, 100), 150, 20, "Wyjscie", sf::Color(250, 250, 250));
	Map.addTextButton("NewGame", NewGame);
	Map.addTextButton("LoadGame", LoadGame);
	Map.addTextButton("Exit", Exit);
	return Map;
}

void  MainMenu::show(sf::RenderWindow& window, ShapeMap Map)
{
	window.clear(sf::Color::Black);

	window.draw(Map.getTextButton("NewGame"));
	window.draw(Map.getTextButton("LoadGame"));
	window.draw(Map.getTextButton("Exit"));

	window.display();
}
