#pragma once
#include <conio.h>
#include <windows.h>
#include "Database.h"

class LoginMenu {
	Database &_database;
	std::string _password;
	unsigned short int _nextPosition;
	unsigned int _ID;
	void EnterPassword();
	void gotoxy(short x, short y);
public:
	LoginMenu(Database &Data);
	~LoginMenu() = default;
	void ShowMenu();
	unsigned int GetID();
	unsigned short int GetNextPosition();

};