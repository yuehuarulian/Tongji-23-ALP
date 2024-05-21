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
char menu()
{
	char option;
	cout << "--------------------------------------------\n"
		<< "A.命令行找出可消除项并标识\n"
		<< "B.命令行完成一次消除（分步骤显示）\n"
		<< "C.命令行完成一关（分步骤显示）\n"
		<< "D.伪图形界面下用鼠标选择一个色块（无分隔线）\n"
		<< "E.伪图形界面下用鼠标选择一个色块（有分隔线）\n"
		<< "F.伪图形界面完成一次消除（分步骤）\n"
		<< "G.伪图形界面完整版\n"
		<< "Q.退出\n"
		<< "--------------------------------------------\n"
		<< "[请选择:]";
	while(1)
	{
		option = _getch();
		if (option >= 'a' && option <= 'g' || option == 'q')
			option = option + 'A' - 'a';
		if (option >= 'A' && option <= 'G' || option == 'Q')
			break;
	}
	return option;
}
int main()
{
	srand((unsigned int)(time(0)));
	char option;
	int row, col;//行列
	char row_I, col_I;//输入的行列
	int score, score_each;//分数
	int remain_star;//剩余星星
	int star[HANG][LIE] = {};
	int star_result[HANG][LIE] = { };
	while(1)
	{
		cct_setconsoleborder(130, 40);
		cct_setcolor();
		cct_cls();
		option = menu();
		if (option == 'Q')
			return 0;
		cct_cls();
		score = 0;
		f_in(star, &row, &col, NULL, NULL, 0);
		tcsz(star, row, col);
		if (option == 'A' || option == 'B' )
			f_out(option, star, star_result, row, col, row_I, col_I,score_each,score);
		if (option == 'C'){
			while (1){
				if (f_out(option, star, star_result, row, col, row_I, col_I, score_each, score) == 0)
					break;
				if (judge_star(star, row, col,remain_star) == 1)//已经结束
					break;
				cout << "\n本次消除结束，按回车键继续新一次的消除..." << endl;
				while (_getch() != '\r')
					;
			}
		}
		if (option == 'D' || option == 'F' || option == 'E') {
			bool DF = 0;
			if (option == 'D' || option == 'F')
				DF = 1;
			cct_setconsoleborder((8 - 2 * DF) * col + (5 + 2 * DF), (4 - DF) * row + (7 + DF));
			cct_cls();
			prime(star, row, col, option);
			cct_gotoxy(0, 0);
			cout << "屏幕当前设置为" << ((4 - DF) * row + (7 + DF)) << "行" << ((8 - 2 * DF) * col + (5 + 2 * DF)) << "列";
			show_XY(star, star_result, row, col, option, score_each, score);
		}
		while (option == 'G'){
			bool bre;
			static int time = 0;
			tcsz(star, row, col);
			initialsz(star_result);
			time++;
			cct_setconsoleborder(8 * col + 5, 4 * row + 7);
			cct_cls();
			prime(star, row, col, option);
			while (judge_star(star, row, col, remain_star) == 0) {
				bre = show_XY(star, star_result, row, col, option, score_each, score);
				if (bre)
					break;
			}
			if (bre)
				break;
			score_each = 1800 - 180 * (remain_star > 10 ? 10 : remain_star);
			cct_gotoxy(0, 0);
			cout << "奖励得分：" << score_each << " 总得分：" << (score += score_each) << "               ";
			cct_gotoxy(X_prime, Y_prime + 2 + 4 * row);
			if (score < (900 + 100 * time) * time)
			{
				cout << "通关分数" << ((900 + 100 * time) * time) << " 总得分：" << (score += score_each) << "游戏结束！                      " << endl;
				while (_getch() != 13)
					;
				break;
			}
			cout << "剩余" << remain_star << "个星星，无可消除项，本关结束！" << endl;
			cout << "通关分数" << ((900 + 100 * time) * time) << " 总得分：" << (score += score_each) << "回车继续下一关";
			while (_getch() != 13)
				;
			erase(X_prime, Y_prime + 2 + 4 * row, 60, 2, 0);
		}
		initialsz(star_result);
		//输入end并退出
		char end[3] = {};
		while(1){
			static bool b = 0;
			if (option == 'A' || option == 'B' || option == 'C')
				cout << endl;
			else if (option == 'E' || option == 'G')
				cct_gotoxy(0, 4 * row + 3);
			else
				cct_gotoxy(0, 3 * row + 4);
			while (getchar() != '\n')
				;
			cct_setcolor(0, 7);
			cout << "\n本小题结束，请输入End继续...";
			for (int i = 0; i < 3; i++)
				end[i] = getchar();
			if ((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D'))
				break;
			cout << "输入错误，请重新输入" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	
	while (getchar() != '\n')
		;
	return 0;
}

