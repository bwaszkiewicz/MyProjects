#include "AbundanceEvent.h"

void AbundanceEvent::init(short int tier)
{
	_chance[TIER_0] = 15;
	_chance[TIER_1] = 11;
	_chance[TIER_2] = 5;
	_chance[TIER_3] = 5;
}

int AbundanceEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> AbundanceEvent::getEvent(short int tier) const
{
	int draw = rand() % 20 + tier * 10 + 15;

	std::vector<int>PrepareEvent(18, 0);
	PrepareEvent[EV_FOOD] = draw;
	return PrepareEvent;
}

short int AbundanceEvent::getEventID() const
{
	return EV_ID_ABUDANCE;
}

std::string AbundanceEvent::getCaption() const
{
	return "Abudance";
}
