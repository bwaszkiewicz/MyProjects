#pragma once
#include "../RandomEvent.h"

class BarbarianAttackEvent : public RandomEvent {

	int _chance[MAX_TIER_EVENT];
public:
	void init(short int tier) override;

	int getChance(short int tier) const override;
	std::vector<int> getEvent(short tier) const override;
	short int getEventID() const;
	std::string getCaption() const;
};