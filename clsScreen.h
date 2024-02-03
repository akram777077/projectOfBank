#pragma once
#include<iostream>
#include"F:\programming\my Classes\clsDate.h"
#include"clsUserNameString.h"
class clsScreen
{
private:
public:
	static void title(std::string firstTitle, std::string secondTitle="", bool isUser = 0)
	{
		std::cout << "\t\t\t=======================================================";
		std::cout << "\n\t\t\t\t\t" + firstTitle;
		if(secondTitle!="")
			std::cout << "\n\t\t\t\t\t\t\t"<< secondTitle;
		std::cout << "\n\t\t\t=======================================================\n";
		std::cout << "\t\t\t" << clsDate::GetSystemDate().DateToString();
		if (UserNameOwned != "")
			std::cout << "\t\t\t\tUser: " << UserNameOwned;
		std::cout << "\n";
	}
	static void line()
	{
		std::cout << "\n\t\t\t=======================================================\n";
	}
	static void clear()
	{
		system("cls");
	}
	static void pressEnter()
	{
		std::cout << "\npress enter to continue....\n";
		system("pause>0");
	}
	static bool NotAllowAndEmpty(bool testPermission=0,bool empty=0)
	{
		if (!testPermission)
		{
			title("Access Denied\n\t\t\tYou don't have Permission To Do this Please Contact your admin..");
			pressEnter();
		}
		else if(empty)
		{
			title("List is empty\n\t\t\tYou don't can do this operation please add items in system.");
			pressEnter();
			return 0;
		}
		return testPermission;
	}
};


