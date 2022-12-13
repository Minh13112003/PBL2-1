#include <iomanip>
#include <iostream>
#include "HoaDon.h"
#include <string>

using namespace std;

int HoaDon::count = 1;


HoaDon::HoaDon() {
	this->tongtien = 0;
}

void HoaDon::Input(List<HangHoa>& a, List <HangHoa>& b) {
	cin.ignore();
	cout << "nhap id khach hang: ";
	cin >> this->id;
	cout << "nhap so tien khach gui: ";
	cin >> this->tiengui;
	bool e = 1;
	while (e == 1) {
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != 1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			cin.ignore();
			ChangeSoluong(a, this->tensp, this->soluong);
			this->giaban = this->soluong * Getgiaban(a, tensp);
			tongtien += this->giaban;
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
			cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
			cin >> e;
		}
	}
}


void HoaDon::show( List <HangHoa> b) {
	Node <HangHoa>* c = b.GetHead();
	cout << "-------------------HoaDon cua khach hang: " << this->id << "----------------------" << endl;
	while (c != NULL) {
		c->data.show();
		c = c->Next;
	}
	cout << "-------------------------------------------------------------------------";
	cout << "Tong tien: " << right << setw(45) << this->tongtien<< endl;
	cout << "Tien khach gui: " << right << setw(45) << this->tiengui << endl;
	cout << "So tien tra lai: " << right << setw(45) << tiengui - tongtien;

}
