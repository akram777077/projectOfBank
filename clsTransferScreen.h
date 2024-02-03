#pragma once
#include"clsScreen.h"
#include<string>
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsTransferScreen :protected clsScreen
{
private:
	static std::string getTarget(std::string fromOrTo)
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to Transfer "+fromOrTo+": ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static void printCard(clsClient *target)
	{
		std::cout << "\n------------------------";
		std::cout << "\naccount number : " << target->getAccountNumber();
		std::cout << "\nFull Name      : " << target->getFullName();
		std::cout << "\naccount balance: " << target->getAccountBalance();
		std::cout << "\n------------------------\n";
	}
	static float readBalance(float max)
	{
		return clsInputValidate::readNumberFloat("enter transfer amount : ", 20, max, "please Enter valid amount...");
	}
	static clsClient* showCard(clsClients& clients ,std::string fromOrTo)
	{
		clsClient* temp = nullptr;
		std::string target = "";
		while (1)
		{
			target = getTarget(fromOrTo);
			temp = clients.find(target);
			if (temp)
			{
				printCard(temp);
				return temp;
			}
			std::cout << "the client has number [" + target + "] is not found. please other account number...\n";
		}
		return nullptr;
	}
public:
	static void TransferScreen(clsClients& clients,clsUser* user,std::string fileName)
	{
		clsScreen::title("Transfer Screen");
		clsClient *ptr1 = nullptr, * ptr2 = nullptr;
		clsClient::stTransfer* ptr3 = nullptr;
		ptr1 = showCard(clients,"From");
		ptr2 = showCard(clients,"To");
		float amount = readBalance(ptr1->getAccountBalance());
		std::string line = "are you sure for: " + ptr1->getFullName() + " --(" + std::to_string(amount) + "$)--> " + ptr2->getFullName();
		if (!clsInputValidate::getYesOrNoFromUser(line))
		{
			std::cout << "The operation is canceled";
			return;
		}
		clsScreen::clear();
		ptr1->withDraw(amount);
		ptr2->deposit(amount);
		clients.reload();
		printCard(ptr1);
		printCard(ptr2);
		ptr3=ptr1->changeToCardTransfer(ptr2, user, amount);
		ptr3->saveTransfer(fileName);
		delete ptr3;
		ptr3 = nullptr;
		std::cout << "The operation is complete...";
	}

};
