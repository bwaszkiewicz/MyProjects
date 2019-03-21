#pragma once
#include "Database.h"

#include "MainMenu.h"
#include "LoginMenu.h"
#include "AdminMenu.h"
#include "UserMenu.h"
#include "AddNewAccountMenu.h"
#include "DeleteAccountMenu.h"
#include "ShowAccountsMenu.h"
#include "ShowAccountHistoryMenu.h"
#include "ShowDebetMenu.h"
#include "DepositMenu.h"
#include "WithdrawMenu.h"
#include "TransferMenu.h"
#include "ShowHistoryMenu.h"
#include "ChangePasswordMenu.h"

enum MenuState { sMainMenu = 1, sExit, sLoginMenu, sAdminMenu, sUserMenu, sAddNewAccountMenu, sDeleteAccountMenu, sShowAccountsMenu, sShowAccountHistoryMenu, sShoDebetMenu,
				sDepositMenu, sWithdrawMenu, sTransferMenu, sShowHistoryMenu, sChangePasswordMenu};

class Menu {
	Database &_Data;
	unsigned short int	_currentState;
	unsigned short int	_choosenMenu;
	int _currentID;
public:
	Menu(Database &Data);
	~Menu() = default;
	void ChangingMenu();

};
