#pragma once
#include <string>

#ifndef Hanghoa_H
#define Hanghoa_H

using namespace std;

class HangHoa {
protected:
	string tensp;
	int soluong;
	float giaban;
	static int a;
public:
	HangHoa();
	HangHoa(string, int, float);
	void show();
	friend istream& operator >> (istream& in, HangHoa& a);
};

#endif // !Hanghoa_H



