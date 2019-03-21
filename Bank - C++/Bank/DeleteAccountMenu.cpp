#include "DeleteAccountMenu.h"

DeleteAccountMenu::DeleteAccountMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void DeleteAccountMenu::ShowMenu()
{
	system("cls");
	DatabaseLoader Loader(_database, CurrentMode);
	unsigned int chosenID;
	size_t index;
	std::string decision;
	std::cout << "Podaj ID konta ktore chcesz usunac" << std::endl;
	std::cin >> chosenID;
	if (chosenID == _currentID)
	{
		std::cout << "Nie mozna usunac konta na ktore jestes zalogowany!" << std::endl;
		_nextPosition = 1;
		return void();
	}

	index = _database.IndexfromID(chosenID);
	if (index != -1)
	{
		std::cout << "Czy na pewno chcesz usunac konto:" << std::endl;
		_database.ShowAccount(index);
		std::cout << "Wpisz \"Potwierdzam\", aby usunac konto" << std::endl;
		std::cin >> decision;
		if (decision == "Potwierdzam")
		{
			switch (_database.CheckBalance(index))
			{
			case -1:
				std::cout << "Nie mozna usunac konta z debetem!" << std::endl;
				system("pause");
				break;
			case 0:
				_database.DeleteAccount(index);
				Loader.SaveDatabase();
				std::cout << "Konto zostalo usuniete." << std::endl;
				system("pause");
				break;
			case 1:
				std::cout << "Nie mozna usunac konta ze srodkami!" << std::endl;
				system("pause");
				break;
			}
		}
		else
		{
			std::cout << "Konto nie zostalo usuniete" << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << "Takie konto nie istnieje!" << std::endl;
		system("pause");
	}
}

unsigned short int DeleteAccountMenu::GetNextPosition()
{
	return _nextPosition;
}
