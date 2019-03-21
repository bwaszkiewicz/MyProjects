#pragma once
#include "Database.h"

class ShowAccountHistoryMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
public:
	ShowAccountHistoryMenu(Database &Data, unsigned int id);
	~ShowAccountHistoryMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();
};