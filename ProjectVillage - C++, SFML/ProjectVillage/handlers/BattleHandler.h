#pragma once
#include <vector>
#include "../Defines.h"

class BattleHandler {
	std::vector<int> _defenders;
	std::vector<int> _attackers;
public:
	BattleHandler(int Pikemans, int Swordsmans, int Axemans, int Archers, int LightCavalrymans, int HeavyCavalrymans, std::vector<int> Event);
	std::vector<int> getDefenders() const;
	std::vector<int> getAttackers() const;
};