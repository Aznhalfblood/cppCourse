#pragma once

class IShufle {
protected:
	virtual void shufle() = 0;
	virtual void shufle(size_t i, size_t j) = 0;
};