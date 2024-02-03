#pragma once
#include"clsScreen.h"
#include"clsCurrencies.h"
#include"F:\programming\my Classes\clsInputValidate.h"
class clsFindCurrency:protected clsScreen
{
private:
	static enum enFindOption
	{
		code = 1,
		country
	};
	static void printCurrency(clsCurrency* target)
	{
		std::cout << "---------------------";
		std::cout << "\nCountry: " << target->getCountry();
		std::cout << "\nCode   : " << target->getCode();
		std::cout << "\nName   : " << target->getName();
		std::cout << "\nRate   : " << target->getRate();
		std::cout << "\n---------------------\n";
	}
	static clsCurrency* findCurrency(clsCurrencies& Currencies,enFindOption option)
	{
		return ((option == enFindOption::code) ? Currencies.findCode(getCode()) : Currencies.findCountry(getCountry()));
	}
	static std::string getCode()
	{
		std::string result = "";
		std::cout << "Enter code: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static std::string getCountry()
	{
		std::string result = "";
		std::cout << "Enter Country: ";
		std::getline(std::cin >> std::ws, result);
		return result;
	}
	static enFindOption getOption()
	{
		std::cout << "Fid by: [1] Code [2] Country: ";
		return (enFindOption)clsInputValidate::ReadIntNumberBetween(1, 2);
	}
	
public:
	static void showFindCurrency(clsCurrencies& Currencies)
	{
		clsScreen::title("Find Currency Screen");
		clsCurrency* target = findCurrency(Currencies, getOption());
		if (!target)
			std::cout << "This currency Not found ...";
		else
			printCurrency(target);
		clsScreen::pressEnter();
	}
};

