#include "ExpEval.h"
#include<assert.h>


ExpEval::ExpEval() {
	operandCount = 20;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

ExpEval::ExpEval(int n) {
	operandCount = n;
	values = new double[operandCount];
	for (int k = 0; k < operandCount; ++k)
		values[k] = 0;
}

void ExpEval::setOperand(size_t pos, double value) {
	assert(pos >= 0 and pos < operandCount);
	values[pos] = value;
}

void ExpEval::setOperands(double ops[], size_t n) {
	assert(n > 0 and n <= operandCount);
	for (int k = 0; k < n; ++k)
		values[k] = ops[k];
}
