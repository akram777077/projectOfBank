#pragma once
#include"clsScreen.h"
#include<string>
#include"clsClients.h"
class clsFindClientScreen:protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to find it: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static std::string cardClient(clsClient *target)
	{
		std::string result = "";
		result += "\n---------------------------------\n";
		result += "account number: " + target->getAccountNumber() + "\n";
		result += "Pin Code      : " + target->getPinCode() + "\n";
		result += "first Name    : " + target->getFirstName() + "\n";
		result += "last Name     : " + target->getLastName() + "\n";
		result += "Phone         : " + target->getPhone() + "\n";
		result += "Email         : " + target->getEmail() + "\n";
		result += "Balance       : " + std::to_string(target->getAccountBalance()) + "\n";
		result += "---------------------------------\n";
		return result;
	}
public:
	static void findClientScreen(clsClients& clients)
	{
		clsScreen::title("Find Client Screen");
		std::string target = getTarget();
		clsClient* temp = clients.find(target);
		if (temp == NULL)
		{
			std::cout << "the client has number [" + target + "] is not found....";
		}
		else
		{
			std::cout << cardClient(temp);
		}
		temp = NULL;
		clsScreen::pressEnter();
	}

};

