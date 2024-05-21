/* 信04 2252941 杨瑞灵 */
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
/* 功能：输入行数列数矩阵坐标
   choose==0：输入行数列数
   choose==1：输入矩阵坐标 */
void f_in(int star[][LIE],int* row, int* col, char* row_I, char* col_I, int choose)
{
	if(choose==0)
	{
		while (1)
		{
			cout << "请输入行数(8-10)：" << endl;
			cin >> *row;
			if (cin.good() && *row >= 8 && *row <= 10)
				break;
			cin.clear();
			cin.ignore(100000, '\n');
		}
		while (1)
		{
			cout << "请输入列数(8-10)：" << endl;
			cin >> *col;
			if (cin.good() && *col >= 8 && *col <= 10)
				break;
			cin.clear();
			cin.ignore(100000, '\n');
		}
	}
	if (choose==1)
	{
		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		while (1)
		{
			cin >> *row_I >> *col_I;
			if (*row_I >= 'a' && *row_I < 'a' + *row)
				*row_I = *row_I - 'a' + 'A';
			if (cin.good() && *row_I >= 'A' && *row_I < 'A' + *row && *col_I >= '0' && *col_I < '0' + *col)
			{
				cout << "输入为" << *row_I << "行" << *col_I << "列         " << endl;
				cin.clear();
				cin.ignore(10000, '\n');
				if (star[*row_I - 'A'][*col_I - '0'] != 0 && surrounding(star, NULL, *row_I, *col_I, 0) == 1)
					break;
				if (star[*row_I - 'A'][*col_I - '0'] == 0)
					cout << "输入的矩阵坐标位置为0（非法位置），请重新输入" << endl;
				else
					cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
				continue;
			}
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入错误，请重新输入.";
			int x, y;
			cct_getxy(x,y);
			erase(39, y - 1, 8, 1, 0);
		}
	}

}
/* 功能：调用函数实现数组改变和输出  ABC */
bool f_out(char option, int star[][LIE], int star_result[][LIE],int row, int col,char &row_I,char &col_I,int &score_each,int &score)
{
	
	if(option=='A'||option=='B'||option=='C')
	{
		cout << "\n当前数组：" << endl;
		f_out_ABC(star, NULL, row, col, 1);
		f_in(star, &row, &col, &row_I, &col_I, 1);
		change_star_result(star, star_result, row_I, col_I, row, col);
		//surrounding(star, star_result, row_I, col_I, 1);//填充star和star_result
		cout << "\n查找结果数组：" << endl;
		f_out_ABC(star_result, NULL, row, col, 2);
		cout << "\n当前数组(不同色标识)：" << endl;
		f_out_ABC(star, star_result, row, col, 4);
	}
	if (option == 'B'||option=='C')
	{
		cout << "\n请确认是否把" << row_I << col_I << "及周围的相同值消除(Y/N/Q)：";
		char YNQ;
		while ((YNQ = _getch()) != 'Y' && YNQ != 'y' && YNQ != 'N' && YNQ != 'n' && YNQ != 'Q' && YNQ != 'q')
			;
		if (YNQ == 'Y' || YNQ == 'y')
		{
			cout << "\n相同值归并后的数组(不同色标识)：" << endl;
			score_each = change_star(star, star_result, row, col, 1,NULL);//选择的星星归零
			score_each = score_each * score_each * 5;
			f_out_ABC(star, star_result, row, col, 3);//输出归零后star
			cout << "\n本次得分：" << score_each << " 总得分：" << (score += score_each) << endl;
			cout << "\n按回车键进行数组下落操作...";
			while (_getch() != 13)
				;
			cout << "\n下落后的数组：" << endl;
			change_star(star, star_result, row, col, 2,NULL);//star下落
			f_out_ABC(star, star_result, row, col, 3);//输出下落后star
		}
		else if (YNQ == 'Q' || YNQ == 'q')
			return 0;
	}
	return 1;
}
/* 输出数组
   choose==1：输出star不标黄
   choose==2：输出star_result不标黄
   choose==3：输出star标黄所有消除了的星星
   choose==4：输出star只标黄本次选中星星*/
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

