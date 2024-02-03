#pragma once
#include"clsUser.h"
#include<fstream>
class clsUsers
{
private:
	std::vector<clsUser> _vUsers;
	std::vector<clsUser> _vUsersRegister;
	std::string _nameOfFile;
	std::string _nameOfFileRegister;
public:
	void setNameFile(std::string nameFile)
	{
		_nameOfFile = nameFile;
	}
	bool save()
	{
		fstream myFile;
		myFile.open(_nameOfFile, std::ios::out);
		if (!myFile.is_open()) return 0;
		for (auto& i : _vUsers)
		{
			if (!i.isDelete())
				myFile << i.convertToLine() << endl;
		}
		myFile.close();
		return 1;
	}
	void addUser(clsUser user)
	{
		_vUsers.push_back(user);

	}
	bool load()
	{
		fstream myFile;
		myFile.open(_nameOfFile, std::ios::in);
		if (!myFile.is_open()) return 0;
		std::string line = "";
		while (std::getline(myFile,line)) // here : while (myFile>>line)
		{
			clsUser temp = clsUser::lineToData(line);
			_vUsers.push_back(temp);
		}
		myFile.close();
		return 1;
	}
	int length()
	{
		return _vUsers.size();
	}
	clsUser* find(std::string userName)
	{
		for (auto& i : _vUsers)
		{
			if (i.getUserName() == userName)
				return &i;
		}
		return nullptr;
	}
	clsUser* find(std::string userName, std::string password)
	{
		for (auto& i : _vUsers)
		{
			if (i.getUserName() == userName && i.getPassword() == password)
				return &i;
		}
		return nullptr;
	}
	std::vector<clsUser> getUsers()
	{
		return _vUsers;
	}
	void restart()
	{
		_vUsers.clear();
	}
	void reload()
	{
		save();
		restart();
		load();
	}
	bool isEmpty()
	{
		return (getUsers().size() == 0);
	}
	int lengthRegister()
	{
		return _vUsersRegister.size();
	}
	std::vector<clsUser> getRegister()
	{
		return _vUsersRegister;
	}
	void setFileRegister(std::string fileName)
	{
		_nameOfFileRegister = fileName;
	}
	bool loadRegister()
	{
		fstream myFile;
		myFile.open(_nameOfFileRegister, std::ios::in);
		if (!myFile.is_open()) return 0;
		std::string line = "";
		while (std::getline(myFile, line))
		{
			clsUser temp = clsUser::lineToUserRegister(line);
			_vUsersRegister.push_back(temp);
		}
		myFile.close();
		return 1;
	}
};
