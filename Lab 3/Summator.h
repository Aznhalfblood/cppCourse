#pragma once
#include "ExpEval.h"

class Summator :
	public ExpEval
{
public:
	Summator();
	Summator(int n);
	virtual double calculate();
	virtual void logToScreen();
	virtual void logToFile(const std::string& fileName);
};

