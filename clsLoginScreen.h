#pragma once
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsUserNameString.h"
class clsLoginScreen:protected clsScreen
{
private:
	static void readUserInfo(std::string *username,std::string *password)
	{
		std::cout << "username: ";
		std::getline(std::cin >> std::ws, *username);
		std::cout << "password: ";
		std::getline(std::cin >> std::ws, *password);
	}
	static clsUsers getUsers(std::string fileName)
	{
		clsUsers users;
		users.setNameFile(fileName);
		users.load();
		return users;
	}
	static clsUser* loginScreen(std::string FileName)
	{
		UserNameOwned = "";
		clsUsers users = getUsers(FileName);
		std::string username = "", password = "";
		clsUser* temp = nullptr;
		bool test = 1;
		short tryCount = 2;
		do
		{
			clsScreen::clear();
			clsScreen::title("login Screen");
			readUserInfo(&username, &password);
			temp = users.find(username, password);
			if (temp != nullptr)
			{
				clsUser* tem = new clsUser;
				*tem = *temp;
				UserNameOwned = temp->getUserName();
				return tem;
			}
			std::cout << "your username or password is wrong please check for your information(you have[" << tryCount << " Attempts])";
			clsScreen::pressEnter();
		} while ((--tryCount) > -1);
		return nullptr;
	}
public:
	static void loginSystem(std::string fileNameClients, std::string fileNameUsers,std::string loginFile,std::string fileTransfer, std::string fileExchange)
	{
		clsUser* ownedUser = nullptr;
		do
		{
			ownedUser = clsLoginScreen::loginScreen(fileNameUsers);
			if (ownedUser)
			{
				ownedUser->setFileLogin(loginFile);
				ownedUser->saveLogin();
				clsScreenMain::showMainScreen(fileNameClients, fileNameUsers, ownedUser,loginFile,fileTransfer,fileExchange);
			}
		} while (ownedUser);
	}
};

