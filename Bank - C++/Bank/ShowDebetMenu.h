#pragma once
#include "Database.h"
class ShowDebetMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

public:
	ShowDebetMenu(Database &Data, unsigned int id);
	~ShowDebetMenu() = default;

	void ShowMenu();
	unsigned short int GetNextPosittion();
};