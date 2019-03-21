#pragma once
#include "../State.h"
#include "InGameMenu.h"

#include "Building States/TownhallWindow.h"
#include "Building States/LumbermillWindow.h"
#include "Building States/BrickyardWindow.h"
#include "Building States/MineWindow.h"
#include "Building States/FarmWindow.h"
#include "Building States/BarrackWindow.h"
#include "Building States/StableWindow.h"
#include "Building States/SmithyWindow.h"
#include "Building States/HousesWindow.h"
#include "Building States/WallsWindow.h"
#include "Endgame States/StarveEndgameWindow.h"
#include "Endgame States/AttackEndgameWindow.h"

#include "../drawable/EventBar.h"

#include "../handlers/BattleHandler.h"
#include "../BattleEngine.h"

#include "../exceptions/InvalidEventIDException.h"
class GameWindow : public State
{
public:
	State* handleInput(Input in, ShapeMap Map, EventHandler& evHandler) override;
	void update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler) override;
	ShapeMap render(const Data& MainData) override;
	void show(sf::RenderWindow &window, ShapeMap Map) override;
};