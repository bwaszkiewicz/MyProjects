#include "Axeman.h"

void Axeman::init()
{
	_numberOfUnits = 0;
	_requireWood = 60;
	_requireIron = 40;
	_requireClay = 30;
	_requirePeople = 1;
}

void Axeman::recruit(int amount)
{
	_numberOfUnits += amount;
}

int Axeman::getHealth()
{
	return 100;
}

int Axeman::getArmor()
{
	return 10;
}

int Axeman::getDamageDistance()
{
	return 0;
}

int Axeman::getDamageMelee()
{
	return 80;
}

int Axeman::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> Axeman::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
