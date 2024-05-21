/* 杨瑞灵 2252941 信04 */
#include <iostream>
#include <cstdio>
using namespace std;

void insd(int sd[][10])
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			while (1)
			{
				cin >> sd[i][j];
				if (cin.good() && sd[i][j] <= 9 && sd[i][j] >= 1)
					break;
				else if (cin.good())
					;
				else
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}
				cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
			}
		}
	}
	return;
}   

int judge(int sd[][10])
{
	int jud[10][10] = { {0,1,2,3,4,5,6,7,8,9},{1} ,{2},{3},{4},{5},{6},{7},{8},{9} };
	//横排
	for (int y = 1; y <= 9; y++)
	{
		for (int x = 1; x <= 9; x++)
		{
			jud[y][sd[y][x]] += 1;
		}
	}
	for (int i = 1; i <=9; i++)
	{
		for (int j = 1; j <=9; j++)
		{
			if (jud[i][j] != 1)
				return 0;
			else
				jud[i][j] = 0;
		}
	}

	//竖排
	for (int y = 1; y <= 9; y++)
	{
		for (int x = 1; x <= 9; x++)
		{
			jud[sd[x][y]][y] += 1;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (jud[i][j] != 1)
				return 0;
			else
				jud[i][j] = 0;
		}
	}
	//小框
	for (int y = 1; y <= 9; y++)
	{
		for (int x = 1; x <= 9; x++)
		{
			jud[y][sd[(y - 1) / 3 * 3 + (x + 2) / 3][((y - 1) % 3 * 3) + ((x - 1) % 3 + 1)]] += 1;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (jud[i][j] != 1)
				return 0;
		}
	}

	return 1;
}

int main()
{
	int sd[10][10] = { {0,1,2,3,4,5,6,7,8,9},{1} ,{2},{3},{4},{5},{6},{7},{8},{9} };
	insd(sd);
	bool b;
	b = judge(sd);
	if (b)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}