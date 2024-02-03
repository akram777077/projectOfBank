#pragma once
#include"clsScreen.h"
#include"clsClients.h"
#include <iomanip>
class clsTransferLog :protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 97; i++)
            line += '-';
        return line;
    }
    static void head()
    {
        std::cout << "\t" + lineTable();
        std::cout << "\n\t|" << std::setw(20) << std::left << " Date-time"
            << "|";
        std::cout << std::setw(10) << std::left << " From"
            << "|";
        std::cout << std::setw(10) << std::left << " To"
            << "|";
        std::cout << std::setw(10) << std::left << " Amount"
            << "|";
        std::cout << std::setw(15) << std::left << " From Balance"
            << "|";
        std::cout << std::setw(14) << std::left << " To Balance"
            << "|";
        std::cout << std::setw(10) << std::left << " User"
            << "|\n";
        std::cout << "\t" + lineTable();

    }
    static void printClients(clsClients* listClients)
    {
        clsScreen::title("transfer register List Screen", std::to_string(listClients->lengthTransfer()) + " Record(s)");
        head();
        std::cout << "\n";
        for (auto& ptr : listClients->getTransfers())
        {
            std::cout << "\t|" << std::setw(20) << std::left << ptr.timeDate;
            std::cout << "|" << std::setw(10) << std::left << ptr.accountNumberFrom;
            std::cout << "|" << std::setw(10) << std::left << ptr.accountNumberTo;
            std::cout << "|" << std::setw(10) << std::left << ptr.amount;
            std::cout << "|" << std::setw(15) << std::left << ptr.accountBalanceFrom;
            std::cout << "|" << std::setw(14) << std::left << ptr.accountBalanceTo;
            std::cout << "|" << std::left << std::setw(10) << ptr.user << "|\n";
        }
        std::cout <<  "\t"+lineTable();
    }
public:
    static void showTransferRecord(std::string fileTransfer,clsClients &clients)
    {
        clients.setFileTransfer(fileTransfer);
        clients.loadTransfers();
        printClients(&clients);
    }
};

