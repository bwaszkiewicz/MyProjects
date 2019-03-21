#include "ShowAccountHistoryMenu.h"

ShowAccountHistoryMenu::ShowAccountHistoryMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void ShowAccountHistoryMenu::ShowMenu()
{
	system("cls");
	int id;
	std::cout << "Podaj numer ID uzytkownika, ktorego historie chcesz wyswietlic: " << std::endl;
	while (1)
	{
		std::cin >> id;
		if (std::cin.fail() || _database.IndexfromID(id) == -1)
		{
			std::cout << "Zly format ID! / Nie ma takiego ID w systemie!" << std::endl;
			id = 0;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
			break;
	}
	_database.ShowAccountHistory(id);
	system("pause");
}

unsigned short int ShowAccountHistoryMenu::GetNextPosition()
{
	return _nextPosition;
}
