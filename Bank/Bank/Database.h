#pragma once
#include <fstream>
#include <time.h>
#include <iostream>
#include "Account.h"
#include "Defines.h"

class Account;

class Database {
	std::vector<Account*> _accounts;
	unsigned long long int _IDcount;

public:
	Database();
	~Database();

	void IncreaseIDcount();

	void ShowAccount(size_t param);
	void ShowAccounts();
	void ShowDebetAccounts();
	void ShowAccountHistory(int param);

	unsigned int CheckBalance(size_t param);
	void AddAccountToDatabase();
	void AddAccountToDatabase(Account * obj);
	void AddAccountToDatabase(unsigned int ID, std::string name, std::string surname, std::string login, std::string password);
	void AddAccountToDatabase(unsigned int ID, std::string name, std::string surname, std::string login, std::string password, double balance, unsigned short int permissions);
	void AddBalance(unsigned int id, double amount);
	void AddHistorySimple(unsigned int id, double balance, bool param);
	void AddHistoryAdvanced(unsigned int id, unsigned int idother, std::string topic, double balance);

	void Transfer(unsigned int id, unsigned int otherid, double balance);
	void DeleteAccount(size_t index);
	void ChangePassword(unsigned int id, std::string password);

	size_t IndexfromID(int id);
	unsigned short int PermissionsfromID(unsigned int id);
	int CheckPass(std::string login, std::string password);
	bool LoginExist(std::string login);
	bool DebetOverflow(int id, double amount);
	bool CheckPasswordWithID(unsigned int id, std::string password);

	// Gettery & Settery //

	void SetIDcount(unsigned long long int count);

	Account* GetAccount(size_t index);
	unsigned long long int GetIDcount();
	size_t GetAccountsSize();
	std::string GetName(unsigned int id);
	double GetBalance(unsigned int id);

};

