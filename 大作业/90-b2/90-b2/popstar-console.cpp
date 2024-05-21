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
/* 功能：输入擦除星星的位置，擦除星星 */
void erase_star(int star_result[][LIE],int row,int col,char option)
{
	bool b = 0;
	if (option == 'G')
		b = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (star_result[i][j] == 1)
			{
				erase(X_prime +4 + j * (6 + b * 2), Y_prime +2 + (3 + b) * i, 6, 3, 15);
			}
		}
	}
	

}
void erase(int x, int y, int len, int high, int color)
{
	for (int k = 0; k < high; k++)
		cct_showch(x, y + k, ' ', color, 7, len);
	cct_setcolor();
	cct_gotoxy(x, y);
}
/* 功能：画初始界面，包括背景和星星
   choose：1画初始的框架
   choose：2移动过程中补上框架 */
void prime(int star[][LIE], int row, int col,char option)
{
	if (option == 'D' || option == 'F'){
		for (int i = 0; i < col; i++)
		{
			//Sleep(2);
			cct_showch(X_prime + 5 + 6 * i, Y_prime, ' ', 0, 7);
			//Sleep(2);
			cct_showch(X_prime + 6 + 6 * i, Y_prime, i + '0', 0, 7);
			//Sleep(2);
			cct_showch(X_prime + 7 + 6 * i, Y_prime, ' ', 0, 7, 4);
		}
		//Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 1, "╔", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1, "═══", 15, 0, col);
		cct_showstr(X_prime + 4 + 6 * col, Y_prime + 1, "╗", 15, 0);
		for (int i = 1; i <= 3 * row; i++)
		{
			if (i % 3 == 2)
				cct_showch(X_prime, Y_prime + 1 + i + (option == 'E') * (i - 1) / 3, i / 3 + 'A', 0, 7);
			//Sleep(2);
			cct_showstr(X_prime + 2, Y_prime + 1 + i + (option == 'E') * (i - 1) / 3, "║", 15, 0);
			//Sleep(2);
			cct_showstr(X_prime + 4, Y_prime + 1 + i, "      ", 15, 0, col);
			cct_showstr(X_prime + 4 + 6 * col, Y_prime + 1 + i, "║", 15, 0);
		}
		//Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 2 + 3 * row + (option == 'E') * (row - 1), "╚", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 2 + 3 * row, "═", 15, 0, 3 * col);
		cct_showstr(X_prime + 4 + 6 * col, Y_prime + 2 + 3 * row, "╝", 15, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 2 + 3 * i, "╔═╗", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 3 + 3 * i, "║★║", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 4 + 3 * i, "╚═╝", 14 - star[i][j], 0);
			}
		}
	}
	else if (option == 'E' || option == 'G'){
		for (int i = 0; i < col; i++)
		{
			Sleep(2);
			cct_showch(X_prime + 5 + 8 * i, Y_prime, ' ', 0, 7);
			Sleep(2);
			cct_showch(X_prime + 6 + 8 * i, Y_prime, i + '0', 0, 7);
			Sleep(2);
			cct_showch(X_prime + 7 + 8 * i, Y_prime, ' ', 0, 7, 6);
		}
		Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 1, "╔", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1, "═══╦", 15, 0, col - 1);
		cct_showstr(X_prime + 4 + 8 * (col - 1), Y_prime + 1, "═══╗", 15, 0);

		for (int i = 1; i <= 3 * row; i++)
		{
			if (i % 3 == 2)
				cct_showch(X_prime, Y_prime + 1 + i + (i - 1) / 3, i / 3 + 'A', 0, 7);
			if (i % 3 == 1 && i != 1)
			{
				cct_showstr(X_prime + 2, Y_prime + i + (i - 1) / 3, "╠", 15, 0);
				cct_showstr(X_prime + 4, Y_prime + i + (i - 1) / 3, "═══╬", 15, 0, col - 1);
				cct_showstr(X_prime + 4 + 8 * (col - 1), Y_prime + i + (i - 1) / 3, "═══╣", 15, 0);
			}
			Sleep(2);
			cct_showstr(X_prime + 2, Y_prime + 1 + i + (i - 1) / 3, "║", 15, 0);
			Sleep(2);
			cct_showstr(X_prime + 4, Y_prime + 1 + i + (i - 1) / 3, "      ║", 15, 0, col);
		}
		Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 1 + 4 * row, "╚", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1 + 4 * row, "═══╩", 15, 0, col - 1);
		cct_showstr(X_prime - 4 + 8 * col, Y_prime + 1 + 4 * row, "═══╝", 15, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 2 + 4 * i, "╔═╗", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 3 + 4 * i, "║★║", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 4 + 4 * i, "╚═╝", 14 - star[i][j], 0);
			}
		}
	}
	cct_setcolor(0, 7);
}
/* 功能：读取键盘和鼠标状态并调用函数实现图形变化
   返回1：按q/Q时，main函数循环退出
   返回0：main函数继续循环 */
bool show_XY(int star[][LIE], int star_result[][LIE], int row, int col, char option, int& score_each, int& score)
{
	int X = X_0, Y = Y_A;//记录鼠标位置
	int X_old = NULL, Y_old = NULL;//记录上一次的位置
	int ret, maction;
	int keycode1, keycode2;
	int sum = 0;
	char row_I = 'A', col_I = '0';
	int star_result_copy[HANG][LIE];
	bool DF = 0;
	if (option == 'D' || option == 'F')
		DF = 1;
	cct_enable_mouse();
	/* 打印初始光标位置[0,0] */
	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	for (int i = 0; i < row; i++) {  //确定初始反选颜色位置为第一列第一个不为0的位置
		if (star[i][0] != 0) {
			row_I += i;
			break;
		}
	}
	highlight_star(row_I - 'A', col_I - '0', star, NULL, row, col, option);
	while (1) {
		/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		X = (X - X_0);
		Y = (Y - Y_A);
		/*****************************************
		   第一个if键盘的情况，第二个if为鼠标情况
		   sum记录下按下左键或者回车的次数
		   其中sum==0时为DEFG，按下highlight_star
		   sum==1时为FG，按下删除方块，G会直接下落
		   sum==2时为F，按下方块下落
		 *****************************************/
		if (ret == CCT_KEYBOARD_EVENT){
			if (sum == 1) {
				int bre = 0;
				switch (keycode1) {
					case keycode_Q:
						return 1;
					case keycode_q:
						return 1;
					case keycode_r:
						erase_star(star_result, row, col, option);
						sum = 2;
						score_each = change_star(star, star_result, row, col, 1, NULL);
						score_each = score_each * score_each * 5;
						cct_gotoxy(0, 0);
						cout << "本次得分：" << score_each << " 总得分：" << (score += score_each) << "       ";
						if (option == 'G'){
							change_star(star, star_result, row, col, 3, option);
							return 0;
						}
						break;
					case keycode_arrow://箭头键
						keycode_224(keycode2, row_I, col_I, row, col, star);
						sum = 0;
						X_old = X;
						Y_old = Y;
						for (int i = 0; i < row; i++)
						{
							for (int j = 0; j < col; j++)
								star_result[i][j] = star_result_copy[i][j];
						}
						break;
				}//end of swicth(keycode1)
				if (bre == 1)
					break;
			}
			if (sum == 2 && keycode1 == 13) {
				change_star(star, star_result, row, col, 1, NULL);
				change_star(star, star_result, row, col, 3, option);
				break;
			}
			if (sum == 0) {
				erase(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, 80, 1, 0);//擦除
				cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "[当前按键] ");
				switch (keycode1) {
					case keycode_Q:
						return 1;
					case keycode_q:
						return 1;
					case keycode_r://回车
						cct_gotoxy(X_prime, Y_prime + (2 + DF) + (4 - DF) * row);
						cout << "选中了" << row_I << "行" << col_I << "列        ";
						if (option == 'D' || option == 'E')
							return 0;
						else {
							if (surrounding(star, NULL, row_I, col_I, 1) == 0) {
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "周围无相同值，箭头键/鼠标移动，回车键/单击左键选择，Q/单机右键结束");
								sum = 0;
								continue;
							}
							else {
								for (int i = 0; i < row; i++) {
									for (int j = 0; j < col; j++)
										star_result_copy[i][j] = star_result[i][j];
								}
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "箭头键/鼠标移动取消当前选择，回车键/单击左键合成");
								change_star_result(star, star_result, row_I, col_I, row, col);
								highlight_star(row_I - 'A', col_I - '0', star, star_result, row, col, option);
								sum = 1;
								X_old = X;
								Y_old = Y;
							}
						}
						break;
					case keycode_arrow://箭头键
						keycode_224(keycode2, row_I, col_I, row, col, star);
						Y = (row_I - 'A') * (4 - DF) + 2;
						X = (col_I - '0') * (8 - 2 * DF) + 4;
						cout << row_I << "行" << col_I << "列";
						highlight_star(row_I - 'A', col_I - '0', star, NULL, row, col, option);
						break;
				}//end of swicth(keycode1)
			}
		}
		if (ret == CCT_MOUSE_EVENT) {
			if (sum == 1) {  //sum==1
				if (X == X_old && Y == Y_old && maction == MOUSE_MOVED) {  //XY不变时保持状态
					highlight_star(Y / (4 - DF), X / (8 - 2 * DF), star, star_result, row, col, option);
					cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "箭头键/鼠标移动取消当前选择，回车键/单击左键合成");
				}
				else if (X == X_old && Y == Y_old && maction == MOUSE_LEFT_BUTTON_CLICK) {  //点击左键擦除
					erase_star(star_result, row, col, option);
					sum = 2;
					score_each = change_star(star, star_result, row, col, 1, NULL);
					score_each = score_each * score_each * 5;
					cct_gotoxy(0, 0);
					cout << "本次得分：" << score_each << " 总得分：" << (score += score_each) << "       ";
					if (option == 'G') {
						change_star(star, star_result, row, col, 3, option);
						break;
					}
				}
				else if (X != X_old || Y != Y_old) {  //移动取消选择
					sum = 0;
					X_old = X;
					Y_old = Y;
					for (int i = 0; i < row; i++)
					{
						for (int j = 0; j < col; j++)
							star_result[i][j] = star_result_copy[i][j];
					}
				}
			}
			if (sum == 2 && maction == MOUSE_LEFT_BUTTON_CLICK) {  //sum==2
				change_star(star, star_result, row, col, 1, NULL);
				change_star(star, star_result, row, col, 3, option);
				sum = 0;
				break;
			}
			if (sum == 0) {  //sum==0
				bool b = 0;
				erase(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, 80, 1, 0);//擦除
				row_I = Y / (4 - DF) + 'A';
				col_I = X / (8 - 2 * DF) + '0';
				cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "[当前鼠标] ");
				if (DF && X >= 0 && X <= 6 * col - 1 && Y >= 0 && Y <= 3 * row - 1)
					b = 1;
				else if (!DF) {
					for (int i = 0; i < col; i++) {
						for (int j = 0; j < row; j++) {
							if (X >= i * 8 && X <= i * 8 + 5 && Y >= j * 4 && Y <= j * 4 + 2)
								b = 1;
						}
					}
				}
				if (b) {
					cout << row_I << "行" << col_I << "列";
					highlight_star(Y / (4 - DF), X / (8 - 2 * DF), star, NULL, row, col, option);
					if (maction == MOUSE_LEFT_BUTTON_CLICK)
					{
						cct_gotoxy(X_prime, Y_prime + (2 + DF) + (4 - DF) * row);
						cout << "选中了" << row_I << "行" << col_I << "列        ";
						if (option == 'D' || option == 'E')
							break;
						else
						{
							if (surrounding(star, NULL, row_I, col_I, 1) == 0)
							{
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "周围无相同值，箭头键/鼠标移动，回车键/单击左键选择，Q/单机右键结束");
								sum = 0;
								continue;
							}
							else
							{
								for (int i = 0; i < row; i++)
								{
									for (int j = 0; j < col; j++)
										star_result_copy[i][j] = star_result[i][j];
								}
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "箭头键/鼠标移动取消当前选择，回车键/单击左键合成");
								change_star_result(star, star_result, row_I, col_I, row, col);
								sum = 1;
								X_old = X;
								Y_old = Y;
							}
							continue;
						}
					}
				}
				else
					cout << "位置非法";	
			}
		} //end of if (CCT_MOUSE_EVENT)
	} //end of while(1)
	cct_setcolor(0, 7);
	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
	return 0;
}
/* 功能：反选星星颜色
   star_result==NULL:只反选一个
   star_result!=NULL:反选所有连着的星星*/
void highlight_star(int row_I, int col_I, int star[][LIE], int star_result[][LIE],int row, int col,int option)
{
	bool b = 0;
	if (option == 'E' || option == 'G')
		b = 1;
	if(star_result==NULL)//只颜色反选一个
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((i == row_I && j == col_I) || star[i][j] == 0)
					continue;
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i, "╔═╗", 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 3 + (3 + b) * i, "║★║", 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 4 + (3 + b) * i, "╚═╝", 14 - star[i][j], 0);
			}
		}//上一个恢复颜色
		if (star[row_I][col_I] != 0) {	 //row_I,col_I上色
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 2 + row_I * (3 + b), "╔═╗", 14 - star[row_I][col_I], 7);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 3 + row_I * (3 + b), "║★║", 14 - star[row_I][col_I], 7);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 4 + row_I * (3 + b), "╚═╝", 14 - star[row_I][col_I], 7);
		}
	}
	else//颜色反选所有打星号的
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (star_result[i][j] == 1 && star[i][j] != 0)
				{
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + i * (3 + b), "╔═╗", 14 - star[i][j], 7);
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 3 + i * (3 + b), "║★║", 14 - star[i][j], 7);
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 4 + i * (3 + b), "╚═╝", 14 - star[i][j], 7);
				}
			}
		}
		if (star[row_I][col_I] != 0) {	 //row_I,col_I上色
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 2 + row_I * (3 + b), "╔═╗", 14 - star[row_I][col_I], 15);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 3 + row_I * (3 + b), "║★║", 14 - star[row_I][col_I], 15);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 4 + row_I * (3 + b), "╚═╝", 14 - star[row_I][col_I], 15);
		}
	}
	cct_setcolor(0, 7);
}
/* 功能：移动星星，包括擦除原星星和画出下一个星星
   choose==1：竖直下落
   choose==2：水平移动方块 */
void move_star(int star[][LIE], int i, int j, int choose, int option)
{
	bool b = 0;
	if (option == 'G')
		b = 1;
	if (choose == 1) {
		for (int k = 3 + b; k >= 1; k--) {
			if (star[i][j] > 0) {
				Sleep(1);
				erase(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - k, 6, 3, 15);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 0), ((Y_prime + 2 + (3 + b) * i - (k - 0)) % 4 == 2 && b == 1 ? "═══" : "      "), 15, 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 1), ((Y_prime + 2 + (3 + b) * i - (k - 1)) % 4 == 2 && b == 1 ? "═══" : "╔═╗"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 2), ((Y_prime + 2 + (3 + b) * i - (k - 2)) % 4 == 2 && b == 1 ? "═══" : "║★║"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 3), ((Y_prime + 2 + (3 + b) * i - (k - 3)) % 4 == 2 && b == 1 ? "═══" : "╚═╝"), 14 - star[i][j], 0);
			}
		}
	}
	else if (choose == 2) {
		for (int k = 6 + b * 2; k >= 1; k--) {
			if (star[i][j] > 0) {
				Sleep(1);
				erase(X_prime + 4 + j * (6 + b * 2) + k, Y_prime + 2 + (3 + b) * i, 6, 3, 15);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 2 + (3 + b) * i, ((Y_prime + 2 + (3 + b) * i) % 4 == 2 && b == 1 ? "═══" : "╔═╗"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 3 + (3 + b) * i, ((Y_prime + 3 + (3 + b) * i) % 4 == 2 && b == 1 ? "═══" : "║★║"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 4 + (3 + b) * i, ((Y_prime + 4 + (3 + b) * i) % 4 == 2 && b == 1 ? "═══" : "╚═╝"), 14 - star[i][j], 0);
			}
		}
		if (b) {
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 2 + (3 + b) * i, "║", 15, 0);
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 3 + (3 + b) * i, "║", 15, 0);
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 4 + (3 + b) * i, "║", 15, 0);
		}
	}
}
/* 功能：根据键盘输入的箭头指向改变所选星星 */
void keycode_224(int keycode2, char& row_I, char& col_I, int row, int col,int star[][LIE])
{
	while(1){
		switch (keycode2) {
			case KB_ARROW_UP://上箭头
				row_I -= 1;
				break;
			case KB_ARROW_DOWN://下箭头
				row_I += 1;
				break;
			case KB_ARROW_LEFT://左箭头
				col_I -= 1;
				break;
			case KB_ARROW_RIGHT://右箭头
				col_I += 1;
				break;
			default:
				break;
		}
		if (row_I < 'A')
			row_I = 'A' + row - 1;
		if (row_I > 'A' + row - 1)
			row_I = 'A';
		if (col_I < '0')
			col_I = '0' + col - 1;
		if (col_I > '0' + col - 1)
			col_I = '0';
		if (star[row_I - 'A'][col_I - '0'] != 0)
			break;
	}
}

