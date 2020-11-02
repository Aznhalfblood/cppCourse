#pragma once
#include<string>
#include<fstream>
#include<iostream>


class Telephone
{
	std::string model;
	std::string number;
	std::string last_called_number;
	double score;


public:

	Telephone();
	Telephone(std::string mod, std::string num, std::string lcn, double sc);
	void setModel(std::string mod);
	void setNumber(std::string num);
	void setLCN(std::string lcn);
	void setScore(double sc);
	std::string getNumber();
	void call(std::string num, double minutes);
	void serialize();
	void deserialize();
	void serialize(const std::string& filename);
	void deserialize(const std::string& filename);
	friend std::ostream& operator<<(std::ostream& out, const Telephone& tel);
};

