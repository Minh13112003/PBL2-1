#include "DSLK.H"
#include "Hanghoa.h"
#include "HoaDon.h"
int main() {
	List <List<HangHoa>> k;
	HoaDon z;
	string c;
	HangHoa x, y;
	List <HangHoa> a,temp;
	List<HangHoa> l;
	cin >> x;
	cin >> y;
	a.InsertLast(x);
	a.InsertLast(y);
	a.Show();
	z.Input(a, temp);
	z.show(temp);
	Node <List<HangHoa>> *c = k.GetHead();

	return 0;
}