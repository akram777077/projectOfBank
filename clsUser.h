#pragma once
#include"clsPerson.h"
#include"F:\programming\my Classes\clsString.h"
#include<vector>
#include"F:/programming/my Classes/clsUtil.h"
#include<string>
class clsUser :public clsPerson
{
private:
    std::string _UserName;
    std::string _password;
    short _Permissions;
    bool _markForDelete;
    std::string _fileLogin;
    std::string _TimeDateLogin;
    std::string _lineLogin()
    {
        std::string sDate = clsDate::GetSystemDate().DateToString() + "-" + clsDate::GetSystemTime().DateToString(":");
        std::vector<std::string> vData = { sDate,this->getUserName(),this->getPassword(),std::to_string(this->getPermissions()) };
        return clsString::JoinString(vData, "#//#");
    }
public:
    enum enPermissions
    {
        PermessionShowClientsList = 0b1,
        PermessionAddNewClients = 0b10,
        PermessionDeleteClient = 0b100,
        PermessionUpdateClient = 0b1000,
        PermessionFindClient = 0b10000,
        PermessionTransaction = 0b100000,
        PermessionManageUsers = 0b1000000,
        PermessionLoginRegister = 0b10000000
    };
    clsUser()
    {
        _UserName = "";
        _password = "";
        _Permissions = 0;
        _markForDelete = 0;
        _fileLogin = "";
        _TimeDateLogin = "";
    }
    clsUser(std::string firstName, std::string lastName, std::string phone, std::string email, std::string userName, std::string password, int permissions,std::string dateTime="")
        :clsPerson(firstName, lastName, email, phone)
    {
        _UserName = userName;
        _password = password;
        _Permissions = permissions;
        _markForDelete = 0;
        _fileLogin = "";
        _TimeDateLogin = dateTime;
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
        std::vector<std::string> vData = { getFirstName(),getLastName(),getPhone(),getEmail(),_UserName,clsUtil::EncryptText(_password,777),std::to_string(_Permissions)};
        return clsString::JoinString(vData, "#//#");
    }
    static clsUser lineToData(std::string line)
    {
        std::vector<std::string> vData = clsString::Split(line, "#//#");
        return clsUser(vData[0], vData[1], vData[2], vData[3], vData[4], clsUtil::DecryptText(vData[5],777), std::stoi(vData[6]));
    }
    void setPassword(std::string password)
    {
        _password = password;
    }
    void setPermissions(int permissions)
    {
        _Permissions = permissions;
    }
    std::string getUserName()
    {
        return _UserName;
    }
    std::string getPassword()
    {
        return _password;
    }
    float getPermissions()
    {
        return _Permissions;
    }
    void addPermissions(enPermissions permission)
    {
        _Permissions |= (short)permission;
    }
    bool isHavePermission(enPermissions permission)
    {
        return ((_Permissions & (short)permission) == (short)permission);
    }
    void saveLogin()
    {
        std::fstream myFile;
        myFile.open(_fileLogin, std::ios::out | std::ios::app);
        if (!myFile.is_open()) return;
        myFile << _lineLogin() << std::endl;
        myFile.close();
    }
    void setFileLogin(std::string fileName)
    {
        _fileLogin = fileName;
    }
    static clsUser lineToUserRegister(std::string line)
    {
        std::vector<std::string> vData=clsString::Split(line, "#//#");
        return clsUser("","","","",vData[1],vData[2],stoi(vData[3]),vData[0]);
    }
    std::string getDateTime()
    {
        return _TimeDateLogin;
    }
};
