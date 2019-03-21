#pragma once

class ResourcesData {
	int _woodAmount;
	int _ironAmount;
	int _clayAmount;
	int _foodAmount;
	int _peopleAmount;
	int _maxPeopleAmount;

public:
	ResourcesData();
	~ResourcesData() = default;
	void updateWood(int amount);
	void updateIron(int amount);
	void updateClay(int amount);
	void updateFood(int amount);
	void updatePoeple(int amount);
	
	void setMaxPeopleAmount(int amount);

	int getWood() const;
	int getIron() const;
	int getClay() const;
	int getFood() const;
	int getPeople() const;
	int getMaxPeopleAmount() const;

	void cleanData();
};