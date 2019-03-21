#include "BuildingsWindowFrame.h"

BuildingsWindowFrame::BuildingsWindowFrame(std::string const iconFilePath, std::string captionContent, const Data & Data): _iconFilePath(iconFilePath), _captionContent(captionContent)
{
	_resources.push_back(Data.getResources(WOOD));
	_resources.push_back(Data.getResources(IRON));
	_resources.push_back(Data.getResources(CLAY));
	_resources.push_back(Data.getResources(FOOD));
	_resources.push_back(Data.getResources(PEOPLE));
	_resources.push_back(Data.getResources(MAXPEOPLE));
	_resources.push_back(Data.getHours());
}

void BuildingsWindowFrame::update(const Data & Data)
{
	_resources[WOOD] = Data.getResources(WOOD);
	_resources[IRON] = Data.getResources(IRON);
	_resources[CLAY] = Data.getResources(CLAY);
	_resources[FOOD] = Data.getResources(FOOD);
	_resources[PEOPLE] = Data.getResources(PEOPLE);
	_resources[MAXPEOPLE] = Data.getResources(MAXPEOPLE);
	_resources[TIME] = Data.getHours();
}

void BuildingsWindowFrame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Color const defaultTextColor(100, 100, 100);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		throw NoBuildingsWindowFrameException();
	}

	// Info top bar

	sf::RectangleShape InfoTopBar(sf::Vector2f(WIDTH*0.90, HEIGHT*0.05));
	InfoTopBar.setPosition(sf::Vector2f(WIDTH*0.05, HEIGHT*0.025));
	InfoTopBar.setFillColor(sf::Color(74, 46, 17));
	target.draw(InfoTopBar);

	sf::Text DayTimeText;
	DayTimeText.setFillColor(defaultTextColor);
	DayTimeText.setFont(font);
	DayTimeText.setString("Dzien " + std::to_string(_resources[TIME] / 24) + " Godzina " + std::to_string(_resources[TIME] % 24));
	DayTimeText.setPosition(WIDTH*0.15f, HEIGHT*0.03f);
	target.draw(DayTimeText);

	// Resource Icons
	Icon WoodIconTop(sf::Vector2f(WIDTH*0.50f, HEIGHT*0.04f), "img/WoodIcon.png", sf::Vector2f(1.2f, 1.2f));
	target.draw(WoodIconTop);

	Icon IronIconTop(sf::Vector2f(WIDTH*0.58f, HEIGHT*0.04f), "img/IronIcon.png", sf::Vector2f(1.2f, 1.2f));
	target.draw(IronIconTop);

	Icon ClayIconTop(sf::Vector2f(WIDTH*0.66f, HEIGHT*0.04f), "img/ClayIcon.png", sf::Vector2f(1.2f, 1.2f));
	target.draw(ClayIconTop);

	Icon FoodIconTop(sf::Vector2f(WIDTH*0.74f, HEIGHT*0.04f), "img/FoodIcon.png", sf::Vector2f(1.2f, 1.2f));
	target.draw(FoodIconTop);

	Icon PeopleIconTop(sf::Vector2f(WIDTH*0.82f, HEIGHT*0.04f), "img/PeopleIcon.png", sf::Vector2f(1.2f, 1.2f));
	target.draw(PeopleIconTop);

	sf::Text WoodText;
	WoodText.setFillColor(defaultTextColor);
	WoodText.setString(std::to_string(_resources[WOOD]));
	WoodText.setPosition(WIDTH*0.52f, HEIGHT*0.03f);
	WoodText.setFont(font);

	sf::Text IronText;
	IronText.setFillColor(defaultTextColor);
	IronText.setString(std::to_string(_resources[IRON]));
	IronText.setPosition(WIDTH*0.6f, HEIGHT*0.03f);
	IronText.setFont(font);

	sf::Text ClayText;
	ClayText.setFillColor(defaultTextColor);
	ClayText.setString(std::to_string(_resources[CLAY]));
	ClayText.setPosition(WIDTH*0.68f, HEIGHT*0.03f);
	ClayText.setFont(font);

	sf::Text FoodText;
	FoodText.setFillColor(defaultTextColor);
	FoodText.setString(std::to_string(_resources[FOOD]));
	FoodText.setPosition(WIDTH*0.76f, HEIGHT*0.03f);
	FoodText.setFont(font);

	sf::Text PeopleText;
	PeopleText.setFillColor(defaultTextColor);
	PeopleText.setString(std::to_string(_resources[PEOPLE]) + "/" + std::to_string(_resources[MAXPEOPLE]));
	PeopleText.setPosition(WIDTH*0.84f, HEIGHT*0.03f);
	PeopleText.setFont(font);

	target.draw(WoodText);
	target.draw(IronText);
	target.draw(ClayText);
	target.draw(FoodText);
	target.draw(PeopleText);

	sf::RectangleShape WindowBackground(sf::Vector2f(WIDTH*0.8f, HEIGHT*0.8f));
	WindowBackground.setPosition(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.1f));
	WindowBackground.setFillColor(sf::Color(74, 46, 17));
	target.draw(WindowBackground);

	Icon BuildingIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.15f), _iconFilePath);
	target.draw(BuildingIcon);

	sf::Text WindowCaption;
	WindowCaption.setFillColor(defaultTextColor);
	WindowCaption.setFont(font);
	WindowCaption.setString(_captionContent);
	WindowCaption.setPosition(WIDTH*0.25f, HEIGHT*0.17f);
	target.draw(WindowCaption);

}
