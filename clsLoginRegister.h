#pragma once
#include"clsScreen.h"
#include"clsUsers.h"
#include <iomanip>
class clsLoginRegister :protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 83; i++)
            line += '-';
        return line;
    }
    static void head()
    {
        std::cout << "\t" + lineTable();
        std::cout << "\n\t|" << std::setw(30) << std::left << " Date-time"
            << "|";
        std::cout << std::setw(17) << std::left << " User Name"
            << "|";
        std::cout << std::setw(18) << std::left << "     Password"
            << "|";
        std::cout << std::setw(13) << std::left << " Permissions"
            << "|\n";
        std::cout <<"\t"+ lineTable();

    }
    static void printClients(clsUsers* listUsers)
    {
        clsScreen::title("login register List Screen",std::to_string(listUsers->lengthRegister()) + " Record(s)");
        head();
        std::cout << "\n";
        for (auto& ptr : listUsers->getRegister())
        {
            std::cout << "\t|" << std::setw(30) << std::left << ptr.getDateTime() << "";
            std::cout << "|" << std::setw(17) << std::left << ptr.getUserName() << "|";
            std::cout << std::setw(18) << std::left << ptr.getPassword() << "|";
            std::cout << std::left << std::setw(13) << ptr.getPermissions() << "|\n";
        }
        std::cout << "\t" + lineTable();
    }
public:
    static void showClientsScreen(std::string fileLogin)
    {
        clsUsers Users;
        Users.setFileRegister(fileLogin);
        Users.loadRegister();
        printClients(&Users);
        clsScreen::pressEnter();
    }
};

