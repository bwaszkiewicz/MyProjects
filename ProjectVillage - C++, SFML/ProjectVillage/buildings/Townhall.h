#pragma once
#include "Building.h"

class Townhall : public Building {
	int _currentlevel;
	int _requireWood[MaxLevel];
	int _requireIron[MaxLevel];
	int _requireClay[MaxLevel];
	int _requirePeople[MaxLevel];
public:
	void init() override;
	void upgrade() override;
	short int getlevel() override;
	virtual int getRequirePeopleOnCurrentLevel() override;
	std::vector<int> getNextLevelRequire() const override;
};