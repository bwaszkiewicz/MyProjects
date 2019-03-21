#include "HeavyCavalryman.h"

void HeavyCavalryman::init()
{
	_numberOfUnits = 0;
	_requireWood = 200;
	_requireIron = 600;
	_requireClay = 150;
	_requirePeople = 6;
}

void HeavyCavalryman::recruit(int amount)
{
	_numberOfUnits += amount;
}

int HeavyCavalryman::getHealth()
{
	return 400;
}

int HeavyCavalryman::getArmor()
{
	return 200;
}

int HeavyCavalryman::getDamageDistance()
{
	return 0;
}

int HeavyCavalryman::getDamageMelee()
{
	return 200;
}

int HeavyCavalryman::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> HeavyCavalryman::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
