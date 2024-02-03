#pragma once
#include"clsScreen.h"
#include"clsClients.h"
#include<vector>
#include <iomanip>
class clsTotalBalances :protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 69; i++)
            line += '-';
        return line;
    }
    static void head()
    {
        std::cout << "\t\t" << lineTable();
        std::cout << "\n\t\t|" << std::setw(20) << std::left << " Account number"
            << "|";
        std::cout << std::setw(25) << std::left << "       Client Name"
            << "|";
        std::cout << std::setw(20) << std::left << " Balance"
            << "|\n";
        std::cout << "\t\t" << lineTable();

    }
    static void printClients(clsClients* listClients)
    {
        double total = 0;
        std::string line = "Clients list(" + std::to_string(listClients->length()) + ") client(s)\n";
        clsScreen::title(line);
        head();
        std::cout << "\n";
        for (clsClient& ptr : listClients->getClients())
        {
            std::cout << "\t\t|" << std::setw(20) << std::left << ptr.getAccountNumber() << "|";
            std::cout << std::setw(25) << std::left << ptr.getFullName() << "|";
            std::cout << std::left << std::setw(20) << ptr.getAccountBalance() << "|\n";
            total += ptr.getAccountBalance();
        }
        std::cout << "\t\t" << lineTable();
        std::cout << "\n\t\t\t\tTotal balances is: " << total << " $";
    }
public:
    static void showTotalBalances(clsClients* clients)
    {
        printClients(clients);
    }
};

