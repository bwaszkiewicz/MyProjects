#include "SmithyWindow.h"

State * SmithyWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		return nullptr;
}

void SmithyWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("SmithyFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("SmithyFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("SmithyFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("SmithyFrame", NewWindowFrame);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("SmithyFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("SmithyFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap SmithyWindow::render(const Data & MainData)
{
	ShapeMap Map;

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame SmithyFrame("img/Smithy.png", "Smithy", MainData);
	Map.addBuildingsWindowFrame("SmithyFrame", SmithyFrame);
	return Map;
}

void SmithyWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getBuildingsWindowFrame("SmithyFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	window.display();
}
