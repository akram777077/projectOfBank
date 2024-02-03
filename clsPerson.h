#pragma once
#include<iostream>
class clsPerson
{
private:
    std::string _FirstName;
    std::string _LastName;
    std::string _Email;
    std::string _Phone;
public:
    clsPerson()
    {
        _FirstName = "";
        _LastName = "";
        _Email = "";
        _Phone = "";
    }
    clsPerson(std::string firstName, std::string lastName, std::string email, std::string phone)
    {
        _FirstName = firstName;
        _LastName = lastName;
        _Email = email;
        _Phone = phone;
    }
    void setFirstName(std::string firstName)
    {
        _FirstName = firstName;
    }
    void setLastName(std::string lastName)
    {
        _LastName = lastName;
    }
    void setEmail(std::string email)
    {
        _Email = email;
    }
    void setPhone(std::string phone)
    {
        _Phone = phone;
    }
    std::string getFirstName()
    {
        return _FirstName;
    }
    std::string getLastName()
    {
        return _LastName;
    }
    std::string getEmail()
    {
        return _Email;
    }
    std::string getPhone()
    {
        return _Phone;
    }
    std::string getFullName()
    {
        return _FirstName + " " + _LastName;
    }
};

