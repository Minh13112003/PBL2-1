#pragma once
#ifndef Date_H
#define Date_H
#include <string>
using namespace std;
class Date {
protected:
	string ngay;
	string thoigian;
public:
	virtual void SetUpDate() = 0;
	virtual void PrintDate() = 0;
	virtual ~Date();
};
#endif // !Date_H

