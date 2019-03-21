#pragma once
#include "State.h"
#include "ShapeMap.h"
#include "States/MainMenu.h"


class StateMachine
{
	State* currentState;
	sf::RenderWindow& _window;
	ShapeMap _currentShapeMap;
	Data _MainData;
public:
	StateMachine(sf::RenderWindow &window);
	~StateMachine();
	void show();
	void update(short int updateCode, EventHandler& evHandler);
	void handleInput(Input in, EventHandler& evHandler);
	void changeState(State*);
};