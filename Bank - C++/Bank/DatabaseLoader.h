#pragma once
#include "Database.h"
#include "Crypter.h"

class DatabaseLoader {
	unsigned short int _mode;
	Database &_Data;

	bool LoadDatabase();
	bool LoadHistory();
public:
	DatabaseLoader(Database &Data, unsigned short int mode);
	~DatabaseLoader() = default;
	void Initialize();
	bool SaveDatabase();
	bool SaveHistory();

};