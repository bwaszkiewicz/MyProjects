#include "BigTreeEvent.h"

void BigTreeEvent::init(short int tier)
{
	_chance[TIER_0] = 15;
	_chance[TIER_1] = 11;
	_chance[TIER_2] = 11;
	_chance[TIER_3] = 6;
}

int BigTreeEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> BigTreeEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_WOOD] = rand() % 15 * 5 + tier * 15 + 5;

	return PrepareEvent;
}

short int BigTreeEvent::getEventID() const
{
	return EV_ID_BIGTREE;
}

std::string BigTreeEvent::getCaption() const
{
	return "Big tree";
}
