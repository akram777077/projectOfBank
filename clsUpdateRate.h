#pragma once
#include"clsScreen.h"
#include"clsCurrencies.h"
#include"F:\programming\my Classes\clsInputValidate.h"
#include<limits>
class clsUpdateRate :protected clsScreen
{
private:
	static float ReadRate()
	{
		return clsInputValidate::readNumberFloat("Enter new rate: ", 0, std::numeric_limits<float>::max(), "Enter valid rate please: ");
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
	static clsCurrency* findCurrency(clsCurrencies& Currencies)
	{
		return Currencies.findCode(getCode());
	}
	static std::string getCode()
	{
		std::string result = "";
		std::cout << "Enter code: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}

public:
	static void showUpdateRate(clsCurrencies& Currencies)
	{
		clsScreen::title("Update Rate Screen");
		clsCurrency* target = findCurrency(Currencies);
		if (!target)
			std::cout << "This currency Not found ...";
		else
		{
			printCurrency(target);
			if(!clsInputValidate::getYesOrNoFromUser("Are you sure for update this Rate"))
				std::cout<<"operation has cancelled";
			else
			{
				target->setRate(ReadRate());
				Currencies.reload();
				clsScreen::clear();
				std::cout << "Currency update successfully\n";
				printCurrency(target);
			}

		}
		clsScreen::pressEnter();
	}
};


