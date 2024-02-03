#pragma once
#include"clsScreen.h"
#include<string>
#include"clsUsers.h"
class clsFindUserScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter User Name of User to find it: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static std::string cardUser(clsUser* target)
	{
		std::string result = "";
		result += "\n---------------------------------\n";
		result += "User Name     : " + target->getUserName() + "\n";
		result += "Password      : " + target->getPassword() + "\n";
		result += "first Name    : " + target->getFirstName() + "\n";
		result += "last Name     : " + target->getLastName() + "\n";
		result += "Phone         : " + target->getPhone() + "\n";
		result += "Email         : " + target->getEmail() + "\n";
		result += "Permissions   : " + std::to_string(target->getPermissions()) + "\n";
		result += "---------------------------------\n";
		return result;
	}
public:
	static void findUserScreen(clsUsers& users)
	{
		clsScreen::title("Find User Screen");
		std::string target = getTarget();
		clsUser* temp = users.find(target);
		if (temp == NULL)
		{
			std::cout << "the User has User Name [" + target + "] is not found....";
		}
		else
		{
			std::cout << cardUser(temp);
		}
		temp = NULL;
		clsScreen::pressEnter();
	}
};

