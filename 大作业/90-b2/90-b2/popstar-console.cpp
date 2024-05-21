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
/* ���ܣ�����������ǵ�λ�ã��������� */
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
/* ���ܣ�����ʼ���棬��������������
   choose��1����ʼ�Ŀ��
   choose��2�ƶ������в��Ͽ�� */
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
		cct_showstr(X_prime + 2, Y_prime + 1, "�X", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1, "�T�T�T", 15, 0, col);
		cct_showstr(X_prime + 4 + 6 * col, Y_prime + 1, "�[", 15, 0);
		for (int i = 1; i <= 3 * row; i++)
		{
			if (i % 3 == 2)
				cct_showch(X_prime, Y_prime + 1 + i + (option == 'E') * (i - 1) / 3, i / 3 + 'A', 0, 7);
			//Sleep(2);
			cct_showstr(X_prime + 2, Y_prime + 1 + i + (option == 'E') * (i - 1) / 3, "�U", 15, 0);
			//Sleep(2);
			cct_showstr(X_prime + 4, Y_prime + 1 + i, "      ", 15, 0, col);
			cct_showstr(X_prime + 4 + 6 * col, Y_prime + 1 + i, "�U", 15, 0);
		}
		//Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 2 + 3 * row + (option == 'E') * (row - 1), "�^", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 2 + 3 * row, "�T", 15, 0, 3 * col);
		cct_showstr(X_prime + 4 + 6 * col, Y_prime + 2 + 3 * row, "�a", 15, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 2 + 3 * i, "�X�T�[", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 3 + 3 * i, "�U��U", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 6, Y_prime + 4 + 3 * i, "�^�T�a", 14 - star[i][j], 0);
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
		cct_showstr(X_prime + 2, Y_prime + 1, "�X", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1, "�T�T�T�j", 15, 0, col - 1);
		cct_showstr(X_prime + 4 + 8 * (col - 1), Y_prime + 1, "�T�T�T�[", 15, 0);

		for (int i = 1; i <= 3 * row; i++)
		{
			if (i % 3 == 2)
				cct_showch(X_prime, Y_prime + 1 + i + (i - 1) / 3, i / 3 + 'A', 0, 7);
			if (i % 3 == 1 && i != 1)
			{
				cct_showstr(X_prime + 2, Y_prime + i + (i - 1) / 3, "�d", 15, 0);
				cct_showstr(X_prime + 4, Y_prime + i + (i - 1) / 3, "�T�T�T�p", 15, 0, col - 1);
				cct_showstr(X_prime + 4 + 8 * (col - 1), Y_prime + i + (i - 1) / 3, "�T�T�T�g", 15, 0);
			}
			Sleep(2);
			cct_showstr(X_prime + 2, Y_prime + 1 + i + (i - 1) / 3, "�U", 15, 0);
			Sleep(2);
			cct_showstr(X_prime + 4, Y_prime + 1 + i + (i - 1) / 3, "      �U", 15, 0, col);
		}
		Sleep(2);
		cct_showstr(X_prime + 2, Y_prime + 1 + 4 * row, "�^", 15, 0);
		cct_showstr(X_prime + 4, Y_prime + 1 + 4 * row, "�T�T�T�m", 15, 0, col - 1);
		cct_showstr(X_prime - 4 + 8 * col, Y_prime + 1 + 4 * row, "�T�T�T�a", 15, 0);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 2 + 4 * i, "�X�T�[", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 3 + 4 * i, "�U��U", 14 - star[i][j], 0);
				//Sleep(2);
				cct_showstr(X_prime + 4 + j * 8, Y_prime + 4 + 4 * i, "�^�T�a", 14 - star[i][j], 0);
			}
		}
	}
	cct_setcolor(0, 7);
}
/* ���ܣ���ȡ���̺����״̬�����ú���ʵ��ͼ�α仯
   ����1����q/Qʱ��main����ѭ���˳�
   ����0��main��������ѭ�� */
bool show_XY(int star[][LIE], int star_result[][LIE], int row, int col, char option, int& score_each, int& score)
{
	int X = X_0, Y = Y_A;//��¼���λ��
	int X_old = NULL, Y_old = NULL;//��¼��һ�ε�λ��
	int ret, maction;
	int keycode1, keycode2;
	int sum = 0;
	char row_I = 'A', col_I = '0';
	int star_result_copy[HANG][LIE];
	bool DF = 0;
	if (option == 'D' || option == 'F')
		DF = 1;
	cct_enable_mouse();
	/* ��ӡ��ʼ���λ��[0,0] */
	cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
	for (int i = 0; i < row; i++) {  //ȷ����ʼ��ѡ��ɫλ��Ϊ��һ�е�һ����Ϊ0��λ��
		if (star[i][0] != 0) {
			row_I += i;
			break;
		}
	}
	highlight_star(row_I - 'A', col_I - '0', star, NULL, row, col, option);
	while (1) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		X = (X - X_0);
		Y = (Y - Y_A);
		/*****************************************
		   ��һ��if���̵�������ڶ���ifΪ������
		   sum��¼�°���������߻س��Ĵ���
		   ����sum==0ʱΪDEFG������highlight_star
		   sum==1ʱΪFG������ɾ�����飬G��ֱ������
		   sum==2ʱΪF�����·�������
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
						cout << "���ε÷֣�" << score_each << " �ܵ÷֣�" << (score += score_each) << "       ";
						if (option == 'G'){
							change_star(star, star_result, row, col, 3, option);
							return 0;
						}
						break;
					case keycode_arrow://��ͷ��
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
				erase(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, 80, 1, 0);//����
				cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "[��ǰ����] ");
				switch (keycode1) {
					case keycode_Q:
						return 1;
					case keycode_q:
						return 1;
					case keycode_r://�س�
						cct_gotoxy(X_prime, Y_prime + (2 + DF) + (4 - DF) * row);
						cout << "ѡ����" << row_I << "��" << col_I << "��        ";
						if (option == 'D' || option == 'E')
							return 0;
						else {
							if (surrounding(star, NULL, row_I, col_I, 1) == 0) {
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "��Χ����ֵͬ����ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����");
								sum = 0;
								continue;
							}
							else {
								for (int i = 0; i < row; i++) {
									for (int j = 0; j < col; j++)
										star_result_copy[i][j] = star_result[i][j];
								}
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
								change_star_result(star, star_result, row_I, col_I, row, col);
								highlight_star(row_I - 'A', col_I - '0', star, star_result, row, col, option);
								sum = 1;
								X_old = X;
								Y_old = Y;
							}
						}
						break;
					case keycode_arrow://��ͷ��
						keycode_224(keycode2, row_I, col_I, row, col, star);
						Y = (row_I - 'A') * (4 - DF) + 2;
						X = (col_I - '0') * (8 - 2 * DF) + 4;
						cout << row_I << "��" << col_I << "��";
						highlight_star(row_I - 'A', col_I - '0', star, NULL, row, col, option);
						break;
				}//end of swicth(keycode1)
			}
		}
		if (ret == CCT_MOUSE_EVENT) {
			if (sum == 1) {  //sum==1
				if (X == X_old && Y == Y_old && maction == MOUSE_MOVED) {  //XY����ʱ����״̬
					highlight_star(Y / (4 - DF), X / (8 - 2 * DF), star, star_result, row, col, option);
					cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
				}
				else if (X == X_old && Y == Y_old && maction == MOUSE_LEFT_BUTTON_CLICK) {  //����������
					erase_star(star_result, row, col, option);
					sum = 2;
					score_each = change_star(star, star_result, row, col, 1, NULL);
					score_each = score_each * score_each * 5;
					cct_gotoxy(0, 0);
					cout << "���ε÷֣�" << score_each << " �ܵ÷֣�" << (score += score_each) << "       ";
					if (option == 'G') {
						change_star(star, star_result, row, col, 3, option);
						break;
					}
				}
				else if (X != X_old || Y != Y_old) {  //�ƶ�ȡ��ѡ��
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
				erase(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, 80, 1, 0);//����
				row_I = Y / (4 - DF) + 'A';
				col_I = X / (8 - 2 * DF) + '0';
				cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "[��ǰ���] ");
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
					cout << row_I << "��" << col_I << "��";
					highlight_star(Y / (4 - DF), X / (8 - 2 * DF), star, NULL, row, col, option);
					if (maction == MOUSE_LEFT_BUTTON_CLICK)
					{
						cct_gotoxy(X_prime, Y_prime + (2 + DF) + (4 - DF) * row);
						cout << "ѡ����" << row_I << "��" << col_I << "��        ";
						if (option == 'D' || option == 'E')
							break;
						else
						{
							if (surrounding(star, NULL, row_I, col_I, 1) == 0)
							{
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "��Χ����ֵͬ����ͷ��/����ƶ����س���/�������ѡ��Q/�����Ҽ�����");
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
								cct_showstr(X_prime, Y_prime + (2 + DF) + (4 - DF) * row, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
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
					cout << "λ�÷Ƿ�";	
			}
		} //end of if (CCT_MOUSE_EVENT)
	} //end of while(1)
	cct_setcolor(0, 7);
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
	return 0;
}
/* ���ܣ���ѡ������ɫ
   star_result==NULL:ֻ��ѡһ��
   star_result!=NULL:��ѡ�������ŵ�����*/
void highlight_star(int row_I, int col_I, int star[][LIE], int star_result[][LIE],int row, int col,int option)
{
	bool b = 0;
	if (option == 'E' || option == 'G')
		b = 1;
	if(star_result==NULL)//ֻ��ɫ��ѡһ��
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((i == row_I && j == col_I) || star[i][j] == 0)
					continue;
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i, "�X�T�[", 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 3 + (3 + b) * i, "�U��U", 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 4 + (3 + b) * i, "�^�T�a", 14 - star[i][j], 0);
			}
		}//��һ���ָ���ɫ
		if (star[row_I][col_I] != 0) {	 //row_I,col_I��ɫ
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 2 + row_I * (3 + b), "�X�T�[", 14 - star[row_I][col_I], 7);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 3 + row_I * (3 + b), "�U��U", 14 - star[row_I][col_I], 7);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 4 + row_I * (3 + b), "�^�T�a", 14 - star[row_I][col_I], 7);
		}
	}
	else//��ɫ��ѡ���д��Ǻŵ�
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (star_result[i][j] == 1 && star[i][j] != 0)
				{
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + i * (3 + b), "�X�T�[", 14 - star[i][j], 7);
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 3 + i * (3 + b), "�U��U", 14 - star[i][j], 7);
					cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 4 + i * (3 + b), "�^�T�a", 14 - star[i][j], 7);
				}
			}
		}
		if (star[row_I][col_I] != 0) {	 //row_I,col_I��ɫ
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 2 + row_I * (3 + b), "�X�T�[", 14 - star[row_I][col_I], 15);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 3 + row_I * (3 + b), "�U��U", 14 - star[row_I][col_I], 15);
			cct_showstr(X_prime + 4 + col_I * (6 + b * 2), Y_prime + 4 + row_I * (3 + b), "�^�T�a", 14 - star[row_I][col_I], 15);
		}
	}
	cct_setcolor(0, 7);
}
/* ���ܣ��ƶ����ǣ���������ԭ���Ǻͻ�����һ������
   choose==1����ֱ����
   choose==2��ˮƽ�ƶ����� */
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
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 0), ((Y_prime + 2 + (3 + b) * i - (k - 0)) % 4 == 2 && b == 1 ? "�T�T�T" : "      "), 15, 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 1), ((Y_prime + 2 + (3 + b) * i - (k - 1)) % 4 == 2 && b == 1 ? "�T�T�T" : "�X�T�["), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 2), ((Y_prime + 2 + (3 + b) * i - (k - 2)) % 4 == 2 && b == 1 ? "�T�T�T" : "�U��U"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2), Y_prime + 2 + (3 + b) * i - (k - 3), ((Y_prime + 2 + (3 + b) * i - (k - 3)) % 4 == 2 && b == 1 ? "�T�T�T" : "�^�T�a"), 14 - star[i][j], 0);
			}
		}
	}
	else if (choose == 2) {
		for (int k = 6 + b * 2; k >= 1; k--) {
			if (star[i][j] > 0) {
				Sleep(1);
				erase(X_prime + 4 + j * (6 + b * 2) + k, Y_prime + 2 + (3 + b) * i, 6, 3, 15);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 2 + (3 + b) * i, ((Y_prime + 2 + (3 + b) * i) % 4 == 2 && b == 1 ? "�T�T�T" : "�X�T�["), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 3 + (3 + b) * i, ((Y_prime + 3 + (3 + b) * i) % 4 == 2 && b == 1 ? "�T�T�T" : "�U��U"), 14 - star[i][j], 0);
				cct_showstr(X_prime + 4 + j * (6 + b * 2) + (k - 1), Y_prime + 4 + (3 + b) * i, ((Y_prime + 4 + (3 + b) * i) % 4 == 2 && b == 1 ? "�T�T�T" : "�^�T�a"), 14 - star[i][j], 0);
			}
		}
		if (b) {
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 2 + (3 + b) * i, "�U", 15, 0);
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 3 + (3 + b) * i, "�U", 15, 0);
			cct_showstr(X_prime + 2 + (j + 1) * 8, Y_prime + 4 + (3 + b) * i, "�U", 15, 0);
		}
	}
}
/* ���ܣ����ݼ�������ļ�ͷָ��ı���ѡ���� */
void keycode_224(int keycode2, char& row_I, char& col_I, int row, int col,int star[][LIE])
{
	while(1){
		switch (keycode2) {
			case KB_ARROW_UP://�ϼ�ͷ
				row_I -= 1;
				break;
			case KB_ARROW_DOWN://�¼�ͷ
				row_I += 1;
				break;
			case KB_ARROW_LEFT://���ͷ
				col_I -= 1;
				break;
			case KB_ARROW_RIGHT://�Ҽ�ͷ
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

