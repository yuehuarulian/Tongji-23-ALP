/* ��04 2252941 ������ */
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
const int n = 10;
void form(char secret[][17],int len,int upp,int low,int num,int oth)
{
	int wz;
	int s = len - upp - low - num - oth;
	for (int i = 0; i < s; i++)
	{
		int r = rand() % 4;
		if (r == 0)
			upp++;
		else if (r == 1)
			low++;
		else if (r == 2)
			num++;
		else if (r == 3)
			oth++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < upp; j++)
		{
			wz = rand() % len;
			if (secret[i][wz] != '\0')
			{
				j--;
				continue;
			}
			secret[i][wz] = rand() % 26 + 'A';
		}
		for (int j = 0; j < low; j++)
		{
			wz = rand() % len;
			if (secret[i][wz] != '\0')
			{
				j--;
				continue;
			}
			secret[i][wz] = rand() % 26 + 'a';
		}
		for (int j = 0; j < num; j++)
		{
			wz = rand() % len;
			if (secret[i][wz] != '\0')
			{
				j--;
				continue;
			}
			secret[i][wz] = rand() % 9 + '0';
		}
		for (int j = 0; j < oth; j++)
		{
			wz = rand() % len;
			if (secret[i][wz] != '\0')
			{
				j--;
				continue;
			}
			secret[i][wz] = other[rand() % 15];
		}
		//while (getchar() != '\n')
		//	;
		//for (int p = 0; p < n; p++)
		//{
		//	for (int q = 0; q < len; q++)
		//		cout << int(secret[p][q]) << ' ';
		//	cout << endl;
		//}
	}
	return;
}
void f_out(char secret[][17])
{
	for (int i = 0; i < n; i++)
		cout << secret[i] << endl;
	return;
}
int main()
{
	srand((unsigned int)(time(0)));
	int len, upp, low, num, oth;
	char secret[n][17] = { 0 };
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> len >> upp >> low >> num >> oth;
	if (cin.fail())
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "���볤��[" << len << "]����ȷ" << endl;
		return 0;
	}
	if (upp < 2 || upp>len)
	{
		cout << "��д��ĸ����[" << upp << "]����ȷ" << endl;
		return 0;
	}
	if (low < 2 || low>len)
	{
		cout << "Сд��ĸ����[" << low << "]����ȷ" << endl;
		return 0;
	}
	if (num < 2 || num>len)
	{
		cout << "���ָ���[" << num << "]����ȷ" << endl;
		return 0;
	}
	if (oth < 2 || oth>len)
	{
		cout << "�������Ÿ���[" << oth << "]����ȷ" << endl;
		return 0;
	}
	if ((upp + low + num + oth) > len)
	{
		cout << "�����ַ�����֮��[" << upp << " + " << low << " + " << num << " + " << oth << "]���������볤��[" << len << "]" << endl;
		return 0;
	}
	cout << len << ' ' << upp << ' ' << low << ' ' << num << ' ' << oth << endl;
	form(secret, len, upp, low, num, oth);
	f_out(secret);


	return 0;
}
