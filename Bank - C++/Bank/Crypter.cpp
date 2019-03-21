#include "Crypter.h"

Crypter::Crypter()
{
	_p = 11;
	_q = 17;
	_e = 7;
	_n = _p*_q;
	_k = ((_p - 1)*(_q - 1) + 1) / _e;
}

std::string Crypter::EncryptString(std::string toencrypt)
{
	std::vector <std::string> code;
	code = to_code(toencrypt);
	std::string output = "";
	std::string temp;
	for (size_t i = 0; i < code.size(); ++i)
	{
		temp = std::to_string(modular(atoi(code[i].c_str()), _e, _n));
		switch (temp.length())
		{
		case 1:
			output += "00" + temp;
			break;
		case 2:
			output += "0" + temp;
			break;
		case 3:
			output += temp;
			break;
		}
	}
	return output;
}

std::string Crypter::DecryptString(std::string todecrypt)
{
	unsigned int cryptCode;
	std::string output = "";
	std::string temp;
	std::string temp2;
	int code;
	for (unsigned int i = 0; i < todecrypt.length() / 3; i++)
	{
		temp = todecrypt.substr(3 * i, 3);
		cryptCode = atoi(temp.c_str());
		code = modular(cryptCode, _k, _n);
		temp2 = (char)code;
		output += temp2;
	}
	return output;
}

std::string Crypter::to_binary(unsigned long long int a)
{
	std::string wej = "";
	while (a > 0)
	{
		if (a % 2 == 1)
		{
			wej += '1';
		}
		else
		{
			wej += '0';
		}
		a /= 2;
	}
	return wej;
}

unsigned long long int Crypter::modular(unsigned long long int a, unsigned long long int b, unsigned long long int n) // (a^b mod n) = d
{
	std::string b_binary = to_binary(b);
	unsigned long long int d = 1;
	for (long long int i = b_binary.length() - 1; i>-1; --i)
	{
		d = (d*d) % n;
		if (b_binary[i] == '1')
		{
			d = (d*a) % n;
		}
	}
	return d;
}

std::vector<std::string> Crypter::to_code(std::string a)
{
	std::string wyj_s = "";
	int wyj_i;
	std::vector <std::string> tab;
	for (size_t i = 0; i<a.length(); i++)
	{
		wyj_i = a[i];
		if (std::to_string(wyj_i).length() == 3)
			wyj_s = std::to_string(wyj_i);
		else
			if (std::to_string(wyj_i).length() == 2)
				wyj_s = "0" + std::to_string(wyj_i);
			else
				wyj_s = "00" + std::to_string(wyj_i);
		tab.push_back(wyj_s);
	}
	return tab;
}