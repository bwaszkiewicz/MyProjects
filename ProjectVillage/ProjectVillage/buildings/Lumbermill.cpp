#include "Lumbermill.h"

void Lumbermill::init()
{
	_currentlevel = 1;
	for (int i = 0; i < MaxLevel; ++i)
	{
		_requireWood[i] = 20 * (i + 3);
		_requireIron[i] = 10 * (i + 3);
		_requireClay[i] = 10 * (i + 2);
		_requirePeople[i] = i * 1;
	}
}

void Lumbermill::upgrade()
{
	_currentlevel++;
}

short int Lumbermill::getlevel()
{
	return _currentlevel;
}

int Lumbermill::getRequirePeopleOnCurrentLevel()
{
	int requirePeopleSum = 0;
	for (int i = 0; i <= _currentlevel; i++)
		requirePeopleSum += _requirePeople[i];

	return requirePeopleSum;
}

std::vector<int> Lumbermill::getNextLevelRequire() const
{
	std::vector<int> resourcesToNextLevel(4);
	resourcesToNextLevel[0] = _requireWood[_currentlevel + 1];
	resourcesToNextLevel[1] = _requireIron[_currentlevel + 1];
	resourcesToNextLevel[2] = _requireClay[_currentlevel + 1];
	resourcesToNextLevel[3] = _requirePeople[_currentlevel + 1];

	return resourcesToNextLevel;
}
