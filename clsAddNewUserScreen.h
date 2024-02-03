#pragma once
#include"clsScreen.h"
#include"clsUsers.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsAddNewUserScreen :protected clsScreen
{
private:
	static clsUser* readUser(clsUsers& temp)
	{
		std::string firstName = "", lastName = "", phone = "", email = "", userName = "", password = "";
		float Permission = 0;

		std::cout << "Enter account user name: ";
		std::getline(std::cin >> std::ws, userName);

		if (temp.find(userName))
		{
			std::cout << "This user is in the system. Please try another user name...";
			return nullptr; // Return nullptr as the client already exists
		}

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

	static clsUser* addUser(clsUsers& temp)
	{
		clsUser* tempUser = readUser(temp);
		if (tempUser == NULL)
			return NULL;
		if (!clsInputValidate::getYesOrNoFromUser("are you sure for adding " + tempUser->getFullName() + " ?"))
			return NULL;
		temp.addUser(*tempUser);
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
	static void AddClientScreen(clsUsers& target)
	{
		clsScreen::title("add Client screen");
		clsUser* temp = addUser(target);
		if (temp == NULL)
		{
			std::cout << "\nthis client is not adding in the system...";
			return;
		}
		clsScreen::clear();
		std::cout << cardUser(temp);
		delete temp;
		std::cout << "add User done...";
		clsScreen::pressEnter();
	}
};

