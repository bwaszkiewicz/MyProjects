#include "RecruitHandler.h"

ShapeMap RecruitHandler::PikemanHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("PikemanWoodRequireText"));
	sf::Text Iron(Map.getText("PikemanIronRequireText"));
	sf::Text Clay(Map.getText("PikemanClayRequireText"));
	sf::Text People(Map.getText("PikemanPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(PIKEMAN)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);

	Map.addText("PikemanWoodRequireText", Wood, defaultFont);
	Map.addText("PikemanIronRequireText", Iron, defaultFont);
	Map.addText("PikemanClayRequireText", Clay, defaultFont);
	Map.addText("PikemanPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::SwordsmanHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("SwordsmanWoodRequireText"));
	sf::Text Iron(Map.getText("SwordsmanIronRequireText"));
	sf::Text Clay(Map.getText("SwordsmanClayRequireText"));
	sf::Text People(Map.getText("SwordsmanPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(SWORDSMAN)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);

	Map.addText("SwordsmanWoodRequireText", Wood, defaultFont);
	Map.addText("SwordsmanIronRequireText", Iron, defaultFont);
	Map.addText("SwordsmanClayRequireText", Clay, defaultFont);
	Map.addText("SwordsmanPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::AxemanHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("AxemanWoodRequireText"));
	sf::Text Iron(Map.getText("AxemanIronRequireText"));
	sf::Text Clay(Map.getText("AxemanClayRequireText"));
	sf::Text People(Map.getText("AxemanPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(AXEMAN)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);


	Map.addText("AxemanWoodRequireText", Wood, defaultFont);
	Map.addText("AxemanIronRequireText", Iron, defaultFont);
	Map.addText("AxemanClayRequireText", Clay, defaultFont);
	Map.addText("AxemanPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::ArcherHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("ArcherWoodRequireText"));
	sf::Text Iron(Map.getText("ArcherIronRequireText"));
	sf::Text Clay(Map.getText("ArcherClayRequireText"));
	sf::Text People(Map.getText("ArcherPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(ARCHERS)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);

	Map.addText("ArcherWoodRequireText", Wood, defaultFont);
	Map.addText("ArcherIronRequireText", Iron, defaultFont);
	Map.addText("ArcherClayRequireText", Clay, defaultFont);
	Map.addText("ArcherPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::LightCavalrymanHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("LightCavalrymanWoodRequireText"));
	sf::Text Iron(Map.getText("LightCavalrymanIronRequireText"));
	sf::Text Clay(Map.getText("LightCavalrymanClayRequireText"));
	sf::Text People(Map.getText("LightCavalrymanPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(LIGHTCAVALRYMAN)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);

	Map.addText("LightCavalrymanWoodRequireText", Wood, defaultFont);
	Map.addText("LightCavalrymanIronRequireText", Iron, defaultFont);
	Map.addText("LightCavalrymanClayRequireText", Clay, defaultFont);
	Map.addText("LightCavalrymanPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::HeavyCavalrymanHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData)
{
	sf::Color const defaultTextColor(100, 100, 100);
	sf::Color const notReachedColor(190, 15, 15);

	sf::Text Wood(Map.getText("HeavyCavalrymanWoodRequireText"));
	sf::Text Iron(Map.getText("HeavyCavalrymanIronRequireText"));
	sf::Text Clay(Map.getText("HeavyCavalrymanClayRequireText"));
	sf::Text People(Map.getText("HeavyCavalrymanPeopleRequireText"));

	Wood.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[WOOD] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Wood.getString()).c_str()) > MainData.getResources(WOOD))
		Wood.setFillColor(notReachedColor);
	else
		Wood.setFillColor(defaultTextColor);

	Iron.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[IRON] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Iron.getString()).c_str()) > MainData.getResources(IRON))
		Iron.setFillColor(notReachedColor);
	else
		Iron.setFillColor(defaultTextColor);

	Clay.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[CLAY] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(Clay.getString()).c_str()) > MainData.getResources(CLAY))
		Clay.setFillColor(notReachedColor);
	else
		Clay.setFillColor(defaultTextColor);

	People.setString(std::to_string(MainData.getUnitRecruitResourceRequire(HEAVYCAVALRYMAN)[PEOPLE] * std::atoi(std::string(evHandler.getTextInput()).c_str())));
	if (std::atoi(std::string(People.getString()).c_str()) + MainData.getResources(PEOPLE) > MainData.getResources(MAXPEOPLE))
		People.setFillColor(notReachedColor);
	else
		People.setFillColor(defaultTextColor);

	Map.addText("HeavyCavalrymanWoodRequireText", Wood, defaultFont);
	Map.addText("HeavyCavalrymanIronRequireText", Iron, defaultFont);
	Map.addText("HeavyCavalrymanClayRequireText", Clay, defaultFont);
	Map.addText("HeavyCavalrymanPeopleRequireText", People, defaultFont);

	return Map;
}

ShapeMap RecruitHandler::ChooseHandle(ShapeMap & Map, const EventHandler evHandler, const Data &MainData, short int unitType)
{
	switch (unitType)
	{
	case PIKEMAN:
		return PikemanHandle(Map, evHandler, MainData);
		break;
	case SWORDSMAN:
		return SwordsmanHandle(Map, evHandler, MainData);
		break;
	case AXEMAN:
		return AxemanHandle(Map, evHandler, MainData);
		break;
	case ARCHERS:
		return ArcherHandle(Map, evHandler, MainData);
		break;
	case LIGHTCAVALRYMAN:
		return LightCavalrymanHandle(Map, evHandler, MainData);
		break;
	case HEAVYCAVALRYMAN:
		return HeavyCavalrymanHandle(Map, evHandler, MainData);
		break;
	default:
		return Map;
		break;
	}
}
