#pragma once
#ifndef HoaDon_H
#define HoaDon_H
#include "KhachHang.h"
#include "Hanghoa.h"
#include "DSLK.cpp"
#include <string>

using namespace std;

class HoaDon :public KhachHang,public HangHoa{
	static int count;
public:
	void Input(List<HangHoa> &);
	void show();
	void capnhatdulieu();

};

#endif // !HoaDon_H

