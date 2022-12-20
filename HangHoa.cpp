#include "HangHoa.h"
int HangHoa::a = 1;


void HangHoa::Setsoluong(int k) {
	this->soluong = k;
}

int HangHoa::Getsoluong() {
	return this->soluong;
}

long HangHoa::Getgiaban() {
	return this->giaban;
}

void HangHoa::Setgiaban(long k) {
	this->giaban = k;
}

string HangHoa::Gettensp() {
	return this->tensp;
}

int LinearSearch(List<HangHoa> a, string tensp) {
	int temp = 0;
	Node<HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			return temp;
		}
		++temp;
		b = b->Next;
	}
	return -1;
}

void ChangeSoluong(List<HangHoa>& a, string tensp, int i)
{
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			if (b->data.soluong >= i) {
				b->data.soluong -= i;
				break;
			}
			else cout << "so hang ko du!";
		}
		b = b->Next;
	}
}

bool checksoluong(List<HangHoa> a, string tensp, int i) {
	Node <HangHoa>* b = a.GetHead();
	while (b != NULL) {
		if (b->data.tensp == tensp) {
			if (b->data.soluong < i) {
				return 0;
			}
		}
		b = b->Next;
	}
	return 1;
}

long Getgiaban1(List<HangHoa> a, string tensp) {
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
	this->gianhap = 0;
	this->a = 0;
	this->tensp = " ";
	this->soluong = 0;
	this->giaban = 0;
}

HangHoa::HangHoa(string tensp, int soluong, long giaban) {
	this->a = 0;
	this->tensp = tensp;
	this->soluong = soluong;
	this->giaban = giaban;
	this->gianhap = 0;
}

istream& operator >> (istream& in, HangHoa& a) {
	cout << "nhap ten sp: ";
	getline(in, a.tensp);
	cout << "nhap so luong: ";
	in >> a.soluong;
	cout << "nhap gia ban: ";
	in >> a.giaban;
	cout << "nhap gia nhap: ";
	in >> a.gianhap;
	cin.ignore();
	return in;
}

void HangHoa::show() {
	cout << a++ << ": " << setw(15) << tensp << right << setw(15) <<  soluong << right << setw(15) << fixed << setprecision(5) << giaban  << endl;
}
void HangHoa::ghiFile(List<HangHoa> l)
{
	ofstream output("file.txt");
	Node<HangHoa>* a = NULL;
	a = l.GetHead();
	if (a != NULL)
	{
			output << a->getData().tensp << " / " << a->getData().soluong << " / " << a->getData().giaban << " ///" << endl;
	}
	output.close();
}
void HangHoa::docFile(List<HangHoa> &l)
{
	string str[200];
	ifstream input("file.txt");
	string s;
	int n = 0;
	int count = 0;
	while (input >> s)
	{
		if (count != 3) {

			++count;
		}
		else {

			count = 0;
		}
		str[n] = s;
		n++;
	}
	input.close();
	int temp = 0;
	string stt, ten;
	int sl;
	long gia;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == "/" && temp != 2)
		{
			temp++;
		}
		else if (temp == 2)
		{
			gia = stof(str[i]);
			i++;
			temp = 0;
			HangHoa hangHoa(ten, sl, gia);
			l.InsertLast(hangHoa);
			if (str[i] == "///")
			{
				ten = "";
				sl = 0;
				gia = 0;
			}
			continue;
		}
		else if (str[i] != "/" && temp == 0)
		{
			while (str[i] != "/")
			{
				ten = ten + str[i] + " ";
				i++;
			}
			ten.pop_back();
			i--;
		}

		else if (str[i] != "/" && temp == 1)
		{
			sl = stoi(str[i]);
		}
	}
}

