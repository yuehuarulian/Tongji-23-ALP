/* ��04 2252941 ������ */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "popstar.h"
using namespace std;
/* ���ܣ���������������������
   choose==0��������������
   choose==1������������� */
void f_in(int star[][LIE],int* row, int* col, char* row_I, char* col_I, int choose)
{
	if(choose==0)
	{
		while (1)
		{
			cout << "����������(8-10)��" << endl;
			cin >> *row;
			if (cin.good() && *row >= 8 && *row <= 10)
				break;
			cin.clear();
			cin.ignore(100000, '\n');
		}
		while (1)
		{
			cout << "����������(8-10)��" << endl;
			cin >> *col;
			if (cin.good() && *col >= 8 && *col <= 10)
				break;
			cin.clear();
			cin.ignore(100000, '\n');
		}
	}
	if (choose==1)
	{
		cout << "������ĸ+������ʽ[����c2]����������꣺";
		while (1)
		{
			cin >> *row_I >> *col_I;
			if (*row_I >= 'a' && *row_I < 'a' + *row)
				*row_I = *row_I - 'a' + 'A';
			if (cin.good() && *row_I >= 'A' && *row_I < 'A' + *row && *col_I >= '0' && *col_I < '0' + *col)
			{
				cout << "����Ϊ" << *row_I << "��" << *col_I << "��         " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				if (star[*row_I - 'A'][*col_I - '0'] != 0 && surrounding(star, NULL, *row_I, *col_I, 0) == 1)
					break;
				if (star[*row_I - 'A'][*col_I - '0'] == 0)
					cout << "����ľ�������λ��Ϊ0���Ƿ�λ�ã�������������" << endl;
				else
					cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
				continue;
			}
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "�����������������.";
			int x, y;
			cct_getxy(x,y);
			erase(39, y - 1, 8, 1, 0);
		}
	}

}
/* ���ܣ����ú���ʵ������ı�����  ABC */
bool f_out(char option, int star[][LIE], int star_result[][LIE],int row, int col,char &row_I,char &col_I,int &score_each,int &score)
{
	
	if(option=='A'||option=='B'||option=='C')
	{
		cout << "\n��ǰ���飺" << endl;
		f_out_ABC(star, NULL, row, col, 1);
		f_in(star, &row, &col, &row_I, &col_I, 1);
		change_star_result(star, star_result, row_I, col_I, row, col);
		//surrounding(star, star_result, row_I, col_I, 1);//���star��star_result
		cout << "\n���ҽ�����飺" << endl;
		f_out_ABC(star_result, NULL, row, col, 2);
		cout << "\n��ǰ����(��ͬɫ��ʶ)��" << endl;
		f_out_ABC(star, star_result, row, col, 4);
	}
	if (option == 'B'||option=='C')
	{
		cout << "\n��ȷ���Ƿ��" << row_I << col_I << "����Χ����ֵͬ����(Y/N/Q)��";
		char YNQ;
		while ((YNQ = _getch()) != 'Y' && YNQ != 'y' && YNQ != 'N' && YNQ != 'n' && YNQ != 'Q' && YNQ != 'q')
			;
		if (YNQ == 'Y' || YNQ == 'y')
		{
			cout << "\n��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
			score_each = change_star(star, star_result, row, col, 1,NULL);//ѡ������ǹ���
			score_each = score_each * score_each * 5;
			f_out_ABC(star, star_result, row, col, 3);//��������star
			cout << "\n���ε÷֣�" << score_each << " �ܵ÷֣�" << (score += score_each) << endl;
			cout << "\n���س������������������...";
			while (_getch() != 13)
				;
			cout << "\n���������飺" << endl;
			change_star(star, star_result, row, col, 2,NULL);//star����
			f_out_ABC(star, star_result, row, col, 3);//��������star
		}
		else if (YNQ == 'Q' || YNQ == 'q')
			return 0;
	}
	return 1;
}
/* �������
   choose==1�����star�����
   choose==2�����star_result�����
   choose==3�����star������������˵�����
   choose==4�����starֻ��Ʊ���ѡ������*/
void f_out_ABC(int star[][LIE], int star_result[][LIE], int row, int col, int choose)
{
	cout << "  | ";
	for (int i = 0; i < col; i++)
		cout << ' ' << i << ' ';
	cout << "\n--+-";
	for (int i = 0; i < col; i++)
		cout << "---";
	cout << endl;
	for (int i = 0; i < row; i++)
	{
		cout << (char)(i + 'A') << " | ";
		for (int j = 0; j < col; j++)
		{
			if (choose == 3 && star_result[i][j] == 1)
			{
				cout << ' ';
				int x, y;
				cct_getxy(x, y);
				cct_showch(x, y, star[i][j]+'0', 14, 0, 1);
				cct_setcolor();
				cout << ' ';
				continue;
			}
			if (choose == 4 && star_result[i][j] == 1 && star[i][j] != 0)
			{
				cout << ' ';
				int x, y;
				cct_getxy(x, y);
				cct_showch(x, y, star[i][j] + '0', 14, 0, 1);
				cct_setcolor();
				cout << ' ';
				continue;
			}
			if (choose == 1 || choose == 3 || choose == 4)
				cout << ' ' << star[i][j] << ' ';
			else if (choose == 2)
				cout << ' ' << (star[i][j] == 0 ? '0' : '*') << ' ';
			
		}
		cout << endl;
	}
}

