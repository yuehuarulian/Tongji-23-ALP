/* 2252941 ������ ��04 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[1000] = { 0 };
	int dif[1000] = { 0 };
	int count[1000] = { 0 };
	int n = 0, m = 0;//��¼�������
	int i, j;//ѭ���Ʋ�
	int max;//ѡ������
	int exchange;//����˳���м��¼

	//����ɼ�
	cout << "������ɼ������1000������������������" << endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			a[i] = 0;
			i--;
			break;
		}
	}
	n = i + 1;
	if (n == 0)
	{
		cout << "����Ч����" << endl;
		return 0;
	}

	//�������
	cout << "���������Ϊ:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
		if (((i + 1) % 10) == 0)
			cout << endl;
		else
			continue;
	}
	if (i % 10 != 0)
		cout << endl;

	//���������ͳ��
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		exchange = a[max];
		a[max] = a[i];
		a[i] = exchange;
	}

	for (count[0] = 1, j = 1; j < n; j++)//1 1   n=2
	{
		if (a[j] == a[j - 1])
			count[j] = count[j - 1];
		else
			count[j] = j + 1;
	}
	m = i;
	//����ɼ�
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << ' ' << count[i] << endl;

	return 0;
}