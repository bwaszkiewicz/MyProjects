#include "Pikeman.h"

void Pikeman::init()
{
	_numberOfUnits = 0;
	_requireWood=50;
	_requireIron=10;
	_requireClay=30;
	_requirePeople=1;
}

void Pikeman::recruit(int amount)
{
	_numberOfUnits += amount;
}

int Pikeman::getHealth()
{
	return 50;
}

int Pikeman::getArmor()
{
	return 25;
}

int Pikeman::getDamageDistance()
{
	return 0;
}

int Pikeman::getDamageMelee()
{
	return 30;
}

int Pikeman::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> Pikeman::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
