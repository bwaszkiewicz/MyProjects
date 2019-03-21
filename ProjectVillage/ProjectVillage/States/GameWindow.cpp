#include "GameWindow.h"

State * GameWindow::handleInput(Input in, ShapeMap Map, EventHandler& evHandler)
{
	if (in.getKey() == sf::Keyboard::Escape)
		return new InGameWindow;
	else
		if (Map.getIconButton("TownhallDoors") == in)
			return new TownhallWindow;
		else
			if (Map.getIconButton("LumbermillDoors") == in)
				return new LumbermillWindow;
			else
				if (Map.getIconButton("BrickyardDoors") == in)
					return new BrickyardWindow;
				else
					if (Map.getIconButton("MineDoors") == in)
						return new MineWindow;
					else
						if (Map.getIconButton("FarmDoors") == in)
							return new FarmWindow;
						else
							if (Map.getIconButton("BarrackDoors") == in)
								return new BarrackWindow;
							else
								if (Map.getIconButton("StableDoors") == in)
									return new StableWindow;
								else
									if (Map.getIconButton("SmithyDoors") == in)
										return new SmithyWindow;
									else
										if (Map.getIconButton("HousesDoors") == in)
											return new HousesWindow;
										else
											if (Map.getIconButton("WallsDoors") == in)
												return new WallsWindow;
											else
												if (evHandler.getStarveEndgame())
													return new StarveEndgameWindow;
												else
													if (evHandler.getAttackEndgame())
														return new AttackEndgameWindow;
													else
														return nullptr;
}

void GameWindow::update(ShapeMap& Map, Data& MainData, short int updateCode, EventHandler& evHandler)
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
		if (MainData.getResources(FOOD) < 0)
			evHandler.setStarveEndgame(true);
	}
	break;
	case RANDOM_EVENT_UPDATE:
	{
		std::vector<int> eventVector;
		eventVector = MainData.randomize();
		if (eventVector[EV_BATTLE] == 1)
		{
			BattleHandler BtHandler(MainData.getUnitsAmount(PIKEMAN), MainData.getUnitsAmount(SWORDSMAN), MainData.getUnitsAmount(AXEMAN), 
				MainData.getUnitsAmount(ARCHERS), MainData.getUnitsAmount(LIGHTCAVALRYMAN), MainData.getUnitsAmount(HEAVYCAVALRYMAN), eventVector);
			BattleEngine BtEngine(BtHandler.getDefenders(),BtHandler.getAttackers(),MainData.getBuildingsLevel(WALLS));
			if(BtEngine.battle(MainData))
			{
				std::cout << "Wygrana" << std::endl;
				MainData.setUnitsAfterBattle(BtEngine.getAfterDefenders());
			}
			else
			{
				std::cout << "Przegrana" << std::endl;
				if (eventVector[EV_ENDGAME] == 1)
					evHandler.setAttackEndgame(true);
					//std::cout << "Koniec gry" << std::endl;
				MainData.setUnitsAfterBattle(BtEngine.getAfterDefenders());
			}

		}
		evHandler.setPeopleCount(true);
		if(MainData.getResources(FOOD) < 0)
			evHandler.setStarveEndgame(true);
		Map = render(MainData);
		evHandler.setEventConfirmed(true);
	}
	break;
	default:
		break;
	}
	
}

ShapeMap GameWindow::render(const Data& MainData)
{
	ShapeMap Map;
	sf::Color defaultTextColor(100, 100, 100);
	
	// Info top bar

	sf::RectangleShape InfoTopBar(sf::Vector2f(WIDTH*0.90,HEIGHT*0.05));
	InfoTopBar.setPosition(sf::Vector2f(WIDTH*0.05,HEIGHT*0.025));
	InfoTopBar.setFillColor(sf::Color(74,46,17));

	sf::Text DayTimeText;
	DayTimeText.setFillColor(defaultTextColor);
	DayTimeText.setString("Dzien " + std::to_string(MainData.getHours() / 24) + " Godzina " + std::to_string(MainData.getHours() % 24));
	DayTimeText.setPosition(WIDTH*0.15f, HEIGHT*0.03f);

	Map.addText("DayTimeText", DayTimeText, defaultFont);

	// Resource Icons
		Icon WoodIcon(sf::Vector2f(WIDTH*0.50f, HEIGHT*0.04f), "img/WoodIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("WoodIcon", WoodIcon);

		Icon IronIcon(sf::Vector2f(WIDTH*0.58f, HEIGHT*0.04f), "img/IronIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("IronIcon", IronIcon);

		Icon ClayIcon(sf::Vector2f(WIDTH*0.66f, HEIGHT*0.04f), "img/ClayIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("ClayIcon", ClayIcon);

		Icon FoodIcon(sf::Vector2f(WIDTH*0.74f, HEIGHT*0.04f), "img/FoodIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("FoodIcon", FoodIcon);

		Icon PeopleIcon(sf::Vector2f(WIDTH*0.82f, HEIGHT*0.04f), "img/PeopleIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("PeopleIcon", PeopleIcon);

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
	PeopleText.setString(std::to_string(MainData.getResources(PEOPLE))+"/"+std::to_string(MainData.getResources(MAXPEOPLE)));
	PeopleText.setPosition(WIDTH*0.84f, HEIGHT*0.03f);

	// Army box

	sf::RectangleShape ArmyBox(sf::Vector2f(WIDTH*0.35, HEIGHT*0.3));
	ArmyBox.setPosition(sf::Vector2f(WIDTH*0.55, HEIGHT*0.15));
	ArmyBox.setFillColor(sf::Color(74, 46, 17));

			// Pikeman \\

		Icon PikemanIcon(sf::Vector2f(WIDTH*0.60f, HEIGHT*0.2f), "img/Pikeman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("PikemanIcon", PikemanIcon);

		sf::Text PikemanText;
		PikemanText.setFillColor(defaultTextColor);
		PikemanText.setString(std::to_string(MainData.getUnitsAmount(PIKEMAN)));
		PikemanText.setPosition(sf::Vector2f(WIDTH*0.63f, HEIGHT*0.19f));
		Map.addText("PikemanText", PikemanText, defaultFont);

			// Swordsman \\

		Icon SwordsmanIcon(sf::Vector2f(WIDTH*0.60f, HEIGHT*0.25f), "img/Swordsman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("SwordsmanIcon", SwordsmanIcon);

		sf::Text SwordsmanText;
		SwordsmanText.setFillColor(defaultTextColor);
		SwordsmanText.setString(std::to_string(MainData.getUnitsAmount(SWORDSMAN)));
		SwordsmanText.setPosition(sf::Vector2f(WIDTH*0.63f, HEIGHT*0.24f));
		Map.addText("SwordsmanText", SwordsmanText, defaultFont);

			// Axeman \\

		Icon AxemanIcon(sf::Vector2f(WIDTH*0.60f, HEIGHT*0.30f), "img/Axeman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("AxemanIcon", AxemanIcon);

		sf::Text AxemanText;
		AxemanText.setFillColor(defaultTextColor);
		AxemanText.setString(std::to_string(MainData.getUnitsAmount(AXEMAN)));
		AxemanText.setPosition(sf::Vector2f(WIDTH*0.63f, HEIGHT*0.29f));
		Map.addText("AxemanText", AxemanText, defaultFont);

			// Archer \\

		Icon ArcherIcon(sf::Vector2f(WIDTH*0.60f, HEIGHT*0.35f), "img/Archer.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("ArcherIcon", ArcherIcon);

		sf::Text ArcherText;
		ArcherText.setFillColor(defaultTextColor);
		ArcherText.setString(std::to_string(MainData.getUnitsAmount(ARCHERS)));
		ArcherText.setPosition(sf::Vector2f(WIDTH*0.63f, HEIGHT*0.34f));
		Map.addText("ArcherText", ArcherText, defaultFont);

			// Light Cavalryman \\

		Icon LightCavalrymanIcon(sf::Vector2f(WIDTH*0.75f, HEIGHT*0.20f), "img/LightCavalryman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("LightCavalrymanIcon", LightCavalrymanIcon);

		sf::Text LightCavalrymanText;
		LightCavalrymanText.setFillColor(defaultTextColor);
		LightCavalrymanText.setString(std::to_string(MainData.getUnitsAmount(LIGHTCAVALRYMAN)));
		LightCavalrymanText.setPosition(sf::Vector2f(WIDTH*0.78f, HEIGHT*0.19f));
		Map.addText("LightCavalrymanText", LightCavalrymanText, defaultFont);

			// Heavy Cavalryman

		Icon HeavyCavalrymanIcon(sf::Vector2f(WIDTH*0.75f, HEIGHT*0.25f), "img/HeavyCavalryman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("HeavyCavalrymanIcon", HeavyCavalrymanIcon);

		sf::Text HeavyCavalrymanText;
		HeavyCavalrymanText.setFillColor(defaultTextColor);
		HeavyCavalrymanText.setString(std::to_string(MainData.getUnitsAmount(HEAVYCAVALRYMAN)));
		HeavyCavalrymanText.setPosition(sf::Vector2f(WIDTH*0.78f, HEIGHT*0.24f));
		Map.addText("HeavyCavalrymanText", HeavyCavalrymanText, defaultFont);

	// Buildings box

	sf::RectangleShape BuildingsBox(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.75f));
	BuildingsBox.setPosition(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.15f));
	BuildingsBox.setFillColor(sf::Color(74, 46, 17));
	
	sf::Text TownhallText;
	TownhallText.setFillColor(defaultTextColor);
	TownhallText.setString("Townhall: " + std::to_string(MainData.getBuildingsLevel(TOWNHALL)));
	TownhallText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.24f));

	sf::Text LumbermillText;
	LumbermillText.setFillColor(defaultTextColor);
	LumbermillText.setString("Lumbermill: " + std::to_string(MainData.getBuildingsLevel(LUMBERMILL)));
	LumbermillText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.28f));

	sf::Text BrickyardText;
	BrickyardText.setFillColor(defaultTextColor);
	BrickyardText.setString("Brickyard: " + std::to_string(MainData.getBuildingsLevel(BRICKYARD)));
	BrickyardText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.32f));

	sf::Text MineText;
	MineText.setFillColor(defaultTextColor);
	MineText.setString("Mine: " + std::to_string(MainData.getBuildingsLevel(MINE)));
	MineText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.36f));

	sf::Text FarmText;
	FarmText.setFillColor(defaultTextColor);
	FarmText.setString("Farm: " + std::to_string(MainData.getBuildingsLevel(FARM)));
	FarmText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.40f));

	sf::Text BarrackText;
	BarrackText.setFillColor(defaultTextColor);
	BarrackText.setString("Barrack: " + std::to_string(MainData.getBuildingsLevel(BARRACK)));
	BarrackText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.44f));

	sf::Text StableText;
	StableText.setFillColor(defaultTextColor);
	StableText.setString("Stable: " + std::to_string(MainData.getBuildingsLevel(STABLE)));
	StableText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.48f));

	sf::Text SmithyText;
	SmithyText.setFillColor(defaultTextColor);
	SmithyText.setString("Smithy: " + std::to_string(MainData.getBuildingsLevel(SMITHY)));
	SmithyText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.52f));

	sf::Text HousesText;
	HousesText.setFillColor(defaultTextColor);
	HousesText.setString("Houses: " + std::to_string(MainData.getBuildingsLevel(HOUSES)));
	HousesText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.56f));

	sf::Text WallsText;
	WallsText.setFillColor(defaultTextColor);
	WallsText.setString("Walls: " + std::to_string(MainData.getBuildingsLevel(WALLS)));
	WallsText.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.60f));

	// Buildings Icons

		IconButton TownhallDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.245f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("TownhallDoors", TownhallDoors);

		IconButton LumbermillDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.285f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("LumbermillDoors", LumbermillDoors);

		IconButton BrickyardDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.325f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("BrickyardDoors", BrickyardDoors);

		IconButton MineDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.365f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("MineDoors", MineDoors);

		IconButton FarmDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.405f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("FarmDoors", FarmDoors);

		IconButton BarrackDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.445f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("BarrackDoors", BarrackDoors);

		IconButton StableDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.485f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("StableDoors", StableDoors);

		IconButton SmithyDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.525f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("SmithyDoors", SmithyDoors);


		IconButton HousesDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.565f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("HousesDoors", HousesDoors);

		IconButton WallsDoors(sf::Vector2f(WIDTH*0.32f, HEIGHT*0.605f), "img/doorsIcon.png", sf::Vector2f(2.0f, 2.0f));
		Map.addIconButton("WallsDoors", WallsDoors);

	// Events box

		sf::RectangleShape EventsBox(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.4f));
		EventsBox.setPosition(sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f));
		EventsBox.setFillColor(sf::Color(74, 46, 17));

		RandomEvent* TempEvent;
		for (int i = 0; i < 4; i++)
		{
			if (TempEvent = MainData.getLatestEvent(i))
			{
				switch (TempEvent->getEventID())
				{
				case EV_ID_ABUDANCE:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Abudance.png",TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_BARBARIANATTACK:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Barbarian.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_DESERTION:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Desertion.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_IRONDEPOSIT:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/ResourcesEvent.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_LOCUST:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Locust.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_MARRAUDERATTACK:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Marrauder.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_THIEVES:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Thieves.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_BLOCKOFCLAY:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/ResourcesEvent.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_BIGTREE:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/ResourcesEvent.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_NOMADSATTACK:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Nomads.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				case EV_ID_RECRUIT:
				{
					EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/Recruit.png", TempEvent->getCaption());
					Map.addEventBar("Ev" + std::to_string(i), EvBar);
				}
					break;
				default:
					throw InvalidEventIDException();
				}
			}
			else
			{
				EventBar EvBar(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.1f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.5f + HEIGHT*i*0.1f), "img/EmptyEvent.png", "");
				Map.addEventBar("Ev" + std::to_string(i), EvBar);
			}
		}
		
	// Load to MapShape

	Map.addRectangleShape("InfoTopBar", InfoTopBar);
	Map.addRectangleShape("ArmyBox", ArmyBox);
	Map.addRectangleShape("BuildingsBox", BuildingsBox);
	Map.addRectangleShape("EventsBox", EventsBox);

	Map.addText("WoodText", WoodText, defaultFont);
	Map.addText("IronText", IronText, defaultFont);
	Map.addText("ClayText", ClayText, defaultFont);
	Map.addText("FoodText", FoodText, defaultFont);
	Map.addText("PeopleText", PeopleText, defaultFont);

	Map.addText("TownhallText", TownhallText, defaultFont);
	Map.addText("LumbermillText", LumbermillText, defaultFont);
	Map.addText("BrickyardText", BrickyardText, defaultFont);
	Map.addText("MineText", MineText, defaultFont);
	Map.addText("FarmText", FarmText, defaultFont);
	Map.addText("BarrackText", BarrackText, defaultFont);
	Map.addText("StableText", StableText, defaultFont);
	Map.addText("SmithyText", SmithyText, defaultFont);
	Map.addText("HousesText", HousesText, defaultFont);
	Map.addText("WallsText", WallsText, defaultFont);

	return Map;
}

void GameWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);

	
	window.draw(Map.getRectangleShape("InfoTopBar"));
	window.draw(Map.getRectangleShape("BuildingsBox"));
	window.draw(Map.getRectangleShape("ArmyBox"));
	window.draw(Map.getRectangleShape("EventsBox"));
	window.draw(Map.getText("DayTimeText"));

	window.draw(Map.getText("WoodText"));
	window.draw(Map.getText("IronText"));
	window.draw(Map.getText("ClayText"));
	window.draw(Map.getText("FoodText"));
	window.draw(Map.getText("PeopleText"));

	window.draw(Map.getIcon("WoodIcon"));
	window.draw(Map.getIcon("IronIcon"));
	window.draw(Map.getIcon("ClayIcon"));
	window.draw(Map.getIcon("FoodIcon"));
	window.draw(Map.getIcon("PeopleIcon"));

	// Armybox content

	window.draw(Map.getIcon("PikemanIcon"));
	window.draw(Map.getIcon("SwordsmanIcon"));
	window.draw(Map.getIcon("AxemanIcon"));
	window.draw(Map.getIcon("ArcherIcon"));
	window.draw(Map.getIcon("LightCavalrymanIcon"));
	window.draw(Map.getIcon("HeavyCavalrymanIcon"));

	window.draw(Map.getText("PikemanText"));
	window.draw(Map.getText("SwordsmanText"));
	window.draw(Map.getText("AxemanText"));
	window.draw(Map.getText("ArcherText"));
	window.draw(Map.getText("LightCavalrymanText"));
	window.draw(Map.getText("HeavyCavalrymanText"));

	window.draw(Map.getText("TownhallText"));
	window.draw(Map.getText("LumbermillText"));
	window.draw(Map.getText("BrickyardText"));
	window.draw(Map.getText("MineText"));
	window.draw(Map.getText("FarmText"));
	window.draw(Map.getText("BarrackText"));
	window.draw(Map.getText("StableText"));
	window.draw(Map.getText("SmithyText"));
	window.draw(Map.getText("HousesText"));
	window.draw(Map.getText("WallsText"));

	window.draw(Map.getIconButton("TownhallDoors"));
	window.draw(Map.getIconButton("LumbermillDoors"));
	window.draw(Map.getIconButton("BrickyardDoors"));
	window.draw(Map.getIconButton("MineDoors"));
	window.draw(Map.getIconButton("FarmDoors"));
	window.draw(Map.getIconButton("BarrackDoors"));
	window.draw(Map.getIconButton("StableDoors"));
	window.draw(Map.getIconButton("SmithyDoors"));
	window.draw(Map.getIconButton("HousesDoors"));
	window.draw(Map.getIconButton("WallsDoors"));

	for (int i = 0; i < 4; i++)
		window.draw(Map.getEventBar("Ev" + std::to_string(i)));

	window.display();
}

