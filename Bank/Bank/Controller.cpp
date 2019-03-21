#include "Controller.h"

bool Controller::CheckChoosePosition(unsigned int maxPosition, unsigned short int input)
{
	if (input <= maxPosition && input > 0)
		return true;
	else
		return false;
}

bool Controller::CheckPasswordNorm(std::string password)
{
	int tab[4] = {0};
	int symbol;
	if (password.length() < 7)
		return false;
	else
	{
		for (unsigned int i = 0; i < password.length(); ++i)
		{
			symbol = password[i];
			if (96 < symbol && symbol < 123)
				tab[0]++;
			else
				if (64 < symbol && symbol < 91)
					tab[1]++;
				else
					if (47 < symbol && symbol < 58)
						tab[2]++;
					else
						if (32 < symbol && symbol < 44 || symbol == 64 || symbol == 94)
							tab[3]++;
		}
		if (tab[0] > 0 && tab[1] > 0 && tab[2] > 0 && tab[3] > 0)
			return true;
	}
	return false;
}

bool Controller::BalanceValidation(double balance)
{
	std::string valid = std::to_string(balance);
	valid = valid.substr(valid.length() - 4, valid.length());
	for (unsigned int i = 0; i < valid.length(); ++i)
	{
		if (valid[i] != '0')
			return false;
	}
	return true;
}

