#pragma once
#include <string>

#ifndef Hanghoa_H
#define Hanghoa_H
#include "DSLK.H"
#include "KhachHang.h"
using namespace std;

class HangHoa {
protected:
	string tensp;
	int soluong;
	float giaban;
	int a;
public:
	HangHoa();
	HangHoa(string, int, float);
	//void Input(List<HangHoa>&,List<HangHoa>&);
	void show();
	friend istream& operator >> (istream& in, HangHoa& a);
	friend int LinearSearch(List<HangHoa>, string);
	friend void ChangeSoluong(List<HangHoa>&,string,int);
	friend float Getgiaban(List<HangHoa>, string);
};

#endif // !Hanghoa_H



