/* ������ 2252941 ��04 */
#include <iostream>
#include <cstdio>
using namespace std;

void insd(int sd[][10])
{
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
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
				cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ" << endl;
			}
		}
	}
	return;
}   

int judge(int sd[][10])
{
	int jud[10][10] = { {0,1,2,3,4,5,6,7,8,9},{1} ,{2},{3},{4},{5},{6},{7},{8},{9} };
	//����
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

	//����
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
	//С��
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
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;
	return 0;
}