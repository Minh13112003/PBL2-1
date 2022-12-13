#include "DSLK.H"
#include "Hanghoa.h"
#include <iostream>

using namespace std;

int main() {
	int k;
	string c;
	HangHoa x, y;
	List <HangHoa> a;
	cin >> x;
	cout << endl;
	cin >> y;
	a.InsertLast(x);
	a.InsertLast(y);
	a.Show();
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

	return 0;
}