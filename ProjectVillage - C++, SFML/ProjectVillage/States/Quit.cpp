#include "Quit.h"

State * Quit::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	return nullptr;
}

void Quit::update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler)
{
}

ShapeMap Quit::render(const Data& MainData)
{
	ShapeMap Map;
	return Map;
}

void Quit::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.close();
}
