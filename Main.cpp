#include "DSLK.H"
#include "Hanghoa.h"
#include "HoaDon.h"
int main() {
	List <HoaDon> HD;
	string id = "";
	HoaDon z,w;
	string c;
	HangHoa x, y,hanghoa1,hanghoa2;
	List <HangHoa> a,temp;
	List<HangHoa> l;
	cin >> x;
	cin >> y;
	a.InsertLast(x);
	a.InsertLast(y);
	a.Show();
	z.Input(a);
	z.show();
	HD.InsertLast(z);
	w.Input(a);
	w.show();
	HD.InsertLast(w);
	show_gianhap(HD,a);
	

	return 0;
}