#include "TransferMenu.h"

TransferMenu::TransferMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void TransferMenu::ShowMenu()
{
	system("cls");
	DatabaseLoader Loader(_database, CurrentMode);
	Controller Control;
	unsigned int otherid;
	std::string topic;
	double amount;
	std::cout << "Podaj ID uzytkownika, ktoremu chcesz przelac pieniadze:" << std::endl;
	while (1)
	{
		std::cin >> otherid;
		if (std::cin.fail() || otherid==0)
		{
			std::cout << "Zly format ID!" << std::endl;
			otherid = 0;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
			break;
	}
	std::cout << "Podaj nazwe przelewu:" << std::endl;
	std::cin >> topic;
	std::cout << "Podaj kwote przelewu:" << std::endl;
	while (1)
	{
		std::cin >> amount;
		if (std::cin.fail() || amount < 0 || !Control.BalanceValidation(amount))
		{
			std::cout << "Zly format kwoty" << std::endl;
			amount = 0;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
			break;
	}

	if (_database.IndexfromID(otherid) == -1)
	{
		std::cout << "Uzytkownik o podanym ID nie istnieje!" << std::endl;
		std::cout << "Akcja zostala anulowana." << std::endl;
		system("pause");
		return void();
	}

	system("cls");
	std::cout << "Zostanie wykonany przelew: " << std::endl
		<< topic << std::endl
		<< "Na konto o numerze ID: " << otherid << std::endl
		<< "Na kwote: " << amount << " zl" << std::endl;
	std::cout << "Wpisz \"Potwierdzam\", jezeli chcesz wykonac przelew" << std::endl;
	std::string decision;
	std::cin >> decision;
	if (decision == "Potwierdzam" && !_database.DebetOverflow(_currentID, amount))
	{
		_database.Transfer(_currentID, otherid, amount);
		Loader.SaveDatabase();
		_database.AddHistoryAdvanced(_currentID, otherid, topic, amount);
		Loader.SaveHistory();
		std::cout << "Srodki zostaly przekazane." << std::endl;
	}
	else
	{
		if (_database.DebetOverflow(_currentID, amount))
			std::cout << "Przekroczenie limitu debetu!" << std::endl;
		std::cout << "Akcja zostala anulowana." << std::endl;
	}
	system("pause");
}

unsigned short int TransferMenu::GetNextPosition()
{
	return _nextPosition;
}
