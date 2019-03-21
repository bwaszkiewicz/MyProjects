#include "AttackEndgameWindow.h"

State * AttackEndgameWindow::handleInput(Input in, ShapeMap Map, EventHandler & evHandler)
{
	if (Map.getTextButton("MenuButton") == in)
		return new MainMenu;
	else
		return nullptr;
}

void AttackEndgameWindow::update(ShapeMap & Map, Data & MainData, short int updateCode, EventHandler& evHandler)
{
	switch (updateCode)
	{
	case ENDGAME_UPDATE:
	{
		MainData.clearData();
	}
	break;
	default:
		break;
	}
}

ShapeMap AttackEndgameWindow::render(const Data & MainData)
{
	ShapeMap Map;

	sf::RectangleShape MainBox(sf::Vector2f(WIDTH*0.7f, HEIGHT*0.7f));
	MainBox.setPosition(sf::Vector2f(WIDTH*0.15f, HEIGHT*0.15f));
	MainBox.setFillColor(sf::Color(100, 100, 100));
	Map.addRectangleShape("MainBox", MainBox);

	sf::Text Description1;
	Description1.setFillColor(sf::Color(255, 255, 255));
	Description1.setString("Your village has been invaded by a barbarian tribe.");
	Description1.setPosition(sf::Vector2f(WIDTH*0.22f, HEIGHT*0.3f));
	Map.addText("Description1", Description1, defaultFont);

	sf::Text Description2;
	Description2.setFillColor(sf::Color(255, 255, 255));
	Description2.setString("The settlement turned into ashes.");
	Description2.setPosition(sf::Vector2f(WIDTH*0.3f, HEIGHT*0.35f));
	Map.addText("Description2", Description2, defaultFont);

	TextButton MenuButton(WIDTH*0.2f, HEIGHT*0.1f, WIDTH*0.4f, HEIGHT*0.65f, sf::Color(200, 200, 200), WIDTH*0.2f*0.1f, HEIGHT*0.1f*0.25f, "Back to menu", sf::Color(100, 100, 100));
	Map.addTextButton("MenuButton", MenuButton);

	return Map;
}

void AttackEndgameWindow::show(sf::RenderWindow & window, ShapeMap Map)
{
	window.clear(sf::Color::Black);

	window.draw(Map.getRectangleShape("MainBox"));

	window.draw(Map.getText("Description1"));
	window.draw(Map.getText("Description2"));

	window.draw(Map.getTextButton("MenuButton"));

	window.display();
}
