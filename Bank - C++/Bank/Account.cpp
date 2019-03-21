#include "Account.h"

Account::Account()
{
	_ID = 0;
	_name = "John";
	_surname = "Doe";
	_login = "admin1234";
	_password = "a123A!";
	_balance = 0;
	_permissions = 1;
	_maxdebet = -1000;
}

Account::Account(unsigned int ID, std::string name, std::string surname, std::string login, std::string password) : _ID(ID), _name(name), _surname(surname), _login(login), _password(password), _balance(0), _permissions(0), _maxdebet(-1000)
{
}

Account::Account(unsigned int ID, std::string name, std::string surname, std::string login, std::string password, double balance, unsigned short int permissions) : _ID(ID), _name(name), _surname(surname), _login(login), _password(password), _balance(balance), _permissions(permissions), _maxdebet(-1000)
{
}

Account::~Account()
{
	_history.clear();
}

void Account::SetPassword(std::string password)
{
	_password = password;
}

void Account::SetPermissions(unsigned short int permissions)
{
	_permissions = permissions;
}

void Account::SetHistory(std::string history)
{
	_history.push_back(history);
}

void Account::AddBalance(double addbalance)
{
	_balance += addbalance;
}

void Account::RemoveBalance(double removebalance)
{
	_balance -= removebalance;
}

void Account::ViewAccountHistory()
{
	for (size_t i = 0; i < _history.size(); ++i)
		std::cout << _history[i] << std::endl;
}

void Account::ViewDebetAccounts()
{
	if (_balance < 0)
	{
		std::cout << _ID << " " << _name << " " << _surname << " " << _login << " " << _balance << std::endl;
	}
}

bool Account::DebetOverflow(double amount)
{
	if (_balance - amount < _maxdebet)
		return true;
	else
		return false;
	return false;
}




// Gettery i Settery

unsigned int Account::GetID()
{
	return _ID;
}

std::string Account::GetName()
{
	return _name;
}

std::string Account::GetSurname()
{
	return _surname;
}

std::string Account::GetLogin()
{
	return _login;
}

std::string Account::GetPassword()
{
	return _password;
}

double Account::GetBalance()
{
	return _balance;
}

unsigned short int Account::GetPermissions()
{
	return _permissions;
}

size_t Account::GetHistorySize()
{
	return _history.size();
}

std::vector<std::string> Account::GetHistory()
{
	return _history;
}

