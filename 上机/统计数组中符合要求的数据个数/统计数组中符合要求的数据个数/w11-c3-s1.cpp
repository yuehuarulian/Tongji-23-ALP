/* ������ 2252941 ��04 */
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
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (int i = 0; i < n; i++)
		cin >> statistics[i];
	cout << "���������[2..9]" << endl;
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
	cout << n << "�����и�λ�ۼӺͱ�" << base << "�����ĸ��� : " << cou << endl;
	return 0;
}
