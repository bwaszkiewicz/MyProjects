#include "ExitWindow.h"

State * ExitWindow::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (Map.getTextButton("Exit") == in)
	{
		return new Quit;
	}
	else
		if (Map.getTextButton("Cancel") == in)
		{
			return new MainMenu;
		}

	return nullptr;
}

void ExitWindow::update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler)
{
}

ShapeMap ExitWindow::render(const Data& MainData)
{
	ShapeMap Map;
	TextButton Caption(600, 400, 300, 200, sf::Color(100, 100, 100), 75, 100, "Czy na pewno chcesz opuscic gre?", sf::Color(250, 250, 250));
	TextButton Exit(200, 75, 350, 450, sf::Color(80, 80, 80), 55, 20, "Wyjdz", sf::Color(250, 250, 250));
	TextButton Cancel(200, 75, 650, 450, sf::Color(80, 80, 80), 55, 20, "Anuluj", sf::Color(250, 250, 250));
	Map.addTextButton("Caption",Caption);
	Map.addTextButton("Exit", Exit);
	Map.addTextButton("Cancel", Cancel);

	return Map;
}

void ExitWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.draw(Map.getTextButton("Caption"));
	window.draw(Map.getTextButton("Exit"));
	window.draw(Map.getTextButton("Cancel"));
	window.display();
}
