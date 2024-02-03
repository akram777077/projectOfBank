#pragma once
#include"F:\programming\my Classes\clsInputValidate.h"
#include"clsScreen.h"
#include"clsClients.h"
#include"clsTotalBalances.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLog.h"
class clsTransactionScreen:protected clsScreen
{
private:
	enum enOption
	{
		Deposit = 1,
		Withdraw,
		TotalBalances,
		Transfer,
		TransferLog,
		MainScreen,
	};
	static void TransactionScreen()
	{
		clsScreen::title("Transaction Screen");
		std::cout << "\t\t\t\t[1] Deposit.\n";
		std::cout << "\t\t\t\t[2] Withdraw.\n";
		std::cout << "\t\t\t\t[3] Total balances.\n";
		std::cout << "\t\t\t\t[4] Transfer.\n";
		std::cout << "\t\t\t\t[5] Transfer Log.\n";
		std::cout << "\t\t\t\t[6] Main Screen.\n";
		clsScreen::line();
	}
	static enOption getOption()
	{

		enOption temp = (enOption)clsInputValidate::readNumber("\t\t\t\t-> Enter option: ", 1, 6, "\t\t\t\tplease enter a valid option");
		clsScreen::clear();
		return temp;
	}
	static void optionSelect(clsClients &clients,clsUser *user,std::string fileName,std::string fileTransfer)
	{
		while (1)
		{
			clsScreen::clear();
			TransactionScreen();
			switch ((enOption)getOption())
			{
			case enOption::Deposit:
				clsDepositScreen::showDepositScreen(clients);
				break;
			case enOption::Withdraw:
				clsWithdrawScreen::showWithdrawScreen(clients);
				break;
			case enOption::TotalBalances:
				clsTotalBalances::showTotalBalances(&clients);
				break;
			case enOption::Transfer:
				clsTransferScreen::TransferScreen(clients,user,fileName);
				break;
			case enOption::TransferLog:
				clsTransferLog::showTransferRecord(fileTransfer, clients);
				break;
			case enOption::MainScreen:
				return;
			}
			clsScreen::pressEnter();
		}
	}
public:
	static void showTransactionScreen (clsClients& clients,clsUser *user,std::string fileName,std::string fileTransfer)
	{
		clsScreen::clear();
		optionSelect(clients,user,fileName,fileTransfer);
	}
};

