#include "AddNewAccountMenu.h"

AddNewAccountMenu::AddNewAccountMenu(Database &Data, unsigned int id): _database(Data), _currentID(id), _nextPosition(1)
{
}

void AddNewAccountMenu::ShowMenu()
{
	system("cls");
	std::string name;
	std::string surname;
	std::string login;
	std::string password;
	DatabaseLoader Loader(_database, CurrentMode);
	Generator Generate;

	std::cout << "Dodawanie nowego konta" << std::endl << std::endl;
	std::cout << "Podaj imie" << std::endl;
	std::cin >> name;
	std::cout << "Podaj nazwisko" << std::endl;
	std::cin >> surname;
	login = Generate.GenerateLogin(name, surname, _database);
	password = Generate.GeneratePass();

	std::cout << "Zostanie zalozone konto: " << std::endl
		<< name << " " << surname << std::endl
		<< "Login " << login << std::endl
		<< "Haslo " << password << std::endl << std::endl
		<< "Czy chcesz zalozyc to konto? Jezeli tak wpisz \"tak\"" << std::endl;
	std::string decision;
	std::cin >> decision;
	if (decision == "tak")
	{
		_database.AddAccountToDatabase(_database.GetIDcount(), name, surname, login, password);
		_database.IncreaseIDcount();
		Loader.SaveDatabase();
		std::cout << "Konto zostalo prawidlowo zalozone" << std::endl;
		system("pause");
	}
	else
	{
		std::cout << "Konto nie zostalo zalozone" << std::endl;
		system("pause");
	}
}

unsigned short int AddNewAccountMenu::GetNextPosition()
{
	return _nextPosition;
}
