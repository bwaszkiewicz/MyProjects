#include "DesertionEvent.h"



void DesertionEvent::init(short int tier)
{
	_chance[TIER_0] = 2;
	_chance[TIER_1] = 3;
	_chance[TIER_2] = 5;
	_chance[TIER_3] = 10;
}

int DesertionEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> DesertionEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_RECRUIT_PIKEMAN] = -(rand() % 5 + tier + 1);
	PrepareEvent[EV_RECRUIT_SWORDSMAN] = -(rand() % 5 + tier + 1);
	PrepareEvent[EV_RECRUIT_AXEMAN] = -(rand() % 5 + tier + 1);
	PrepareEvent[EV_RECRUIT_ARCHERS] = -(rand() % 5 + tier + 1);
	PrepareEvent[EV_RECRUIT_LIGHTCAVALRYMAN] = -(rand() % 5 + tier);
	PrepareEvent[EV_RECRUIT_HEAVYCAVALRYMAN] = -(rand() % 5 + tier);

	return PrepareEvent;
}

short int DesertionEvent::getEventID() const
{
	return EV_ID_DESERTION;
}

std::string DesertionEvent::getCaption() const
{
	return "Desertion";
}
