#pragma once
#include "ExpEval.h"
#include<string>


class Multiplier :
	public ExpEval
{
public:
	Multiplier();
	Multiplier(int n);
	virtual double calculate();
	virtual void logToScreen();
	virtual void logToFile(const std::string& fileName);
};

