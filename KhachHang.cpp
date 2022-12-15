#include "KhachHang.h"
KhachHang::KhachHang() {
	this->ngay = "00/00/00";
	this->thoigian = "00:00:00";
	this->id = " ";
	this->tiengui = 0;
}
void KhachHang::SetUpDate() {
	cout << "nhap thoi gian: ";
	cin >> this->thoigian;
	cout << "nhap ngay: ";
	cin >> this->ngay;
}

void KhachHang::PrintDate() {
	cout << "ngay: " << this->ngay << endl;
	cout << "thoi gian: " << this->thoigian << endl;
}

istream& operator >> (istream& in, KhachHang& a) {
	cout << "nhap id khach: ";
	in >> a.id;
	in.ignore();
	a.SetUpDate();
	return in;
}

void KhachHang::show() {
	cout << setw(6) << "Khach hang: " << this->id << endl;
	PrintDate();
}
