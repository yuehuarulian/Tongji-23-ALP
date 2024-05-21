/* 杨瑞灵 2252941 信04 */
#include <iostream>
#include <cstdio>
#include <iomanip>;
using namespace std;
int main()
{
	int yh[14][14] = { 0 };
	int line;
	int i, j;
	cout << "请输入要打印的行数[3..13]" << endl;
	cin >> line;
	for (i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
	for (i = 0; i <= 7; i++)
		cout << i << "         ";
	cout << endl;
	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 9; j++)
			cout << j;
	}
	cout << endl;
	for (i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
	for (i = 1; i <= 13; i++)
	{
		yh[i][1] = 1;
		for (j = 2; j <= i - 1; j++)
		{
			yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
		}
		yh[i][i] = 1;
	}
	for (i = 1; i <= line; i++)
	{
		j = 0;
		while( j < 3 * (line - i))
		{
			cout << ' ';
			j++;
		}
		for (j = 1; j <= i; j++)
		{
			cout <<setw(6)<< yh[i][j];
		}
		cout << endl;
	}

	for (i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
	for (i = 0; i <= 7; i++)
	{
		for (j = 0; j <= 9; j++)
			cout << j;
	}
	cout << endl;
	for (i = 0; i <= 7; i++)
		cout << i << "         ";
	cout << endl;
	for (i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
	cout << endl;
	return 0;
}
