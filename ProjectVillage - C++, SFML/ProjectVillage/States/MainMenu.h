#pragma once
#include <vector>
#include "../State.h"
#include "GameWindow.h"
#include "ExitWindow.h"

class MainMenu : public State
{
public:
	State* handleInput(Input in, ShapeMap Map, EventHandler& evHandler) override;
	void update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler) override;
	ShapeMap render(const Data& MainData) override;
	void show(sf::RenderWindow &window, ShapeMap Map) override;
};