
#include <iostream>
#include "HoaDon.h"
#include <string>

using namespace std;

int HoaDon::count = 1;


void HoaDon::Input(List<HangHoa>& a,List <HangHoa> &b) {
	cin.ignore();
	cout << "nhap id khach hang: ";
	cin >> this->id;
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


}
