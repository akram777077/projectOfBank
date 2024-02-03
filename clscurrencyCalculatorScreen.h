#pragma once
#include"clsScreen.h"
#include"clsCurrencies.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static float ReadRate()
	{
		return clsInputValidate::readNumberFloat("Enter amount you want to change: ", 0, std::numeric_limits<float>::max(), "Enter valid rate please: ");
	}
	static void printCurrency(clsCurrency* target)
	{
		std::cout << "---------------------";
		std::cout << "\nCountry: " << target->getCountry();
		std::cout << "\nCode   : " << target->getCode();
		std::cout << "\nName   : " << target->getName();
		std::cout << "\nRate   : " << target->getRate();
		std::cout << "\n---------------------\n";
	}
	static clsCurrency* findCurrency(clsCurrencies& Currencies,std::string message)
	{
		do 
		{
			clsCurrency* temp = Currencies.findCode(getCode(message));
			if (temp) return temp;
			std::cout << "this code is wrong..\n";
		} while (1);
		return nullptr;
	}
	static std::string getCode(std::string message)
	{
		std::string result = "";
		std::cout << message;
		std::getline(std::cin >> std::ws, result);
		return result;
	}

public:
	static void showCurrencyCalculator(clsCurrencies& Currencies)
	{
		do
		{
			clsScreen::clear();
			clsScreen::title("Currency Calculator Screen");
			clsCurrency* from = findCurrency(Currencies, "Enter currency for change from: ");
			printCurrency(from);
			clsCurrency* to = findCurrency(Currencies, "Enter currency for change to: ");
			printCurrency(to);
			float amount = ReadRate();
			if (!clsInputValidate::getYesOrNoFromUser("Are you sure for change this amount"))
				std::cout << "operation has cancelled";
			else
				std::cout << amount << " " + from->getCode() << " ---> " << clsCurrency::change(from, to, amount) << " " + to->getCode();
		} while (clsInputValidate::getYesOrNoFromUser("Do you want do change again"));
		clsScreen::pressEnter();
	}
};

