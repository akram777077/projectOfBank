#pragma once
#include"clsClient.h"
#include<fstream>
class clsClients
{
private:
	std::vector<clsClient> _vUsers;
	std::vector<clsClient::stTransfer> _vTransfers;
	std::string _nameOfFile;
	std::string _fileNameTransfers;
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
			if(!i.isDelete())
				myFile << i.convertToLine() << endl;
		}
		myFile.close();
		return 1;
	}
	void addClient(clsClient client)
	{
		_vUsers.push_back(client);

	}
	bool load()
	{
		fstream myFile;
		myFile.open(_nameOfFile, std::ios::in);
		if (!myFile.is_open()) return 0;
		std::string line="";
		while (std::getline(myFile,line))
		{
			_vUsers.push_back(clsClient::lineToData(line));
		}
		myFile.close();
		return 1;
	}
	int length()
	{
		return _vUsers.size();
	}
	clsClient* find(std::string accountNumber)
	{
		for (auto& i : _vUsers)
		{
			if (i.getAccountNumber() == accountNumber)
				return &i;
		}
		return NULL;
	}
	clsClient* find(std::string accountNumber,std::string pinCode)
	{
		for (auto& i : _vUsers)
		{
			if (i.getAccountNumber() == accountNumber && i.getPinCode()==pinCode)
				return &i;
		}
		return NULL;
	}
	std::vector<clsClient> getClients()
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
		return (length() == 0);
	}
	void loadTransfers()
	{
		std::string line = "";
		fstream myFile;
		myFile.open(_fileNameTransfers, std::ios::in);
		if (!myFile.is_open()) return;
		while (std::getline(myFile, line))
		{
			_vTransfers.push_back(*clsClient::stTransfer::lineToTransfer(line));
		}
	}
	std::vector<clsClient::stTransfer> getTransfers()
	{
		return _vTransfers;
	}
	int lengthTransfer()
	{
		return _vTransfers.size();
	}
	void setFileTransfer(std::string fileName)
	{
		_fileNameTransfers = fileName;
	}
};

