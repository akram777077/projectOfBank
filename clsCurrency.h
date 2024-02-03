#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"F:\programming\my Classes\clsString.h"
class clsCurrency
{
private:
	std::string _country;
	std::string _code;
	std::string _name;
	float _rate;
public:
	clsCurrency(std::string country, std::string code, std::string name, float rate)
	{
		_country = country;
		_code = code;
		_name = name;
		_rate = rate;
	}
	void setRate(float rate)
	{
		_rate = rate;
	}
	float getRate()
	{
		return _rate;
	}
	std::string getCountry()
	{
		return _country;
	}
	std::string getCode()
	{
		return _code;
	}
	std::string getName()
	{
		return _name;
	}
	std::string ToLine()
	{
		std::vector<std::string> vData = { _country,_code,_name,std::to_string(_rate) };
		return clsString::JoinString(vData, "#//#");
	}
	static clsCurrency fromLine(std::string line)
	{
		std::vector<std::string> vData = clsString::Split(line, "#//#");
		return clsCurrency(vData[0], vData[1], vData[2], std::stof(vData[3]));
	}
	static float change(clsCurrency* from, clsCurrency* to, float amount)
	{
		if (to->getCode() == "usd")
			return amount / from->getRate();
		return (amount / from->getRate()) * to->getRate();
	}
};

