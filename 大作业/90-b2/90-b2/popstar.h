/* ��04 2252941 ������ */
#pragma once
#define X_prime  0
#define Y_prime  1
#define X_0  4
#define Y_A  3
#define HANG  10
#define LIE  10
#define keycode_Q 81
#define keycode_q 113
#define keycode_r 13
#define keycode_arrow 224
/* main */
char menu();
/* tools ������� С��ABC */
void f_in(int star[][LIE], int* row, int* col, char* row_I, char* col_I, int choose);//�������
bool f_out(char option, int star[][LIE], int star_result[][LIE], int row, int col, char& row_I, char& col_I, int& score_each, int& score);//������ú����ĺ���
void f_out_ABC(int star[][LIE], int star_result[][LIE], int row, int col,int choose);
/* base ����ʵ�ֺ͸ı� */
void tcsz(int star[][LIE], int row, int col);//�������
void initialsz(int star[][LIE]);//��ʼ������
int change_star(int star[][LIE], int star_result[][LIE], int row, int col,int choose,int option);//�ı����ǣ�������������
void change_star_result(int star[][LIE], int star_result[][LIE], char row_I, char col_I,char row,char col);//�ı�star_result,����'*'
bool surrounding(int star[][LIE], int star_result[][LIE], char row_I, char col_I, bool color);//�ж���Χ��ͬ����
bool judge_star(int star[][LIE], int row, int col, int& remain_star);//�жϽ���������ʣ����������
/* console ��ͼ */
void erase_star(int star_result[][LIE], int row, int col, char option);
void erase(int x, int y, int len, int high, int color);
void prime(int star[][LIE], int row, int col,char option);//��ʼ����
bool show_XY(int star[][LIE], int star_result[][LIE], int row, int col, char option, int& score_each, int& score);//�������ƶ���ѡ��
void highlight_star(int row_I, int col_I, int star[][LIE], int star_result[][LIE], int row,int col,int option);//����ƶ���ͼ����ǿ����ɫ
void move_star(int star[][LIE], int j, int i, int choose,int option);//�ƶ�����
void keycode_224(int keycode2, char& row_I, char& col_I, int row, int col, int star[][LIE]);//�����ƶ��жϽ���λ��
