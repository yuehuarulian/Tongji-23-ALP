/* 信04 2252941 杨瑞灵 */
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
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> len >> upp >> low >> num >> oth;
	if (cin.fail())
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (len < 12 || len>16)
	{
		cout << "密码长度[" << len << "]不正确" << endl;
		return 0;
	}
	if (upp < 2 || upp>len)
	{
		cout << "大写字母个数[" << upp << "]不正确" << endl;
		return 0;
	}
	if (low < 2 || low>len)
	{
		cout << "小写字母个数[" << low << "]不正确" << endl;
		return 0;
	}
	if (num < 2 || num>len)
	{
		cout << "数字个数[" << num << "]不正确" << endl;
		return 0;
	}
	if (oth < 2 || oth>len)
	{
		cout << "其他符号个数[" << oth << "]不正确" << endl;
		return 0;
	}
	if ((upp + low + num + oth) > len)
	{
		cout << "所有字符类型之和[" << upp << " + " << low << " + " << num << " + " << oth << "]大于总密码长度[" << len << "]" << endl;
		return 0;
	}
	cout << len << ' ' << upp << ' ' << low << ' ' << num << ' ' << oth << endl;
	form(secret, len, upp, low, num, oth);
	f_out(secret);


	return 0;
}
