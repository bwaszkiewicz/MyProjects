#include "BrickyardWindow.h"

State * BrickyardWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		return nullptr;
}

void BrickyardWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BrickyardFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BrickyardFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BrickyardFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BrickyardFrame", NewWindowFrame);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BrickyardFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BrickyardFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap BrickyardWindow::render(const Data & MainData)
{
	ShapeMap Map;

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame BrickyardFrame("img/Brickyard.png", "Brickyard", MainData);
	Map.addBuildingsWindowFrame("BrickyardFrame", BrickyardFrame);
	return Map;
}

void BrickyardWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getBuildingsWindowFrame("BrickyardFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	window.display();
}
