#pragma once
#include "DatabaseLoader.h"
#include "Controller.h"
#include <conio.h>
#include <windows.h>

class ChangePasswordMenu {
	Database &_database;
	unsigned short int _nextPosition;
	unsigned int _currentID;

	std::string EnterPassword(unsigned int param);
	void gotoxy(short x, short y);
public:
	ChangePasswordMenu(Database &Data, unsigned int id);
	~ChangePasswordMenu() = default;

	void ShowMenu();

	unsigned short int GetNextPosition();
};