#pragma once
#include"clsScreen.h"
#include<string>
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsDepositScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to deposit to: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static void DepositTo(clsClients& clients)
	{
		std::string target = getTarget();
		clsClient* temp = clients.find(target);
		if (temp == NULL)
		{
			std::cout << "the client has number [" + target + "] is not found....";
		}
		else
		{
			float depositBalance = clsInputValidate::readNumberFloat("Enter amount to add to <" + temp->getFullName() + "> has [" + std::to_string(temp->getAccountBalance()) + "$]: ", 500, numeric_limits<float>::max(), "Please enter a valid amount: ");
			std::string line = "are you sure for add [" + std::to_string(depositBalance) + "] to: " + temp->getFullName();
			if (!clsInputValidate::getYesOrNoFromUser(line))
				std::cout << "operation cancelled....";
			temp->deposit(depositBalance);
			clients.reload();
			std::cout << temp->getFullName() << "-> " << temp->getAccountBalance() << "$";
			std::cout << "\noperation has been successes...";
		}
		temp = NULL;
	}
public:
	static void showDepositScreen(clsClients& clients)
	{
		clsScreen::title("deposit Screen");
		DepositTo(clients);
	}

};

