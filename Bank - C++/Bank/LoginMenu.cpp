#include "LoginMenu.h"

void LoginMenu::ShowMenu()
{
	system("cls");
	std::string login;
	std::cout << "Logowanie" << std::endl;
	std::cout << "Podaj login" << std::endl;
	std::cin >> login;
	std::cout << "Podaj haslo" << std::endl;
	EnterPassword();
	int id = _database.CheckPass(login, _password);
	if (id != -1)
	{
		_ID = id;
		if (_database.PermissionsfromID(id) == 1)
			_nextPosition = 1;
		else
			_nextPosition = 2;
	}
	else
	{
		system("cls");
		std::cout << "Bledne dane logowania!" << std::endl;
		system("pause");
		_nextPosition = 3;
	}
}

unsigned int LoginMenu::GetID()
{
	return _ID;
}

unsigned short int LoginMenu::GetNextPosition()
{
	return _nextPosition;
}

void LoginMenu::EnterPassword()
{
	std::string password = "";
	char keypressed;
	while (1) 
	{
		keypressed = NULL;
		keypressed = _getch();
		if (((keypressed >= 60 && keypressed <= 90) || (keypressed >= 97 && keypressed <= 122) || (keypressed >= 48 && keypressed <= 57) || (keypressed >=33 && keypressed <=43)))
		{
			password += keypressed; 
			std::cout << "*";
		}
		else if (password.size()>0 && keypressed == 8)
		{
			password.resize(password.size() - 1); 
			gotoxy(0, 4);
			for (unsigned char l = 0; l<password.size(); l++) 
				std::cout << "*"; 
			std::cout << " "; 
			gotoxy(0 + password.size(), 4); 
		}
		else if (keypressed == 13) break; 
	}
	_password = password;
}

void LoginMenu::gotoxy(short x, short y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

LoginMenu::LoginMenu(Database &Data): _database(Data)
{
}
