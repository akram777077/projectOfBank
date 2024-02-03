#include<iostream>
#include"F:\programming\vs\projectOfBank\clsScreenMain.h"
#include"clsLoginScreen.h"
int main()
{
	clsLoginScreen::loginSystem("clients.txt", "users.txt","login.txt","transfer.txt","exchange.txt");
	return 0;
}