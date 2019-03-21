#include "StateMachine.h"

StateMachine::StateMachine(sf::RenderWindow &window) : currentState(new MainMenu), _window(window)
{
	_currentShapeMap = currentState->render(_MainData);
}

StateMachine::~StateMachine()
{
	delete currentState;
}

void StateMachine::show()
{
	currentState->show(_window, _currentShapeMap);
}

void StateMachine::update(short int updateCode, EventHandler& evHandler)
{
	currentState->update(_currentShapeMap, _MainData, updateCode, evHandler);
}

void StateMachine::handleInput(Input in, EventHandler& evHandler)
{
	State* temp = currentState->handleInput(in, _currentShapeMap, evHandler);
	if(temp!=nullptr)			// Jezeli uzytkownik kliknie na zaden button etc.
		changeState(temp);
	return void();
}

void StateMachine::changeState(State * newState)
{
	delete currentState;
	currentState = newState;
	_currentShapeMap = currentState->render(_MainData);
	currentState->show(_window, _currentShapeMap);
}