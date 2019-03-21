#include "ArmyData.h"

ArmyData::ArmyData(): _archers(new Archer), _pikemans(new Pikeman), _swordsmans(new Swordsman), _axemans(new Axeman), _lightCavalrymans(new LightCavalryman), _heavyCavalrymans(new HeavyCavalryman)
{
	_pikemans->init();
	_swordsmans->init();
	_axemans->init();
	_archers->init();
	_lightCavalrymans->init();
	_heavyCavalrymans->init();
}

ArmyData::~ArmyData()
{
	delete _archers;
	delete _pikemans;
	delete _swordsmans;
	delete _axemans;
	delete _lightCavalrymans;
	delete _heavyCavalrymans;
}

bool ArmyData::recruit(ResourcesData &Data, Unit * unit, int amount)
{
	std::vector<int> require = unit->getRecruitRequire();
	if (require[WOOD]*amount <= Data.getWood() && require[IRON]*amount <= Data.getIron() && require[CLAY]*amount <= Data.getClay()
		&& require[PEOPLE]*amount + Data.getPeople() <= Data.getMaxPeopleAmount())
	{
		Data.updateWood(-require[WOOD]*amount);
		Data.updateIron(-require[IRON]*amount);
		Data.updateClay(-require[CLAY]*amount);

		unit->recruit(amount);
		return true;
	}
	else
		return false;
	return false;
}

void ArmyData::editUnits(Unit * unit, int amount)
{
	if (getUnitAmount(unit) + amount < 0)
		unit->recruit(-getUnitAmount(unit));
	else
		unit->recruit(amount);
}

int ArmyData::getUnitAmount(Unit * unitType) const
{
	return unitType->getNumberOfUnits();
}

int ArmyData::getSumArmyPeople() const
{
	int currentPeopleSum = 0;
	currentPeopleSum += getArchers()->getRecruitRequire()[PEOPLE] * getArchers()->getNumberOfUnits();
	currentPeopleSum += getPikemans()->getRecruitRequire()[PEOPLE] * getPikemans()->getNumberOfUnits();
	currentPeopleSum += getSwordsmans()->getRecruitRequire()[PEOPLE] * getSwordsmans()->getNumberOfUnits();
	currentPeopleSum += getAxemans()->getRecruitRequire()[PEOPLE] * getAxemans()->getNumberOfUnits();
	currentPeopleSum += getLightCavalrymans()->getRecruitRequire()[PEOPLE] * getLightCavalrymans()->getNumberOfUnits();
	currentPeopleSum += getHeavyCavalrymans()->getRecruitRequire()[PEOPLE] * getHeavyCavalrymans()->getNumberOfUnits();
	return currentPeopleSum;
}

std::vector<int> ArmyData::getUnitRecruitResourceRequire(Unit * unitType) const
{
	return unitType->getRecruitRequire();
}

Archer * ArmyData::getArchers() const
{
	return _archers;
}

Pikeman * ArmyData::getPikemans() const
{
	return _pikemans;
}

Swordsman * ArmyData::getSwordsmans() const
{
	return _swordsmans;
}

Axeman * ArmyData::getAxemans() const
{
	return _axemans;
}

LightCavalryman * ArmyData::getLightCavalrymans() const
{
	return _lightCavalrymans;
}

HeavyCavalryman * ArmyData::getHeavyCavalrymans() const
{
	return _heavyCavalrymans;
}

void ArmyData::cleanData()
{
	_pikemans->init();
	_swordsmans->init();
	_axemans->init();
	_archers->init();
	_lightCavalrymans->init();
	_heavyCavalrymans->init();
}
