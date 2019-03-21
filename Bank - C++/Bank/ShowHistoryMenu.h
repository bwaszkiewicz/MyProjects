#pragma once
#include "Database.h"

class ShowHistoryMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
public:
	ShowHistoryMenu(Database &Data, unsigned int id);
	~ShowHistoryMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();
};