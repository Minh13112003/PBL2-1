#include "HoaDon.h"
int HoaDon::count = 1;


HoaDon::HoaDon() {
	this->id = "";
	this->tongtien = 0;
	this->tongtiennhap = 0;
}

void HoaDon::Input(List<HangHoa>& a) {
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
			gianhap = this->soluong * Getgianhap1(a, tensp);
			tongtien += giaban;
			tongtiennhap += gianhap;
			if (tiengui < tongtien) {
				tongtien -= giaban;
				tongtiennhap -= gianhap;
				throw "so tien ban ko du de mua san pham nay! ";
				cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
				cin >> e;
				goto label;
			}
			ChangeSoluong(a, tensp, soluong);
			
			Node <HangHoa>* c = this->HD.GetHead();
			while (c != NULL) {
				if (c->getData().Gettensp() == tensp) {
					c->data.Setsoluong(c->getData().Getsoluong() + soluong);
					c->data.Setgiaban(c->getData().Getsoluong() * Getgiaban1(a, tensp));
					c->data.Setgianhap(c->getData().Getsoluong() * Getgianhap1(a, tensp));
					cout << "ban co muon tiep tuc mua khong: 1(co),0(khong): ";
					cin >> e;
					goto label;
				}
				c = c->Next;
			}
			HangHoa temp(this->tensp, this->soluong, this->giaban,this->gianhap);
			HD.InsertLast(temp);
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



void HoaDon::show() {
	Node <HangHoa>* c = this->HD.GetHead();
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


void show_gianhap(List <HoaDon> &a,List <HangHoa> b) {
	long doanhthu = 0;
	long long chiphi = 0;
	Node<HoaDon>* c = a.GetHead();
	List<HangHoa> temp;
	while (c != NULL) {
		Node <HangHoa>* k = c->data.HD.GetHead();
		while (k != NULL) {
			HangHoa temp2(k->data.Gettensp(), k->data.Getsoluong(),k->data.Getgiaban(),k->data.Getgianhap());
			temp.InsertLast(temp2);
			k = k->Next;
		}
		c = c->Next;
	}
	
	for (Node<HangHoa>* i = temp.GetHead(); i != NULL; i = i->Next) {
		string str = i->data.Gettensp();
		for (Node<HangHoa>* j = i->Next; j != NULL; j = j->Next) {
			if (LinearSearch(temp, j->data.Gettensp()) != -1) {
				i->data.Setsoluong(i->data.Getsoluong() + j->data.Getsoluong());
				i->data.Setgianhap(i->data.Getgianhap() + j->data.Getgianhap());
				i->data.Setgiaban(i->data.Getgiaban() + j->data.Getgiaban());
				if (j->Next == NULL) {
					Node<HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					p->Next = NULL;
					j = p;
					delete temp;

				}
				else {
					Node <HangHoa>* p = j->Pre;
					Node <HangHoa>* temp = j;
					Node <HangHoa>* p2 = temp->Next;
					p->Next = p2;
					p2->Pre = p;
					delete temp;
				}

			}
		}
	}

	Node <HangHoa>* temp2 = temp.GetHead();
	while (temp2 != NULL) {
		temp2->data.show_gianhap();
		temp2 = temp2->Next;
	}

	/*
	Node <HangHoa>* hh2 = temp.GetHead();
	cout << "---------------------Doanh thu cua quan-----------------------" << endl;
	cout << "STT" << setw(16) << "Ten san pham" << right << setw(15) << "so luong" << right << setw(15) << "gia nhap" << right << setw(15) << "gia ban" << endl;
	while (hh2 != NULL) {
		hh2->data.show_gianhap();
		doanhthu += hh2->data.Getgiaban();
		hh2 = hh2->Next;
	}
	Node <HangHoa> *d = b.GetHead();
	while (d != NULL) {
		chiphi += d->data.Getgianhap() * d->data.Getsoluong();
		d = d->Next;
	}
	
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "doanh thu: " << right << setw(37) << doanhthu << endl;
	cout << "chi phi nhap hang: " << right << setw(32) << chiphi << endl;
	cout << "loi nhuan: " << right << setw(31) << doanhthu - chiphi << endl;
	*/
}

string HoaDon::getid() {
	 return this->id;
}

void Search(List<HoaDon> a) {
	string k;
	cout << "Nhap ma hoa don can tim : ";
	cin >> k;
	Node<HoaDon>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.getid() == k) {
			b->data.show();
		}
		b = b->Next;
	}
}
