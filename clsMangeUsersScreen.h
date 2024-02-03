#pragma once
#include"F:\programming\my Classes\clsInputValidate.h"
#include"clsScreen.h"
#include"clsUsers.h"
#include"clsShowUsersScreen.h"
#include"clsFindUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsUpdateUserScreen.h"
class clsMangeUsersScreen :protected clsScreen
{
private:
	enum enOption
	{
		ListUsers = 1,
		addNewUser,
		DeleteUser,
		updateUser,
		findUser,
		MainScreen
	};
	static void ManageUsersScreen()
	{
		clsScreen::title("Users manage Screen");
		std::cout << "\t\t\t\t[1] show Users list.\n";
		std::cout << "\t\t\t\t[2] Add new User.\n";
		std::cout << "\t\t\t\t[3] Delete User.\n";
		std::cout << "\t\t\t\t[4] Update User.\n";
		std::cout << "\t\t\t\t[5] Find User.\n";
		std::cout << "\t\t\t\t[6] Main Screen";
		clsScreen::line();
	}
	static enOption getOption()
	{

		enOption temp = (enOption)clsInputValidate::readNumber("\t\t\t\t-> Enter option: ", 1, 6, "\t\t\t\tplease enter a valid option");
		clsScreen::clear();
		return temp;
	}
	static void optionSelect(std::string fileName,clsUser* owned)
	{
		clsUsers Users;
		Users.setNameFile(fileName);
		Users.load();
		while (1)
		{
			clsScreen::clear();
			ManageUsersScreen();
			switch ((enOption)getOption())
			{
			case enOption::ListUsers:
				if (clsScreen::NotAllowAndEmpty(1,Users.isEmpty()))
					clsShowUsersScreen::showClientsScreen(&Users);
				break;
			case enOption::addNewUser:
					clsAddNewUserScreen::AddClientScreen(Users);
				break;
			case enOption::DeleteUser:
				if (clsScreen::NotAllowAndEmpty(1, Users.isEmpty()))
					clsDeleteUserScreen::deleteUserScreen(Users,owned);
				break;
			case enOption::updateUser:
				if (clsScreen::NotAllowAndEmpty(1, Users.isEmpty()))
					clsUpdateUserScreen::UpdateUserScreen(Users);
				break;
			case enOption::findUser:
				if (clsScreen::NotAllowAndEmpty(1, Users.isEmpty()))
					clsFindUserScreen::findUserScreen(Users);
				break;
			case enOption::MainScreen:
				return;
			}
		}
	}
public:
	static void showUsersMange(std::string fileName,clsUser* owned)
	{
		clsScreen::clear();
		optionSelect(fileName,owned);
	}
};
