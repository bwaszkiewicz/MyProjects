#include "Generator.h"

std::string Generator::GeneratePass()
{
	std::string password = "";
	char x[15];
	int PassSize = 7 + rand() % 8, CodeChance;

	for (int i = 0; i < PassSize; ++i)
	{
		CodeChance = rand() % 64;
		if (CodeChance < 20)
			x[i] = 65 + rand() % 26; //UpperCase <65,90>
		else
			if (CodeChance < 40)
				x[i] = 97 + rand() % 26; //LowerCase <97,122>
			else
				if (CodeChance < 50)
					x[i] = 48 + rand() % 10;//Digits <48,57>
				else
					x[i] = 33 + rand() % 11; //SpecialSigns <33,43>
		password = password + x[i];
	}
	return password;
}

std::string Generator::GenerateLogin(std::string name, std::string surname, Database &Data)
{
	std::string login, bufor;;
	login = name.substr(0, 3) + surname.substr(0, 3);
	if (Data.LoginExist(login))
	{
		int i = 1;
		bufor = std::to_string(i);
		while (Data.LoginExist(login + bufor))
		{
			i++;
		}
		login = login + bufor;
	}

	return login;
}
