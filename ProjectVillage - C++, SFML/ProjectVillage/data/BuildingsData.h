#pragma once
#include "..\buildings\Barrack.h"
#include "..\buildings\Brickyard.h"
#include "..\buildings\Farm.h"
#include "..\buildings\Houses.h"
#include "..\buildings\Lumbermill.h"
#include "..\buildings\Mine.h"
#include "..\buildings\Smithy.h"
#include "..\buildings\Stable.h"
#include "..\buildings\Townhall.h"
#include "..\buildings\Walls.h"

#include "..\Defines.h"

class BuildingsData {
	Barrack * _barrack;
	Brickyard * _brickyard;
	Farm * _farm;
	Houses * _houses;
	Lumbermill * _lumbermill;
	Mine * _mine;
	Smithy * _smithy;
	Stable * _stable;
	Townhall * _townhall;
	Walls * _walls;

public:
	BuildingsData();
	~BuildingsData();
	bool upgrade(ResourcesData& Data, Building * buildingType);
	short int getBuildingLevel(Building * buildingType) const;

	int getSumBuildingsPeople() const;
	std::vector<int> getBuildingNextLevelResourceRequire(Building* buildingType) const;

	Barrack * getBarrack() const;
	Brickyard * getBrickyard() const;
	Farm * getFarm() const;
	Houses * getHouses() const;
	Lumbermill * getLumbermill() const;
	Mine * getMine() const;
	Smithy * getSmithy() const;
	Stable * getStable() const;
	Townhall * getTownhall() const;
	Walls * getWalls() const;

	void cleanData();
};