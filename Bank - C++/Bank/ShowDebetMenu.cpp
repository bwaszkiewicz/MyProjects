#include "ShowDebetMenu.h"

ShowDebetMenu::ShowDebetMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void ShowDebetMenu::ShowMenu()
{
	system("cls");
	std::cout << "Konta z debetem: " << std::endl;
	_database.ShowDebetAccounts();
	system("pause");
}

unsigned short int ShowDebetMenu::GetNextPosittion()
{
	return _nextPosition;
}
