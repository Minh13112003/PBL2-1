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
	try {
	label:	while (e == 1) {
		cin.ignore();
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != -1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			if (checksoluong(a, tensp, soluong) == 0) {
				throw "san pham cua ban da het so luong!";
				cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
				cin >> e;
				goto label;
			}
			giaban = this->soluong * Getgiaban1(a, tensp);
			tongtien += giaban;
			if (tiengui < tongtien) {
				tongtien -= giaban;
				throw "so tien ban ko du de mua san pham nay! ";
				cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
				cin >> e;
				goto label;
			}
			ChangeSoluong(a, tensp, soluong);
			
			Node <HangHoa>* c = b.GetHead();
			while (c != NULL) {
				if (c->getData().Gettensp() == tensp) {
					c->data.Setsoluong(c->getData().Getsoluong() + soluong);
					c->data.Setgiaban(c->getData().Getsoluong() * Getgiaban1(a, tensp));
					cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
					cin >> e;
					goto label;
				}
				c = c->Next;
			}
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
			cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
			cin >> e;

		}
		else throw "da het hang !";
	}
	}
	catch (const char* temp) {
		cerr << temp << endl;
	}
}



void HoaDon::show( List <HangHoa> b) {
	Node <HangHoa>* c = b.GetHead();
	cout << "-------------------HoaDon cua khach hang: " << this->id << "----------------------" << endl;
	cout << "STT" << setw(16) << "Ten san pham" << right << setw(15) << "so luong" << right << setw(15) << "so tien" << endl;
	while (c != NULL) {
		c->data.show();
		c = c->Next;
	}
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Tong tien: " << right << setw(37) << this->tongtien << endl;
	cout << "Tien khach gui: " << right << setw(32)  << this->tiengui << endl;
	cout << "So tien tra lai: " << right << setw(31)  << (tiengui - tongtien) << endl;
	delete[] c;
}
