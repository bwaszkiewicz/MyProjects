#include "RandomMachine.h"

RandomEvent* RandomMachine::createRandomEvent(short int tier)
{
	int draw = rand() % 100;
	RandomEvent* tempEvent=nullptr;
	switch (tier)
	{
	case 0:
	{
		int sum = 0;
		tempEvent = new AbundanceEvent;
		tempEvent->init(tier);
		sum += tempEvent->getChance(tier);
		if (draw < sum)
			return tempEvent;
		else
		{
			delete tempEvent;
			tempEvent = new BarbarianAttackEvent;
			tempEvent->init(tier);
			sum += tempEvent->getChance(tier);
			if (draw < sum)
				return tempEvent;
			else
			{
				delete tempEvent;
				tempEvent = new DesertionEvent;
				tempEvent->init(tier);
				sum += tempEvent->getChance(tier);
				if (draw < sum)
					return tempEvent;
				else
				{
					delete tempEvent;
					tempEvent = new IronDepositFindEvent;
					tempEvent->init(tier);
					sum += tempEvent->getChance(tier);
					if (draw < sum)
						return tempEvent;
					else
					{
						delete tempEvent;
						tempEvent = new LocustEvent;
						tempEvent->init(tier);
						sum += tempEvent->getChance(tier);
						if (draw < sum)
							return tempEvent;
						else
						{
							delete tempEvent;
							tempEvent = new MarrauderAttackEvent;
							tempEvent->init(tier);
							sum += tempEvent->getChance(tier);
							if (draw < sum)
								return tempEvent;
							else
							{
								delete tempEvent;
								tempEvent = new ThievesEvent;
								tempEvent->init(tier);
								sum += tempEvent->getChance(tier);
								if (draw < sum)
									return tempEvent;
								else
								{
									delete tempEvent;
									tempEvent = new BlockOfClayEvent;
									tempEvent->init(tier);
									sum += tempEvent->getChance(tier);
									if (draw < sum)
										return tempEvent;
									else
									{
										delete tempEvent;
										tempEvent = new BigTreeEvent;
										tempEvent->init(tier);
										sum += tempEvent->getChance(tier);
										if (draw < sum)
											return tempEvent;
										else
										{
											delete tempEvent;
											tempEvent = new NomadsAttackEvent;
											tempEvent->init(tier);
											sum += tempEvent->getChance(tier);
											if (draw < sum)
												return tempEvent;
											else
											{
												delete tempEvent;
												tempEvent = new RecruitEvent;
												tempEvent->init(tier);
												sum += tempEvent->getChance(tier);
												if (draw <= sum)
													return tempEvent;
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}
		break;
	case 1:
	{
		int sum = 0;
		delete tempEvent;
		tempEvent = new AbundanceEvent;
		tempEvent->init(tier);
		sum += tempEvent->getChance(tier);
		if (draw < sum)
			return tempEvent;
		else
		{
			delete tempEvent;
			tempEvent = new BarbarianAttackEvent;
			tempEvent->init(tier);
			sum += tempEvent->getChance(tier);
			if (draw < sum)
				return tempEvent;
			else
			{
				delete tempEvent;
				tempEvent = new DesertionEvent;
				tempEvent->init(tier);
				sum += tempEvent->getChance(tier);
				if (draw < sum)
					return tempEvent;
				else
				{
					delete tempEvent;
					tempEvent = new IronDepositFindEvent;
					tempEvent->init(tier);
					sum += tempEvent->getChance(tier);
					if (draw < sum)
						return tempEvent;
					else
					{
						delete tempEvent;
						tempEvent = new LocustEvent;
						tempEvent->init(tier);
						sum += tempEvent->getChance(tier);
						if (draw < sum)
							return tempEvent;
						else
						{
							delete tempEvent;
							tempEvent = new MarrauderAttackEvent;
							tempEvent->init(tier);
							sum += tempEvent->getChance(tier);
							if (draw < sum)
								return tempEvent;
							else
							{
								delete tempEvent;
								tempEvent = new ThievesEvent;
								tempEvent->init(tier);
								sum += tempEvent->getChance(tier);
								if (draw < sum)
									return tempEvent;
								else
								{
									delete tempEvent;
									tempEvent = new BlockOfClayEvent;
									tempEvent->init(tier);
									sum += tempEvent->getChance(tier);
									if (draw < sum)
										return tempEvent;
									else
									{
										delete tempEvent;
										tempEvent = new BigTreeEvent;
										tempEvent->init(tier);
										sum += tempEvent->getChance(tier);
										if (draw < sum)
											return tempEvent;
										else
										{
											delete tempEvent;
											tempEvent = new NomadsAttackEvent;
											tempEvent->init(tier);
											sum += tempEvent->getChance(tier);
											if (draw < sum)
												return tempEvent;
											else
											{
												delete tempEvent;
												tempEvent = new RecruitEvent;
												tempEvent->init(tier);
												sum += tempEvent->getChance(tier);
												if (draw <= sum)
													return tempEvent;
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}
		break;
	case 2:
	{
		int sum = 0;
		delete tempEvent;
		tempEvent = new AbundanceEvent;
		tempEvent->init(tier);
		sum += tempEvent->getChance(tier);
		if (draw < sum)
			return tempEvent;
		else
		{
			delete tempEvent;
			tempEvent = new BarbarianAttackEvent;
			tempEvent->init(tier);
			sum += tempEvent->getChance(tier);
			if (draw < sum)
				return tempEvent;
			else
			{
				delete tempEvent;
				tempEvent = new DesertionEvent;
				tempEvent->init(tier);
				sum += tempEvent->getChance(tier);
				if (draw < sum)
					return tempEvent;
				else
				{
					delete tempEvent;
					tempEvent = new IronDepositFindEvent;
					tempEvent->init(tier);
					sum += tempEvent->getChance(tier);
					if (draw < sum)
						return tempEvent;
					else
					{
						delete tempEvent;
						tempEvent = new LocustEvent;
						tempEvent->init(tier);
						sum += tempEvent->getChance(tier);
						if (draw < sum)
							return tempEvent;
						else
						{
							delete tempEvent;
							tempEvent = new MarrauderAttackEvent;
							tempEvent->init(tier);
							sum += tempEvent->getChance(tier);
							if (draw < sum)
								return tempEvent;
							else
							{
								delete tempEvent;
								tempEvent = new ThievesEvent;
								tempEvent->init(tier);
								sum += tempEvent->getChance(tier);
								if (draw < sum)
									return tempEvent;
								else
								{
									delete tempEvent;
									tempEvent = new BlockOfClayEvent;
									tempEvent->init(tier);
									sum += tempEvent->getChance(tier);
									if (draw < sum)
										return tempEvent;
									else
									{
										delete tempEvent;
										tempEvent = new BigTreeEvent;
										tempEvent->init(tier);
										sum += tempEvent->getChance(tier);
										if (draw < sum)
											return tempEvent;
										else
										{
											delete tempEvent;
											tempEvent = new NomadsAttackEvent;
											tempEvent->init(tier);
											sum += tempEvent->getChance(tier);
											if (draw < sum)
												return tempEvent;
											else
											{
												delete tempEvent;
												tempEvent = new RecruitEvent;
												tempEvent->init(tier);
												sum += tempEvent->getChance(tier);
												if (draw <= sum)
													return tempEvent;
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}
		break;
	case 3:
	{
		int sum = 0;
		delete tempEvent;
		tempEvent = new AbundanceEvent;
		tempEvent->init(tier);
		sum += tempEvent->getChance(tier);
		if (draw < sum)
			return tempEvent;
		else
		{
			delete tempEvent;
			tempEvent = new BarbarianAttackEvent;
			tempEvent->init(tier);
			sum += tempEvent->getChance(tier);
			if (draw < sum)
				return tempEvent;
			else
			{
				delete tempEvent;
				tempEvent = new DesertionEvent;
				tempEvent->init(tier);
				sum += tempEvent->getChance(tier);
				if (draw < sum)
					return tempEvent;
				else
				{
					delete tempEvent;
					tempEvent = new IronDepositFindEvent;
					tempEvent->init(tier);
					sum += tempEvent->getChance(tier);
					if (draw < sum)
						return tempEvent;
					else
					{
						delete tempEvent;
						tempEvent = new LocustEvent;
						tempEvent->init(tier);
						sum += tempEvent->getChance(tier);
						if (draw < sum)
							return tempEvent;
						else
						{
							delete tempEvent;
							tempEvent = new MarrauderAttackEvent;
							tempEvent->init(tier);
							sum += tempEvent->getChance(tier);
							if (draw < sum)
								return tempEvent;
							else
							{
								delete tempEvent;
								tempEvent = new ThievesEvent;
								tempEvent->init(tier);
								sum += tempEvent->getChance(tier);
								if (draw < sum)
									return tempEvent;
								else
								{
									delete tempEvent;
									tempEvent = new BlockOfClayEvent;
									tempEvent->init(tier);
									sum += tempEvent->getChance(tier);
									if (draw < sum)
										return tempEvent;
									else
									{
										delete tempEvent;
										tempEvent = new BigTreeEvent;
										tempEvent->init(tier);
										sum += tempEvent->getChance(tier);
										if (draw < sum)
											return tempEvent;
										else
										{
											delete tempEvent;
											tempEvent = new NomadsAttackEvent;
											tempEvent->init(tier);
											sum += tempEvent->getChance(tier);
											if (draw < sum)
												return tempEvent;
											else
											{
												delete tempEvent;
												tempEvent = new RecruitEvent;
												tempEvent->init(tier);
												sum += tempEvent->getChance(tier);
												if (draw <= sum)
													return tempEvent;
											}
										}
									}
								}
							}
						}
					}
				}

			}
		}
	}
		break;
	default:
		throw InvalidEventTierException();
		break;
	}
}

RandomMachine::RandomMachine(): _ticks(0), _tier(-1), _currentTierLength(0)
{
}

RandomMachine::~RandomMachine()
{
}

RandomEvent* RandomMachine::randomize()
{
	if (_currentTierLength <= _ticks && _tier !=MAX_TIER_EVENT)
	{
		_currentTierLength = rand() % 8 + 9;
		_tier++;
		_ticks = 0;
	}
	else
		_ticks++;
	return  createRandomEvent(_tier);
}

int RandomMachine::getTier() const
{
	return _tier;
}

void RandomMachine::cleanData()
{
	_ticks = 0;
	_tier = -1;
	_currentTierLength = 0;
}
