#pragma once
#ifndef KhachHang_H
#define KhachHang_H
#include "Date.h"
class KhachHang : public Date {
protected:
	string id;
	long tiengui;
public:
	KhachHang();
	~KhachHang() {}
	friend istream& operator >> (istream&, KhachHang&);
	void show();
	virtual void PrintDate();
	virtual void SetUpDate();
};

#endif // !KhachHang_H



