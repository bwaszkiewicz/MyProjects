#include "BarbarianAttackEvent.h"

void BarbarianAttackEvent::init(short int tier)
{
	_chance[TIER_0] = 3;
	_chance[TIER_1] = 5;
	_chance[TIER_2] = 5;
	_chance[TIER_3] = 10;
}

int BarbarianAttackEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> BarbarianAttackEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);


	PrepareEvent[EV_ENEMY_PIKEMAN] = rand() % 10 + tier * 3;
	PrepareEvent[EV_ENEMY_AXEMAN] = rand() % 10 + tier * 5;
	PrepareEvent[EV_ENEMY_ARCHERS] = rand() % 10 + tier * 2 + 2;
	PrepareEvent[EV_ENEMY_LIGHTCAVALRYMAN] = rand() % 10 + tier;

	PrepareEvent[EV_BATTLE] = 1;
	PrepareEvent[EV_ENDGAME] = 1;
	return PrepareEvent;
}

short int BarbarianAttackEvent::getEventID() const
{
	return EV_ID_BARBARIANATTACK;
}

std::string BarbarianAttackEvent::getCaption() const
{
	return "Barbarian Attack";
}
