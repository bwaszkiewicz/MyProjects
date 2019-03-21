#include "LocustEvent.h"

void LocustEvent::init(short int tier)
{
	_chance[TIER_0] = 10;
	_chance[TIER_1] = 10;
	_chance[TIER_2] = 10;
	_chance[TIER_3] = 10;
}

int LocustEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> LocustEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_FOOD] = -((rand() % 10 + 10)*tier + 10);

	return PrepareEvent;
}

short int LocustEvent::getEventID() const
{
	return EV_ID_LOCUST;
}

std::string LocustEvent::getCaption() const
{
	return "Locust";
}
