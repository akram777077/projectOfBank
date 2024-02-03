#pragma once
#include"clsScreen.h"
#include<string>
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
class clsDeleteScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to delete it: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static std::string cardClient(clsClient* target)
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
	static void restart(clsClients &target)
	{
		target.save();
		target.restart();
		target.load();
	}
public:
	static void deleteClientScreen(clsClients& clients)
	{
		clsScreen::title("delete Client Screen");
		std::string target = getTarget();
		clsClient* temp = clients.find(target);
		if (temp == NULL)
		{
			std::cout << "the client has number [" + target + "] is not found....";
		}
		else
		{
			std::cout << cardClient(temp);
			if (!clsInputValidate::getYesOrNoFromUser("are you sure of delete this client"))
				std::cout << "operation cancelled....";
			else
			{
				temp->markDelete();
				restart(clients);
				std::cout << "This account is delete ..";
			}

		}
		temp = NULL;
		clsScreen::pressEnter();
	}

};

