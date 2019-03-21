#include "EventHandler.h"

EventHandler::EventHandler(): _EventHandlerLocker(true), _maxPeopleCount(true), _peopleCount(true), _textInputLocker(true), _unitRecruitLocker(true), _cleanDataLocker(true), _starveEndgame(false), 
_attackEndgame(false), _eventConfirmed(false)
{
}

void EventHandler::setEventHandlerLocker(bool condition)
{
	_EventHandlerLocker = condition;
}

void EventHandler::setMaxPeopleCount(bool condition)
{
	_maxPeopleCount = condition;
}

void EventHandler::setPeopleCount(bool condition)
{
	_peopleCount = condition;
}

bool EventHandler::getEventHandlerLocker()
{
	return _EventHandlerLocker;
}

bool EventHandler::getMaxPeopleCount()
{
	return _maxPeopleCount;
}

bool EventHandler::getPeopleCount()
{
	return _peopleCount;
}

void EventHandler::setBuildingsUpgradeLocker(bool condition)
{
	_buildingsUpgradeLocker = condition;
}

bool EventHandler::getBuildingsUpgradeLocker()
{
	return _buildingsUpgradeLocker;
}

void EventHandler::setBuildingsTypeUpgrade(short int buildingsType)
{
	_buildingsTypeUpgrade = buildingsType;
}

short int EventHandler::getBuildingsTypeUpgrade()
{
	return _buildingsTypeUpgrade;
}

void EventHandler::setTextInputLocker(bool condition, std::string name)
{
	_textInputLocker = condition;
	_textInputName = name;
}

bool EventHandler::getTextInputLocker()
{
	return _textInputLocker;
}

std::string EventHandler::getTextInputName()
{
	return _textInputName;
}

void EventHandler::setTextInput(sf::String text)
{
	_textInput = text;
}

sf::String EventHandler::getTextInput() const
{
	return _textInput;
}

void EventHandler::setUnitTypeRecruitInput(short int unitType)
{
	_unitTypeRecruitInput = unitType;
}

short int EventHandler::getUnitTypeRecruitInput()
{
	return _unitTypeRecruitInput;
}

void EventHandler::setUnitRecruitLocker(bool condition)
{
	_unitRecruitLocker = condition;
}

bool EventHandler::getUnitRecruitLocker()
{
	return _unitRecruitLocker;
}

void EventHandler::setUnitTypeRecruit(short int unitType)
{
	_unitTypeRecruit = unitType;
}

short int EventHandler::getUnitTypeRecruit()
{
	return _unitTypeRecruit;
}

void EventHandler::setCleanDataLocker(bool condition)
{
	_cleanDataLocker = condition;
}

bool EventHandler::getCleanDataLocker()
{
	return _cleanDataLocker;
}

void EventHandler::setStarveEndgame(bool condition)
{
	_starveEndgame = condition;
}

bool EventHandler::getStarveEndgame()
{
	return _starveEndgame;
}

void EventHandler::setAttackEndgame(bool condition)
{
	_attackEndgame = condition;
}

bool EventHandler::getAttackEndgame()
{
	return _attackEndgame;
}

void EventHandler::setEventConfirmed(bool condition)
{
	_eventConfirmed = condition;
}

bool EventHandler::getEventConfirmed()
{
	return _eventConfirmed;
}
