#include "ThievesEvent.h"

void ThievesEvent::init(short int tier)
{
	_chance[TIER_0] = 5;
	_chance[TIER_1] = 12;
	_chance[TIER_2] = 15;
	_chance[TIER_3] = 15;
}

int ThievesEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> ThievesEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_WOOD] = -(rand() % 10 + 5 + tier * 10);
	PrepareEvent[EV_IRON] = -(rand() % 10 + 5 + tier * 10);
	PrepareEvent[EV_CLAY] = -(rand() % 10 + 5 + tier * 10);
	PrepareEvent[EV_FOOD] = -(rand() % 10 + 5 + tier * 10);

	return PrepareEvent;
}

short int ThievesEvent::getEventID() const
{
	return EV_ID_THIEVES;
}

std::string ThievesEvent::getCaption() const
{
	return "Thieves";
}
