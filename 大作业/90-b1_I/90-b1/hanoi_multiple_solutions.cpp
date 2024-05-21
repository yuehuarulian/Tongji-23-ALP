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
static int delay = 5;
static int cou = 0;
const int base_position_h = 25;
const int base_position_z = 20;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ��������ӺͲ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void f_in(char *src, char *tmp, char *dst, int *n,int option)
{
    cou = 0;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> *n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && *n >= 1 && *n <= 10)
            break;
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> *src;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && *src == 'a' || *src == 'A' || *src == 'b' || *src == 'B' || *src == 'c' || *src == 'C')
            break;
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *dst;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && (*dst == 'A' || *dst == 'a' || *dst == 'B' || *dst == 'b' || *dst == 'C' || *dst == 'c')
            && *dst != *src && *dst != (*src + 'a' - 'A') && *dst != (*src - 'a' + 'A'))
            break;
        else if (*dst == *src || *dst != (*src + 'a' - 'A') || *dst != (*src - 'a' + 'A'))
            cout << "Ŀ����(" << char(*src >= 65 && *src <= 67 ? *src : *src - 32) << ")��������ʼ��("
            << char(*src >= 65 && *src <= 67 ? *src : *src - 32) << ")��ͬ" << endl;
    }
    if (*src >= 'a')
        *src -= 32;
    if (*dst >= 'a')
        *dst -= 32;
    *tmp = 'A' + 'B' + 'C' - *src - *dst;
    while (option==4||option==8)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> delay;
        if (cin.good() && delay >= 0 && delay <= 5)
            break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
void hanoi(int n, char src, char tmp, char dst, int option, int han[][10], int top[])
{
    if (n == 1){
        cou++;
        f_out(n, src, tmp, dst, option, han, top);
    }
    else {
        hanoi(n - 1, src, dst, tmp, option, han, top);
        cou++;
        f_out(n, src, tmp, dst, option, han, top);
        hanoi(n - 1, tmp, src, dst, option, han, top);
    }
}
void f_out(int n, char src, char tmp, char dst, int option, int han[][10], int top[])
{
    int yd = 0;//��ǰ�ƶ��̺�
    yd = han[src - 'A'][top[src - 'A'] - 1];
    if (option == 1)
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
    if (option == 2)
        cout << "��" << setw(4) << cou << "��(" << setw(2) << n << "# " << src << "-->" << dst << ")" << endl;
    if (option == 3)
    {
        changesz(src, dst, han, top);
        out_h(yd, src, dst, option, han, top,0);
    }
    if (option == 4)
    {
        changesz(src, dst, han, top);
        if (!delay)
        {
            while (getchar() != '\n')
                continue;
        }
        else
        {
            Sleep(502 - delay * 100);
        }
        out_h(yd, src, dst, option, han, top,0);
        out_z(yd, src, dst, option, han, top,0);
    }
    if (option == 8)
    {
        if (!delay)
        {
            while (getchar() != '\n')
                continue;
        }
        else
        {
            Sleep(502 - delay * 100);
        }
        move_z(han[src-'A'][top[src - 'A'] - 1], (src - 'A') * 32 + 12, 15 - top[src - 'A'], (dst - 'A') * 32 + 12, 14 - top[dst - 'A']);
        changesz(src, dst, han, top);
        out_h(yd, src, dst, option, han, top, 1);
        out_z(yd, src, dst, option, han, top, 1);
    }
}
void tcsz(char src, int n,int han[][10],int top[])
{
    int s = src - 'A';
    for (top[s] = 0; top[s] < n; top[s]++)
        han[s][top[s]] = n - top[s];
}
void changesz(char src, char dst,int han[][10],int top[])
{
    int s = src - 'A';
    int d = dst - 'A';
    han[d][top[d]++] = han[s][--top[s]];
    han[s][top[s]] = 0;
    return;
}
void out_h(int yd, char src, char dst, int option, int han[][10], int top[], int h)
{
    int i, j;
    if (option != 3)
        cct_gotoxy(0, base_position_h + 7 * h);
    cout << "��" << setw(4) << cou << " ��(" << setw(2) << yd << "): " << src << "-->" << dst << '\40';
    for (i = 0; i < 3; i++)
    {
        cout << (char)(i + 'A') << ":";
        for (j = 0; j < top[i]; j++)
            cout << setw(2) << han[i][j];
        for (j = 0; j < 10 - top[i]; j++)
            cout << "  ";
        cout << '\40';
    }
    cout << endl;
    return;
}
void prime(char src, char dst, int n,int han[][10],int top[],int h)
{
    if (h == 0)
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay;
    cct_gotoxy(0, base_position_h +7*h);
    cout << "��ʼ:                ";
    int i;
    for (int j = 0; j < 3; j++)
    {
        cout << char('A' + j) << ':';
        for (i = 0; i < top[j]; i++)
            cout << setw(2) << han[j][i];
        for (i = 0; i < 10 - top[j]; i++)
            cout << "  ";
        cout << " ";
    }
}
void out_z(int yd, char src, char dst, int option, int han[][10], int top[], int h)
{
    int i;
    cct_gotoxy(9, base_position_z + h * 7);
    cout << "=========================";
    cct_gotoxy(9, base_position_z + 1 + h * 7);
    cout << "  A         B         C  ";
    for (int j = 0; j < 3; j++)
    {
        for (i = 0; i < top[j]; i++)
        {
            cct_gotoxy(10 * (j + 1) + 1, base_position_z - 1 + h * 7 - i);
            cout << han[j][i];
        }
        for (i = 0; i < 10 - top[j]; i++)
        {
            cct_gotoxy(10 * (j + 1) + 1, base_position_z - 1 + h * 7 - top[j] - i);
            cout << ' ';
        }
    }
    if (!delay)
    {
        while (getchar() != '\n')
            continue;
    }
    else
    {
        Sleep(502 - delay * 100);
    }
    return;
}

void draw_z(int option)
{
    if (option == 8)
        cout << "����ʱ����Ϊ " << delay;
    for (int j = 0; j <= 64; j += 32)
    {
        for (int i = 1; i <= 23; i++)
        {
            Sleep(3);
            cct_showch(i+j, 15, ' ', 14, 0, 1);
        }
    }
   
    for (int i = 14; i >= 3; i--)
    {
        for (int j = 0; j <= 64; j += 32)
        {
            Sleep(20);
            cct_showch(12 + j, i, ' ', 14, 0, 1);
        }
    }
    cct_setcolor(0,7); //�ָ�ȱʡ��ɫ
    return;
}
void draw_p(int n, int han[][10], int top[])
{
    int i, j;
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < top[j]; i++)
        {
            Sleep(5);
            draw_p_each(han[j][i], j * 32 + 12, 14 - i);
        }
    }
    cct_setcolor(0, 7); //�ָ�ȱʡ��ɫ
    return;
}
void draw_p_each(int num, int x, int y)
{
    int i;
    for (i = 0; i < 2 * num + 1; i++)
    {
        cct_showch(x - num + i, y, ' ', num, 7, 1);
    }
    cct_setcolor(0, 7); //�ָ�ȱʡ��ɫ
    return;
}
void erase_p_each(int num, int x, int y)
{
    int i;
    for (i = 0; i < 2 * num + 1; i++)
    {
        cct_showch(x - num + i, y, ' ', 0, 7, 1);
    }
    if (y != 1 && y != 2)
    {
        cct_showch(x, y, ' ', 14, 7, 1);
    }
    cct_setcolor(0, 7); //�ָ�ȱʡ��ɫ
    return;
}
void move_z(int num, int x1, int y1, int x2, int y2)
{
    int i;
    for (i = y1; i > 1; i--)
    {
        Sleep(250 - 50 * delay);
        erase_p_each(num, x1, i);
        draw_p_each(num, x1, i - 1);
    }
    if(x1<x2)
    {
        for (i = x1; i < x2; i++)
        {
            Sleep(250 - 50 * delay);
            erase_p_each(num, i, 1);
            draw_p_each(num, i + 1, 1);
        }
    }
    else
    {
        for (i = x1; i > x2; i--)
        {
            Sleep(250 - 50 * delay);
            erase_p_each(num, i, 1);
            draw_p_each(num, i - 1, 1);
        }
    }
    for (i = 1; i < y2; i++)
    {
        Sleep(250 - 50 * delay);
        erase_p_each(num, x2, i);
        draw_p_each(num, x2, i + 1);
    }
    return;
}

int f_in_I(char* src_I, char* dst_I, int han[][10], int top[])
{
    char a[1000] = { 0 };
    bool b = 1;
    while (1)
    {

        while (1)
        {
            cct_gotoxy(56, 34);
            cin >> a;
            if ((a[0] == 'q' || a[0] == 'Q') && a[1] == 0)
                return 0;
            if ((a[0] == 'a' || a[0] == 'A' || a[0] == 'b' || a[0] == 'B' || a[0] == 'c' || a[0] == 'C')
                && (a[1] == 'a' || a[1] == 'A' || a[1] == 'b' || a[1] == 'B' || a[1] == 'c' || a[1] == 'C')
                && a[1] != a[0] && a[1] != (a[0] - 'a' - 'A') && a[1] != (a[0] - 'a' + 'A') && a[2] == 0)
                break;
            a[0] = 0;
            a[1] = 0;
            cct_gotoxy(56, 34);
            cout << "                                                                       ";
        }
        cct_gotoxy(56, 34);
        cout << "                                                                           ";
        if (a[0] >= 'a')
            a[0] -= 32;
        if (a[1] >= 'a')
            a[1] -= 32;
        *src_I = a[0];
        *dst_I = a[1];
        if (top[*src_I - 'A'] - 1 < 0)
        {
            cct_gotoxy(0, 35);
            cout << "Դ��Ϊ��";
            Sleep(400);
            cct_gotoxy(0, 35);
            cout << "        ";
            continue;
        }
        if (top[*dst_I - 'A'] - 1 >= 0 && han[*src_I - 'A'][top[*src_I - 'A'] - 1] > han[*dst_I - 'A'][top[*dst_I - 'A'] - 1])
        {
            cct_gotoxy(0, 35);
            cout << "����ѹС�̣��Ƿ��ƶ�";
            Sleep(400);
            cct_gotoxy(0, 35);
            cout << "                    ";
            continue;
        }
        break;
    }
    cou++;
    return 1;
}