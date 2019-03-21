#pragma once
#include "../data/ResourcesData.h"
#include "../Defines.h"
#include <vector>

class Unit {
	int _health;
	int _armor;
	int _damageDistance;
	int _damageMelee;
	int _numberOfUnits;

	int _requireWood;
	int _requireIron;
	int _requireClay;
	int _requirePeople;
public:
	virtual void init() = 0;
	virtual void recruit(int amount) = 0;

	virtual int getHealth() = 0;
	virtual int getArmor() = 0;
	virtual int getDamageDistance() = 0;
	virtual int getDamageMelee() = 0;
	virtual int getNumberOfUnits() = 0;

	virtual std::vector<int> getRecruitRequire() const = 0;

	//virtual void setNumberOfUnits(int amount)=0;
};