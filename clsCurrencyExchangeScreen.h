#pragma once
#include"F:\programming\my Classes\clsInputValidate.h"
#include"clsScreen.h"
#include"clsListCurrencies.h"
#include"clsFindCurrency.h"
#include"clsUpdateRate.h"
#include"clscurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :protected clsScreen
{
private:
	enum enOption
	{
		Listcurrencies = 1,
		Findcurrency,
		UpdateRate,
		currencyCalculator,
		mainMenu
	};
	static void ExchangeScreen()
	{
		clsScreen::title("Currency Exchange Screen");
		std::cout << "\t\t\t\t[1] List currencies.\n";
		std::cout << "\t\t\t\t[2] Find currency.\n";
		std::cout << "\t\t\t\t[3] Update rate.\n";
		std::cout << "\t\t\t\t[4] currency calculator.\n";
		std::cout << "\t\t\t\t[5] main menu.\n";
		clsScreen::line();
	}
	static enOption getOption()
	{

		enOption temp = (enOption)clsInputValidate::readNumber("\t\t\t\t-> Enter option: ", 1, 5, "\t\t\t\tplease enter a valid option");
		clsScreen::clear();
		return temp;
	}
	static void optionSelect(std::string file)
	{
		clsCurrencies Currencies;
		Currencies.setFileName(file);
		Currencies.load();
		do
		{
			clsScreen::clear();
			ExchangeScreen();
			switch ((enOption)getOption())
			{
			case enOption::Listcurrencies:
				clsListCurrencies::showListCurrencies(Currencies);
				break;
			case enOption::Findcurrency:
				clsFindCurrency::showFindCurrency(Currencies);
				break;
			case enOption::UpdateRate:
				clsUpdateRate::showUpdateRate(Currencies);
				break;
			case enOption::currencyCalculator:
				clsCurrencyCalculatorScreen::showCurrencyCalculator(Currencies);
				break;
			case enOption::mainMenu:
				return;
			}
		} while (1);
	}
public:
	static void showExchangeScreen(std::string fileExchange)
	{
		clsScreen::clear();
		optionSelect(fileExchange);
	}
};

