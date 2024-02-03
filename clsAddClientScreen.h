#pragma once
#include"clsScreen.h"
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsAddClientScreen:protected clsScreen
{
private:
	static clsClient* readClient(clsClients& temp)
	{
		std::string firstName = "", lastName = "", phone = "", email = "", accountNumber = "", pinCode = "";
		float accountBalance = 0;

		std::cout << "Enter account number: ";
		std::getline(std::cin >> std::ws, accountNumber);

		if (temp.find(accountNumber))
		{
			std::cout << "This client is in the system. Please try another account number...";
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
		accountBalance = clsInputValidate::readNumberFloat("Enter account balance: ", 0, std::numeric_limits<float>::max(), "Please enter a valid number.");
		std::cout << "Enter Pin Code: ";
		std::getline(std::cin >> std::ws, pinCode);
		clsClient* newClient = new clsClient(firstName, lastName, phone, email, accountNumber, pinCode, accountBalance);
		return newClient;
	}

	static clsClient* addClient(clsClients& temp)
	{
		clsClient *tempClient = readClient(temp);
		if (tempClient == NULL) 
			return NULL;
		if (!clsInputValidate::getYesOrNoFromUser("are you sure for adding " + tempClient->getFullName() + " ?"))
			return NULL;
		temp.addClient(*tempClient);
		temp.reload();
		return tempClient;
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
public:
	static void AddClientScreen(clsClients& target)
	{
		clsScreen::title("add Client screen");
		clsClient *temp=addClient(target);
		if (temp == NULL)
		{
			std::cout << "\nthis client is not adding in the system...";
			return;
		}
		clsScreen::clear();
		std::cout << cardClient(temp);
		delete temp;
		std::cout << "add client done...";
		clsScreen::pressEnter();
	}
};

