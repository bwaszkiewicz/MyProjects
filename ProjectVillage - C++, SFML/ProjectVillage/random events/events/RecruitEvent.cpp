#include "RecruitEvent.h"



void RecruitEvent::init(short int tier)
{
	_chance[TIER_0] = 10;
	_chance[TIER_1] = 11;
	_chance[TIER_2] = 7;
	_chance[TIER_3] = 5;
}

int RecruitEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> RecruitEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_RECRUIT_PIKEMAN] = rand() % 5 + tier + 1;
	PrepareEvent[EV_RECRUIT_SWORDSMAN] = rand() % 5 + tier + 1;
	PrepareEvent[EV_RECRUIT_AXEMAN] = rand() % 5 + tier + 1;
	PrepareEvent[EV_RECRUIT_ARCHERS] = rand() % 5 + tier + 1;
	PrepareEvent[EV_RECRUIT_LIGHTCAVALRYMAN] = rand() % 5 + tier;
	PrepareEvent[EV_RECRUIT_HEAVYCAVALRYMAN] = rand() % 5 + tier;

	return PrepareEvent;
}

short int RecruitEvent::getEventID() const
{
	return EV_ID_RECRUIT;
}

std::string RecruitEvent::getCaption() const
{
	return "Recruit";
}
