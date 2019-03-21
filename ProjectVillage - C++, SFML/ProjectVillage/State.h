#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Input.h"
#include "ShapeMap.h"
#include "Defines.h"
#include "data\Data.h"
#include "handlers/TextHandler.h"
#include "handlers/EventHandler.h"
#include "drawable/Icon.h"

class State
{
public:
	virtual State* handleInput(Input, ShapeMap, EventHandler&) = 0;
	virtual void update(ShapeMap&, Data&, short int updateCode, EventHandler& evHandler) = 0;
	virtual ShapeMap render(const Data&) = 0;
	virtual void show(sf::RenderWindow&, ShapeMap) = 0;
};