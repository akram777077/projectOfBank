#pragma once
#include"clsScreen.h"
#include"clsClients.h"
#include<vector>
#include <iomanip>
class clsShowClientsScreen:protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 114; i++)
            line+= '-';
        return line;
    }
    static void head()
    {
        std::cout << lineTable();
        std::cout << "\n|" << std::setw(17) << std::left << " Account number"
            << "|";
        std::cout << std::setw(18) << std::left << "     Pin Code"
            << "|";
        std::cout << std::setw(25) << std::left << "       Client Name"
            << "|";
        std::cout << std::setw(11) << std::left << "  Phone"
            << "|";
        std::cout << std::setw(25) << std::left << "         Email"
            << "|";
        std::cout << std::setw(11) << std::left << " Balance"
            << "|\n";
        std::cout << lineTable();

    }
    static void printClients(clsClients* listClients)
    {
        std::string line = "Clients list(" + std::to_string(listClients->length()) + ") client(s)\n";
        clsScreen::title(line);
        head();
        std::cout << "\n";
        for (clsClient& ptr : listClients->getClients())
        {
            std::cout << "|" << std::setw(17) << std::left << ptr.getAccountNumber() << "|";
            std::cout << std::setw(18) << std::left << ptr.getPinCode() << "|";
            std::cout << std::setw(25) << std::left << ptr.getFullName() << "|";
            std::cout << std::setw(11) << std::left << ptr.getPhone() << "|";
            std::cout << std::setw(25) << std::left << ptr.getEmail() << "|";
            std::cout << std::left << std::setw(11) << ptr.getAccountBalance() << "|\n";
        }
        std::cout << lineTable();
    }
public:
    static void showClientsScreen(clsClients* clients)
    {
        printClients(clients);
        clsScreen::pressEnter();
    }
};

