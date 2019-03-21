#pragma once
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "data\Data.h"

class BattleEngine {
	std::vector<int> _defenders;
	std::vector<int> _attackers;
	short int _wallsLevel;
	int _gameEndBattleFlag;

	std::vector<int> _afterDefenders;
	std::vector<int> _afterAttackers;

	int calculateHealth(Data const &MainData, std::vector<int> units);
	int calculateForce(Data const &MainData, std::vector<int> units);

	std::vector<int> calculateResult(std::vector<int> units, double factor);
public:
	BattleEngine(std::vector<int> defenders, std::vector<int> attackers, short int wallsLevel);
	~BattleEngine() = default;
	bool battle(Data const &MainData);

	std::vector<int> getAfterDefenders();
	std::vector<int> getAfterAttackers();
};