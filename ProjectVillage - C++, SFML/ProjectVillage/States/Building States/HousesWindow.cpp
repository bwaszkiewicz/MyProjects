#include "HousesWindow.h"

State * HousesWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		return nullptr;
}

void HousesWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("HousesFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("HousesFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("HousesFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("HousesFrame", NewWindowFrame);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("HousesFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("HousesFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap HousesWindow::render(const Data & MainData)
{
	ShapeMap Map;

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame HousesFrame("img/Houses.png", "Houses", MainData);
	Map.addBuildingsWindowFrame("HousesFrame", HousesFrame);
	return Map;
}

void HousesWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getBuildingsWindowFrame("HousesFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	window.display();
}
