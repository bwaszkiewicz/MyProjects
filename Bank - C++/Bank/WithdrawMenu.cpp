#include "WithdrawMenu.h"

WithdrawMenu::WithdrawMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void WithdrawMenu::ShowMenu()
{
	system("cls");
	DatabaseLoader Loader(_database, CurrentMode);
	Controller Control;
	double amount;
	std::string decision;
	std::cout << "Podaj kwote ktora chcesz wyplacic" << std::endl;
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
	std::cout << "Czy na pewno chcesz wyplacic kwote " << amount << " zl ze swojego konta?" << std::endl;
	std::cout << "Aby potwierdzic wpisz \"tak\"." << std::endl;
	std::cin >> decision;
	if (decision == "tak" && !_database.DebetOverflow(_currentID, amount))
	{
		amount = amount*(-1);
		_database.AddBalance(_currentID, amount);
		Loader.SaveDatabase();
		_database.AddHistorySimple(_currentID, amount, 1);
		Loader.SaveHistory();
		std::cout << "Srodki zostaly wyplacone." << std::endl;
	}
	else
	{
		if (_database.DebetOverflow(_currentID, amount))
			std::cout << "Przekroczenie limitu debetu!" << std::endl;
		std::cout << "Akcja zostala anulowana." << std::endl;
	}
	system("pause");
}

unsigned short int WithdrawMenu::GetNextPosition()
{
	return _nextPosition;
}
