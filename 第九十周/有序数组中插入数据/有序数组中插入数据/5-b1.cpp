/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;

int main()
{
	int a[40] = { 0 };
	int i, j, t;
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i < 20; i++)
	{
		while (1)
		{
			cin >> a[i];
			if (cin.good())
				break;
			else
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}
		}
		if (a[i] <= 0)
		{
			a[i] = 0;
			i--;
			break;
		}
	}
	if (i < 0)
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore(10000, '\n');
	cout << "ԭ����Ϊ��" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;
	cout << "������Ҫ�����������" << endl;
	while (1)
	{
		i++;
		cin >> a[i];
		if (cin.good())
			break;
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
	for (j = i; j > 0; j--)
	{
		if (a[j] < a[j - 1])
		{
			t = a[j];
			a[j] = a[j - 1];
			a[j - 1] = t;

		}
	}
	cout << "����������Ϊ��" << endl;
	for (j = 0; j <= i; j++)
		cout << a[j] << ' ';
	cout << endl;
	return 0;
}
