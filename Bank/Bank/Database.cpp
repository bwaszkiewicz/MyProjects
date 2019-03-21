#include "Database.h"

Database::Database()
{
}

Database::~Database()
{
	for (size_t i = 0; i < _accounts.size(); ++i)
		delete _accounts[i];
	_accounts.clear();
}

void Database::IncreaseIDcount()
{
	_IDcount++;
}

void Database::AddAccountToDatabase()
{
	Account *acc = new Account();
	_accounts.push_back(acc);
}

void Database::AddAccountToDatabase(Account * obj)
{
	_accounts.push_back(obj);
}

void Database::AddAccountToDatabase(unsigned int ID, std::string name, std::string surname, std::string login, std::string password)
{
	Account *acc = new Account(ID, name, surname, login, password);
	_accounts.push_back(acc);
}

void Database::AddAccountToDatabase(unsigned int ID, std::string name, std::string surname, std::string login, std::string password, double balance, unsigned short int permissions)
{
	Account *acc = new Account(ID, name, surname, login, password, balance, permissions);
	_accounts.push_back(acc);
}

void Database::ShowAccount(size_t param)
{
	std::cout << _accounts[param]->GetID() << " " << _accounts[param]->GetName() << " " << _accounts[param]->GetSurname() << " " << _accounts[param]->GetLogin() << " " << _accounts[param]->GetBalance() << std::endl;
}

void Database::ShowAccounts()
{
	size_t count = GetAccountsSize();
	for (size_t i = 0; i < count; ++i)
		std::cout << _accounts[i]->GetID() << " " << _accounts[i]->GetName() << " " << _accounts[i]->GetSurname() << " " << _accounts[i]->GetLogin() << " " << _accounts[i]->GetBalance() << std::endl;
}

void Database::ShowDebetAccounts()
{
	size_t count = GetAccountsSize();
	for (size_t i = 0; i < count; ++i)
		_accounts[i]->ViewDebetAccounts();
}

void Database::ShowAccountHistory(int param)
{
	size_t index = IndexfromID(param);
		_accounts[index]->ViewAccountHistory();
}

unsigned int Database::CheckBalance(size_t param)
{
	double balance = _accounts[param]->GetBalance();
	if (balance > 0)
		return 1;
	else
		if (balance < 0)
			return -1;
		else
			return 0;
}

void Database::Transfer(unsigned int id, unsigned int otherid, double balance)
{
	AddBalance(otherid, balance);
	balance *= (-1);
	AddBalance(id, balance);
}

void Database::DeleteAccount(size_t index)
{
	auto bufor = _accounts[index];
	_accounts.erase(_accounts.begin()+index);
	delete bufor;
}

void Database::ChangePassword(unsigned int id, std::string password)
{
	size_t index = IndexfromID(id);
	_accounts[index]->SetPassword(password);
}

void Database::AddBalance(unsigned int id, double amount)
{
	size_t index = IndexfromID(id);
	_accounts[index]->AddBalance(amount);
}

void Database::AddHistorySimple(unsigned int id, double balance, bool param)
{
	struct tm newtime;
	time_t long_time;
	_time64(&long_time);
	localtime_s(&newtime, &long_time);
	std::string s_balance = std::to_string(balance);
	s_balance = s_balance.substr(0, s_balance.length() - 4);
	std::string history;
	size_t index = IndexfromID(id);
	if (!param)
	{			// WPLATA //
		history = "[" + std::to_string(newtime.tm_mday) + "." + std::to_string(newtime.tm_mon + 1) + "." + std::to_string(newtime.tm_year + 1900) + "]" 
				+ " WPLATA " + s_balance + "zl";
		_accounts[index]->SetHistory(history);
	}
	else
	{			// WYPLATA //
		history = "[" + std::to_string(newtime.tm_mday) + "." + std::to_string(newtime.tm_mon + 1) + "." + std::to_string(newtime.tm_year + 1900) + "]"
			+ " WYPLATA " + s_balance + "zl";
		_accounts[index]->SetHistory(history);
	}
}

void Database::AddHistoryAdvanced(unsigned int id, unsigned int idother, std::string topic, double balance)
{
	struct tm newtime;
	time_t long_time;
	_time64(&long_time);
	localtime_s(&newtime, &long_time);
	std::string s_balance = std::to_string(balance);
	s_balance = s_balance.substr(0, s_balance.length() - 4);
	std::string history;

	size_t index = IndexfromID(id);
	size_t indexother = IndexfromID(idother);

	history = "[" + std::to_string(newtime.tm_mday) + "." + std::to_string(newtime.tm_mon + 1) + "." + std::to_string(newtime.tm_year + 1900) + "]"
		+ " TRANSFER DO uzytkownika o ID: " + std::to_string(idother) + " \"" + topic + "\"" + " NA KWOTE " + s_balance + "zl";
	_accounts[index]->SetHistory(history);

	history = "[" + std::to_string(newtime.tm_mday) + "." + std::to_string(newtime.tm_mon + 1) + "." + std::to_string(newtime.tm_year + 1900) + "]"
		+ " TRANSFER OD uzytkownika o ID: " + std::to_string(id) + " \"" + topic + "\"" + " NA KWOTE " + s_balance + "zl";
	_accounts[indexother]->SetHistory(history);
}

size_t Database::IndexfromID(int id)
{
	for(size_t i=0;i<_accounts.size();++i)
		if(_accounts[i]->GetID()==id)
			return i;
	return -1; // nie znaleziono indexu z danym id
}

unsigned short int Database::PermissionsfromID(unsigned int id)
{
	size_t index = IndexfromID(id);
	return _accounts[index]->GetPermissions();
}

int Database::CheckPass(std::string login, std::string password)
{
	for (size_t i = 0; i < _accounts.size(); ++i)
	{
		if ( _accounts[i]->GetLogin() == login && _accounts[i]->GetPassword() == password)
		{
			return _accounts[i]->GetID();
		}
	}
	return -1;
}

bool Database::LoginExist(std::string login)
{
	for (size_t i = 0; i < _accounts.size(); ++i)
	{
		if (_accounts[i]->GetLogin() == login)
			return true;
	}
	return false;
}

bool Database::DebetOverflow(int id, double amount)
{
	size_t index = IndexfromID(id);
	return _accounts[index]->DebetOverflow(amount);
}

bool Database::CheckPasswordWithID(unsigned int id, std::string password)
{
	size_t index = IndexfromID(id);
	if (_accounts[index]->GetPassword() == password)
		return true;
	else
		return false;
}


	// Gettery & Settery //

void Database::SetIDcount(unsigned long long int count)
{
	_IDcount = count;
}

Account * Database::GetAccount(size_t index)
{
	if (_accounts[index])
		return _accounts[index];
	else
		return nullptr;
}

unsigned long long int Database::GetIDcount()
{
	return _IDcount;
}

size_t Database::GetAccountsSize()
{
	return _accounts.size();
}

std::string Database::GetName(unsigned int id)
{
	size_t index = IndexfromID(id);
	return _accounts[index]->GetName();
}

double Database::GetBalance(unsigned int id)
{
	size_t index = IndexfromID(id);
	return _accounts[index]->GetBalance();
}

