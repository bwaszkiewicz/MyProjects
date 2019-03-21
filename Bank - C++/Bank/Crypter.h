#pragma once
#include <string>
#include <vector>

class Crypter {
	unsigned long long int _p, _q, _e, _n, _k;

	friend class Database;
	friend class DatabaseLoader;
//public:
	Crypter();
	std::string EncryptString(std::string toencrypt);
	std::string DecryptString(std::string todecrypt);
	std::string to_binary(unsigned long long int a);
	unsigned long long int modular(unsigned long long int a, unsigned long long int b, unsigned long long int n); // (a^b) mod n = d
	std::vector <std::string> to_code(std::string a);
};