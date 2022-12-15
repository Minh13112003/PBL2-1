#pragma once
#ifndef Date_H
#define Date_H
#include "Mylib.h"
class Date {
protected:
	string ngay;
	string thoigian;
public:
	virtual void SetUpDate() = 0;
	virtual void PrintDate() = 0;
};
#endif // !Date_H

