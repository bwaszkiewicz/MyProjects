#include "BuildingsData.h"

BuildingsData::BuildingsData(): _barrack(new Barrack), _brickyard(new Brickyard), _farm(new Farm), _houses(new Houses), _lumbermill(new Lumbermill),
_mine(new Mine), _smithy(new Smithy), _stable(new Stable), _townhall(new Townhall), _walls(new Walls)
{
	_barrack->init();
	_brickyard->init();
	_farm->init();
	_houses->init();
	_lumbermill->init();
	_mine->init();
	_smithy->init();
	_stable->init();
	_townhall->init();
	_walls->init();
}

BuildingsData::~BuildingsData()
{
	delete _barrack;
	delete _brickyard;
	delete _farm;
	delete _houses;
	delete _lumbermill;
	delete _mine;
	delete _smithy;
	delete _stable;
	delete _townhall;
	delete _walls;
}

bool BuildingsData::upgrade(ResourcesData& Data, Building * buildingType)
{
	std::vector<int> require = buildingType->getNextLevelRequire();
	if (require[WOOD] <= Data.getWood() && require[IRON] <= Data.getIron() && require[CLAY] <= Data.getClay()
		&& require[PEOPLE-1] + Data.getPeople() <= Data.getMaxPeopleAmount() && buildingType->getlevel() < MaxLevel)
	{
		Data.updateWood(-require[WOOD]);
		Data.updateIron(-require[IRON]);
		Data.updateClay(-require[CLAY]);
		//Data.updatePoeple(require[PEOPLE-1]);
		buildingType->upgrade();
		return true;
	}
	else
		return false;
	return false;
}

short int BuildingsData::getBuildingLevel(Building * buildingType) const
{
	return buildingType->getlevel();
}

int BuildingsData::getSumBuildingsPeople() const
{
	int currentPeopleSum = 0;
	currentPeopleSum += getTownhall()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getLumbermill()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getBrickyard()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getMine()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getFarm()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getBarrack()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getStable()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getSmithy()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getHouses()->getRequirePeopleOnCurrentLevel();
	currentPeopleSum += getWalls()->getRequirePeopleOnCurrentLevel();

	return currentPeopleSum;
}

std::vector<int> BuildingsData::getBuildingNextLevelResourceRequire(Building * buildingType) const
{
	return buildingType->getNextLevelRequire();
}

Lumbermill * BuildingsData::getLumbermill() const
{
	return _lumbermill;
}

Mine * BuildingsData::getMine() const
{
	return _mine;
}

Smithy * BuildingsData::getSmithy() const
{
	return _smithy;
}

Stable * BuildingsData::getStable() const
{
	return _stable;
}

Townhall * BuildingsData::getTownhall() const
{
	return _townhall;
}

Walls * BuildingsData::getWalls() const
{
	return _walls;
}

Barrack * BuildingsData::getBarrack() const
{
	return _barrack;
}

Brickyard * BuildingsData::getBrickyard() const
{
	return _brickyard;
}

Farm * BuildingsData::getFarm() const
{
	return _farm;
}

Houses * BuildingsData::getHouses() const
{
	return _houses;
}


void BuildingsData::cleanData()
{
	_townhall->init();
	_lumbermill->init();
	_brickyard->init();
	_mine->init();
	_farm->init();
	_barrack->init();
	_stable->init();
	_smithy->init();
	_houses->init();
	_walls->init();
}