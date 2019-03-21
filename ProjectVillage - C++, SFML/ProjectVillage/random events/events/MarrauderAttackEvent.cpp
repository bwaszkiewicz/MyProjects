#include "MarrauderAttackEvent.h"

void MarrauderAttackEvent::init(short int tier)
{
	_chance[TIER_0] = 5;
	_chance[TIER_1] = 10;
	_chance[TIER_2] = 13;
	_chance[TIER_3] = 15;
}

int MarrauderAttackEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> MarrauderAttackEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);


	PrepareEvent[EV_ENEMY_PIKEMAN] = rand() % 10 + (tier + 3) * 2;
	PrepareEvent[EV_ENEMY_SWORDSMAN] = rand() % 10 + (tier + 1) * 2;
	PrepareEvent[EV_ENEMY_AXEMAN] = rand() % 10 * 2 + tier * 2;
	PrepareEvent[EV_ENEMY_ARCHERS] = rand() % 10 + tier * 2;
	PrepareEvent[EV_ENEMY_LIGHTCAVALRYMAN] = (rand() % 10 + 2)* tier;
	PrepareEvent[EV_ENEMY_HEAVYCAVALRYMAN] = rand() % 10 * tier;

	PrepareEvent[EV_BATTLE] = 1;
	return PrepareEvent;
}

short int MarrauderAttackEvent::getEventID() const
{
	return EV_ID_MARRAUDERATTACK;
}

std::string MarrauderAttackEvent::getCaption() const
{
	return "Marrauder attack";
}
