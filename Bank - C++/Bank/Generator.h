#pragma once
#include "Database.h"
class Generator {
public:
	Generator() = default;
	~Generator() = default;
	std::string GeneratePass();
	std::string GenerateLogin(std::string name, std::string surname, Database &Data);
};