#include "Data.h"

int Data::calculateResources(int buildingLevel)
{
	return buildingLevel*10;
}

int Data::calculateMaxPeople(int buildingLevel)
{
	return buildingLevel * 100;
}

int Data::calculatePeople()
{
	int currentPeopleSum = _Buildings.getSumBuildingsPeople();
	currentPeopleSum += _Army.getSumArmyPeople();
	return currentPeopleSum;
}

Building * Data::getBuildingType(short int buildingType) const
{
	switch (buildingType)
	{
	case TOWNHALL:
		return _Buildings.getTownhall();
		break;
	case LUMBERMILL:
		return _Buildings.getLumbermill();
		break;
	case BRICKYARD:
		return _Buildings.getBrickyard();
		break;
	case MINE:
		return _Buildings.getMine();
		break;
	case FARM:
		return _Buildings.getFarm();
		break;
	case BARRACK:
		return _Buildings.getBarrack();
		break;
	case STABLE:
		return _Buildings.getStable();
		break;
	case SMITHY:
		return _Buildings.getSmithy();
		break;
	case HOUSES:
		return _Buildings.getHouses();
		break;
	case WALLS:
		return _Buildings.getWalls();
		break;
	default:
		throw InvalidBuildingTypeException();
		break;
	}
	throw DataAccessViolationException();
}

Unit * Data::getUnitType(short int unitType) const
{
	switch (unitType)
	{
	case PIKEMAN:
		return _Army.getPikemans();
		break;
	case SWORDSMAN:
		return _Army.getSwordsmans();
		break;
	case AXEMAN:
		return _Army.getAxemans();
		break;
	case ARCHERS:
		return _Army.getArchers();
		break;
	case LIGHTCAVALRYMAN:
		return _Army.getLightCavalrymans();
		break;
	case HEAVYCAVALRYMAN:
		return _Army.getHeavyCavalrymans();
		break;
	default:
		throw InvalidUnitTypeException();
		break;
	}
	throw DataAccessViolationException();
}

void Data::addToEventsList(RandomEvent * Event)
{
	_EventsList.push_front(Event);
}

void Data::editResources(short int resourcesType, int amount)
{
	switch (resourcesType)
	{
	case WOOD:
		_Resources.updateWood(amount);
		break;
	case IRON:
		_Resources.updateIron(amount);
		break;
	case CLAY:
		_Resources.updateClay(amount);
		break;
	case FOOD:
		_Resources.updateFood(amount);
		break;
	case PEOPLE:
		_Resources.updatePoeple(amount); //
		break;
	case MAXPEOPLE:
		_Resources.setMaxPeopleAmount(amount); //
		break;
	default:
		throw InvalidResourcesTypeException();
		break; 
	}
}

void Data::editUnits(short int unitType, int amount)
{
	_Army.editUnits(getUnitType(unitType), amount);
}

Data::Data(): _hours(0)
{
}

Data::~Data()
{
	 if(!_EventsList.empty())
		for (std::list<RandomEvent*>::iterator it = _EventsList.begin(); it != _EventsList.end(); it++)
			delete *it;
	_EventsList.clear();
}

void Data::updateResources(short int resourcesType)
{
	switch (resourcesType)
	{
	case WOOD:
		_Resources.updateWood( calculateResources( _Buildings.getBuildingLevel(_Buildings.getLumbermill())) );
		break;
	case IRON:
		_Resources.updateIron( calculateResources(_Buildings.getBuildingLevel(_Buildings.getMine())) );
		break;
	case CLAY:
		_Resources.updateClay( calculateResources(_Buildings.getBuildingLevel(_Buildings.getBrickyard())) );
		break;
	case FOOD:
		_Resources.updateFood( calculateResources(_Buildings.getBuildingLevel(_Buildings.getFarm())) );
		break;
	case PEOPLE:
		_Resources.updatePoeple(calculatePeople());
		break;
	case MAXPEOPLE:
		_Resources.setMaxPeopleAmount(calculateMaxPeople(_Buildings.getBuildingLevel(_Buildings.getHouses())) );
		break;
	default:
		throw InvalidResourcesTypeException();
		break;
	}

}

void Data::recalculateFood()
{
	_Resources.updateFood(-calculatePeople()*FOOD_TO_ONE_MAN);
}

bool Data::recruitUnits(short int unitType, int amount)
{
	if (_Army.recruit(_Resources, getUnitType(unitType),amount))
		return true;
	else
		return false;
	return false;
}

bool Data::updateBuilding(short int buildingType)
{
	if (_Buildings.upgrade(_Resources, getBuildingType(buildingType)))
		return true;
	else
		return false;
	return false;
}

int Data::getUnitsAmount(short int unitsType) const
{
	switch (unitsType)
	{
	case PIKEMAN:
		return _Army.getPikemans()->getNumberOfUnits();
		break;
	case SWORDSMAN:
		return _Army.getSwordsmans()->getNumberOfUnits();
		break;
	case AXEMAN:
		return _Army.getAxemans()->getNumberOfUnits();
		break;
	case ARCHERS:
		return _Army.getArchers()->getNumberOfUnits();
		break;
	case LIGHTCAVALRYMAN:
		return _Army.getLightCavalrymans()->getNumberOfUnits();
		break;
	case HEAVYCAVALRYMAN:
		return _Army.getHeavyCavalrymans()->getNumberOfUnits();
		break;
	default:
		throw InvalidUnitTypeException();
		break;
	};
}

std::vector<int> Data::getUnitRecruitResourceRequire(short int unitType) const
{
	return _Army.getUnitRecruitResourceRequire(getUnitType(unitType));
}

void Data::setUnitsAfterBattle(std::vector<int> units)
{
	editUnits(PIKEMAN, -units[PIKEMAN]);
	editUnits(SWORDSMAN, -units[SWORDSMAN]);
	editUnits(AXEMAN, -units[AXEMAN]);
	editUnits(ARCHERS, -units[ARCHERS]);
	editUnits(LIGHTCAVALRYMAN, -units[LIGHTCAVALRYMAN]);
	editUnits(HEAVYCAVALRYMAN, -units[HEAVYCAVALRYMAN]);
}

int Data::getResources(short int resourcesType) const
{
	int toReturn;
	switch (resourcesType)
	{
	case WOOD:
		toReturn = _Resources.getWood();
		break;
	case IRON:
		toReturn = _Resources.getIron();
		break;
	case CLAY:
		toReturn = _Resources.getClay();
		break;
	case FOOD:
		toReturn = _Resources.getFood();
		break;
	case PEOPLE:
		toReturn = _Resources.getPeople();
		break;
	case MAXPEOPLE:
		toReturn = _Resources.getMaxPeopleAmount();
		break;
	default:
		throw InvalidResourcesTypeException();
		break;
	}
	return toReturn;
}

short int Data::getBuildingsLevel(short int buildingType) const
{
	return _Buildings.getBuildingLevel(getBuildingType(buildingType));
}

std::vector<int> Data::getBuildingsNextLevelRequire(short int buildingType) const
{
	return _Buildings.getBuildingNextLevelResourceRequire(getBuildingType(buildingType));
}

void Data::hoursIncerement()
{
	_hours++;
}

void Data::setHours(int hours)
{
	_hours = hours;
}

int Data::getHours() const
{
	return _hours;
}

std::vector<int> Data::randomize()
{
	RandomEvent * Event;
	std::vector<int> EventVector;
	Event = _RandomMachine.randomize();
	Event->init(_RandomMachine.getTier());
	addToEventsList(Event);
	EventVector = Event->getEvent(_RandomMachine.getTier());
	editResources(WOOD, EventVector[EV_WOOD]);
	editResources(IRON, EventVector[EV_IRON]);
	editResources(CLAY, EventVector[EV_CLAY]);
	editResources(FOOD, EventVector[EV_FOOD]);

	editUnits(PIKEMAN, EventVector[EV_RECRUIT_PIKEMAN]);
	editUnits(SWORDSMAN, EventVector[EV_RECRUIT_SWORDSMAN]);
	editUnits(AXEMAN, EventVector[EV_RECRUIT_AXEMAN]);
	editUnits(ARCHERS, EventVector[EV_RECRUIT_ARCHERS]);
	editUnits(LIGHTCAVALRYMAN, EventVector[EV_RECRUIT_LIGHTCAVALRYMAN]);
	editUnits(HEAVYCAVALRYMAN, EventVector[EV_RECRUIT_HEAVYCAVALRYMAN]);

	return std::move(EventVector);
}

std::list<RandomEvent*> Data::getEventList() const
{
	return _EventsList;
}

RandomEvent * Data::getLatestEvent(short int i) const
{
	std::list<RandomEvent*> list = getEventList();
	std::list<RandomEvent*>::iterator it = list.begin();
	if (_EventsList.begin() == _EventsList.end())
		return nullptr;
	else
		if (i == 0 && list.size() >= 1)
			return *it;
		else
			if (i == 1 && list.size() >= 2)
			{
				it++;
				return *it;
			}
			else
				if (i == 2 && list.size() >= 3)
				{
					it++;
					it++;
					return *it;
				}
				else
					if (i == 3 && list.size() >= 4)
					{
						it++;
						it++;
						it++;
						return *it;
					}
					else
						return nullptr;
}

void Data::clearData()
{
	_Army.cleanData();
	_Resources.cleanData();
	_Buildings.cleanData();
	_RandomMachine.cleanData();
	_hours = 0;
	if (!_EventsList.empty())
		for (std::list<RandomEvent*>::iterator it = _EventsList.begin(); it != _EventsList.end(); it++)
			delete *it;
	_EventsList.clear();
	updateResources(PEOPLE);
}
