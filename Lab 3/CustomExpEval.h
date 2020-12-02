#pragma once
#include "ExpEval.h"
#include "IShufle.h"

class CustomExpEval :
	public ExpEval, IShufle
{
public:
	CustomExpEval();
	CustomExpEval(int n);
	virtual double calculate();
	virtual void shufle();
	virtual void shufle(size_t i, size_t j);
	virtual void logToScreen();
	virtual void logToFile(const std::string& fileName);
};


