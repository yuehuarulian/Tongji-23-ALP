/*2252941 ��04 ������*/
#include <iostream>
#include <math.h>
using namespace std;

extern double a, b, c;

void f1()
{
	cout << "����һԪ���η���" << endl;
	return;
}

void f2()
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "����������ʵ����\n" << "x1=" << x1 << '\n' << "x2=" << x2 << endl;
	return;
}

void f3()
{
	double x;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "���������ʵ����\n" << "x1=x2=" << x << endl;
	return;
}

void f4()
{
	double s, x;
	s = -b / (2 * a);
	x = fabs(sqrt(-(b * b - 4 * a * c)) / (2 * a));
	if (fabs(s) < 1e-6)
	{
		if (x == 1)
			cout << "�����������\n" << "x1=" << 'i' << '\n' << "x2=" << '-' << 'i' << endl;
		else
			cout << "�����������\n" << "x1=" << x << 'i' << '\n' << "x2=" << '-' << x << 'i' << endl;
	}
	else
	{
		if (x == 1)
			cout << "�����������\n" << "x1=" << s << '+' << 'i' << '\n' << "x2=" << s << '-' << 'i' << endl;
		else
			cout << "�����������\n" << "x1=" << s << '+' << x << 'i' << '\n' << "x2=" << s << '-' << x << 'i' << endl;
	}
	return;
}