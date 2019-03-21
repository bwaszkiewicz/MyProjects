#pragma once
#include "..\army\Archer.h"
#include "..\army\Pikeman.h"
#include "..\army\Swordsman.h"
#include "..\army\Axeman.h"
#include "..\army\LightCavalryman.h"
#include "..\army\HeavyCavalryman.h"
#include <vector>

class ArmyData {
	Archer * _archers;
	Pikeman * _pikemans;
	Swordsman * _swordsmans;
	Axeman * _axemans;
	LightCavalryman * _lightCavalrymans;
	HeavyCavalryman * _heavyCavalrymans;


public:
	ArmyData();
	~ArmyData();
	
	bool recruit(ResourcesData &Data, Unit * unit, int amount);
	void editUnits(Unit * unit, int amount);

	int getUnitAmount(Unit * unitType) const;
	int getSumArmyPeople() const;

	std::vector<int> getUnitRecruitResourceRequire(Unit* unitType) const;

	Archer * getArchers() const;
	Pikeman * getPikemans() const;
	Swordsman * getSwordsmans() const;
	Axeman * getAxemans() const;
	LightCavalryman * getLightCavalrymans() const;
	HeavyCavalryman * getHeavyCavalrymans() const;

	void cleanData();
};