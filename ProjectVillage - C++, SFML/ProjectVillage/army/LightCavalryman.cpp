#include "LightCavalryman.h"

void LightCavalryman::init()
{
	_numberOfUnits = 0;
	_requireWood = 125;
	_requireIron = 250;
	_requireClay = 100;
	_requirePeople = 4;
}

void LightCavalryman::recruit(int amount)
{
	_numberOfUnits += amount;
}

int LightCavalryman::getHealth()
{
	return 200;
}

int LightCavalryman::getArmor()
{
	return 100;
}

int LightCavalryman::getDamageDistance()
{
	return 0;
}

int LightCavalryman::getDamageMelee()
{
	return 150;
}

int LightCavalryman::getNumberOfUnits()
{
	return _numberOfUnits;
}

std::vector<int> LightCavalryman::getRecruitRequire() const
{
	std::vector<int> resourcesToRecruit(5);
	resourcesToRecruit[WOOD] = _requireWood;
	resourcesToRecruit[IRON] = _requireIron;
	resourcesToRecruit[CLAY] = _requireClay;
	resourcesToRecruit[PEOPLE] = _requirePeople;

	return resourcesToRecruit;
}
