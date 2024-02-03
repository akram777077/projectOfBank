#pragma once
#include"clsScreen.h"
#include"clsCurrencies.h"
#include <iomanip>
class clsListCurrencies :protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 105; i++)
            line += '-';
        return line;
    }
    static void head()
    {
        std::cout << "\t" + lineTable();
        std::cout << "\n\t|" << std::setw(30) << std::left << " Country"
            << "|";
        std::cout << std::setw(17) << std::left << " Code"
            << "|";
        std::cout << std::setw(40) << std::left << "     Name"
            << "|";
        std::cout << std::setw(13) << std::left << " Rate(1$)"
            << "|\n";
        std::cout << "\t" + lineTable();

    }
    static void printCurrencies(clsCurrencies* currencies)
    {
        clsScreen::title("currencies List Screen", std::to_string(currencies->length()) + " Record(s)");
        head();
        std::cout << "\n";
        for (auto& ptr : currencies->getCurrencies())
        {
            std::cout << "\t|" << std::setw(30) << std::left << ptr.getCountry() << "";
            std::cout << "|" << std::setw(17) << std::left << ptr.getCode() << "|";
            std::cout << std::setw(40) << std::left << ptr.getName() << "|";
            std::cout << std::left << std::setw(13) << ptr.getRate() << "|\n";
        }
        std::cout << "\t" + lineTable();
    }
public:
    static void showListCurrencies(clsCurrencies &currencies)
    {
        printCurrencies(&currencies);
        clsScreen::pressEnter();
    }
};
