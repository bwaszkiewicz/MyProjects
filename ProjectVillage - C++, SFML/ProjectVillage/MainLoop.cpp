#include "MainLoop.h"

void MainLoop::loop()
{
				// MAIN SFML VARIABLE DECLARATIONS

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Village");
	StateMachine Machine(window);
	sf::Clock clock;
	sf::Clock DayTime;
	sf::Clock FoodClock;
	sf::Clock RabndomEventClock;
	sf::Time FoodCycle = sf::seconds(80);
	sf::Time ResourceCycle = sf::seconds(10);
	sf::Time HourCycle = sf::seconds(10);
	sf::Time RandomEventCycle = sf::seconds(50);
	std::string str="";

	EventHandler evHandler;

	while (window.isOpen())
	{
		window.setFramerateLimit(60);
		// sprawdzenie wszelkich eventów zachodz¹cych w tym oknie

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) // zamkniêcie okna
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) // nacisniecie przycisku na myszy
			{
				Input in(sf::Mouse::getPosition(window));
				Machine.handleInput(in, evHandler);
			}
			if (event.type == sf::Event::KeyPressed)
			{
				Input in(event.key.code);
				Machine.handleInput(in, evHandler);
			}
			if (!evHandler.getTextInputLocker())
			{
				sf::String text;
				if (event.type == sf::Event::TextEntered)
				{
					str = evHandler.getTextInput();
					if (event.text.unicode > 47 && event.text.unicode < 58)
					{
						str += static_cast<char>(event.text.unicode);
						evHandler.setTextInput(str);
						Machine.update(UNITS_INPUT_AMOUNT_UPDATE, evHandler);
					}
					else
						if (event.text.unicode == 8)
						{
							str = str.substr(0, str.size() - 1);
							evHandler.setTextInput(str);
							Machine.update(UNITS_INPUT_AMOUNT_UPDATE, evHandler);
						}
				}
			}
			else
			{

				str = "";
			}

		}


		if (!evHandler.getEventHandlerLocker())
		{
			sf::Time ElapsedTime = clock.getElapsedTime();
			if (ElapsedTime >= ResourceCycle)
			{
				Machine.update(RESOURCES_UPDATE, evHandler);
				clock.restart();
			}

			sf::Time DayElapsedTime = DayTime.getElapsedTime();
			if (DayElapsedTime >= HourCycle)
			{
				Machine.update(TIME_UPDATE, evHandler);
				DayTime.restart();
			}
			sf::Time FoodElapsedTime = FoodClock.getElapsedTime();
			if (FoodElapsedTime >= FoodCycle)
			{
				Machine.update(FOOD_UPDATE, evHandler);
				FoodClock.restart();
			}

			sf::Time RandomEventElapsedTime = RabndomEventClock.getElapsedTime();
			if (RandomEventElapsedTime>=RandomEventCycle)
			{
				Machine.update(RANDOM_EVENT_UPDATE, evHandler);
				if (evHandler.getEventConfirmed())
				{
					RabndomEventClock.restart();
					evHandler.setEventConfirmed(false);
				}
			}

			if (evHandler.getMaxPeopleCount())
			{
				Machine.update(PEOPLE_MAX_COUNT_UPDATE, evHandler);
				evHandler.setMaxPeopleCount(false);
			}

			if (evHandler.getPeopleCount())
			{
				Machine.update(PEOPLE_COUNT_UPDATE, evHandler);
				evHandler.setPeopleCount(false);

			}

			if (!evHandler.getBuildingsUpgradeLocker())
			{
				
				Machine.update(BUILDINGS_UPDATE, evHandler);

				evHandler.setPeopleCount(true);
				evHandler.setMaxPeopleCount(true);
				evHandler.setBuildingsUpgradeLocker(true);
				evHandler.setBuildingsTypeUpgrade(-1);
			}
			if (!evHandler.getUnitRecruitLocker())
			{
				Machine.update(UNITS_UPDATE, evHandler);

				evHandler.setPeopleCount(true);
				evHandler.setUnitRecruitLocker(true);
				evHandler.setUnitTypeRecruit(-1);
			}
			if (!evHandler.getCleanDataLocker())
			{
				Machine.update(ENDGAME_UPDATE, evHandler);
				evHandler.setCleanDataLocker(true);
			}

					// End game
			if (evHandler.getStarveEndgame())
			{
				Input in;
				Machine.handleInput(in, evHandler);
				Machine.update(ENDGAME_UPDATE, evHandler);
				evHandler.setStarveEndgame(false);
			}
			if (evHandler.getAttackEndgame())
			{
				Input in;
				Machine.handleInput(in, evHandler);
				Machine.update(ENDGAME_UPDATE, evHandler);
				evHandler.setAttackEndgame(false);
			}
		}

		Machine.show();
	}
}
