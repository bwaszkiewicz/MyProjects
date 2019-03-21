#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>

#include "../Defines.h"
#include "RandomEvent.h"

#include "events/AbundanceEvent.h"
#include "events/BarbarianAttackEvent.h"
#include "events/DesertionEvent.h"
#include "events/IronDepositFindEvent.h"
#include "events/LocustEvent.h"
#include "events/MarrauderAttackEvent.h"
#include "events/ThievesEvent.h"
#include "events/BlockOfClayEvent.h"
#include "events/BigTreeEvent.h"
#include "events/NomadsAttackEvent.h"
#include "events/RecruitEvent.h"

#include "../exceptions/InvalidEventTierException.h"

class RandomMachine
{
	short int _tier;
	int _ticks;
	int _currentTierLength;

	RandomEvent* createRandomEvent(short int tier);
public:
	RandomMachine();
	~RandomMachine();
	RandomEvent* randomize();

	int getTier() const;

	void cleanData();
};