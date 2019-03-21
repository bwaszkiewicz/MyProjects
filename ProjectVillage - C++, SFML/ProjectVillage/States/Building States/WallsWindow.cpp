#include "WallsWindow.h"

State * WallsWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		return nullptr;
}

void WallsWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("WallsFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("WallsFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("WallsFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("WallsFrame", NewWindowFrame);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("WallsFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("WallsFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap WallsWindow::render(const Data & MainData)
{
	ShapeMap Map;

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame WallsFrame("img/Walls.png", "Walls", MainData);
	Map.addBuildingsWindowFrame("WallsFrame", WallsFrame);
	return Map;
}

void WallsWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getBuildingsWindowFrame("WallsFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	window.display();
}
