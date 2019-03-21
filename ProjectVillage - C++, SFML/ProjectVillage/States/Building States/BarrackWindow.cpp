#include "BarrackWindow.h"

State * BarrackWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	std::string TextInputName = "";
	if (Map.getTextButton("BackToGame") == in)
	{
		evHandler.setTextInputLocker(true, "");
		return new GameWindow;
	}
	else
		if (Map.getTextInput("PikemanRecruitAmountBox") == in)
		{
			evHandler.setTextInput(Map.getTextInput("PikemanRecruitAmountBox").getText());
			TextInputName = "PikemanRecruitAmountBox";
			evHandler.setTextInputLocker(false, TextInputName);
			evHandler.setUnitTypeRecruitInput(PIKEMAN);
		}
		else
			if (Map.getTextInput("SwordsmanRecruitAmountBox") == in)
			{
				evHandler.setTextInput(Map.getTextInput("SwordsmanRecruitAmountBox").getText());
				TextInputName = "SwordsmanRecruitAmountBox";
				evHandler.setTextInputLocker(false, TextInputName);
				evHandler.setUnitTypeRecruitInput(SWORDSMAN);
			}
			else
				if (Map.getTextInput("AxemanRecruitAmountBox") == in)
				{
					evHandler.setTextInput(Map.getTextInput("AxemanRecruitAmountBox").getText());
					TextInputName = "AxemanRecruitAmountBox";
					evHandler.setTextInputLocker(false, TextInputName);
					evHandler.setUnitTypeRecruitInput(AXEMAN);
				}
				else
					if (Map.getTextInput("ArcherRecruitAmountBox") == in)
					{
						evHandler.setTextInput(Map.getTextInput("ArcherRecruitAmountBox").getText());
						TextInputName = "ArcherRecruitAmountBox";
						evHandler.setTextInputLocker(false, TextInputName);
						evHandler.setUnitTypeRecruitInput(ARCHERS);
					}
					else
						if (Map.getTextButton("PikemanRecruitButton") == in)
						{
							evHandler.setTextInput(Map.getTextInput("PikemanRecruitAmountBox").getText());
							evHandler.setUnitRecruitLocker(false);
							evHandler.setUnitTypeRecruit(PIKEMAN);
							return nullptr;
						}
						else
							if (Map.getTextButton("SwordsmanRecruitButton") == in)
							{
								evHandler.setTextInput(Map.getTextInput("SwordsmanRecruitAmountBox").getText());
								evHandler.setUnitRecruitLocker(false);
								evHandler.setUnitTypeRecruit(SWORDSMAN);
								return nullptr;
							}
							else
								if (Map.getTextButton("AxemanRecruitButton") == in)
								{
									evHandler.setTextInput(Map.getTextInput("AxemanRecruitAmountBox").getText());
									evHandler.setUnitRecruitLocker(false);
									evHandler.setUnitTypeRecruit(AXEMAN);
									return nullptr;
								}
								else
									if (Map.getTextButton("ArcherRecruitButton") == in)
									{
										evHandler.setTextInput(Map.getTextInput("ArcherRecruitAmountBox").getText());
										evHandler.setUnitRecruitLocker(false);
										evHandler.setUnitTypeRecruit(ARCHERS);
										return nullptr;
									}
					else
					{ // jako ostatni
						if (in.getKey() == -1)
							evHandler.setTextInputLocker(true, "");
					}
	return nullptr;
}

void BarrackWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case RESOURCES_UPDATE:
	{
		MainData.updateResources(WOOD);
		MainData.updateResources(IRON);
		MainData.updateResources(CLAY);
		MainData.updateResources(FOOD);

		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BarrackFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BarrackFrame", NewWindowFrame);
	}
	break;
	case PEOPLE_COUNT_UPDATE:
	{
		MainData.updateResources(PEOPLE);
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BarrackFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BarrackFrame", NewWindowFrame);
	}
	break;
	case TIME_UPDATE:
	{
		MainData.hoursIncerement();
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BarrackFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BarrackFrame", NewWindowFrame);
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
		BuildingsWindowFrame NewWindowFrame(Map.getBuildingsWindowFrame("BarrackFrame"));
		NewWindowFrame.update(MainData);
		Map.addBuildingsWindowFrame("BarrackFrame", NewWindowFrame);
	}
	break;
	default:
		break;
	}
}

ShapeMap BarrackWindow::render(const Data & MainData)
{
	ShapeMap Map;
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

		// Frame

	TextButton BackToGame(200, 75, WIDTH*0.7f, HEIGHT*0.78f, sf::Color(100, 100, 100), 60, 20, "Back", sf::Color(250, 250, 250));
	Map.addTextButton("BackToGame", BackToGame);

	BuildingsWindowFrame BarrackFrame("img/Barrack.png", "Barrack", MainData);
	Map.addBuildingsWindowFrame("BarrackFrame", BarrackFrame);

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

		// Pikeman \\
		
		Icon PikemanIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.32f), "img/Pikeman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("PikemanIcon", PikemanIcon);

		sf::Text PikemanWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(PIKEMAN)[WOOD])
			PikemanWoodRequireText.setFillColor(defaultTextColor);
		else
			PikemanWoodRequireText.setFillColor(notReachedColor);
		PikemanWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[WOOD]));
		PikemanWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.32f));
		Map.addText("PikemanWoodRequireText", PikemanWoodRequireText, defaultFont);

		sf::Text PikemanIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(PIKEMAN)[IRON])
		PikemanIronRequireText.setFillColor(defaultTextColor);
		else
			PikemanIronRequireText.setFillColor(notReachedColor);
		PikemanIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[IRON]));
		PikemanIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.32f));
		Map.addText("PikemanIronRequireText", PikemanIronRequireText, defaultFont);

		sf::Text PikemanClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(PIKEMAN)[CLAY])
			PikemanClayRequireText.setFillColor(defaultTextColor);
		else
			PikemanClayRequireText.setFillColor(notReachedColor);
		PikemanClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[CLAY]));
		PikemanClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.32f));
		Map.addText("PikemanClayRequireText", PikemanClayRequireText, defaultFont);

		sf::Text PikemanPeopleRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(PIKEMAN)[PEOPLE])
			PikemanPeopleRequireText.setFillColor(defaultTextColor);
		else
			PikemanPeopleRequireText.setFillColor(notReachedColor);
		PikemanPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[PEOPLE]));
		PikemanPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.32f));
		Map.addText("PikemanPeopleRequireText", PikemanPeopleRequireText, defaultFont);

		// Swordsman \\

		Icon SwordsmanIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.4f), "img/Swordsman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("SwordsmanIcon", SwordsmanIcon);

		sf::Text SwordsmanWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(SWORDSMAN)[WOOD])
			SwordsmanWoodRequireText.setFillColor(defaultTextColor);
		else
			SwordsmanWoodRequireText.setFillColor(notReachedColor);
		SwordsmanWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[WOOD]));
		SwordsmanWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.4f));
		Map.addText("SwordsmanWoodRequireText", SwordsmanWoodRequireText, defaultFont);

		sf::Text SwordsmanIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(SWORDSMAN)[IRON])
			SwordsmanIronRequireText.setFillColor(defaultTextColor);
		else
			SwordsmanIronRequireText.setFillColor(notReachedColor);
		SwordsmanIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[IRON]));
		SwordsmanIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.4f));
		Map.addText("SwordsmanIronRequireText", SwordsmanIronRequireText, defaultFont);

		sf::Text SwordsmanClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(SWORDSMAN)[CLAY])
			SwordsmanClayRequireText.setFillColor(defaultTextColor);
		else
			SwordsmanClayRequireText.setFillColor(notReachedColor);
		SwordsmanClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[CLAY]));
		SwordsmanClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.4f));
		Map.addText("SwordsmanClayRequireText", SwordsmanClayRequireText, defaultFont);

		sf::Text SwordsmanPeopleRequireText;
		if (MainData.getResources(PEOPLE) >= MainData.getUnitRecruitResourceRequire(SWORDSMAN)[PEOPLE])
			SwordsmanPeopleRequireText.setFillColor(defaultTextColor);
		else
			SwordsmanPeopleRequireText.setFillColor(notReachedColor);
		SwordsmanPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[PEOPLE]));
		SwordsmanPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.4f));
		Map.addText("SwordsmanPeopleRequireText", SwordsmanPeopleRequireText, defaultFont);

		// Axeman \\

		Icon AxemanIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.48f), "img/Axeman.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("AxemanIcon", AxemanIcon);

		sf::Text AxemanWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(AXEMAN)[WOOD])
			AxemanWoodRequireText.setFillColor(defaultTextColor);
		else
			AxemanWoodRequireText.setFillColor(notReachedColor);
		AxemanWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[WOOD]));
		AxemanWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.48f));
		Map.addText("AxemanWoodRequireText", AxemanWoodRequireText, defaultFont);

		sf::Text AxemanIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(AXEMAN)[IRON])
			AxemanIronRequireText.setFillColor(defaultTextColor);
		else
			AxemanIronRequireText.setFillColor(notReachedColor);
		AxemanIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[IRON]));
		AxemanIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.48f));
		Map.addText("AxemanIronRequireText", AxemanIronRequireText, defaultFont);

		sf::Text AxemanClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(AXEMAN)[CLAY])
			AxemanClayRequireText.setFillColor(defaultTextColor);
		else
			AxemanClayRequireText.setFillColor(notReachedColor);
		AxemanClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[CLAY]));
		AxemanClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.48f));
		Map.addText("AxemanClayRequireText", AxemanClayRequireText, defaultFont);

		sf::Text AxemanPeopleRequireText;
		if (MainData.getResources(PEOPLE) >= MainData.getUnitRecruitResourceRequire(AXEMAN)[PEOPLE])
			AxemanPeopleRequireText.setFillColor(defaultTextColor);
		else
			AxemanPeopleRequireText.setFillColor(notReachedColor);
		AxemanPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[PEOPLE]));
		AxemanPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.48f));
		Map.addText("AxemanPeopleRequireText", AxemanPeopleRequireText, defaultFont);

		// Archer \\

		Icon ArcherIcon(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.56f), "img/Archer.png", sf::Vector2f(1.2f, 1.2f));
		Map.addIcon("ArcherIcon", ArcherIcon);

		sf::Text ArcherWoodRequireText;
		if (MainData.getResources(WOOD) >= MainData.getUnitRecruitResourceRequire(ARCHERS)[WOOD])
			ArcherWoodRequireText.setFillColor(defaultTextColor);
		else
			ArcherWoodRequireText.setFillColor(notReachedColor);
		ArcherWoodRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[WOOD]));
		ArcherWoodRequireText.setPosition(sf::Vector2f(WIDTH*0.25f, HEIGHT*0.56f));
		Map.addText("ArcherWoodRequireText", ArcherWoodRequireText, defaultFont);

		sf::Text ArcherIronRequireText;
		if (MainData.getResources(IRON) >= MainData.getUnitRecruitResourceRequire(ARCHERS)[IRON])
			ArcherIronRequireText.setFillColor(defaultTextColor);
		else
			ArcherIronRequireText.setFillColor(notReachedColor);
		ArcherIronRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[IRON]));
		ArcherIronRequireText.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.56f));
		Map.addText("ArcherIronRequireText", ArcherIronRequireText, defaultFont);

		sf::Text ArcherClayRequireText;
		if (MainData.getResources(CLAY) >= MainData.getUnitRecruitResourceRequire(ARCHERS)[CLAY])
			ArcherClayRequireText.setFillColor(defaultTextColor);
		else
			ArcherClayRequireText.setFillColor(notReachedColor);
		ArcherClayRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[CLAY]));
		ArcherClayRequireText.setPosition(sf::Vector2f(WIDTH*0.35f, HEIGHT*0.56f));
		Map.addText("ArcherClayRequireText", ArcherClayRequireText, defaultFont);

		sf::Text ArcherPeopleRequireText;
		if (MainData.getResources(PEOPLE) >= MainData.getUnitRecruitResourceRequire(ARCHERS)[PEOPLE])
			ArcherPeopleRequireText.setFillColor(defaultTextColor);
		else
			ArcherPeopleRequireText.setFillColor(notReachedColor);
		ArcherPeopleRequireText.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[PEOPLE]));
		ArcherPeopleRequireText.setPosition(sf::Vector2f(WIDTH*0.4f, HEIGHT*0.56f));
		Map.addText("ArcherPeopleRequireText", ArcherPeopleRequireText, defaultFont);


		// Text input //

					// Pikeman
		TextInput PikemanRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.32f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255,255,255));
		Map.addTextInput("PikemanRecruitAmountBox", PikemanRecruitAmountBox);

		TextButton PikemanRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.32f, sf::Color(70, 70, 77),WIDTH*0.05f*0.25f,0.0f,
			"Ok", sf::Color(255,255,255));
		Map.addTextButton("PikemanRecruitButton", PikemanRecruitButton);
			
					// Swordsman
		TextInput SwordsmanRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.4f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255, 255, 255));
		Map.addTextInput("SwordsmanRecruitAmountBox", SwordsmanRecruitAmountBox);

		TextButton SwordsmanRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.4f, sf::Color(70, 70, 77), WIDTH*0.05f*0.25f, 0.0f,
			"Ok", sf::Color(255, 255, 255));
		Map.addTextButton("SwordsmanRecruitButton", SwordsmanRecruitButton);

					// Axeman
		TextInput AxemanRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.48f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255, 255, 255));
		Map.addTextInput("AxemanRecruitAmountBox", AxemanRecruitAmountBox);

		TextButton AxemanRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.48f, sf::Color(70, 70, 77), WIDTH*0.05f*0.25f, 0.0f,
			"Ok", sf::Color(255, 255, 255));
		Map.addTextButton("AxemanRecruitButton", AxemanRecruitButton);

					// Archer
		TextInput ArcherRecruitAmountBox(sf::Vector2f(WIDTH*0.1f, HEIGHT*0.05f), sf::Vector2f(WIDTH*0.55f, HEIGHT*0.56f), sf::Color(100, 100, 100), sf::Vector2f(WIDTH*0.1f*0.2f, 0.0f),
			"1", sf::Color(255, 255, 255));
		Map.addTextInput("ArcherRecruitAmountBox", ArcherRecruitAmountBox);

		TextButton ArcherRecruitButton(WIDTH*0.05f, HEIGHT*0.05f, WIDTH*0.7f, HEIGHT*0.56f, sf::Color(70, 70, 77), WIDTH*0.05f*0.25f, 0.0f,
			"Ok", sf::Color(255, 255, 255));
		Map.addTextButton("ArcherRecruitButton", ArcherRecruitButton);
	return Map;
}

void BarrackWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);
	
	// Frame

	window.draw(Map.getBuildingsWindowFrame("BarrackFrame"));
	window.draw(Map.getTextButton("BackToGame"));

	// Recruit

	window.draw(Map.getIcon("WoodIcon"));
	window.draw(Map.getIcon("IronIcon"));
	window.draw(Map.getIcon("ClayIcon"));
	window.draw(Map.getIcon("PeopleIcon"));

	window.draw(Map.getIcon("PikemanIcon"));
	window.draw(Map.getIcon("SwordsmanIcon"));
	window.draw(Map.getIcon("AxemanIcon"));
	window.draw(Map.getIcon("ArcherIcon"));

	// Pikeman

	window.draw(Map.getText("PikemanWoodRequireText"));
	window.draw(Map.getText("PikemanIronRequireText"));
	window.draw(Map.getText("PikemanClayRequireText"));
	window.draw(Map.getText("PikemanPeopleRequireText"));

	window.draw(Map.getTextInput("PikemanRecruitAmountBox"));
	window.draw(Map.getTextButton("PikemanRecruitButton"));

	// Swordsman

	window.draw(Map.getText("SwordsmanWoodRequireText"));
	window.draw(Map.getText("SwordsmanIronRequireText"));
	window.draw(Map.getText("SwordsmanClayRequireText"));
	window.draw(Map.getText("SwordsmanPeopleRequireText"));

	window.draw(Map.getTextInput("SwordsmanRecruitAmountBox"));
	window.draw(Map.getTextButton("SwordsmanRecruitButton"));

	// Axeman

	window.draw(Map.getText("AxemanWoodRequireText"));
	window.draw(Map.getText("AxemanIronRequireText"));
	window.draw(Map.getText("AxemanClayRequireText"));
	window.draw(Map.getText("AxemanPeopleRequireText"));

	window.draw(Map.getTextInput("AxemanRecruitAmountBox"));
	window.draw(Map.getTextButton("AxemanRecruitButton"));

	// Archer
	
	window.draw(Map.getText("ArcherWoodRequireText"));
	window.draw(Map.getText("ArcherIronRequireText"));
	window.draw(Map.getText("ArcherClayRequireText"));
	window.draw(Map.getText("ArcherPeopleRequireText"));

	window.draw(Map.getTextInput("ArcherRecruitAmountBox"));
	window.draw(Map.getTextButton("ArcherRecruitButton"));

	window.display();
}