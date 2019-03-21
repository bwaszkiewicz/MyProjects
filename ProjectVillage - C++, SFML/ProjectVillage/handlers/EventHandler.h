#pragma once
#include <SFML/Graphics.hpp>

class EventHandler {

	bool _EventHandlerLocker;

	bool _maxPeopleCount;
	bool _peopleCount;

	bool _buildingsUpgradeLocker;
	short int _buildingsTypeUpgrade;


	// To Units recruit
	bool _textInputLocker;
	sf::String _textInput;
	std::string _textInputName;
	short int _unitTypeRecruitInput;

	bool _unitRecruitLocker;
	short int _unitTypeRecruit;

	// Clean Data
	bool _cleanDataLocker;

	// Endgames
	bool _starveEndgame;
	bool _attackEndgame;

	// Event confirmed
	bool _eventConfirmed;

public:
	EventHandler();
	~EventHandler()=default;

	// EventHanlder lockers

	void setEventHandlerLocker(bool condition);
	bool getEventHandlerLocker();

	// People resources lockers

	void setMaxPeopleCount(bool condition);
	void setPeopleCount(bool condition);

	bool getMaxPeopleCount();
	bool getPeopleCount();

	// Buildings lockers

	void setBuildingsUpgradeLocker(bool condition);
	bool getBuildingsUpgradeLocker();

	void setBuildingsTypeUpgrade(short int buildingsType);
	short int getBuildingsTypeUpgrade();

	// TextInput lockers

	void setTextInputLocker(bool condition, std::string name);
	bool getTextInputLocker();
	std::string getTextInputName();

	void setTextInput(sf::String text);
	sf::String getTextInput() const;

	void setUnitTypeRecruitInput(short int unitType);
	short int getUnitTypeRecruitInput();

	void setUnitRecruitLocker(bool condition);
	bool getUnitRecruitLocker();
	void setUnitTypeRecruit(short int unitType);
	short int getUnitTypeRecruit();

	// Clean Data

	void setCleanDataLocker(bool condition);
	bool getCleanDataLocker();

	// Endgames
	void setStarveEndgame(bool condition);
	bool getStarveEndgame();

	void setAttackEndgame(bool condition);
	bool getAttackEndgame();

	// Event confirmed
	void setEventConfirmed(bool condition);
	bool getEventConfirmed();

};