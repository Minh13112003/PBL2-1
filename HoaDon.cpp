#include "HoaDon.h"
int HoaDon::count = 1;


HoaDon::HoaDon() {
	this->tongtien = 0;
}

void HoaDon::Input(List<HangHoa>& a, List <HangHoa>& b) {
	cout << "nhap id khach hang: ";
	cin >> this->id;
	cin.ignore();
	cout << "nhap so tien khach gui: ";
	cin >> this->tiengui;
	bool e = 1;
	while (e == 1) {
		cin.ignore();
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != -1) {
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
		else cout << "eu co hang nha ma" << endl;
	}
}


void HoaDon::show( List <HangHoa> b) {
	Node <HangHoa>* c = b.GetHead();
	cout << "-------------------HoaDon cua khach hang: " << this->id << "----------------------" << endl;
	while (c != NULL) {
		c->data.show();
		c = c->Next;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Tong tien: " << right << setw(37) << this->tongtien<< endl;
	cout << "Tien khach gui: " << right << setw(32) << this->tiengui << endl;
	cout << "So tien tra lai: " << right << setw(31) << tiengui - tongtien;

}
