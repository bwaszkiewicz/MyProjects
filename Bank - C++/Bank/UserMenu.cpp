#include "UserMenu.h"

void UserMenu::ChoosePosition()
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

UserMenu::UserMenu(Database &Data, unsigned int id): _database(Data), _currentID(id)
{
}

void UserMenu::ShowMenu()
{
	system("cls");
	std::cout << "Witaj " << _database.GetName(_currentID) << std::endl
		<< "Srodki na koncie: " << _database.GetBalance(_currentID) << std::endl;
	std::cout << "Panel uzytkownika" << std::endl
		<< "1. Dodaj srodki" << std::endl
		<< "2. Wyplac srodki" << std::endl
		<< "3. Zrob przelew" << std::endl
		<< "4. Zobacz historie" << std::endl
		<< "5. Zmien haslo" << std::endl
		<< "6. Wyloguj" << std::endl;
	ChoosePosition();
}

unsigned short int UserMenu::GetNextPosition()
{
	return _nextPosition;
}
