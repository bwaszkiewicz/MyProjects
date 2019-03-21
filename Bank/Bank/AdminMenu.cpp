#include "AdminMenu.h"

void AdminMenu::ChoosePosition()
{
	Controller Control;
	unsigned short int choosen;
	std::cout << std::endl << "Wybierz pozycje" << std::endl;
	while (1)
	{
		std::cin >> choosen;
		if (std::cin.fail() || !Control.CheckChoosePosition(6, choosen))
		{
			std::cout << "Brak pozycji" << std::endl;
			choosen = 0;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
			break;
	}
	_nextPosition = choosen;
}

AdminMenu::AdminMenu(Database &Data, unsigned int id): _database(Data), _currentID(id)
{
}

void AdminMenu::ShowMenu()
{
	system("cls");
		std::cout << "Witaj " << _database.GetName(_currentID) << std::endl;
		std::cout << "Panel Administratora" << std::endl;
		std::cout << "1. Dodaj nowe konto" << std::endl
			<< "2. Usun konto" << std::endl
			<< "3. Zobacz liste kont" << std::endl
			<< "4. Zobacz historie konta" << std::endl
			<< "5. Zobacz liste debetow" << std::endl
			<< "6. Wyloguj" << std::endl;
		ChoosePosition();
}

unsigned short int AdminMenu::GetNextPosition()
{
	return _nextPosition;
}
