#pragma once
#include"clsCurrency.h"
#include<fstream>
class clsCurrencies
{
private:
	std::vector<clsCurrency> _currencies;
	std::string _fileOfCurrencies;
public:
	void setFileName(std::string fileName)
	{
		_fileOfCurrencies = fileName;
	}
	void save()
	{
		fstream myFile;
		myFile.open(_fileOfCurrencies, std::ios::out);
		if (!myFile.is_open()) return;
		for (auto& i : _currencies)
			myFile << i.ToLine() << std::endl;
		myFile.close();
	}
	void load()
	{
		fstream myFile;
		myFile.open(_fileOfCurrencies, std::ios::in);
		if (!myFile.is_open()) return;
		std::string line = "";
		while (getline(myFile, line))
		{
			_currencies.push_back(clsCurrency::fromLine(line));
		}
	}
	void reload()
	{
		save();
		_currencies.clear();
		load();
	}
	clsCurrency* findCode(std::string code)
	{
		code = clsString::UpperAllString(code);
		for (auto& i : _currencies)
		{
			if (i.getCode() == code) return &i;
		}
		return nullptr;
	}
	clsCurrency* findCountry(std::string Country)
	{
		Country = clsString::UpperAllString(Country);
		for (auto& i : _currencies)
		{
			if (clsString::UpperAllString(i.getCountry()) == Country) return &i;
		}
		return nullptr;
	}
	int length()
	{
		return _currencies.size();
	}
	std::vector<clsCurrency> getCurrencies()
	{
		return _currencies;
	}
};

