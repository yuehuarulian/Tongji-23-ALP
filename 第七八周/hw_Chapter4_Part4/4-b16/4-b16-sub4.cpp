/*2252941 信04 杨瑞灵*/
#include <iostream>
#include <math.h>
using namespace std;

void f4(double a, double b, double c)
{
	double s, x;
	s = -b / (2 * a);
	x = fabs(sqrt(-(b * b - 4 * a * c)) / (2 * a));
	if (fabs(s) < 1e-6)
	{
		if (x == 1)
			cout << "有两个虚根：\n" << "x1=" << 'i' << '\n' << "x2=" << '-' << 'i' << endl;
		else
			cout << "有两个虚根：\n" << "x1=" << x << 'i' << '\n' << "x2=" << '-' << x << 'i' << endl;
	}
	else
	{
		if (x == 1)
			cout << "有两个虚根：\n" << "x1=" << s << '+' << 'i' << '\n' << "x2=" << s << '-' << 'i' << endl;
		else
			cout << "有两个虚根：\n" << "x1=" << s << '+' << x << 'i' << '\n' << "x2=" << s << '-' << x << 'i' << endl;
	}
	return;
}