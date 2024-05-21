/* 信04 2252941 杨瑞灵 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
//int delay;
//int cou = 0;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int option;
    char src, tmp, dst;
    int n;
	int han[3][10] = { 0 };
	int top[3] = { 0 };
	while(1)
	{
		for (int i = 0; i < 3; i++)
		{
			top[i] = 0;
			for (int j = 0; j < 10; j++)
				han[i][j] = 0;
		}
		n = 0;
		cct_setcolor();
		cct_cls();
		option = menu();
		if (!option)//判断option是否为0退出
			break;
		if (option != 5)
		{
			f_in(&src, &tmp, &dst, &n, option);//输入ABC柱和delay
			tcsz(src, n, han, top);
		}
		if (option >= 4)
			cct_cls();
		if (option == 5)
			draw_z(option);
		if (option >= 6 )
		{
			cout << "从" << src << "移动到" << dst << ", 共" << setw(2) << n << "层";
			draw_z(option);
			draw_p(n, han, top);
		}
		if (option == 4||option==8||option==9)
		{
			prime(src, dst, n, han, top, option!=4);
			out_z(1, src, dst, option, han, top, option!=4);
		}
		while ((option == 7 || option == 8) && getchar() != '\n')
			;
		if (option == 7)
		{
			move_z(han[src - 'A'][top[src - 'A'] - 1], (src - 'A') * 32 + 12, 15 - top[src - 'A'], (dst - 'A') * 32 + 12, 14 - top[dst - 'A']);
		}
		if (option >= 1 && option <= 4 || option == 8)
			hanoi(n, src, tmp, dst, option, han, top);
		if (option == 9)
		{
			char src_I, dst_I;
			int yd = 0;//当前移动盘号
			int back;
			cct_gotoxy(0, 34);
			cout << "请输入移动的柱号(命令形式:AC=A顶端的盘子移动到C,Q=退出):";
			while (1)
			{
				back = f_in_I(&src_I, &dst_I, han, top);
				if (!back)
				{
					cct_gotoxy(0, 35);
					cout << "游戏中止!!!!!";
					break;
				}
				yd = han[src_I - 'A'][top[src_I - 'A'] - 1];
				move_z(han[src_I - 'A'][top[src_I - 'A'] - 1], (src_I - 'A') * 32 + 12, 15 - top[src_I - 'A'], (dst_I - 'A') * 32 + 12, 14 - top[dst_I - 'A']);
				changesz(src_I, dst_I, han, top);
				out_h(yd, src_I, dst_I, option, han, top, 1);
				out_z(yd, src_I, dst_I, option, han, top, 1);
				if (top[dst - 'A'] == n)
				{
					cct_gotoxy(0, 35);
					cout << "游戏结束!!!!!";
					break;
				}
			}
		}
		if (option != 3 && option != 2 && option != 1)
			cct_gotoxy(0, 38);
		else
			cout << endl;
		cout << "按回车键继续";
		while (1)
		{
			if (_getch() == 13)
				break;
		}
	}
	return 0;
}