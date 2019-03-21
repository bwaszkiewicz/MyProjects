#pragma once
#include <iostream>
#include "Controller.h"


class MainMenu {
	unsigned short int _nextPosition;

	void ChoosePosition();
public:
	MainMenu() = default;
	~MainMenu() = default;
	void ShowMenu();
	unsigned short int GetNextPosition();
};