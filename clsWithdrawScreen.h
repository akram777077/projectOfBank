#pragma once
#include"clsScreen.h"
#include<string>
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsWithdrawScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to withdraw from: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static void WithDrawTo(clsClients& clients)
	{
		std::string target = getTarget();
		clsClient* temp = clients.find(target);
		if (temp == NULL)
		{
			std::cout << "the client has number [" + target + "] is not found....";
		}
		else
		{
			float WithDrawBalance = clsInputValidate::readNumberFloat("Enter amount to withdraw from <" + temp->getFullName() + "> has [" + std::to_string(temp->getAccountBalance()) + "$]: ",500, temp->getAccountBalance(), "Please enter a valid amount: ");
			std::string line = "are you sure for withdraw [" + std::to_string(WithDrawBalance) + "] from: " + temp->getFullName();
			if (!clsInputValidate::getYesOrNoFromUser(line))
				std::cout << "operation cancelled....";
			temp->withDraw(WithDrawBalance);
			clients.reload();
			std::cout << temp->getFullName() << "-> " << temp->getAccountBalance() << "$";
			std::cout << "\noperation has been successes...";
		}
		temp = NULL;
	}
public:
	static void showWithdrawScreen(clsClients& clients)
	{
		clsScreen::title("withDraw Screen");
		WithDrawTo(clients);
	}

};
