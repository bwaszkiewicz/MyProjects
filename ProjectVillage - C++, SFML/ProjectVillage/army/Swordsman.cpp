#include "Swordsman.h"

void Swordsman::init()
{
	_numberOfUnits = 0;
	_requireWood = 30;
	_requireIron = 70;
	_requireClay = 30;
	_requirePeople = 1;
}

void Swordsman::recruit(int amount)
{
	_numberOfUnits += amount;
}

int Swordsman::getHealth()
{
	return 50;
}

int Swordsman::getArmor()
{
	return 50;
}

int Swordsman::getDamageDistance()
{
	return 0;
}

int Swordsman::getDamageMelee()
{
	return 50;
}

int Swordsman::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> Swordsman::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
