#pragma once
#include"clsScreen.h"
#include<string>
#include"clsUsers.h"
#include"F:\programming\my Classes\clsInputValidate.h"
class clsDeleteUserScreen :protected clsScreen
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
	static bool isAdmin(std::string target)
	{
		return target == "admin";
	}
	static void doTheDelete(clsUsers& users,clsUser* owned)
	{
		clsUser* temp = nullptr;
		std::string target = getTarget();
		if (target==owned->getUserName())
		{
			std::cout << "You can't delete your account please enter other username.";
			return;
		}
		else if (isAdmin(target))
		{
			std::cout << "You can't delete admin please enter other username....";
		}
		else
		{
			temp = users.find(target);
			if (temp == NULL)
			{
				std::cout << "the user has user Name [" + target + "] is not found....";
			}
			else
			{
				std::cout << cardUser(temp);
				if (!clsInputValidate::getYesOrNoFromUser("are you sure of delete this User"))
					std::cout << "operation cancelled....";
				else
				{
					temp->markDelete();
					users.reload();
					std::cout << "This User is delete ..";
				}

			}
		}
		temp = NULL;
	}
public:
	static void deleteUserScreen(clsUsers& users,clsUser* owned)
	{
		clsScreen::title("delete Client Screen");
		doTheDelete(users,owned);
		clsScreen::pressEnter();
	}
};

