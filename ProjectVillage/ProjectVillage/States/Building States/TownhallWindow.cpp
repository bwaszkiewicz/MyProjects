#include "TownhallWindow.h"

State * TownhallWindow::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		if (Map.getIconButton("TownhallUpgradeIcon") == in)
		{
			evHandler.setBuildingsUpgradeLocker(false);
			evHandler.setBuildingsTypeUpgrade(TOWNHALL);
			return nullptr;
		}
		else
			if (Map.getIconButton("LumbermillUpgradeIcon") == in)
			{
				evHandler.setBuildingsUpgradeLocker(false);
				evHandler.setBuildingsTypeUpgrade(LUMBERMILL);
				return nullptr;
			}
			else
				if (Map.getIconButton("BrickyardUpgradeIcon") == in)
				{
					evHandler.setBuildingsUpgradeLocker(false);
					evHandler.setBuildingsTypeUpgrade(BRICKYARD);
					return nullptr;
				}
				else
					if (Map.getIconButton("MineUpgradeIcon") == in)
					{
						evHandler.setBuildingsUpgradeLocker(false);
						evHandler.setBuildingsTypeUpgrade(MINE);
						return nullptr;
					}
					else
						if (Map.getIconButton("FarmUpgradeIcon") == in)
						{
							evHandler.setBuildingsUpgradeLocker(false);
							evHandler.setBuildingsTypeUpgrade(FARM);
							return nullptr;
						}
						else
							if (Map.getIconButton("BarrackUpgradeIcon") == in)
							{
								evHandler.setBuildingsUpgradeLocker(false);
								evHandler.setBuildingsTypeUpgrade(BARRACK);
								return nullptr;
							}
							else
								if (Map.getIconButton("StableUpgradeIcon") == in)
								{
									evHandler.setBuildingsUpgradeLocker(false);
									evHandler.setBuildingsTypeUpgrade(STABLE);
									return nullptr;
								}
								else
									if (Map.getIconButton("SmithyUpgradeIcon") == in)
									{
										evHandler.setBuildingsUpgradeLocker(false);
										evHandler.setBuildingsTypeUpgrade(SMITHY);
										return nullptr;
									}
									else
										if (Map.getIconButton("HousesUpgradeIcon") == in)
										{
											evHandler.setBuildingsUpgradeLocker(false);
											evHandler.setBuildingsTypeUpgrade(HOUSES);
											return nullptr;
										}
										else
											if (Map.getIconButton("WallsUpgradeIcon") == in)
											{
												evHandler.setBuildingsUpgradeLocker(false);
												evHandler.setBuildingsTypeUpgrade(WALLS);
												return nullptr;
											}
											else
												return nullptr;
}

void TownhallWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		TextHandler Handler;
		MainData.updateResources(WOOD);
		Handler.setText(Map.getText("WoodText"));
		Handler.modifyText(std::to_string(MainData.getResources(WOOD)));
		Map.setText("WoodText", Handler.getText());

		MainData.updateResources(IRON);
		Handler.setText(Map.getText("IronText"));
		Handler.modifyText(std::to_string(MainData.getResources(IRON)));
		Map.setText("IronText", Handler.getText());

		MainData.updateResources(CLAY);
		Handler.setText(Map.getText("ClayText"));
		Handler.modifyText(std::to_string(MainData.getResources(CLAY)));
		Map.setText("ClayText", Handler.getText());

		MainData.updateResources(FOOD);
		Handler.setText(Map.getText("FoodText"));
		Handler.modifyText(std::to_string(MainData.getResources(FOOD)));
		Map.setText("FoodText", Handler.getText());

	}
	Map = render(MainData);
	break;
	case PEOPLE_COUNT_UPDATE:
	{
		TextHandler Handler;

		MainData.updateResources(PEOPLE);
		Handler.setText(Map.getText("PeopleText"));
		Handler.modifyText(std::to_string(MainData.getResources(PEOPLE)) + "/" + std::to_string(MainData.getResources(MAXPEOPLE)));
		Map.setText("PeopleText", Handler.getText());
	}
	break;
	case PEOPLE_MAX_COUNT_UPDATE:
	{
		TextHandler Handler;
		MainData.updateResources(MAXPEOPLE);
		Handler.setText(Map.getText("PeopleText"));
		Handler.modifyText(std::to_string(MainData.getResources(PEOPLE)) + "/" + std::to_string(MainData.getResources(MAXPEOPLE)));
		Map.setText("PeopleText", Handler.getText());
	}
	break;
	case BUILDINGS_UPDATE:
		MainData.updateBuilding(evHandler.getBuildingsTypeUpgrade());
		Map = render(MainData);
		break;
	case TIME_UPDATE:
	{
		TextHandler Handler;
		MainData.hoursIncerement();
		Handler.setText(Map.getText("DayTimeText"));
		Handler.modifyText("Dzien " + std::to_string(MainData.getHours() / 24) + " Godzina " + std::to_string(MainData.getHours() % 24));
		Map.setText("DayTimeText", Handler.getText());
	}
	break;
	case FOOD_UPDATE:
	{
		TextHandler Handler;
		MainData.recalculateFood();
		Handler.setText(Map.getText("FoodText"));
		Handler.modifyText(std::to_string(MainData.getResources(FOOD)));
		Map.setText("FoodText", Handler.getText());
	}
	break;
	default:
		break;
	}
}

ShapeMap TownhallWindow::render(const Data & MainData)
{
	ShapeMap Map;
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	// Header

		// Info top bar

		sf::RectangleShape InfoTopBar(sf::Vector2f(WIDTH*0.90, HEIGHT*0.05));
		InfoTopBar.setPosition(sf::Vector2f(WIDTH*0.05, HEIGHT*0.025));
		InfoTopBar.setFillColor(sf::Color(74, 46, 17));

		Map.addRectangleShape("InfoTopBar", InfoTopBar);

		sf::Text DayTimeText;
		DayTimeText.setFillColor(defaultTextColor);
		DayTimeText.setString("Dzien " + std::to_string(MainData.getHours() / 24) + " Godzina " + std::to_string(MainData.getHours() % 24));
		DayTimeText.setPosition(WIDTH*0.15f, HEIGHT*0.03f);

		Map.addText("DayTimeText", DayTimeText, defaultFont);

		// Resource Icons
		Icon WoodIconTop(sf::Vector2f(WIDTH*0.50f, HEIGHT*0.04f), "img/WoodIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("WoodIconTop", WoodIconTop);

		Icon IronIconTop(sf::Vector2f(WIDTH*0.58f, HEIGHT*0.04f), "img/IronIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("IronIconTop", IronIconTop);

		Icon ClayIconTop(sf::Vector2f(WIDTH*0.66f, HEIGHT*0.04f), "img/ClayIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("ClayIconTop", ClayIconTop);

		Icon FoodIconTop(sf::Vector2f(WIDTH*0.74f, HEIGHT*0.04f), "img/FoodIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("FoodIconTop", FoodIconTop);

		Icon PeopleIconTop(sf::Vector2f(WIDTH*0.82f, HEIGHT*0.04f), "img/PeopleIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("PeopleIconTop", PeopleIconTop);

		sf::Text WoodText;
		WoodText.setFillColor(defaultTextColor);
		WoodText.setString(std::to_string(MainData.getResources(WOOD)));
		WoodText.setPosition(WIDTH*0.52f, HEIGHT*0.03f);

		sf::Text IronText;
		IronText.setFillColor(defaultTextColor);
		IronText.setString(std::to_string(MainData.getResources(IRON)));
		IronText.setPosition(WIDTH*0.6f, HEIGHT*0.03f);

		sf::Text ClayText;
		ClayText.setFillColor(defaultTextColor);
		ClayText.setString(std::to_string(MainData.getResources(CLAY)));
		ClayText.setPosition(WIDTH*0.68f, HEIGHT*0.03f);

		sf::Text FoodText;
		FoodText.setFillColor(defaultTextColor);
		FoodText.setString(std::to_string(MainData.getResources(FOOD)));
		FoodText.setPosition(WIDTH*0.76f, HEIGHT*0.03f);

		sf::Text PeopleText;
		PeopleText.setFillColor(defaultTextColor);
		PeopleText.setString(std::to_string(MainData.getResources(PEOPLE)) + "/" + std::to_string(MainData.getResources(MAXPEOPLE)));
		PeopleText.setPosition(WIDTH*0.84f, HEIGHT*0.03f);

		Map.addText("WoodText", WoodText, defaultFont);
		Map.addText("IronText", IronText, defaultFont);
		Map.addText("ClayText", ClayText, defaultFont);
		Map.addText("FoodText", FoodText, defaultFont);
		Map.addText("PeopleText", PeopleText, defaultFont);

	sf::RectangleShape WindowBackground(sf::Vector2f(WIDTH*0.8f, HEIGHT*0.8f));
	WindowBackground.setPosition(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.1f));
	WindowBackground.setFillColor(sf::Color(74, 46, 17));

	Map.addRectangleShape("WindowBackground", WindowBackground);

	Icon TownhallIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.15f), "img/Townhall.png");
	Map.addIcon("TownhallIcon", TownhallIcon);

	sf::Text WindowCaption;
	WindowCaption.setFillColor(defaultTextColor);
	WindowCaption.setString("Townhall");
	WindowCaption.setPosition(WIDTH*0.25f, HEIGHT*0.17f);
	Map.addText("WindowCaption", WindowCaption, defaultFont);

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	// Resources Icons

	Icon WoodIcon(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.28f), "img/WoodIcon.png", sf::Vector2f(1.2f, 1.2f));
	Map.addIcon("WoodIcon", WoodIcon);

	Icon IronIcon(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.28f), "img/IronIcon.png", sf::Vector2f(1.2f, 1.2f));
	Map.addIcon("IronIcon", IronIcon);

	Icon ClayIcon(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.28f), "img/ClayIcon.png", sf::Vector2f(1.2f, 1.2f));
	Map.addIcon("ClayIcon", ClayIcon);

	Icon PeopleIcon(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.28f), "img/PeopleIcon.png", sf::Vector2f(1.2f, 1.2f));
	Map.addIcon("PeopleIcon", PeopleIcon);

	// Upgrade Icons

	IconButton TownhallUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.32f), "img/upgradeIcon2.png");
	Map.addIconButton("TownhallUpgradeIcon", TownhallUpgradeIcon);

	IconButton LumbermillUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.36f), "img/upgradeIcon2.png");
	Map.addIconButton("LumbermillUpgradeIcon", LumbermillUpgradeIcon);

	IconButton BrickyardUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.4f), "img/upgradeIcon2.png");
	Map.addIconButton("BrickyardUpgradeIcon", BrickyardUpgradeIcon);

	IconButton MineUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.44f), "img/upgradeIcon2.png");
	Map.addIconButton("MineUpgradeIcon", MineUpgradeIcon);

	IconButton FarmUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.48f), "img/upgradeIcon2.png");
	Map.addIconButton("FarmUpgradeIcon", FarmUpgradeIcon);

	IconButton BarrackUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.52f), "img/upgradeIcon2.png");
	Map.addIconButton("BarrackUpgradeIcon", BarrackUpgradeIcon);

	IconButton StableUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.56f), "img/upgradeIcon2.png");
	Map.addIconButton("StableUpgradeIcon", StableUpgradeIcon);

	IconButton SmithyUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.6f), "img/upgradeIcon2.png");
	Map.addIconButton("SmithyUpgradeIcon", SmithyUpgradeIcon);

	IconButton HousesUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.64f), "img/upgradeIcon2.png");
	Map.addIconButton("HousesUpgradeIcon", HousesUpgradeIcon);

	IconButton WallsUpgradeIcon(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.68f), "img/upgradeIcon2.png");
	Map.addIconButton("WallsUpgradeIcon", WallsUpgradeIcon);

	// Building List

			// Townhall

		sf::Text TownhallText;
		TownhallText.setFillColor(defaultTextColor);
		TownhallText.setString("Townhall: ");
		TownhallText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.32f));

		sf::Text TownhallLevelText;
		TownhallLevelText.setFillColor(defaultTextColor);
		TownhallLevelText.setString(std::to_string(MainData.getBuildingsLevel(TOWNHALL)));
		TownhallLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.32f));

		sf::Text TownhallWoodRequireText;
		if(MainData.getResources(WOOD)>=MainData.getBuildingsNextLevelRequire(TOWNHALL)[0])
			TownhallWoodRequireText.setFillColor(defaultTextColor);
		else
			TownhallWoodRequireText.setFillColor(notReachedColor);
		TownhallWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(TOWNHALL)[0]));
		TownhallWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.32f));

		sf::Text TownhallIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(TOWNHALL)[1])
			TownhallIronRequireText.setFillColor(defaultTextColor);
		else
			TownhallIronRequireText.setFillColor(notReachedColor);
		TownhallIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(TOWNHALL)[1]));
		TownhallIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.32f));

		sf::Text TownhallClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(TOWNHALL)[2])
			TownhallClayRequireText.setFillColor(defaultTextColor);
		else
			TownhallClayRequireText.setFillColor(notReachedColor);
		TownhallClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(TOWNHALL)[2]));
		TownhallClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.32f));

		sf::Text TownhallPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(TOWNHALL)[3]+MainData.getResources(PEOPLE))
			TownhallPeopleRequireText.setFillColor(defaultTextColor);
		else
			TownhallPeopleRequireText.setFillColor(notReachedColor);
		TownhallPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(TOWNHALL)[3]));
		TownhallPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.32f));

			// Lumbermill

		sf::Text LumbermillText;
		LumbermillText.setFillColor(defaultTextColor);
		LumbermillText.setString("Lumbermill: ");
		LumbermillText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.36f));

		sf::Text LumbermillLevelText;
		LumbermillLevelText.setFillColor(defaultTextColor);
		LumbermillLevelText.setString(std::to_string(MainData.getBuildingsLevel(LUMBERMILL)));
		LumbermillLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.36f));

		sf::Text LumbermillWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(LUMBERMILL)[0])
			LumbermillWoodRequireText.setFillColor(defaultTextColor);
		else
			LumbermillWoodRequireText.setFillColor(notReachedColor);
		LumbermillWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(LUMBERMILL)[0]));
		LumbermillWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.36f));

		sf::Text LumbermillIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(LUMBERMILL)[1])
			LumbermillIronRequireText.setFillColor(defaultTextColor);
		else
			LumbermillIronRequireText.setFillColor(notReachedColor);
		LumbermillIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(LUMBERMILL)[1]));
		LumbermillIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.36f));

		sf::Text LumbermillClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(LUMBERMILL)[2])
			LumbermillClayRequireText.setFillColor(defaultTextColor);
		else
			LumbermillClayRequireText.setFillColor(notReachedColor);
		LumbermillClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(LUMBERMILL)[2]));
		LumbermillClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.36f));

		sf::Text LumbermillPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(LUMBERMILL)[3] + MainData.getResources(PEOPLE))
			LumbermillPeopleRequireText.setFillColor(defaultTextColor);
		else
			LumbermillPeopleRequireText.setFillColor(notReachedColor);
		LumbermillPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(LUMBERMILL)[3]));
		LumbermillPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.36f));

			// Brickyard

		sf::Text BrickyardText;
		BrickyardText.setFillColor(defaultTextColor);
		BrickyardText.setString("Brickyard: ");
		BrickyardText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.4f));

		sf::Text BrickyardLevelText;
		BrickyardLevelText.setFillColor(defaultTextColor);
		BrickyardLevelText.setString(std::to_string(MainData.getBuildingsLevel(BRICKYARD)));
		BrickyardLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.4f));

		sf::Text BrickyardWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(BRICKYARD)[0])
			BrickyardWoodRequireText.setFillColor(defaultTextColor);
		else
			BrickyardWoodRequireText.setFillColor(notReachedColor);
		BrickyardWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BRICKYARD)[0]));
		BrickyardWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.4f));

		sf::Text BrickyardIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(BRICKYARD)[1])
			BrickyardIronRequireText.setFillColor(defaultTextColor);
		else
			BrickyardIronRequireText.setFillColor(notReachedColor);
		BrickyardIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BRICKYARD)[1]));
		BrickyardIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.4f));

		sf::Text BrickyardClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(BRICKYARD)[2])
			BrickyardClayRequireText.setFillColor(defaultTextColor);
		else
			BrickyardClayRequireText.setFillColor(notReachedColor);
		BrickyardClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BRICKYARD)[2]));
		BrickyardClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.4f));

		sf::Text BrickyardPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(BRICKYARD)[3] + MainData.getResources(PEOPLE))
			BrickyardPeopleRequireText.setFillColor(defaultTextColor);
		else
			BrickyardPeopleRequireText.setFillColor(notReachedColor);
		BrickyardPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BRICKYARD)[3]));
		BrickyardPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.4f));

			// Mine

		sf::Text MineText;
		MineText.setFillColor(defaultTextColor);
		MineText.setString("Mine: ");
		MineText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.44f));

		sf::Text MineLevelText;
		MineLevelText.setFillColor(defaultTextColor);
		MineLevelText.setString(std::to_string(MainData.getBuildingsLevel(MINE)));
		MineLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.44f));

		sf::Text MineWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(MINE)[0])
			MineWoodRequireText.setFillColor(defaultTextColor);
		else
			MineWoodRequireText.setFillColor(notReachedColor);
		MineWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(MINE)[0]));
		MineWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.44f));

		sf::Text MineIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(MINE)[1])
			MineIronRequireText.setFillColor(defaultTextColor);
		else
			MineIronRequireText.setFillColor(notReachedColor);
		MineIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(MINE)[1]));
		MineIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.44f));

		sf::Text MineClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(MINE)[2])
			MineClayRequireText.setFillColor(defaultTextColor);
		else
			MineClayRequireText.setFillColor(notReachedColor);
		MineClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(MINE)[2]));
		MineClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.44f));

		sf::Text MinePeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(MINE)[3] + MainData.getResources(PEOPLE))
			MinePeopleRequireText.setFillColor(defaultTextColor);
		else
			MinePeopleRequireText.setFillColor(notReachedColor);
		MinePeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(MINE)[3]));
		MinePeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.44f));

			// Farm

		sf::Text FarmText;
		FarmText.setFillColor(defaultTextColor);
		FarmText.setString("Farm: ");
		FarmText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.48f));

		sf::Text FarmLevelText;
		FarmLevelText.setFillColor(defaultTextColor);
		FarmLevelText.setString(std::to_string(MainData.getBuildingsLevel(FARM)));
		FarmLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.48f));

		sf::Text FarmWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(FARM)[0])
			FarmWoodRequireText.setFillColor(defaultTextColor);
		else
			FarmWoodRequireText.setFillColor(notReachedColor);
		FarmWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(FARM)[0]));
		FarmWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.48f));

		sf::Text FarmIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(FARM)[1])
			FarmIronRequireText.setFillColor(defaultTextColor);
		else
			FarmIronRequireText.setFillColor(notReachedColor);
		FarmIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(FARM)[1]));
		FarmIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.48f));

		sf::Text FarmClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(FARM)[2])
			FarmClayRequireText.setFillColor(defaultTextColor);
		else
			FarmClayRequireText.setFillColor(notReachedColor);
		FarmClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(FARM)[2]));
		FarmClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.48f));

		sf::Text FarmPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(FARM)[3] + MainData.getResources(PEOPLE))
			FarmPeopleRequireText.setFillColor(defaultTextColor);
		else
			FarmPeopleRequireText.setFillColor(notReachedColor);
		FarmPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(FARM)[3]));
		FarmPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.48f));

			// Barrack

		sf::Text BarrackText;
		BarrackText.setFillColor(defaultTextColor);
		BarrackText.setString("Barrack: ");
		BarrackText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.52f));

		sf::Text BarrackLevelText;
		BarrackLevelText.setFillColor(defaultTextColor);
		BarrackLevelText.setString(std::to_string(MainData.getBuildingsLevel(BARRACK)));
		BarrackLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.52f));

		sf::Text BarrackWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(BARRACK)[0])
			BarrackWoodRequireText.setFillColor(defaultTextColor);
		else
			BarrackWoodRequireText.setFillColor(notReachedColor);
		BarrackWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BARRACK)[0]));
		BarrackWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.52f));

		sf::Text BarrackIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(BARRACK)[1])
			BarrackIronRequireText.setFillColor(defaultTextColor);
		else
			BarrackIronRequireText.setFillColor(notReachedColor);
		BarrackIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BARRACK)[1]));
		BarrackIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.52f));

		sf::Text BarrackClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(BARRACK)[2])
			BarrackClayRequireText.setFillColor(defaultTextColor);
		else
			BarrackClayRequireText.setFillColor(notReachedColor);
		BarrackClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BARRACK)[2]));
		BarrackClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.52f));

		sf::Text BarrackPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(BARRACK)[3] + MainData.getResources(PEOPLE))
			BarrackPeopleRequireText.setFillColor(defaultTextColor);
		else
			BarrackPeopleRequireText.setFillColor(notReachedColor);
		BarrackPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(BARRACK)[3]));
		BarrackPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.52f));

			// Stable

		sf::Text StableText;
		StableText.setFillColor(defaultTextColor);
		StableText.setString("Stable: ");
		StableText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.56f));

		sf::Text StableLevelText;
		StableLevelText.setFillColor(defaultTextColor);
		StableLevelText.setString(std::to_string(MainData.getBuildingsLevel(STABLE)));
		StableLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.56f));

		sf::Text StableWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(STABLE)[0])
			StableWoodRequireText.setFillColor(defaultTextColor);
		else
			StableWoodRequireText.setFillColor(notReachedColor);
		StableWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(STABLE)[0]));
		StableWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.56f));

		sf::Text StableIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(STABLE)[1])
			StableIronRequireText.setFillColor(defaultTextColor);
		else
			StableIronRequireText.setFillColor(notReachedColor);
		StableIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(STABLE)[1]));
		StableIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.56f));

		sf::Text StableClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(STABLE)[2])
			StableClayRequireText.setFillColor(defaultTextColor);
		else
			StableClayRequireText.setFillColor(notReachedColor);
		StableClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(STABLE)[2]));
		StableClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.56f));

		sf::Text StablePeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(STABLE)[3] + MainData.getResources(PEOPLE))
			StablePeopleRequireText.setFillColor(defaultTextColor);
		else
			StablePeopleRequireText.setFillColor(notReachedColor);
		StablePeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(STABLE)[3]));
		StablePeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.56f));

			// Smithy

		sf::Text SmithyText;
		SmithyText.setFillColor(defaultTextColor);
		SmithyText.setString("Smithy: ");
		SmithyText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.6f));

		sf::Text SmithyLevelText;
		SmithyLevelText.setFillColor(defaultTextColor);
		SmithyLevelText.setString(std::to_string(MainData.getBuildingsLevel(SMITHY)));
		SmithyLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.6f));

		sf::Text SmithyWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(SMITHY)[0])
			SmithyWoodRequireText.setFillColor(defaultTextColor);
		else
			SmithyWoodRequireText.setFillColor(notReachedColor);
		SmithyWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(SMITHY)[0]));
		SmithyWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.6f));

		sf::Text SmithyIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(SMITHY)[1])
			SmithyIronRequireText.setFillColor(defaultTextColor);
		else
			SmithyIronRequireText.setFillColor(notReachedColor);
		SmithyIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(SMITHY)[1]));
		SmithyIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.6f));

		sf::Text SmithyClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(SMITHY)[2])
			SmithyClayRequireText.setFillColor(defaultTextColor);
		else
			SmithyClayRequireText.setFillColor(notReachedColor);
		SmithyClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(SMITHY)[2]));
		SmithyClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.6f));

		sf::Text SmithyPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(SMITHY)[3] + MainData.getResources(PEOPLE))
			SmithyPeopleRequireText.setFillColor(defaultTextColor);
		else
			SmithyPeopleRequireText.setFillColor(notReachedColor);
		SmithyPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(SMITHY)[3]));
		SmithyPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.6f));

			// Houses

		sf::Text HousesText;
		HousesText.setFillColor(defaultTextColor);
		HousesText.setString("Houses: ");
		HousesText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.64f));

		sf::Text HousesLevelText;
		HousesLevelText.setFillColor(defaultTextColor);
		HousesLevelText.setString(std::to_string(MainData.getBuildingsLevel(HOUSES)));
		HousesLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.64f));

		sf::Text HousesWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(HOUSES)[0])
			HousesWoodRequireText.setFillColor(defaultTextColor);
		else
			HousesWoodRequireText.setFillColor(notReachedColor);
		HousesWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(HOUSES)[0]));
		HousesWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.64f));

		sf::Text HousesIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(HOUSES)[1])
			HousesIronRequireText.setFillColor(defaultTextColor);
		else
			HousesIronRequireText.setFillColor(notReachedColor);
		HousesIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(HOUSES)[1]));
		HousesIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.64f));

		sf::Text HousesClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(HOUSES)[2])
			HousesClayRequireText.setFillColor(defaultTextColor);
		else
			HousesClayRequireText.setFillColor(notReachedColor);
		HousesClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(HOUSES)[2]));
		HousesClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.64f));

		sf::Text HousesPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(HOUSES)[3] + MainData.getResources(PEOPLE))
			HousesPeopleRequireText.setFillColor(defaultTextColor);
		else
			HousesPeopleRequireText.setFillColor(notReachedColor);
		HousesPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(HOUSES)[3]));
		HousesPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.64f));

			// Walls

		sf::Text WallsText;
		WallsText.setFillColor(defaultTextColor);
		WallsText.setString("Walls: ");
		WallsText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.68f));

		sf::Text WallsLevelText;
		WallsLevelText.setFillColor(defaultTextColor);
		WallsLevelText.setString(std::to_string(MainData.getBuildingsLevel(WALLS)));
		WallsLevelText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.68f));

		sf::Text WallsWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getBuildingsNextLevelRequire(WALLS)[0])
			WallsWoodRequireText.setFillColor(defaultTextColor);
		else
			WallsWoodRequireText.setFillColor(notReachedColor);
		WallsWoodRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(WALLS)[0]));
		WallsWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.68f));

		sf::Text WallsIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getBuildingsNextLevelRequire(WALLS)[1])
			WallsIronRequireText.setFillColor(defaultTextColor);
		else
			WallsIronRequireText.setFillColor(notReachedColor);
		WallsIronRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(WALLS)[1]));
		WallsIronRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.68f));

		sf::Text WallsClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getBuildingsNextLevelRequire(WALLS)[2])
			WallsClayRequireText.setFillColor(defaultTextColor);
		else
			WallsClayRequireText.setFillColor(notReachedColor);
		WallsClayRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(WALLS)[2]));
		WallsClayRequireText.setPosition(sf::Vector2f(WIDTH*0.45f, HEIGHT*0.68f));

		sf::Text WallsPeopleRequireText;
		if (MainData.getResources(MAXPEOPLE) >= MainData.getBuildingsNextLevelRequire(WALLS)[3] + MainData.getResources(PEOPLE))
			WallsPeopleRequireText.setFillColor(defaultTextColor);
		else
			WallsPeopleRequireText.setFillColor(notReachedColor);
		WallsPeopleRequireText.setString(std::to_string(MainData.getBuildingsNextLevelRequire(WALLS)[3]));
		WallsPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.5f, HEIGHT*0.68f));



	Map.addText("TownhallText", TownhallText, defaultFont);
	Map.addText("TownhallLevelText", TownhallLevelText, defaultFont);
	Map.addText("TownhallWoodRequireText", TownhallWoodRequireText, defaultFont);
	Map.addText("TownhallIronRequireText", TownhallIronRequireText, defaultFont);
	Map.addText("TownhallClayRequireText", TownhallClayRequireText, defaultFont);
	Map.addText("TownhallPeopleRequireText", TownhallPeopleRequireText, defaultFont);

	Map.addText("LumbermillText", LumbermillText, defaultFont);
	Map.addText("LumbermillLevelText", LumbermillLevelText, defaultFont);
	Map.addText("LumbermillWoodRequireText", LumbermillWoodRequireText, defaultFont);
	Map.addText("LumbermillIronRequireText", LumbermillIronRequireText, defaultFont);
	Map.addText("LumbermillClayRequireText", LumbermillClayRequireText, defaultFont);
	Map.addText("LumbermillPeopleRequireText", LumbermillPeopleRequireText, defaultFont);

	Map.addText("BrickyardText", BrickyardText, defaultFont);
	Map.addText("BrickyardLevelText", BrickyardLevelText, defaultFont);
	Map.addText("BrickyardWoodRequireText", BrickyardWoodRequireText, defaultFont);
	Map.addText("BrickyardIronRequireText", BrickyardIronRequireText, defaultFont);
	Map.addText("BrickyardClayRequireText", BrickyardClayRequireText, defaultFont);
	Map.addText("BrickyardPeopleRequireText", BrickyardPeopleRequireText, defaultFont);

	Map.addText("MineText", MineText, defaultFont);
	Map.addText("MineLevelText", MineLevelText, defaultFont);
	Map.addText("MineWoodRequireText", MineWoodRequireText, defaultFont);
	Map.addText("MineIronRequireText", MineIronRequireText, defaultFont);
	Map.addText("MineClayRequireText", MineClayRequireText, defaultFont);
	Map.addText("MinePeopleRequireText", MinePeopleRequireText, defaultFont);

	Map.addText("FarmText", FarmText, defaultFont);
	Map.addText("FarmLevelText", FarmLevelText, defaultFont);
	Map.addText("FarmWoodRequireText", FarmWoodRequireText, defaultFont);
	Map.addText("FarmIronRequireText", FarmIronRequireText, defaultFont);
	Map.addText("FarmClayRequireText", FarmClayRequireText, defaultFont);
	Map.addText("FarmPeopleRequireText", FarmPeopleRequireText, defaultFont);

	Map.addText("BarrackText", BarrackText, defaultFont);
	Map.addText("BarrackLevelText", BarrackLevelText, defaultFont);
	Map.addText("BarrackWoodRequireText", BarrackWoodRequireText, defaultFont);
	Map.addText("BarrackIronRequireText", BarrackIronRequireText, defaultFont);
	Map.addText("BarrackClayRequireText", BarrackClayRequireText, defaultFont);
	Map.addText("BarrackPeopleRequireText", BarrackPeopleRequireText, defaultFont);

	Map.addText("StableText", StableText, defaultFont);
	Map.addText("StableLevelText", StableLevelText, defaultFont);
	Map.addText("StableWoodRequireText", StableWoodRequireText, defaultFont);
	Map.addText("StableIronRequireText", StableIronRequireText, defaultFont);
	Map.addText("StableClayRequireText", StableClayRequireText, defaultFont);
	Map.addText("StablePeopleRequireText", StablePeopleRequireText, defaultFont);

	Map.addText("SmithyText", SmithyText, defaultFont);
	Map.addText("SmithyLevelText", SmithyLevelText, defaultFont);
	Map.addText("SmithyWoodRequireText", SmithyWoodRequireText, defaultFont);
	Map.addText("SmithyIronRequireText", SmithyIronRequireText, defaultFont);
	Map.addText("SmithyClayRequireText", SmithyClayRequireText, defaultFont);
	Map.addText("SmithyPeopleRequireText", SmithyPeopleRequireText, defaultFont);

	Map.addText("HousesText", HousesText, defaultFont);
	Map.addText("HousesLevelText", HousesLevelText, defaultFont);
	Map.addText("HousesWoodRequireText", HousesWoodRequireText, defaultFont);
	Map.addText("HousesIronRequireText", HousesIronRequireText, defaultFont);
	Map.addText("HousesClayRequireText", HousesClayRequireText, defaultFont);
	Map.addText("HousesPeopleRequireText", HousesPeopleRequireText, defaultFont);

	Map.addText("WallsText", WallsText, defaultFont);
	Map.addText("WallsLevelText", WallsLevelText, defaultFont);
	Map.addText("WallsWoodRequireText", WallsWoodRequireText, defaultFont);
	Map.addText("WallsIronRequireText", WallsIronRequireText, defaultFont);
	Map.addText("WallsClayRequireText", WallsClayRequireText, defaultFont);
	Map.addText("WallsPeopleRequireText", WallsPeopleRequireText, defaultFont);

	return Map;
}

void TownhallWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	window.draw(Map.getRectangleShape("InfoTopBar"));
	window.draw(Map.getRectangleShape("WindowBackground"));
	window.draw(Map.getText("DayTimeText"));
	window.draw(Map.getTextButton("BackToGame"));
	window.draw(Map.getIcon("TownhallIcon"));
	window.draw(Map.getText("WindowCaption"));

	window.draw(Map.getIcon("WoodIconTop"));
	window.draw(Map.getIcon("IronIconTop"));
	window.draw(Map.getIcon("ClayIconTop"));
	window.draw(Map.getIcon("FoodIconTop"));
	window.draw(Map.getIcon("PeopleIconTop"));

	window.draw(Map.getText("WoodText"));
	window.draw(Map.getText("IronText"));
	window.draw(Map.getText("ClayText"));
	window.draw(Map.getText("FoodText"));
	window.draw(Map.getText("PeopleText"));

	window.draw(Map.getIcon("WoodIcon"));
	window.draw(Map.getIcon("IronIcon"));
	window.draw(Map.getIcon("ClayIcon"));
	window.draw(Map.getIcon("PeopleIcon"));

	window.draw(Map.getIconButton("TownhallUpgradeIcon"));
	window.draw(Map.getIconButton("LumbermillUpgradeIcon"));
	window.draw(Map.getIconButton("BrickyardUpgradeIcon"));
	window.draw(Map.getIconButton("MineUpgradeIcon"));
	window.draw(Map.getIconButton("FarmUpgradeIcon"));
	window.draw(Map.getIconButton("BarrackUpgradeIcon"));
	window.draw(Map.getIconButton("StableUpgradeIcon"));
	window.draw(Map.getIconButton("SmithyUpgradeIcon"));
	window.draw(Map.getIconButton("HousesUpgradeIcon"));
	window.draw(Map.getIconButton("WallsUpgradeIcon"));

	window.draw(Map.getText("TownhallText"));
	window.draw(Map.getText("TownhallLevelText"));
	window.draw(Map.getText("TownhallWoodRequireText"));
	window.draw(Map.getText("TownhallIronRequireText"));
	window.draw(Map.getText("TownhallClayRequireText"));
	window.draw(Map.getText("TownhallPeopleRequireText"));

	window.draw(Map.getText("LumbermillText"));
	window.draw(Map.getText("LumbermillLevelText"));
	window.draw(Map.getText("LumbermillWoodRequireText"));
	window.draw(Map.getText("LumbermillIronRequireText"));
	window.draw(Map.getText("LumbermillClayRequireText"));
	window.draw(Map.getText("LumbermillPeopleRequireText"));

	window.draw(Map.getText("BrickyardText"));
	window.draw(Map.getText("BrickyardLevelText"));
	window.draw(Map.getText("BrickyardWoodRequireText"));
	window.draw(Map.getText("BrickyardIronRequireText"));
	window.draw(Map.getText("BrickyardClayRequireText"));
	window.draw(Map.getText("BrickyardPeopleRequireText"));

	window.draw(Map.getText("MineText"));
	window.draw(Map.getText("MineLevelText"));
	window.draw(Map.getText("MineWoodRequireText"));
	window.draw(Map.getText("MineIronRequireText"));
	window.draw(Map.getText("MineClayRequireText"));
	window.draw(Map.getText("MinePeopleRequireText"));

	window.draw(Map.getText("FarmText"));
	window.draw(Map.getText("FarmLevelText"));
	window.draw(Map.getText("FarmWoodRequireText"));
	window.draw(Map.getText("FarmIronRequireText"));
	window.draw(Map.getText("FarmClayRequireText"));
	window.draw(Map.getText("FarmPeopleRequireText"));

	window.draw(Map.getText("BarrackText"));
	window.draw(Map.getText("BarrackLevelText"));
	window.draw(Map.getText("BarrackWoodRequireText"));
	window.draw(Map.getText("BarrackIronRequireText"));
	window.draw(Map.getText("BarrackClayRequireText"));
	window.draw(Map.getText("BarrackPeopleRequireText"));

	window.draw(Map.getText("StableText"));
	window.draw(Map.getText("StableLevelText"));
	window.draw(Map.getText("StableWoodRequireText"));
	window.draw(Map.getText("StableIronRequireText"));
	window.draw(Map.getText("StableClayRequireText"));
	window.draw(Map.getText("StablePeopleRequireText"));

	window.draw(Map.getText("SmithyText"));
	window.draw(Map.getText("SmithyLevelText"));
	window.draw(Map.getText("SmithyWoodRequireText"));
	window.draw(Map.getText("SmithyIronRequireText"));
	window.draw(Map.getText("SmithyClayRequireText"));
	window.draw(Map.getText("SmithyPeopleRequireText"));

	window.draw(Map.getText("HousesText"));
	window.draw(Map.getText("HousesLevelText"));
	window.draw(Map.getText("HousesWoodRequireText"));
	window.draw(Map.getText("HousesIronRequireText"));
	window.draw(Map.getText("HousesClayRequireText"));
	window.draw(Map.getText("HousesPeopleRequireText"));

	window.draw(Map.getText("WallsText"));
	window.draw(Map.getText("WallsLevelText"));
	window.draw(Map.getText("WallsWoodRequireText"));
	window.draw(Map.getText("WallsIronRequireText"));
	window.draw(Map.getText("WallsClayRequireText"));
	window.draw(Map.getText("WallsPeopleRequireText"));

	window.display();
}
