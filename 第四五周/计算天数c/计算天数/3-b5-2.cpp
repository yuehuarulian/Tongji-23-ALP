//��04 2252941 ������
#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	int a, b;
	bool c, d;
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;

	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		b = 29;
	else
		b = 28;

	if (month >= 1)
	{
		a = day;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 2)
	{
		a += 31;
		if (day >= 1 && day <= b)
			d = true;
		else
			d = false;
	}
	if (month >= 3)
	{
		a += b;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 4)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 5)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 6)
	{
		a += 31;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 7)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 8)
	{
		a += 31;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 9)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 10)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}
	if (month >= 11)
	{
		a += 31;
		if (day >= 1 && day <= 30)
			d = true;
		else
			d = false;
	}
	if (month >= 12)
	{
		a += 30;
		if (day >= 1 && day <= 31)
			d = true;
		else
			d = false;
	}

	if (month >= 1 && month <= 12)
		c = true;
	else
		c = false;

	if ((c == true) && (d == true))
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
	else if (c == false)
		cout << "�������-�·ݲ���ȷ" << endl;
	else if (d==false)
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;

	return 0;
}