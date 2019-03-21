#pragma once
#include "Controller.h"
#include "Database.h"
class UserMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

	void ChoosePosition();
public:
	UserMenu(Database &Data, unsigned int id);
	~UserMenu() = default;
	void ShowMenu();
	unsigned short int GetNextPosition();
};