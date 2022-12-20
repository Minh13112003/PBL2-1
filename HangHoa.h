#pragma once
#ifndef Hanghoa_H
#define Hanghoa_H
#include "DSLK.H"
#include "KhachHang.h"
#include "Mylib.h"
using namespace std;

class HangHoa {
protected:
	string tensp;
	int soluong;
	long giaban;
	static int a;
	long gianhap;
public:
	HangHoa();
	HangHoa(string, int, long);
	void show();
	int Getsoluong();
	void Setsoluong(int);
	long Getgiaban();
	void Setgiaban(long);
	string Gettensp();
	friend bool checksoluong(List<HangHoa>, string, int);
	friend istream& operator >> (istream& in, HangHoa& a);
	friend int LinearSearch(List<HangHoa>, string);
	friend void ChangeSoluong(List<HangHoa>&, string, int);
	friend long Getgiaban1(List<HangHoa>, string);
	void ghiFile(List<HangHoa> l);
	void docFile(List<HangHoa> &l);


};

#endif // !Hanghoa_H




