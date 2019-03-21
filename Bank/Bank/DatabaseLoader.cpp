#include "DatabaseLoader.h"


bool DatabaseLoader::LoadDatabase()
{
	switch (_mode)
	{
	case 0:
	{
		Crypter Crypt;
		std::ifstream datain_s("data_s.txt", std::ios::binary);
		bool done = false;
		unsigned int ID;
		std::string name;
		std::string surname;
		std::string login;
		std::string password;
		double balance;
		unsigned short int permissions;

		std::string temp;
		size_t point;
		size_t pointT;
		if (datain_s.good())
		{
			getline(datain_s, temp, '\0');
			//datain_s >> temp;
			_Data.SetIDcount(atoi(Crypt.DecryptString(temp).c_str()));
			while (!datain_s.eof())
			{
				//datain_s >> temp;
				getline(datain_s, temp, '\0');
				temp = Crypt.DecryptString(temp);
				point = temp.find(" ");
				ID = atoi(temp.substr(0, point).c_str());									// ID

				pointT = temp.find(" ", point + 1);
				name = temp.substr(point + 1, pointT - point - 1);							// NAME

				point = temp.find(" ", pointT + 1);
				surname = temp.substr(pointT + 1, point - pointT - 1);						// SURNAME

				pointT = temp.find(" ", point + 1);
				login = temp.substr(point + 1, pointT - point - 1);							// LOGIN

				point = temp.find(" ", pointT + 1);
				password = temp.substr(pointT + 1, point - pointT - 1);						// PASSWORD

				pointT = temp.find(" ", point + 1);
				balance = atof(temp.substr(point + 1, pointT - point - 1).c_str());			// BALANCE

				point = temp.find(" ", pointT + 1);
				permissions = atoi(temp.substr(pointT + 1, point - pointT - 1).c_str());	// PERMISSIONS

				if (datain_s.eof())
					break;
				_Data.AddAccountToDatabase(ID, name, surname, login, password, balance, permissions);
			}
			done = true;
		}
		else
		{
			std::cout << "Brak pliku bazy do wczytania." << std::endl
				<< "Zostala utworzona nowa baza" << std::endl;
			system("pause");
		}
		datain_s.close();
		return done;
		break;
	}
	case 1:
	{
		std::ifstream datain("data.txt");
		bool done = false;
		unsigned int ID;
		unsigned long long int IDcount;
		std::string name;
		std::string surname;
		std::string login;
		std::string password;
		double balance;
		unsigned short int permissions;
		if (datain.good())
		{
			datain >> IDcount;
			_Data.SetIDcount(IDcount);
			while (!datain.eof())
			{
				datain >> ID >> name >> surname >> login >> password >> balance >> permissions;
				if (datain.eof())
					break;
				_Data.AddAccountToDatabase(ID, name, surname, login, password, balance, permissions);
			}
			done = true;
		}
		else
		{
			std::cout << "Brak pliku bazy do wczytania." << std::endl
				<< "Zostala utworzona nowa baza" << std::endl;
			system("pause");
		}
		datain.close();
		return done;
		break;
	}
	}
	return false;
}

bool DatabaseLoader::LoadHistory()
{
	switch (_mode)
	{
	case 0:
	{
		Crypter Crypt;
		std::ifstream historyin_s("history_s.txt", std::ios::binary);
		bool done = false;
		unsigned int currentid;
		size_t index;
		int historysize;
		std::string history;

		std::string temp;
		size_t point;
		size_t pointT;

		size_t AccountSize = _Data.GetAccountsSize();
		if (historyin_s.good())
		{
			for (size_t i = 0; i < AccountSize; ++i)
			{
				getline(historyin_s, temp, '\0');
				temp = Crypt.DecryptString(temp);

				point = temp.find(" ");
				currentid = atoi(temp.substr(0, point).c_str()); // CURRENT ID

				pointT = temp.find(" ", point + 1);
				historysize = atoi(temp.substr(point + 1, pointT - point - 1).c_str());
				for (int j = 0; j < historysize; ++j)
				{
					index = _Data.IndexfromID(currentid);
					getline(historyin_s, temp, '\0');
					_Data.GetAccount(index)->SetHistory(Crypt.DecryptString(temp));

				}
			}
			done = true;
		}
		historyin_s.close();
		return done;
		break;
	}
	case 1:
	{
		std::ifstream historyin("history.txt");
		bool done = false;
		unsigned int currentid;
		size_t index;
		int historysize;
		std::string history;

		size_t AccountSize = _Data.GetAccountsSize();
		if (historyin.good())
		{
			for (size_t i = 0; i < AccountSize; ++i)
			{
				historyin >> currentid >> historysize;
				getline(historyin, history);
				for (int j = 0; j < historysize; ++j)
				{
					index = _Data.IndexfromID(currentid);
					getline(historyin, history);
					_Data.GetAccount(index)->SetHistory(history);
				}
			}
			done = true;
		}
		historyin.close();
		return done;
		break;
	}
	}
	return false;
}

DatabaseLoader::DatabaseLoader(Database & Data, unsigned short int mode): _Data(Data), _mode(mode)
{
}

void DatabaseLoader::Initialize()
{
	if (!LoadDatabase())
	{
		_Data.AddAccountToDatabase();
		_Data.IncreaseIDcount();
		SaveDatabase();
	}
	LoadHistory();
}

bool DatabaseLoader::SaveDatabase()
{
	switch (_mode)
	{
	case 0:
	{
		Crypter Crypt;
		std::ofstream dataout_s("data_s.txt", std::ios::binary);
		bool done = false;
		std::string temp;
		size_t AccountSize = _Data.GetAccountsSize();
		Account* tempAccount;
		if (dataout_s.good())
		{
			temp = std::to_string(_Data.GetIDcount());
			temp = Crypt.EncryptString(temp);
			dataout_s.write(temp.c_str(), temp.size() + 1);
			for (size_t i = 0; i < AccountSize; ++i)
			{
				tempAccount = _Data.GetAccount(i);
				temp = std::to_string(tempAccount->GetID()) + " " + tempAccount->GetName() + " " + tempAccount->GetSurname() + " " + tempAccount->GetLogin() + " " +
					tempAccount->GetPassword() + " " + std::to_string(tempAccount->GetBalance()) + " " + std::to_string(tempAccount->GetPermissions());
				temp = Crypt.EncryptString(temp);
				dataout_s.write(temp.c_str(), temp.size() + 1);
			}
			done = true;
		}
		dataout_s.close();
		return done;
		break;
	}
	case 1:
	{
		std::ofstream dataout("data.txt");
		bool done = false;
		size_t AccountSize = _Data.GetAccountsSize();
		Account* tempAccount;
		if (dataout.good())
		{
			dataout << _Data.GetIDcount() << std::endl;
			for (size_t i = 0; i < AccountSize; ++i)
			{
				tempAccount = _Data.GetAccount(i);
				dataout << tempAccount->GetID() << " " << tempAccount->GetName() << " " << tempAccount->GetSurname() << " " << tempAccount->GetLogin() << " " 
						<< tempAccount->GetPassword() << " " << tempAccount->GetBalance() << " " << tempAccount->GetPermissions() << std::endl;
			}
			done = true;
		}
		dataout.close();
		return done;
		break;
	}
	}
	return false;
}

bool DatabaseLoader::SaveHistory()
{
	switch (_mode)
	{
	case 0:
	{
		Crypter Crypt;
		std::ofstream historyout_s("history_s.txt", std::ios::binary);
		bool done = false;
		std::string temp;
		size_t AccountSize = _Data.GetAccountsSize();
		Account* tempAccount;
		if (historyout_s.good())
		{
			for (size_t i = 0; i < AccountSize; ++i)
			{
				tempAccount = _Data.GetAccount(i);
				temp = std::to_string(tempAccount->GetID()) + " " + std::to_string(tempAccount->GetHistorySize());
				temp = Crypt.EncryptString(temp);
				historyout_s.write(temp.c_str(), temp.size() + 1);
				for (size_t j = 0; j < tempAccount->GetHistory().size(); ++j)
				{
					temp = Crypt.EncryptString(tempAccount->GetHistory()[j]);
					historyout_s.write(temp.c_str(), temp.size() + 1);
				}
			}
			done = true;
		}
		historyout_s.close();
		return done;
		break;
	}
	case 1:
	{
		std::ofstream historyout("history.txt");
		bool done = false;
		size_t AccountSize = _Data.GetAccountsSize();
		Account* tempAccount;
		if (historyout.good())
		{
			for (size_t i = 0; i < AccountSize; ++i)
			{
				tempAccount = _Data.GetAccount(i);
				historyout << tempAccount->GetID() << " " << tempAccount->GetHistorySize() << std::endl;
				for (size_t j = 0; j < tempAccount->GetHistory().size(); ++j)
				{
					historyout << tempAccount->GetHistory()[j] << std::endl;
				}
			}
			done = true;
		}
		historyout.close();
		return done;
		break;
	}
	}
	return false;
}
