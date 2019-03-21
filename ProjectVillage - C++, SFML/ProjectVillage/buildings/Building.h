#pragma once
#include "../data/ResourcesData.h"
#include <vector>
#define MaxLevel 10

class Building {
	int _currentlevel;
	int _requireWood[MaxLevel];
	int _requireIron[MaxLevel];
	int _requireClay[MaxLevel];
	int _requirePeople[MaxLevel];

public:
	virtual void init() = 0;
	virtual void upgrade() = 0;
	virtual short int getlevel() = 0;
	virtual int getRequirePeopleOnCurrentLevel() = 0;
	virtual std::vector<int> getNextLevelRequire() const = 0;
};