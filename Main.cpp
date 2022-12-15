#include "DSLK.H"
#include "Hanghoa.h"
#include "HoaDon.h"
int main() {
	HoaDon z;
	int k;
	string c;
	HangHoa x, y;
	List <HangHoa> a,temp;
	List<HangHoa> l;
	x.docFile(l);
	l.Show();
	system("pause");
	/*cin >> x;
	cout << endl;
	cin >> y;
	a.InsertLast(x);
	a.InsertLast(y);*/
	a.Show();
	/*
	for (int i = 0; i <= 1; i++) {
		cout << "nhap hang ban muon mua: ";
		getline(cin, c);
		cout << endl;
		if (LinearSearch(a, c) != -1) {
			cout << "hang ban nhap o vi tri thu: " << LinearSearch(a, c) + 1 << endl;
			cout << "nhap so luong ban muon mua: ";
			cin >> k;
			cout << endl;
			ChangeSoluong(a, c, k);
			a.Show();
			cin.ignore();
		}
		else cout << "mon hang cua ban da het hang";
	}
	*/
	z.Input(a, temp);
	z.show(temp);
	x.ghiFile(l);

	return 0;
}