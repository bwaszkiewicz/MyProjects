#pragma once
#include "DatabaseLoader.h"

class DeleteAccountMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

public:
	DeleteAccountMenu(Database &Data, unsigned int id);
	~DeleteAccountMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();

};