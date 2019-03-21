#pragma once
#include <string>
#include <vector>
#include "Database.h"
class AdminAccount;

class Account {
	unsigned int _ID;
	std::string _name;
	std::string _surname;
	std::string _login;
	std::string _password;
	double _balance;
	unsigned short int _permissions;
	std::vector <std::string> _history;
	double _maxdebet;


	void SetPassword(std::string password);
	void SetPermissions(unsigned short int permissions);
	void SetHistory(std::string history);

	void AddBalance(double addbalance);
	void RemoveBalance(double removebalance);

	void ViewAccountHistory();
	void ViewDebetAccounts();

	bool DebetOverflow(double amount);

	friend class Database;
	friend class DatabaseLoader;
public:

	Account();
	Account(unsigned int ID, std::string name, std::string surname, std::string login, std::string password);
	Account(unsigned int ID, std::string name, std::string surname, std::string login, std::string password, double balance, unsigned short int permissions);
	~Account();

	// Gettery & Settery //
	unsigned int GetID();
	std::string GetName();
	std::string GetSurname();
	std::string GetLogin();
	std::string GetPassword();
	double GetBalance();
	unsigned short int GetPermissions();
	size_t GetHistorySize();
	std::vector<std::string> GetHistory();
};