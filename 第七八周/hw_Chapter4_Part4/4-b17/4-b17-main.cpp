/*2252941 ��04 ������*/
#include <iostream>
#include <math.h>
using namespace std;

void f1();
void f2();
void f3();
void f4();
double a, b, c;

int main()
{
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a;
	if (fabs(a) < 1e-6)
		a = 0;
	if (!cin.good() || a == 0)
	{
		f1();
		return 0;
	}
	cin >> b >> c;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	double deta;
	deta = b * b - 4 * a * c;
	if (deta >= 1e-6)
		f2();
	else if (fabs(deta) < 1e-6)
		f3();
	else
		f4();
	return 0;

}