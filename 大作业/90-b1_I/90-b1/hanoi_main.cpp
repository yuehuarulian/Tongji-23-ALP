/* ��04 2252941 ������ */
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

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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
		if (!option)//�ж�option�Ƿ�Ϊ0�˳�
			break;
		if (option != 5)
		{
			f_in(&src, &tmp, &dst, &n, option);//����ABC����delay
			tcsz(src, n, han, top);
		}
		if (option >= 4)
			cct_cls();
		if (option == 5)
			draw_z(option);
		if (option >= 6 )
		{
			cout << "��" << src << "�ƶ���" << dst << ", ��" << setw(2) << n << "��";
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
			int yd = 0;//��ǰ�ƶ��̺�
			int back;
			cct_gotoxy(0, 34);
			cout << "�������ƶ�������(������ʽ:AC=A���˵������ƶ���C,Q=�˳�):";
			while (1)
			{
				back = f_in_I(&src_I, &dst_I, han, top);
				if (!back)
				{
					cct_gotoxy(0, 35);
					cout << "��Ϸ��ֹ!!!!!";
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
					cout << "��Ϸ����!!!!!";
					break;
				}
			}
		}
		if (option != 3 && option != 2 && option != 1)
			cct_gotoxy(0, 38);
		else
			cout << endl;
		cout << "���س�������";
		while (1)
		{
			if (_getch() == 13)
				break;
		}
	}
	return 0;
}