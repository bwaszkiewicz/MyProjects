#pragma once
#include <vector>
#include <string>
#include "../Defines.h"

class RandomEvent {
	int _chance[MAX_TIER_EVENT];

public:
	virtual void init(short int tier) = 0;
	virtual ~RandomEvent() = default;

	virtual int getChance(short int tier) const = 0;
	virtual std::vector<int> getEvent(short int tier) const = 0;
	virtual short int getEventID() const = 0;
	virtual std::string getCaption() const = 0;
};