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
char menu()
{
	char option;
	cout << "--------------------------------------------\n"
		<< "A.�������ҳ����������ʶ\n"
		<< "B.���������һ���������ֲ�����ʾ��\n"
		<< "C.���������һ�أ��ֲ�����ʾ��\n"
		<< "D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�\n"
		<< "E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�\n"
		<< "F.αͼ�ν������һ���������ֲ��裩\n"
		<< "G.αͼ�ν���������\n"
		<< "Q.�˳�\n"
		<< "--------------------------------------------\n"
		<< "[��ѡ��:]";
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
	int row, col;//����
	char row_I, col_I;//���������
	int score, score_each;//����
	int remain_star;//ʣ������
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
				if (judge_star(star, row, col,remain_star) == 1)//�Ѿ�����
					break;
				cout << "\n�����������������س���������һ�ε�����..." << endl;
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
			cout << "��Ļ��ǰ����Ϊ" << ((4 - DF) * row + (7 + DF)) << "��" << ((8 - 2 * DF) * col + (5 + 2 * DF)) << "��";
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
			cout << "�����÷֣�" << score_each << " �ܵ÷֣�" << (score += score_each) << "               ";
			cct_gotoxy(X_prime, Y_prime + 2 + 4 * row);
			if (score < (900 + 100 * time) * time)
			{
				cout << "ͨ�ط���" << ((900 + 100 * time) * time) << " �ܵ÷֣�" << (score += score_each) << "��Ϸ������                      " << endl;
				while (_getch() != 13)
					;
				break;
			}
			cout << "ʣ��" << remain_star << "�����ǣ��޿���������ؽ�����" << endl;
			cout << "ͨ�ط���" << ((900 + 100 * time) * time) << " �ܵ÷֣�" << (score += score_each) << "�س�������һ��";
			while (_getch() != 13)
				;
			erase(X_prime, Y_prime + 2 + 4 * row, 60, 2, 0);
		}
		initialsz(star_result);
		//����end���˳�
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
			cout << "\n��С�������������End����...";
			for (int i = 0; i < 3; i++)
				end[i] = getchar();
			if ((end[0] == 'e' || end[0] == 'E') && (end[1] == 'n' || end[1] == 'N') && (end[2] == 'd' || end[2] == 'D'))
				break;
			cout << "�����������������" << endl;
			while (getchar() != '\n')
				continue;
		}
	}
	
	while (getchar() != '\n')
		;
	return 0;
}

