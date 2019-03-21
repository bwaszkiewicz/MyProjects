#pragma once
#include "../RandomEvent.h"

class ThievesEvent : public RandomEvent {
	int _chance[MAX_TIER_EVENT];
public:
	void init(short int tier) override;

	int getChance(short int tier) const override;
	std::vector<int> getEvent(short int tier) const override;
	short int getEventID() const;
	std::string getCaption() const;
};