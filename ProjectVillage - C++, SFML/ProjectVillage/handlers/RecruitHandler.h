#pragma once
#include "../ShapeMap.h"
#include "../data/Data.h"
#include "EventHandler.h"

class RecruitHandler {
	ShapeMap PikemanHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
	ShapeMap SwordsmanHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
	ShapeMap AxemanHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
	ShapeMap ArcherHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
	ShapeMap LightCavalrymanHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
	ShapeMap HeavyCavalrymanHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData);
public:
	RecruitHandler() = default;
	~RecruitHandler() = default;
	ShapeMap ChooseHandle(ShapeMap& Map, const EventHandler evHandler, const Data &MainData, short int unitType);
};