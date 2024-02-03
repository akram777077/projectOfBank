#pragma once
#include"clsScreen.h"
#include"clsClients.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsUpdateClientScreen :protected clsScreen
{
private:
	static std::string getTarget()
	{
		std::string result = "";
		std::cout << "-> Enter account Number of clients to update it: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static clsClient* readUpdateClient(clsClients& temp,std::string accountNumber)
	{
		std::string firstName = "", lastName = "", phone = "", email = "", pinCode = "";
		float accountBalance = 0;

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

	static clsClient* updateClient(clsClients& temp,std::string target)
	{
		clsClient* tempClient = temp.find(target);
		if (tempClient == NULL)
			return NULL;
		clsClient* tempUpdate = readUpdateClient(temp,tempClient->getAccountNumber());
		if (!clsInputValidate::getYesOrNoFromUser("are you sure for update " + tempClient->getFullName() + " ?"))
			return NULL;
		*tempClient = *tempUpdate;
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
	static void UpdateClientScreen(clsClients& target)
	{
		clsScreen::title("Update Client screen");
		std::string accountNumber = getTarget();
		clsClient* temp = updateClient(target,accountNumber);
		if (temp == NULL)
		{
			std::cout << "\nthis client is not update in the system...";
			return;
		}
		clsScreen::clear();
		std::cout << cardClient(temp);
		std::cout << "update client done...";
		clsScreen::pressEnter();
	}
};

