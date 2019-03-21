#pragma once
#include "DatabaseLoader.h"
#include "Generator.h"

class AddNewAccountMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

public:
	AddNewAccountMenu(Database &Data, unsigned int id);
	~AddNewAccountMenu() = default;

	void ShowMenu();
	unsigned short int GetNextPosition();
};