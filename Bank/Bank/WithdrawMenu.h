#pragma once
#include "DatabaseLoader.h"
#include "Controller.h"
class WithdrawMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
public:
	WithdrawMenu(Database &Data, unsigned int id);
	~WithdrawMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();
};