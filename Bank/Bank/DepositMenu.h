#pragma once
#include "DatabaseLoader.h"
#include "Controller.h"
class DepositMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

public:
	DepositMenu(Database &Data, unsigned int id);
	~DepositMenu() = default;

	void ShowMenu();
	unsigned short int GetNextPosition();
};