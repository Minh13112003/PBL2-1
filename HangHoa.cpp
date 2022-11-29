#include "HangHoa.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int HangHoa::a = 1;

HangHoa::HangHoa() {
	this->tensp = " ";
	this->soluong = 0;
	this->giaban = 0;
}

HangHoa::HangHoa(string tensp,int soluong,float giaban) {
	this->tensp = tensp;
	this->soluong = soluong;
	this->giaban = giaban;
}
istream& operator >> (istream& in, HangHoa& a) {
	cout << "nhap ten sp: "; 
	getline(in,a.tensp);
	cout << "nhap so luong: ";
	in >> a.soluong;
	cout << "nhap gia ban: ";
	in >> a.giaban;
	cin.ignore();
	return in;
}

void HangHoa::show() {
	cout << a++ << ": " << setw(15)  << tensp << right << setw(15) << soluong << right << setw(15) << giaban << endl;
}