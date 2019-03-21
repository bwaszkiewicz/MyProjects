#pragma once
#include "../Defines.h"
#include "BuildingsData.h"
#include "ArmyData.h"
#include "ResourcesData.h"
#include "../random events/RandomMachine.h"

#include "../exceptions/InvalidBuildingTypeException.h"
#include "../exceptions/InvalidUnitTypeException.h"
#include "../exceptions/InvalidResourcesTypeException.h"
#include "../exceptions/DataAccessViolationException.h"

#include <list>

class Data {
	ResourcesData _Resources;
	ArmyData _Army;
	BuildingsData _Buildings;
	RandomMachine _RandomMachine;
	std::list<RandomEvent*> _EventsList;

	int _hours;


	int calculateResources(int buildingLevel);
	int calculateMaxPeople(int amount);
	int calculatePeople();
	Building * getBuildingType(short int buildingType) const;
	
	void addToEventsList(RandomEvent* Event);
	void editResources(short int resourcesType, int amount);
	void editUnits(short int unitType, int amount);
public:

	Data();
	~Data();

	/**
	*\brief Updating resources amount
	*\param resourcesType: 0 - Wood, 1 - Iron, 2 - Clay, 3 - Food, 4 - People, 5 - MaxPeople
	*/
	void updateResources(short int resourcesType);
	void recalculateFood();
	/**
	*\brief Recruting units
	*\param resourcesType: 0 - Swordsman, 1 - Pikeman, 2 - Archers
	*\param amount: number of given units 
	*/
	bool recruitUnits(short int unitType, int amount);
	bool updateBuilding(short int buildingType);


	int getUnitsAmount(short int unitsType) const;
	Unit * getUnitType(short int unitType) const;
	std::vector<int> getUnitRecruitResourceRequire(short int unitType) const;
	void setUnitsAfterBattle(std::vector<int> units);

	int getResources(short int resourcesType) const;
	short int getBuildingsLevel(short int buildingType) const;
	std::vector<int> getBuildingsNextLevelRequire(short int buildingType) const;

	void hoursIncerement();
	void setHours(int hours);
	int getHours() const;

	// RandomMachine methods:

	std::vector<int> randomize();
	std::list<RandomEvent*> getEventList() const;
	RandomEvent* getLatestEvent(short int i) const;

	void clearData();
};