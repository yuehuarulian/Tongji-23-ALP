/*2252941 信04 杨瑞灵*/
#include <iostream>
#include <math.h>
using namespace std;

void f3(double a, double b, double c)
{
	double x;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：\n" << "x1=x2=" << x << endl;
	return;
}