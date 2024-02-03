#pragma once
#include"F:\programming\my Classes\clsInputValidate.h"
#include"clsShowClientsScreen.h"
#include"clsFindClientScreen.h"
#include"clsDeleteScreen.h"
#include"clsAddClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsMangeUsersScreen.h"
#include"clsLoginRegister.h"
#include"clsCurrencyExchangeScreen.h"
class clsScreenMain:protected clsScreen
{
private:
	enum enOption
	{
		showClientsList = 1,
		addNewClient,
		DeleteClient,
		updateClient,
		findClient,
		Transaction,
		manageUsers,
		loginRegister,
		CurrencyExchange,
		logout
	};
	static void mainScreen()
	{
		clsScreen::title("Main Screen");
		std::cout << "\t\t\t\t[1] show Clients list.\n";
		std::cout << "\t\t\t\t[2] Add new Client.\n";
		std::cout << "\t\t\t\t[3] Delete Client.\n";
		std::cout << "\t\t\t\t[4] Update client.\n";
		std::cout << "\t\t\t\t[5] Find Client.\n";
		std::cout << "\t\t\t\t[6] Transaction.\n";
		std::cout << "\t\t\t\t[7] manage Users\n";
		std::cout << "\t\t\t\t[8] Login Register.\n";
		std::cout << "\t\t\t\t[9] Currency Exchange.\n";
		std::cout << "\t\t\t\t[10] logout";
		clsScreen::line();
	}
	static enOption getOption()
	{

		enOption temp= (enOption)clsInputValidate::readNumber("\t\t\t\t-> Enter option: ", 1, 10, "\t\t\t\tplease enter a valid option");
		clsScreen::clear();
		return temp;
	}
	static void optionSelect(std::string fileNameClients,std::string fileNameUsers,clsUser* user,std::string fileLogin,std::string fileTransfer, std::string fileExchange)
	{
		clsClients clients;
		clients.setNameFile(fileNameClients);
		clients.load();
		do
		{
			clsScreen::clear();
			mainScreen();
			switch ((enOption)getOption())
			{
			case enOption::showClientsList:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionShowClientsList),clients.isEmpty()))
					clsShowClientsScreen::showClientsScreen(&clients);
				break;
			case enOption::addNewClient:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionAddNewClients)))
					clsAddClientScreen::AddClientScreen(clients);
				break;
			case enOption::DeleteClient:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionDeleteClient),clients.isEmpty()))
					clsDeleteScreen::deleteClientScreen(clients);				
				break;
			case enOption::updateClient:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionUpdateClient),clients.isEmpty()))
					clsUpdateClientScreen::UpdateClientScreen(clients);
				break;
			case enOption::findClient:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionFindClient),clients.isEmpty()))
					clsFindClientScreen::findClientScreen(clients);
				break;
			case enOption::Transaction:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionTransaction),clients.isEmpty()))
					clsTransactionScreen::showTransactionScreen(clients,user,fileTransfer,fileTransfer);
				break;
			case enOption::manageUsers:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionManageUsers),clients.isEmpty()))
					clsMangeUsersScreen::showUsersMange(fileNameUsers,user);
				break;
			case enOption::loginRegister:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionLoginRegister), clients.isEmpty()))
					clsLoginRegister::showClientsScreen(fileLogin);
				break;
			case enOption::CurrencyExchange:
				if (clsScreen::NotAllowAndEmpty(user->isHavePermission(clsUser::enPermissions::PermessionLoginRegister), clients.isEmpty()))
					clsCurrencyExchangeScreen::showExchangeScreen(fileExchange);
				break;
			case enOption::logout:
				return;
			}
		} while (1);
	}
public:
	static void showMainScreen(std::string fileNameClients, std::string fileNameUsers, clsUser* user, std::string fileLogin, std::string fileTransfer,std::string fileExchange)
	{
		clsScreen::clear();
		optionSelect(fileNameClients,fileNameUsers,user,fileLogin,fileTransfer,fileExchange);
	}
};

