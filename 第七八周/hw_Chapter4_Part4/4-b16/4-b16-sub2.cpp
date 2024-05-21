/*2252941 信04 杨瑞灵*/
#include <iostream>
#include <math.h>
using namespace std;

void f2(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "有两个不等实根：\n" << "x1=" << x1 << '\n' << "x2=" << x2 << endl;
	return;
}