#include "IronDepositFindEvent.h"


void IronDepositFindEvent::init(short int tier)
{
	_chance[TIER_0] = 15;
	_chance[TIER_1] = 11;
	_chance[TIER_2] = 11;
	_chance[TIER_3] = 7;
}

int IronDepositFindEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> IronDepositFindEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_IRON] = rand() % 15 * 5 + tier * 15 + 5;

	return PrepareEvent;
}

short int IronDepositFindEvent::getEventID() const
{
	return EV_ID_IRONDEPOSIT;
}

std::string IronDepositFindEvent::getCaption() const
{
	return "Iron deposit";
}
