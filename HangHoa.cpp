#include "HangHoa.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/*
void HangHoa::Input(List<HangHoa>& a,List<HangHoa> &b) {
	cin.ignore();
	cout << "nhap id khach hang: ";
	cin >> this->id;
	int e = 1;
	while (e == 1) {
		cout << "nhap ten san pham muon mua: ";
		getline(cin, this->tensp);
		if (LinearSearch(a, tensp) != 1) {
			cout << "nhap so luong: ";
			cin >> this->soluong;
			ChangeSoluong(a, this->tensp, this->soluong);
			this->giaban = this->soluong * Getgiaban(a, tensp);
			HangHoa temp(this->tensp, this->soluong, this->giaban);
			b.InsertLast(temp);
		}
	}
}
*/

int LinearSearch(List<HangHoa> a,string tensp) {
	int temp = 0;
	Node<HangHoa>* b = a.GetHead();
	while (b != NULL ) {
		if (b->data.tensp == tensp) {
			return temp;
		}
		++temp;
		b = b->Next;
	}
	return -1;
}

void ChangeSoluong(List<HangHoa> &a,string tensp, int i) 
{
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if ( b->data.tensp == tensp) {
			if (b->data.soluong >= i) {
				b->data.soluong -= i;
				break;
			}
			else throw "so hang ko du!";
		}
		b = b->Next;
	}
}

float Getgiaban(List<HangHoa> a, string tensp) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return b->data.giaban;
		}
		b = b->Next;
	}
	return -1;
}


HangHoa::HangHoa() {
	this->a = 0;
	this->tensp = " ";
	this->soluong = 0;
	this->giaban = 0;
}

HangHoa::HangHoa(string tensp,int soluong,float giaban) {
	this->a = 0;
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