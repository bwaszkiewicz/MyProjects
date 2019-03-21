#pragma once
#include "DatabaseLoader.h"
#include "Controller.h"
class TransferMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;
public:
	TransferMenu(Database &Data, unsigned int id);
	~TransferMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();
};