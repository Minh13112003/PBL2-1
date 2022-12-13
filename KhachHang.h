
#pragma once
#ifndef KhachHang_H
#define KhachHang_H
#include <string>
#include "Date.h"
using namespace std;
class KhachHang : public Date{
protected:
	string id;
	float tiengui;
public:
	KhachHang();
	~KhachHang(){}
	friend istream& operator >> (istream&, KhachHang&);
	void show();
	virtual void PrintDate();
	virtual void SetUpDate();
};

#endif // !KhachHang_H


