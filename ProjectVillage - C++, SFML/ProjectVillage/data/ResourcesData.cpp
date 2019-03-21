#include "ResourcesData.h"

ResourcesData::ResourcesData() : _woodAmount(100), _ironAmount(100), _clayAmount(100), _foodAmount(0)
{
}

void ResourcesData::updateWood(int amount)
{
	if (_woodAmount + amount < 0)
		_woodAmount = 0;
	else
		_woodAmount += amount;
}

void ResourcesData::updateIron(int amount)
{
	if (_ironAmount + amount < 0)
		_ironAmount =0;
	else
		_ironAmount += amount;
}

void ResourcesData::updateClay(int amount)
{
	if (_clayAmount + amount < 0)
		_clayAmount = 0;
	else
		_clayAmount += amount;
}

void ResourcesData::updateFood(int amount)
{
		_foodAmount += amount;
}

void ResourcesData::updatePoeple(int amount)
{
	_peopleAmount = amount;
}

void ResourcesData::setMaxPeopleAmount(int amount)
{
	_maxPeopleAmount = amount;
}

int ResourcesData::getWood() const
{
	return _woodAmount;
}

int ResourcesData::getIron() const
{
	return _ironAmount;
}

int ResourcesData::getClay() const
{
	return _clayAmount;
}

int ResourcesData::getFood() const
{
	return _foodAmount;
}

int ResourcesData::getPeople() const
{
	return _peopleAmount;
}

int ResourcesData::getMaxPeopleAmount() const
{
	return _maxPeopleAmount;
}

void ResourcesData::cleanData()
{
	_woodAmount = 100;
	_ironAmount = 100;
	_clayAmount = 100;
	_foodAmount = 0;
}
