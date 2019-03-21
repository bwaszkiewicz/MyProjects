#pragma once
#include <SFML/Graphics.hpp>
#include "StateMachine.h"

class MainLoop
{
public:
	MainLoop() = default;
	~MainLoop() = default;
	void loop();
};