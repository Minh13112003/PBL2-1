#include "DSLK.cpp"
#include "Hanghoa.h"
#include <iostream>

using namespace std;

int main() {
	HangHoa x;
	cin >> x;
	List <HangHoa> a;
	a.InsertLast((HangHoa) x);
	a.Show();
	HangHoa y;
	cin >> y;
	a.InsertLast((HangHoa) y);
	a.Show();
	
}