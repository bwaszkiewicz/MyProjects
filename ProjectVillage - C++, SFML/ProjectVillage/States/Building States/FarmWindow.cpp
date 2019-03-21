#include "FarmWindow.h"

State * FarmWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		return nullptr;
}

void FarmWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("FarmFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("FarmFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("FarmFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("FarmFrame", NewWindowFrame);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("FarmFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("FarmFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap FarmWindow::render(const Data & MainData)
{
	ShapeMap Map;

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame FarmFrame("img/Farm.png", "Farm", MainData);
	Map.addBuildingsWindowFrame("FarmFrame", FarmFrame);
	return Map;
}

void FarmWindow::show(sf::RenderWindow & window, ShapeMap Map)
{

	window.clear(sf::Color::Black);
	window.draw(Map.getBuildingsWindowFrame("FarmFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	window.display();
}
