/*2252941 信04 杨瑞灵*/
#include <iostream>
#include <math.h>
#include "4-b16.h"
using namespace std;

int main()
{
	double a, b, c;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a;
	if (fabs(a) < 1e-6)
		a = 0;
	if (!cin.good() || a == 0)
	{
		f1(0, 0, 0);
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
		f2(a, b, c);
	else if (fabs(deta) < 1e-6)
		f3(a, b, c);
	else
		f4(a, b, c);
	return 0;

}