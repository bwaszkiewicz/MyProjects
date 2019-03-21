#include "StableWindow.h"

State * StableWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	std::string TextInputName = "";
	if (Map.getTextButton("BackToGame") == in)
	{
		return new GameWindow;
	}
	else
		if (Map.getTextInput("LightCavalrymanRecruitAmountBox") == in)
		{
			evHandler.setTextInput(Map.getTextInput("LightCavalrymanRecruitAmountBox").getText());
			TextInputName = "LightCavalrymanRecruitAmountBox";
			evHandler.setTextInputLocker(false, TextInputName);
			evHandler.setUnitTypeRecruitInput(LIGHTCAVALRYMAN);
		}
		else
			if (Map.getTextInput("HeavyCavalrymanRecruitAmountBox") == in)
			{
				evHandler.setTextInput(Map.getTextInput("HeavyCavalrymanRecruitAmountBox").getText());
				TextInputName = "HeavyCavalrymanRecruitAmountBox";
				evHandler.setTextInputLocker(false, TextInputName);
				evHandler.setUnitTypeRecruitInput(HEAVYCAVALRYMAN);
			}
			else
				if (Map.getTextButton("LightCavalrymanRecruitButton") == in)
				{
					evHandler.setTextInput(Map.getTextInput("LightCavalrymanRecruitAmountBox").getText());
					evHandler.setUnitRecruitLocker(false);
					evHandler.setUnitTypeRecruit(LIGHTCAVALRYMAN);
					return nullptr;
				}
				else
					if (Map.getTextButton("HeavyCavalrymanRecruitButton") == in)
					{
						evHandler.setTextInput(Map.getTextInput("HeavyCavalrymanRecruitAmountBox").getText());
						evHandler.setUnitRecruitLocker(false);
						evHandler.setUnitTypeRecruit(HEAVYCAVALRYMAN);
						return nullptr;
					}
					else
					{ // jako ostatni
						if (in.getKey() == -1)
							evHandler.setTextInputLocker(true, "");
					}
	return nullptr;
}

void StableWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("StableFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("StableFrame", NewWindowFrame);
	}
	break;
	case PEOPLE_COUNT_UPDATE:
	{
		MainData.updateResources(PEOPLE);
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("StableFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("StableFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("StableFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("StableFrame", NewWindowFrame);
	}
	break;
	case UNITS_INPUT_AMOUNT_UPDATE:
	{
		TextInput temp(Map.getTextInput(evHandler.getTextInputName()));
		temp.setText(evHandler.getTextInput());
		Map.addTextInput(evHandler.getTextInputName(), temp);

		RecruitHandler Handler;
		Map = Handler.ChooseHandle(Map, evHandler, MainData, evHandler.getUnitTypeRecruitInput());
	}
	break;
	case UNITS_UPDATE:
	{
		MainData.recruitUnits(evHandler.getUnitTypeRecruit(), std::stoi(std::string(evHandler.getTextInput()).c_str()));
		Map = render(MainData);
	}
	break;
	case FOOD_UPDATE:
	{
		MainData.recalculateFood();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("StableFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("StableFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap StableWindow::render(const Data & MainData)
{
	ShapeMap Map;

	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

		// Frame

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame StableFrame("img/Stable.png", "Stable", MainData);
	Map.addBuildingsWindowFrame("StableFrame", StableFrame);

		// Recruit

			// Resources headers

		Icon WoodIcon(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.28f), "img/WoodIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("WoodIcon", WoodIcon);

		Icon IronIcon(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.28f), "img/IronIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("IronIcon", IronIcon);

		Icon ClayIcon(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.28f), "img/ClayIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("ClayIcon", ClayIcon);

		Icon PeopleIcon(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.28f), "img/PeopleIcon.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("PeopleIcon", PeopleIcon);

			// Units

		// LightCavalryman \\

		Icon LightCavalrymanIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.32f), "img/LightCavalryman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("LightCavalrymanIcon", LightCavalrymanIcon);

		sf::Text LightCavalrymanWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[WOOD])
			LightCavalrymanWoodRequireText.setFillColor(defaultTextColor);
		else
			LightCavalrymanWoodRequireText.setFillColor(notReachedColor);
		LightCavalrymanWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[WOOD]));
		LightCavalrymanWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.32f));
		Map.addText("LightCavalrymanWoodRequireText", LightCavalrymanWoodRequireText, defaultFont);

		sf::Text LightCavalrymanIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[IRON])
			LightCavalrymanIronRequireText.setFillColor(defaultTextColor);
		else
			LightCavalrymanIronRequireText.setFillColor(notReachedColor);
		LightCavalrymanIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[IRON]));
		LightCavalrymanIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.32f));
		Map.addText("LightCavalrymanIronRequireText", LightCavalrymanIronRequireText, defaultFont);

		sf::Text LightCavalrymanClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[CLAY])
			LightCavalrymanClayRequireText.setFillColor(defaultTextColor);
		else
			LightCavalrymanClayRequireText.setFillColor(notReachedColor);
		LightCavalrymanClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[CLAY]));
		LightCavalrymanClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.32f));
		Map.addText("LightCavalrymanClayRequireText", LightCavalrymanClayRequireText, defaultFont);

		sf::Text LightCavalrymanPeopleRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[PEOPLE])
			LightCavalrymanPeopleRequireText.setFillColor(defaultTextColor);
		else
			LightCavalrymanPeopleRequireText.setFillColor(notReachedColor);
		LightCavalrymanPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[PEOPLE]));
		LightCavalrymanPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.32f));
		Map.addText("LightCavalrymanPeopleRequireText", LightCavalrymanPeopleRequireText, defaultFont);

		// HeavyCavalryman \\

		Icon HeavyCavalrymanIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.4f), "img/HeavyCavalryman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("HeavyCavalrymanIcon", HeavyCavalrymanIcon);

		sf::Text HeavyCavalrymanWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[WOOD])
			HeavyCavalrymanWoodRequireText.setFillColor(defaultTextColor);
		else
			HeavyCavalrymanWoodRequireText.setFillColor(notReachedColor);
		HeavyCavalrymanWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[WOOD]));
		HeavyCavalrymanWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.4f));
		Map.addText("HeavyCavalrymanWoodRequireText", HeavyCavalrymanWoodRequireText, defaultFont);

		sf::Text HeavyCavalrymanIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[IRON])
			HeavyCavalrymanIronRequireText.setFillColor(defaultTextColor);
		else
			HeavyCavalrymanIronRequireText.setFillColor(notReachedColor);
		HeavyCavalrymanIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[IRON]));
		HeavyCavalrymanIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.4f));
		Map.addText("HeavyCavalrymanIronRequireText", HeavyCavalrymanIronRequireText, defaultFont);

		sf::Text HeavyCavalrymanClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[CLAY])
			HeavyCavalrymanClayRequireText.setFillColor(defaultTextColor);
		else
			HeavyCavalrymanClayRequireText.setFillColor(notReachedColor);
		HeavyCavalrymanClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[CLAY]));
		HeavyCavalrymanClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.4f));
		Map.addText("HeavyCavalrymanClayRequireText", HeavyCavalrymanClayRequireText, defaultFont);

		sf::Text HeavyCavalrymanPeopleRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[PEOPLE])
			HeavyCavalrymanPeopleRequireText.setFillColor(defaultTextColor);
		else
			HeavyCavalrymanPeopleRequireText.setFillColor(notReachedColor);
		HeavyCavalrymanPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[PEOPLE]));
		HeavyCavalrymanPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.4f));
		Map.addText("HeavyCavalrymanPeopleRequireText", HeavyCavalrymanPeopleRequireText, defaultFont);

		// Text input //

			// LightCavalryman
		TextInput LightCavalrymanRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.32f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255, 255, 255));
		Map.addTextInput("LightCavalrymanRecruitAmountBox", LightCavalrymanRecruitAmountBox);

		TextButton LightCavalrymanRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.32f, sf::Color(70, 70, 77), WIDTH*0.05f*0.25f, 0.0f,
			"Ok", sf::Color(255, 255, 255));
		Map.addTextButton("LightCavalrymanRecruitButton", LightCavalrymanRecruitButton);

			// HeavyCavalryman
		TextInput HeavyCavalrymanRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.4f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255, 255, 255));
		Map.addTextInput("HeavyCavalrymanRecruitAmountBox", HeavyCavalrymanRecruitAmountBox);

		TextButton HeavyCavalrymanRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.4f, sf::Color(70, 70, 77), WIDTH*0.05f*0.25f, 0.0f,
			"Ok", sf::Color(255, 255, 255));
		Map.addTextButton("HeavyCavalrymanRecruitButton", HeavyCavalrymanRecruitButton);

	return Map;
}

void StableWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);

	//	Frame
	window.draw(Map.getBuildingsWindowFrame("StableFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	// Recruit

	window.draw(Map.getIcon("WoodIcon"));
	window.draw(Map.getIcon("IronIcon"));
	window.draw(Map.getIcon("ClayIcon"));
	window.draw(Map.getIcon("PeopleIcon"));

	window.draw(Map.getIcon("LightCavalrymanIcon"));
	window.draw(Map.getIcon("HeavyCavalrymanIcon"));

	// LightCavalryman

	window.draw(Map.getText("LightCavalrymanWoodRequireText"));
	window.draw(Map.getText("LightCavalrymanIronRequireText"));
	window.draw(Map.getText("LightCavalrymanClayRequireText"));
	window.draw(Map.getText("LightCavalrymanPeopleRequireText"));

	window.draw(Map.getTextInput("LightCavalrymanRecruitAmountBox"));
	window.draw(Map.getTextButton("LightCavalrymanRecruitButton"));

	// HeavyCavalryman

	window.draw(Map.getText("HeavyCavalrymanWoodRequireText"));
	window.draw(Map.getText("HeavyCavalrymanIronRequireText"));
	window.draw(Map.getText("HeavyCavalrymanClayRequireText"));
	window.draw(Map.getText("HeavyCavalrymanPeopleRequireText"));

	window.draw(Map.getTextInput("HeavyCavalrymanRecruitAmountBox"));
	window.draw(Map.getTextButton("HeavyCavalrymanRecruitButton"));

	window.display();
}
