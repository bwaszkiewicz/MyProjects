#include "BlockOfClayEvent.h"

void BlockOfClayEvent::init(short int tier)
{
	_chance[TIER_0] = 15;
	_chance[TIER_1] = 11;
	_chance[TIER_2] = 11;
	_chance[TIER_3] = 7;

}

int BlockOfClayEvent::getChance(short int tier) const
{
	return _chance[tier];
}

std::vector<int> BlockOfClayEvent::getEvent(short int tier) const
{
	std::vector<int>PrepareEvent(18, 0);

	PrepareEvent[EV_CLAY] = rand() % 15 * 5 + tier * 15 + 5;

	return PrepareEvent;
}

short int BlockOfClayEvent::getEventID() const
{
	return EV_ID_BLOCKOFCLAY;
}

std::string BlockOfClayEvent::getCaption() const
{
	return "Block of clay";
}
