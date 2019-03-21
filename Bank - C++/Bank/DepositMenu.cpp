#include "DepositMenu.h"

DepositMenu::DepositMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void DepositMenu::ShowMenu()
{
	system("cls");
	DatabaseLoader Loader(_database, CurrentMode);
	Controller Control;
	double amount;
	std::string decision;
	std::cout << "Podaj kwote ktora chcesz wplacic" << std::endl;
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
	std::cout << "Czy na pewno chcesz wplacic kwote " << amount << " zl do swojego konta?" << std::endl;
	std::cout << "Aby potwierdzic wpisz \"tak\"." << std::endl;
	std::cin >> decision;
	if (decision == "tak")
	{
		_database.AddBalance(_currentID, amount);
		Loader.SaveDatabase();
		_database.AddHistorySimple(_currentID, amount, 0);
		Loader.SaveHistory();
		std::cout << "Srodki zostaly dodane do konta." << std::endl;
	}
	else
	{
		std::cout << "Akcja zostala anulowana." << std::endl;
	}
	system("pause");
}

unsigned short int DepositMenu::GetNextPosition()
{
	return _nextPosition;
}
