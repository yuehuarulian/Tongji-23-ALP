/* ��04 2252941 ������ */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int year, mon, week, day;
	int daym;//һ���µ�������
	//�������²��ж�����
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> mon; 
		if (cin.good() && year >= 2000 && year <= 2030 && mon >= 1 && mon <= 12)
			break;
		else
			cout << "����Ƿ�������������" << endl;

		if (cin.good() == 0)
		{
			cin.clear();//��������־λ
			cin.ignore(10000000000, '\n');//���������������}
		}
		else
		{
			cin.clear();//��������־λ
			cin.ignore();//���������������}
		}
	}

	//�������ڼ����ж�����
	while (1) {
		cout << "������" << year << "��" << mon << "��1�յ�����(0-6��ʾ������-������) : " ;
		cin >> week;
		if (cin.good() && week >= 0 && week <= 6)
		{
			cout << endl;
			break;
		}
		else
			cout << "����Ƿ�������������" << endl;

		if (cin.good() == 0)
		{
			cin.clear();//��������־λ
			cin.ignore(10000000000, '\n');//���������������}
		}
		else
		{
			cin.clear();//��������־λ
			cin.ignore();//���������������}
		}
	}
	//�ж�һ���µ�����
	if (mon == 4 || mon == 9 || mon == 11 || mon == 6)
		daym = 30;
	else if (mon != 2)
		daym = 31;
	else if (mon == 2)
		daym = 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));


	//�������
	int n = 8;
	cout << year << "��" << mon << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << setw(week * 8 + 4) << 1;
	for (day = 2, week += 1; day <= daym; day++, week++)
	{
		n = 8;
		if (week == 7)
		{
			cout << endl;
			week -= 7;
			n = 4;
		}
		cout << setw(n) << day;

	}
	if (week == 7)
		cout << endl;
	cout << endl;



	return 0;
}