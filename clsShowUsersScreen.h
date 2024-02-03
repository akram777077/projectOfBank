#pragma once
#include"clsScreen.h"
#include"clsUsers.h"
#include <iomanip>
class clsShowUsersScreen :protected clsScreen
{
private:
    static std::string lineTable()
    {
        std::string line = "";
        for (short i = 0; i < 116; i++)
            line += '-';
        return line;
    }
    static void head()
    {
        std::cout << lineTable();
        std::cout << "\n|" << std::setw(17) << std::left << " User Name"
            << "|";
        std::cout << std::setw(18) << std::left << "     Password"
            << "|";
        std::cout << std::setw(25) << std::left << "       Full Name"
            << "|";
        std::cout << std::setw(11) << std::left << "  Phone"
            << "|";
        std::cout << std::setw(25) << std::left << "         Email"
            << "|";
        std::cout << std::setw(13) << std::left << " Permissions"
            << "|\n";
        std::cout << lineTable();

    }
    static void printClients(clsUsers* listUsers)
    {
        std::string line = "users list(" + std::to_string(listUsers->length()) + ") User(s)\n";
        clsScreen::title(line);
        head();
        std::cout << "\n";
        for (auto &ptr : listUsers->getUsers())
        {
            std::cout << "|" << std::setw(17) << std::left << ptr.getUserName() << "|";
            std::cout << std::setw(18) << std::left << ptr.getPassword() << "|";
            std::cout << std::setw(25) << std::left << ptr.getFullName() << "|";
            std::cout << std::setw(11) << std::left << ptr.getPhone() << "|";
            std::cout << std::setw(25) << std::left << ptr.getEmail() << "|";
            std::cout << std::left << std::setw(13) << ptr.getPermissions() << "|\n";
        }
        std::cout << lineTable();
    }
public:
    static void showClientsScreen(clsUsers* Users)
    {
        printClients(Users);
        clsScreen::pressEnter();
    }
};

