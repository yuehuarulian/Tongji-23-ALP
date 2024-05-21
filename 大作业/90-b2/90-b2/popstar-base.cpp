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
void tcsz(int star[][LIE], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			star[i][j] = rand() % 5 + 1;
	}
}
void initialsz(int star[][LIE])
{
	for (int i = 0; i < HANG;i++)
	{
		for (int j = 0; j < LIE; j++)
			star[i][j] = 0;
	}
}
/* ����surrounding���ı�star_result����ġ�*��*/
void change_star_result(int star[][LIE], int star_result[][LIE], char row_I, char col_I, char row, char col)
{
	surrounding(star, star_result, row_I, col_I, 1);
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				if (star_result[i][j] == 1)
					surrounding(star, star_result, i + 'A', j + '0', 1);
			}
		}
	}
}
/* �ж�row_I,col_I��Χ����ֵͬ�м��������ظ��������Ƿ��� */
bool surrounding(int star[][LIE], int star_result[][LIE], char row_I, char col_I, bool color)
{
	int num = 0;
	int row = row_I - 'A';
	int col = col_I - '0';

	if (star_result != NULL)
		star_result[row][col] = 1;

	if (col - 1 >= 0 && star[row][col - 1] == star[row][col]) {
		if (star_result != NULL && star_result[row][col - 1] != 1) {
			star_result[row][col - 1] = 1;
			num++;
		}
		else if (star_result == NULL)
			return 1;
	}
	if (col + 1 < LIE && star[row][col + 1] == star[row][col]) {
		if (star_result != NULL && star_result[row][col + 1] != 1) {
			star_result[row][col + 1] = 1;
			num++;
		}
		else if (star_result == NULL)
			return 1;
	}
	if (row - 1 >= 0 && star[row - 1][col] == star[row][col]) {
		if (star_result != NULL && star_result[row - 1][col] != 1) {
			star_result[row - 1][col] = 1;
			num++;
		}
		else if (star_result == NULL)
			return 1;
	}
	if (row + 1 < HANG && star[row + 1][col] == star[row][col]) {
		if (star_result != NULL && star_result[row + 1][col] != 1) {
			star_result[row + 1][col] = 1;
			num++;
		}
		else if (star_result == NULL)
			return 1;
	}
	return num;
}

/* ����row��col�ı�star��star_result
   choose==1��star�е�ֵ���㣬����num����������������
   choose==2��star�е�ֵ����
   choose==3��star�е�ֵ����+����
*/
int change_star(int star[][LIE], int star_result[][LIE],int row,int col,int choose,int option)
{
	int num = 0;
	int judge = 0;
	if(choose==1)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (star_result[i][j] == 1 && star[i][j] != 0)
				{
					num++;
					star[i][j] = 0;
				}
			}
		}
	}
	if (choose == 2||choose==3)
	{
		//for (int i = 0; i < col; i++)//������ֱ
		//{
		//	int judge = 0;
		//	for (int j = 0; j < row; j++)
		//	{
		//		if (star[j][i] == 0)
		//		{
		//			if (++judge == j + 1)
		//				continue;
		//			for (int k = j; k > 0; k--)//exchange star[k][i] star[k-1][i]
		//			{
		//				int t = star[k - 1][i];
		//				star[k - 1][i] = star[k][i];
		//				star[k][i] = t;
		//				t = star_result[k - 1][i];
		//				star_result[k - 1][i] = star_result[k][i];
		//				star_result[k][i] = t;
		//				if (choose == 3)
		//				{
		//					Sleep(20);
		//					move_star(star, k, i, 1,option);//��ֱ���䶯��
		//				}
		//			}
		//		}
		//	}
		//}
		for (int i = 0; i < col; i++) {  //������ֱ
			for (int j = row - 1; j > 0; j--) {
				if (star[j][i] == 0 && star[j - 1][i] != 0)
				{
					for (int k = j; star[k][i] == 0 && k < row; k++) {  //exchange star[j][i]��������һ��0��λ��
						int t = star[k - 1][i];
						star[k - 1][i] = star[k][i];
						star[k][i] = t;
						t = star_result[k - 1][i];
						star_result[k - 1][i] = star_result[k][i];
						star_result[k][i] = t;
						if (choose == 3) {
							Sleep(5);
							move_star(star, k, i, 1, option);//��ֱ���䶯��
						}
					}

				}
			}
		}
		for (int i = col - 1, judge = 0; i >= 0; i--) {//����ˮƽ
			for (int j = 0; j < row; j++){
				if (star[j][i] != 0)
					break;
				if (j == row - 1){
					if (++judge == col - i)
						continue;
					for (int k = j; k >= 0; k--){
						for (int g = i; g + 1 < col; g++) {//exchange star[k][g] star[k][g+1]
							int t = star[k][g];
							star[k][g] = star[k][g + 1];
							star[k][g + 1] = t;
							t = star_result[k][g];
							star_result[k][g] = star_result[k][g + 1];
							star_result[k][g + 1] = t;
							if (choose == 3){
								Sleep(1);
								move_star(star, k, g, 2, option);//ˮƽ����
							}
						}
					}
				}
					
			}
		}
	}
	return num;
}
/* �ж������ǲ����޿������������ʣ�������� */
bool judge_star(int star[][LIE],int row,int col,int &remain_star)
{
	remain_star = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;j++)
		{
			if (star[i][j] != 0)
				remain_star++;
			if (star[i][j] != 0 && surrounding(star, NULL, i + 'A', j + '0', 1) == 1)
			{
				return 0;//δ����
			}
		}
	}
	return 1;//�Ѿ�����
}

