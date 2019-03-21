#include "ShowHistoryMenu.h"

ShowHistoryMenu::ShowHistoryMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void ShowHistoryMenu::ShowMenu()
{
	system("cls");
	std::cout << "Twoja historia konta: " << std::endl;
	_database.ShowAccountHistory(_currentID);
	system("pause");
}

unsigned short int ShowHistoryMenu::GetNextPosition()
{
	return _nextPosition;
}
