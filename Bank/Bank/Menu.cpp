#include "Menu.h"

Menu::Menu(Database &Data): _Data(Data), _currentState(1), _currentID(-1)
{
}

void Menu::ChangingMenu()
{
	while (1)
	{
		switch (_currentState)
		{
		case 1:
		{
			MainMenu oMainMenu;
			oMainMenu.ShowMenu();
			_choosenMenu = oMainMenu.GetNextPosition();
			switch (_choosenMenu)
			{
			case 1:
				_currentState = sLoginMenu;
				break;
			case 2:
				_currentState = sExit;
				break;
			}
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "Nastapi zakonczenie pracy programu" << std::endl;
			return void();
			break;
		case 3:
			LoginMenu oLoginMenu(_Data);
			oLoginMenu.ShowMenu();
			_currentID = oLoginMenu.GetID();
			_choosenMenu = oLoginMenu.GetNextPosition();
			switch (_choosenMenu)
			{
			case 1:
				_currentState = sAdminMenu;
				break;
			case 2:
				_currentState = sUserMenu;
				break;
			case 3:
				_currentState = sMainMenu;
				break;
			}
			break;
		}
		case 4:
		{
			AdminMenu oAdminMenu(_Data, _currentID);
			oAdminMenu.ShowMenu();
			_choosenMenu = oAdminMenu.GetNextPosition();
			switch (_choosenMenu)
			{
			case 1:
				_currentState = sAddNewAccountMenu;
				break;
			case 2:
				_currentState = sDeleteAccountMenu;
				break;
			case 3:
				_currentState = sShowAccountsMenu;
				break;
			case 4:
				_currentState = sShowAccountHistoryMenu;
				break;
			case 5:
				_currentState = sShoDebetMenu;
				break;
			case 6:
				_currentState = sMainMenu;
				system("cls");
				std::cout << "Nastapi wylogowanie" << std::endl;
				system("pause");
				_currentID = -1;
				break;
			}
			break;
		}
		case 5:
		{
			UserMenu oUserMenu(_Data, _currentID);
			oUserMenu.ShowMenu();
			_choosenMenu = oUserMenu.GetNextPosition();
			switch (_choosenMenu)
			{
			case 1:
				_currentState = sDepositMenu;
				break;
			case 2:
				_currentState = sWithdrawMenu;
				break;
			case 3:
				_currentState = sTransferMenu;
				break;
			case 4:
				_currentState = sShowHistoryMenu;
				break;
			case 5:
				_currentState = sChangePasswordMenu;
				break;
			case 6:
				_currentState = sMainMenu;
				system("cls");
				std::cout << "Nastapi wylogowanie" << std::endl;
				system("pause");
				_currentID = -1;
				break;
			}
			break;
		}
		case 6:
		{
			AddNewAccountMenu oAddNewAccountMenu(_Data, _currentID);
			oAddNewAccountMenu.ShowMenu();
			_currentState = sAdminMenu;
			break;
		}
		case 7:
		{
			DeleteAccountMenu oDeleteAccountMenu(_Data, _currentID);
			oDeleteAccountMenu.ShowMenu();
			_currentState = sAdminMenu;
			break;
		}
		case 8:
		{
			ShowAccountsMenu oShowAccountsMenu(_Data, _currentID);
			oShowAccountsMenu.ShowMenu();
			_currentState = sAdminMenu;
			break;
		}
		case 9:
		{
			ShowAccountHistoryMenu oShowAccountHistoryMenu(_Data, _currentID);
			oShowAccountHistoryMenu.ShowMenu();
			_currentState = sAdminMenu;
			break;
		}
		case 10:
		{
			ShowDebetMenu oShowDebetMenu(_Data, _currentID);
			oShowDebetMenu.ShowMenu();
			_currentState = sAdminMenu;
			break;
		}
		case 11:
		{
			DepositMenu oDepositMenu(_Data, _currentID);
			oDepositMenu.ShowMenu();
			_currentState = sUserMenu;
			break;
		}
		case 12:
		{
			WithdrawMenu oWithdrawMenu(_Data, _currentID);
			oWithdrawMenu.ShowMenu();
			_currentState = sUserMenu;
			break;
		}
		case 13:
		{
			TransferMenu oTransferMenu(_Data, _currentID);
			oTransferMenu.ShowMenu();
			_currentState = sUserMenu;
			break;
		}
		case 14:
		{
			ShowHistoryMenu oShowHistoryMenu(_Data, _currentID);
			oShowHistoryMenu.ShowMenu();
			_currentState = sUserMenu;
			break;
		}
		case 15:
		{
			ChangePasswordMenu oChangePasswordMenu(_Data, _currentID);
			oChangePasswordMenu.ShowMenu();
			_currentState = sUserMenu;
			break;
		}

		}

	}
}
