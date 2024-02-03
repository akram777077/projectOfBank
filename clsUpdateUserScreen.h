#pragma once
#include"clsScreen.h"
#include"clsUsers.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsUpdateUserScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter User Name of User to edit it: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static clsUser* readUpdateUser()
	{
		std::string firstName = "", lastName = "", phone = "", email = "", userName = "", password = "";
		float Permission = 0;

		std::cout << "Enter account user name: ";
		std::getline(std::cin >> std::ws, userName);

		std::cout << "Enter first Name: ";
		std::getline(std::cin >> std::ws, firstName);
		std::cout << "Enter last Name: ";
		std::getline(std::cin >> std::ws, lastName);
		std::cout << "Enter phone: ";
		std::getline(std::cin >> std::ws, phone);
		std::cout << "Enter Email: ";
		std::getline(std::cin >> std::ws, email);
		std::cout << "Enter Pin Code: ";
		std::getline(std::cin >> std::ws, password);
		if (clsInputValidate::getYesOrNoFromUser("do you want to give full access: "))
			Permission = -1;
		else
		{
			std::cout << "do want to give access to : \n";
			if (clsInputValidate::getYesOrNoFromUser("-> Show client list: "))
				Permission += (short)clsUser::enPermissions::PermessionShowClientsList;
			if (clsInputValidate::getYesOrNoFromUser("-> Add new Client: "))
				Permission += (short)clsUser::enPermissions::PermessionAddNewClients;
			if (clsInputValidate::getYesOrNoFromUser("-> Delete Client: "))
				Permission += (short)clsUser::enPermissions::PermessionDeleteClient;
			if (clsInputValidate::getYesOrNoFromUser("-> Update Client: "))
				Permission += (short)clsUser::enPermissions::PermessionUpdateClient;
			if (clsInputValidate::getYesOrNoFromUser("-> Find Client: "))
				Permission += (short)clsUser::enPermissions::PermessionFindClient;
			if (clsInputValidate::getYesOrNoFromUser("-> Transaction: "))
				Permission += (short)clsUser::enPermissions::PermessionTransaction;
			if (clsInputValidate::getYesOrNoFromUser("-> Manage Users: "))
				Permission += (short)clsUser::enPermissions::PermessionManageUsers;
			if (clsInputValidate::getYesOrNoFromUser("-> Login Registe: "))
				Permission += (short)clsUser::enPermissions::PermessionLoginRegister;
		}
		clsUser* newUser = new clsUser(firstName, lastName, phone, email, userName, password, Permission);
		return newUser;
	}

	static clsUser* UpdateUser(clsUsers& temp)
	{
		std::string target = getTarget();
		clsUser* found = temp.find(target);
		if (!found)
		{
			std::cout << "This user is not in the system. Please try another user name...";
			return nullptr; // Return nullptr as the client already exists
		}
		clsUser* tempUser = readUpdateUser();
		if (tempUser == NULL)
			return NULL;
		if (!clsInputValidate::getYesOrNoFromUser("are you sure for update " + tempUser->getFullName() + " ?"))
			return NULL;
		*found = *tempUser;
		temp.reload();
		return tempUser;
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
	static void UpdateUserScreen(clsUsers& target)
	{
		clsScreen::title("update user screen");
		clsUser* temp = UpdateUser(target);
		if (temp == NULL)
		{
			std::cout << "\nthis user is not updating in the system...";
			return;
		}
		clsScreen::clear();
		std::cout << cardUser(temp);
		delete temp;
		std::cout << "update User done...";
		clsScreen::pressEnter();
	}
};