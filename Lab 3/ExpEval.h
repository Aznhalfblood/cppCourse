#pragma once
#include "Iloggable.h"


class ExpEval :
	public ILoggable
{
protected:
	int operandCount;
	double *values;

public:
	
	ExpEval();
	ExpEval(int n);
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);

	virtual ~ExpEval() {
		delete[] values;
	}

	virtual double calculate() = 0;


};

