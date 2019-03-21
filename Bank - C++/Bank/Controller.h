#pragma once
#include <string>
class Controller {
	bool CheckChoosePosition(unsigned int maxPosition, unsigned short int input);
	bool CheckPasswordNorm(std::string password);
	bool BalanceValidation(double balance);

	friend class MainMenu;
	friend class AdminMenu;
	friend class UserMenu;
	friend class ChangePasswordMenu;
	friend class DepositMenu;
	friend class TransferMenu;
	friend class WithdrawMenu;
public:
	Controller() = default;
	~Controller() = default;
};