#include "MainMenu.h"

void MainMenu::ShowMenu()
{
	system("cls");
	std::cout << "Menu glowne" << std::endl;
	std::cout << "1. Logowanie" << std::endl;
	std::cout << "2. Exit" << std::endl;
	ChoosePosition();
}

unsigned short int MainMenu::GetNextPosition()
{
	return _nextPosition;
}

void MainMenu::ChoosePosition()
{
	Controller Control;
	unsigned short int choosen;
	std::cout << std::endl << "Wybierz pozycje" << std::endl;
	while (1)
	{
		std::cin >> choosen;
		if (std::cin.fail() || !Control.CheckChoosePosition(2, choosen))
		{
			std::cout << "Brak pozycji" << std::endl;
			choosen = 0;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else
			break;
	}
	_nextPosition = choosen;
}
