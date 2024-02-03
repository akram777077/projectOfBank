#pragma once
#include"clsPerson.h"
#include"F:\programming\my Classes\clsString.h"
#include<vector>
#include<string>
#include"clsUser.h"
class clsClient:public clsPerson
{
private:
    std::string _AccountNumber;
    std::string _PinCode;
    float _AccountBalance;
    bool _markForDelete;
public:
    clsClient(std::string firstName, std::string lastName, std::string phone, std::string email, std::string accountNumber, std::string pinCode, float accountBalance)
        :clsPerson(firstName, lastName, email, phone)
    {
        _AccountNumber = accountNumber;
        _PinCode = pinCode;
        _AccountBalance = accountBalance;
        _markForDelete = 0;
    }
    static struct stTransfer
    {
        std::string accountNumberFrom;
        std::string fullNameFrom;
        float accountBalanceFrom;
        std::string accountNumberTo;
        std::string fullNameTo;
        float accountBalanceTo;
        std::string timeDate;
        std::string user;
        float amount;
        std::string creatLineTransfer()
        {
            std::vector<std::string> vData = {timeDate,accountNumberFrom,accountNumberTo,std::to_string(amount),std::to_string(accountBalanceFrom) ,std::to_string(accountBalanceTo),user};
            return clsString::JoinString(vData, "#//#");
        }
        void saveTransfer(std::string fileName)
        {
            fstream myFile;
            myFile.open(fileName, std::ios::out | std::ios::app);
            if (!myFile.is_open()) return;
            myFile << creatLineTransfer() << std::endl;
            myFile.close();

        }
        static stTransfer* lineToTransfer(std::string line)
        {
            std::vector<std::string>vData = clsString::Split(line, "#//#");
            stTransfer* result = new stTransfer;
            result->timeDate = vData[0];
            result->accountNumberFrom = vData[1];
            result->accountNumberTo = vData[2];
            result->amount = std::stof(vData[3]);
            result->accountBalanceFrom = std::stof(vData[4]);
            result->accountBalanceTo = std::stof(vData[5]);
            result->user = vData[6];
            return result;
        }
    };
    stTransfer *changeToCardTransfer(clsClient *to,clsUser *user,float amount)
    {
        stTransfer *temp=new stTransfer;
        temp->fullNameFrom = getFullName();
        temp->accountNumberFrom = getAccountNumber();
        temp->accountBalanceFrom = getAccountBalance();
        temp->fullNameTo = to->getFullName();
        temp->accountNumberTo = to->getAccountNumber();
        temp->accountBalanceTo = to->getAccountBalance();
        temp->user = user->getUserName();
        temp->timeDate = clsDate::TimeDateLineSystem();
        temp->amount = amount;
        return temp;
    }
    bool isDelete()
    {
        return _markForDelete;
    }
    void markDelete()
    {
        _markForDelete = 1;
    }
    std::string convertToLine()
    {
        std::vector<std::string> vData = { getFirstName(),getLastName(),getPhone(),getEmail(),_AccountNumber,_PinCode,std::to_string(_AccountBalance) };
        return clsString::JoinString(vData, "#//#");
    }
    static clsClient lineToData(std::string line)
    {
        std::vector<std::string> vData = clsString::Split(line, "#//#");
        return clsClient(vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], std::stof(vData[6]));
    }
    void setPinCode(std::string pinCode)
    {
        _PinCode = pinCode;
    }
    void setAccountBalance(float balance)
    {
        _AccountBalance = balance;
    }
    std::string getAccountNumber()
    {
        return _AccountNumber;
    }
    std::string getPinCode()
    {
        return _PinCode;
    }
    float getAccountBalance()
    {
        return _AccountBalance;
    }
    void deposit(float amount)
    {
        _AccountBalance += amount;
    }
    void withDraw(float amount)
    {
        _AccountBalance -= amount;
    }
};
