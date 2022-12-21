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
	HangHoa(string, int, long,long);
	void show();
	void show_gianhap();
	int Getsoluong();
	void Setsoluong(int);
	long Getgiaban();
	void Setgiaban(long);
	string Gettensp();
	void Setgianhap(long);
	long Getgianhap();
	friend long Getgianhap1(List <HangHoa>, string);
	friend bool checksoluong(List<HangHoa>, string, int);
	friend istream& operator >> (istream& in, HangHoa& a);
	friend int LinearSearch(List<HangHoa>, string);
	friend void ChangeSoluong(List<HangHoa>&, string, int);
	friend long Getgiaban1(List<HangHoa>, string);
	friend bool check(List <HangHoa>, string);
	void ghiFile(List<HangHoa> l);
	void docFile(List<HangHoa> &l);
	friend long long chiphinhapkho(List<HangHoa>&);
};

#endif // !Hanghoa_H




