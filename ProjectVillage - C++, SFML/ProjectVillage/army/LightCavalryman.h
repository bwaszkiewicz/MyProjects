#pragma once
#include "Unit.h"


class LightCavalryman : public Unit {
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
	void init() override;
	void recruit(int amount) override;

	int getHealth() override;
	int getArmor() override;
	int getDamageDistance() override;
	int getDamageMelee() override;
	int getNumberOfUnits() override;
	std::vector<int> getRecruitRequire() const override;
};