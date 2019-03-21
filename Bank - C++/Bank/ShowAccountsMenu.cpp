#include "ShowAccountsMenu.h"

ShowAccountsMenu::ShowAccountsMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void ShowAccountsMenu::ShowMenu()
{
	system("cls");
	std::cout << "Lista kont: " << std::endl;
	_database.ShowAccounts();
	system("pause");
}

unsigned short int ShowAccountsMenu::GetNextPosition()
{
	return _nextPosition;
}
