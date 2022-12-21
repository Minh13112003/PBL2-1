#pragma once
#ifndef HoaDon_H
#define HoaDon_H
#include "KhachHang.h"
#include "Hanghoa.h"
using namespace std;

class HoaDon :public KhachHang, public HangHoa {
	static int count;
	long tongtien;
	long tongtiennhap;
	List <HangHoa> HD;
public:
	string getid();
	HoaDon();
	void Input(List<HangHoa>&);
	void show();
	void output();
	friend void show_gianhap(List <HoaDon> &,List <HangHoa> );

};


#endif // !HoaDon_H


