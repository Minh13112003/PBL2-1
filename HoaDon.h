#pragma once
#ifndef HoaDon_H
#define HoaDon_H
#include "KhachHang.h"
#include "Hanghoa.h"
using namespace std;

class HoaDon :public KhachHang, public HangHoa {
	static int count;
	long tongtien;
public:
	HoaDon();
	void Input(List<HangHoa>&, List<HangHoa>&);
	void show(List <HangHoa>);
	friend void Search(List<HoaDon>, List<List<HangHoa>>);
	void capnhatdulieu();

};


#endif // !HoaDon_H


