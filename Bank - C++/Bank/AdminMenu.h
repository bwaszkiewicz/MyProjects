#pragma once
#include "Controller.h"
#include "Database.h"
class AdminMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
	void ChoosePosition();
public:
	AdminMenu(Database &Data, unsigned int id);
	~AdminMenu() = default;
	void ShowMenu();
	unsigned short int GetNextPosition();
};