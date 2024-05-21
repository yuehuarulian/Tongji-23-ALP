/* 杨瑞灵 2252941 信04 */
#include <iostream>
#include <cstdio>
#include <windows.h> 
#include <time.h>
using namespace std;
int main()
{
	int statistics[100000] = { 0 };
	int statistics_h[100000] = { 0 };
	int n;
	int base;
	int cou = 0;
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	for (int i = 0; i < n; i++)
		cin >> statistics[i];
	cout << "请输入基数[2..9]" << endl;
	cin >> base;
	for (int i = 0; i < n; i++)
	{
		statistics_h[i] = statistics[i] % 10 + statistics[i] % 100 / 10 + statistics[i] % 1000 / 100 + statistics[i] / 1000;
	}
	for (int i = 0; i < n; i++)
	{
		if (statistics_h[i] % base == 0)
			cou++;
	}
	cout << n << "个数中各位累加和被" << base << "整除的个数 : " << cou << endl;
	return 0;
}
