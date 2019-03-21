#include "ChangePasswordMenu.h"

std::string ChangePasswordMenu::EnterPassword(unsigned int param)
{
	unsigned short int tab[3] = { 2,11,13 };
	std::string password = "";
	char keypressed;
	while (1)
	{
		keypressed = NULL;
		keypressed = _getch();
		if (((keypressed >= 60 && keypressed <= 90) || (keypressed >= 97 && keypressed <= 122) || (keypressed >= 48 && keypressed <= 57) || (keypressed >= 33 && keypressed <= 43)))
		{
			password += keypressed;
			std::cout << "*";
		}
		else if (password.size()>0 && keypressed == 8)
		{
			password.resize(password.size() - 1);
			gotoxy(0, tab[param]);
			for (unsigned char l = 0; l<password.size(); l++) 
				std::cout << "*";
			std::cout << " ";
			gotoxy(0 + password.size(), tab[param]);
		}
		else if (keypressed == 13) break;
	}
	return password;
}

void ChangePasswordMenu::gotoxy(short x, short y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

ChangePasswordMenu::ChangePasswordMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void ChangePasswordMenu::ShowMenu()
{
	system("cls");
	Controller Control;
	DatabaseLoader Loader(_database, CurrentMode);
	std::string oldpassword;
	std::string newpassword;
	std::string tempnewpassword;
	std::cout << "Zmiana hasla" << std::endl
		<< "Podaj stare haslo" << std::endl;
	oldpassword = EnterPassword(0);
	std::cout << std::endl;
	if (!_database.CheckPasswordWithID(_currentID, oldpassword))
	{
		std::cout << "Niepoprawne haslo!" << std::endl
			<< "Nastapi powrot do poprzedniego menu" << std::endl;
		system("pause");
		return void();
	}
	std::cout << "Pamietaj, ze nowe haslo powinno spelniac nastepujace warunki:" << std::endl
		<< "- Minimalna dlugosc 7 znakow" << std::endl
		<< "- Haslo musi zawierac co najmniej jedna duza i mala litere" << std::endl
		<< "- Haslo musi zawierac co najmniej jedna cyfre" << std::endl
		<< "- Haslo musi zawierac co najmniej jeden znak specjalny" << std::endl
		<< "- Haslo nie moze zawierac znaku spacji" << std::endl << std::endl;
	std::cout << "Podaj nowe haslo" << std::endl;
	newpassword = EnterPassword(1);
	std::cout << std::endl;
	std::cout << "Podaj nowe haslo jeszcze raz" << std::endl;
	tempnewpassword = EnterPassword(2);
	std::cout << std::endl;
	if (newpassword == tempnewpassword)
	{
		if (Control.CheckPasswordNorm(newpassword))
		{
			_database.ChangePassword(_currentID, newpassword);
			Loader.SaveDatabase();
			std::cout << "Haslo zostalo zmienione!" << std::endl;
			system("pause");
			return void();
		}
		else
		{
			std::cout << "Haslo nie spelnia warunkow!" << std::endl;
			system("pause");
			return void();
		}
	}
	else
	{
		std::cout << "Podane hasla sie nie sa takie same" << std::endl;
		system("pause");
		return void();
	}
}

unsigned short int ChangePasswordMenu::GetNextPosition()
{
	return _nextPosition;
}
