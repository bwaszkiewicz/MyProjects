#pragma once
#include "Database.h"

class ShowAccountsMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
public:
	ShowAccountsMenu(Database &Data, unsigned int id);
	~ShowAccountsMenu() = default;
	
	void ShowMenu();

	unsigned short int GetNextPosition();
};