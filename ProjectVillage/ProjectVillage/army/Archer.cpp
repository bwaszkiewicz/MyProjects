#include "Archer.h"

void Archer::init()
{
	_numberOfUnits = 0;

	_requireWood=100;
	_requireIron=60;
	_requireClay=30;
	_requirePeople=1;
}

void Archer::recruit(int amount)
{
	_numberOfUnits+=amount;
}

int Archer::getHealth()
{
	return 50;
}

int Archer::getArmor()
{
	return 10;
}

int Archer::getDamageDistance()
{
	return 70;
}

int Archer::getDamageMelee()
{
	return 10;
}

int Archer::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> Archer::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
