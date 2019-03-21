#include "NomadsAttackEvent.h"

void NomadsAttackEvent::init(short int tier)
{
	_chance[TIER_0] = 5;
	_chance[TIER_1] = 5;
	_chance[TIER_2] = 7;
	_chance[TIER_3] = 10;
}

int NomadsAttackEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> NomadsAttackEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_ENEMY_LIGHTCAVALRYMAN] = rand() % 15 + 1 + tier * 5;
	PrepareEvent[EV_ENEMY_HEAVYCAVALRYMAN] = rand() % 15 * tier;

	PrepareEvent[EV_ENDGAME] = 1;
	PrepareEvent[EV_BATTLE] = 1;
	return PrepareEvent;
}

short int NomadsAttackEvent::getEventID() const
{
	return EV_ID_NOMADSATTACK;
}

std::string NomadsAttackEvent::getCaption() const
{
	return "Nomads attack";
}
