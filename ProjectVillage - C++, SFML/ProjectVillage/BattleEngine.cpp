#include "BattleEngine.h"

int BattleEngine::calculateHealth(Data const & MainData, std::vector<int> units)
{
	int toReturnSum = 0;
	toReturnSum += units[PIKEMAN] * int(MainData.getUnitType(PIKEMAN)->getHealth() + MainData.getUnitType(PIKEMAN)->getArmor()*0.5);
	toReturnSum += units[SWORDSMAN] * int(MainData.getUnitType(SWORDSMAN)->getHealth() + MainData.getUnitType(SWORDSMAN)->getArmor()*0.5);
	toReturnSum += units[AXEMAN] * int(MainData.getUnitType(AXEMAN)->getHealth() + MainData.getUnitType(AXEMAN)->getArmor()*0.5);
	toReturnSum += units[ARCHERS] * int(MainData.getUnitType(ARCHERS)->getHealth() + MainData.getUnitType(ARCHERS)->getArmor()*0.5);
	toReturnSum += units[LIGHTCAVALRYMAN] * int(MainData.getUnitType(LIGHTCAVALRYMAN)->getHealth() + MainData.getUnitType(LIGHTCAVALRYMAN)->getArmor()*0.5);
	toReturnSum += units[HEAVYCAVALRYMAN] * int(MainData.getUnitType(HEAVYCAVALRYMAN)->getHealth() + MainData.getUnitType(HEAVYCAVALRYMAN)->getArmor()*0.5);
	return toReturnSum;
}

int BattleEngine::calculateForce(Data const & MainData, std::vector<int> units)
{
	int toReturnSum = 0;
	toReturnSum += units[PIKEMAN] * (MainData.getUnitType(PIKEMAN)->getDamageDistance() + MainData.getUnitType(PIKEMAN)->getDamageMelee());
	toReturnSum += units[SWORDSMAN] * (MainData.getUnitType(SWORDSMAN)->getDamageDistance() + MainData.getUnitType(SWORDSMAN)->getDamageMelee());
	toReturnSum += units[AXEMAN] * (MainData.getUnitType(AXEMAN)->getDamageDistance() + MainData.getUnitType(AXEMAN)->getDamageMelee());
	toReturnSum += units[ARCHERS] * (MainData.getUnitType(ARCHERS)->getDamageDistance() + MainData.getUnitType(ARCHERS)->getDamageMelee());
	toReturnSum += units[LIGHTCAVALRYMAN] * (MainData.getUnitType(LIGHTCAVALRYMAN)->getDamageDistance() + MainData.getUnitType(LIGHTCAVALRYMAN)->getDamageMelee());
	toReturnSum += units[HEAVYCAVALRYMAN] * (MainData.getUnitType(HEAVYCAVALRYMAN)->getDamageDistance() + MainData.getUnitType(HEAVYCAVALRYMAN)->getDamageMelee());
	return toReturnSum;
}

std::vector<int> BattleEngine::calculateResult(std::vector<int> units, double factor)
{
	factor *= 100;
	double draw = rand() % 100;
	if (draw < factor && units[PIKEMAN]>0)
	{
		double temp = units[PIKEMAN] * 0.188;
		units[PIKEMAN] = -int(round(temp));
	}
	draw = rand() % 100;
	if (draw < factor && units[SWORDSMAN]>0)
	{
		double temp = units[SWORDSMAN] * 0.186;
		units[SWORDSMAN] = -int(round(temp));
	}
	draw = rand() % 100;
	if (draw < factor && units[AXEMAN]>0)
	{
		double temp = units[AXEMAN] * 0.18;
		units[AXEMAN] = -int(round(temp));
	}
	draw = rand() % 100;
	if (draw < factor && units[ARCHERS]>0)
	{
		double temp = units[ARCHERS] * 0.19;
		units[ARCHERS] = -int(round(temp));
	}
	draw = rand() % 100;
	if (draw < factor && units[LIGHTCAVALRYMAN]>0)
	{
		double temp = units[LIGHTCAVALRYMAN] * 0.152;
		units[LIGHTCAVALRYMAN] = -int(round(temp));
	}
	draw = rand() % 100;
	if (draw < factor && units[HEAVYCAVALRYMAN]>0)
	{
		double temp = units[HEAVYCAVALRYMAN] * 0.104;
		units[HEAVYCAVALRYMAN] = -int(round(temp));
	}

	return units;
}

BattleEngine::BattleEngine(std::vector<int> defenders, std::vector<int> attackers, short int wallsLevel): _defenders(defenders), _attackers(attackers), _wallsLevel(wallsLevel)
{
}

bool BattleEngine::battle(Data const &MainData)
{
	int defendersHealth = calculateHealth(MainData, _defenders);
	defendersHealth += defendersHealth * _wallsLevel / 100;
	int defendersForce = calculateForce(MainData, _defenders);

	int attackersHealth = calculateHealth(MainData, _attackers);
	int attackersForce = calculateForce(MainData, _attackers);

	double resultDefendersHealth = defendersHealth - attackersForce;
	if (resultDefendersHealth < 0)
		resultDefendersHealth = 0;

	double resultAttackersHealth = attackersHealth - defendersForce;
	if (resultAttackersHealth < 0)
		resultAttackersHealth = 0;

	double defenderHealtFactor = 1 - abs(resultDefendersHealth / defendersHealth);
	double attackerHealtFactor = 1 - abs(resultAttackersHealth / attackersHealth);

	_afterAttackers = calculateResult(_attackers, attackerHealtFactor);

	if (defenderHealtFactor < attackerHealtFactor)
	{
		_afterDefenders = calculateResult(_defenders, defenderHealtFactor);
		return true;
	}
	else
	{
		_afterDefenders = _defenders;
		return false;
	}
}

std::vector<int> BattleEngine::getAfterDefenders()
{
	return _afterDefenders;
}

std::vector<int> BattleEngine::getAfterAttackers()
{
	return _afterAttackers;
}
