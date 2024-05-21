/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	int y_1, m_1, d_1, c_1;
	c_1 = (y - (m == 1 || m == 2)) / 100;
	y_1 = (y - (m == 1 || m == 2)) % 100;
	m_1 = (m == 1 || m == 2 ? m + 12 : m);
	d_1 = d;
	int w;
	w = y_1 + y_1 / 4 + c_1 / 4 - 2 * c_1 + (13 * (m_1 + 1)) / 5 + d_1 - 1;
	if (w < 0)
		w += 7;
	w %= 7;
	return w;
}

int main()
{
	int year, mon, day;
	int w;

	//����������
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> mon >> day;
		//����ÿ�����������
		int day_m;
		if (mon != 2 && mon != 4 && mon != 6 && mon != 9 && mon != 11)
			day_m = 31;
		else if (mon != 2)
			day_m = 30;
		else
			day_m = 28 + (year % 400 == 0 || ((year % 4 == 0) && year % 100 != 0));

		//�ж�������ȷ
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (year < 1900 || year>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else if (mon < 1 || mon>12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		else if (day<0 || day>day_m)
		{
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		else
			break;
	}
	
	//����zeller�����������ڼ�
	w = zeller(year, mon, day);
	switch (w)
	{
		case(0):
			cout << "������" << endl;
			break;
		case(1):
			cout << "����һ" << endl;
			break;
		case(2):
			cout << "���ڶ�" << endl;
			break;
		case(3):
			cout << "������" << endl;
			break;
		case(4):
			cout << "������" << endl;
			break;
		case(5):
			cout << "������" << endl;
			break;
		case(6):
			cout << "������" << endl;
			break;

	}
}