#include "BattleHandler.h"

BattleHandler::BattleHandler(int Pikemans, int Swordsmans, int Axemans, int Archers, int LightCavalrymans, int HeavyCavalrymans, std::vector<int> Event)
{
	std::vector<int> defenders(6);
	defenders[PIKEMAN] = Pikemans;
	defenders[SWORDSMAN] = Swordsmans;
	defenders[AXEMAN] = Axemans;
	defenders[ARCHERS] = Archers;
	defenders[LIGHTCAVALRYMAN] = LightCavalrymans;
	defenders[HEAVYCAVALRYMAN] = HeavyCavalrymans;
	_defenders = defenders;

	std::vector<int> attackers(6);
	attackers[PIKEMAN] = Event[EV_ENEMY_PIKEMAN];
	attackers[SWORDSMAN] = Event[EV_ENEMY_SWORDSMAN];
	attackers[AXEMAN] = Event[EV_ENEMY_AXEMAN];
	attackers[ARCHERS] = Event[EV_ENEMY_ARCHERS];
	attackers[LIGHTCAVALRYMAN] = Event[EV_ENEMY_LIGHTCAVALRYMAN];
	attackers[HEAVYCAVALRYMAN] = Event[EV_ENEMY_HEAVYCAVALRYMAN];
	_attackers = attackers;
}

std::vector<int> BattleHandler::getDefenders() const
{
	return _defenders;
}

std::vector<int> BattleHandler::getAttackers() const
{
	return _attackers;
}
