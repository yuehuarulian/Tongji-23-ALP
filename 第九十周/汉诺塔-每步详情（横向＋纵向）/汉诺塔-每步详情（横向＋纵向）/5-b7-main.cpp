/* 2252941 ������ ��04 */
#include <iostream>
#include <cstdio>
#include "5-b7.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

//ȫ�ֱ���
int cou = 0;
int A[10] = { 0 };
int B[10] = { 0 };
int C[10] = { 0 };
int top_A = 0;
int top_B = 0;
int top_C = 0;
static int delay;
static int show;
void out();
void prime(char src,char dst,int n)
{
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << delay << "��" << (show == 1 ? "" : "��") << "��ʾ�ڲ�����ֵ";
    cct_gotoxy(19, 25);
    cout << "��ʼ:                ";
    int i;
    cout << "A:";
    for (i = 0; i < top_A; i++)
        cout <<setw(2)<< A[i];
    for (i = 0; i < 10 - top_A; i++)
        cout << "  ";
    cout << " ";

    cout << "B:";
    for (i = 0; i < top_B; i++)
        cout << setw(2) << B[i];
    for (i = 0; i < 10 - top_B; i++)
        cout << "  ";
    cout << " ";

    cout << "C:";
    for (i = 0; i < top_C; i++)
        cout << setw(2) << C[i];
    for (i = 0; i < 10 - top_B; i++)
        cout << "  ";
    cout << " ";
    return;
}

/***************************************************************************
  �������ƣ��������
  ��    �ܣ�������ʼ������
  �����������ʼ��������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tcsz(char src, int n)
{
    if (src == 'A')
    {
        for (top_A = 0; top_A < n; top_A++)
            A[top_A] = n - top_A;
    }
    else if (src == 'B')
    {
        for (top_B = 0; top_B < n; top_B++)
            B[top_B] = n - top_B;
    }
    else if (src == 'C')
    {
        for (top_C = 0; top_C < n; top_C++)
            C[top_C] = n - top_C;
    }
}

void changesz(char src, char dst)
{
    if (src == 'A' && dst == 'B')
    {
        B[top_B++] = A[--top_A];
        A[top_A] = 0;
    }
    else if (src == 'A' && dst == 'C')
    {
        C[top_C++] = A[--top_A];
        A[top_A] = 0;
    }
    else if (src == 'B' && dst == 'A')
    {
        A[top_A++] = B[--top_B];
        B[top_B] = 0;
    }
    else if (src == 'B' && dst == 'C')
    {
        C[top_C++] = B[--top_B];
        B[top_B] = 0;
    }
    else if (src == 'C' && dst == 'A')
    {
        A[top_A++] = C[--top_C];
        C[top_C] = 0;
    }
    else if (src == 'C' && dst == 'B')
    {
        B[top_B++] = C[--top_C];
        C[top_C] = 0;
    }
    return;
}

/***************************************************************************
    �������ƣ�out
    ��    �ܣ���ӡԲ�̱��
    ���������
    �� �� ֵ��
    ˵    ����
  ***************************************************************************/
void out(int yd, char src, char dst,int n)
{
    int i;
    if (!delay)
    {
        while (getchar() != '\n')
            continue;
    }
    else
        Sleep(100 * (5.05 - delay));
    //������ʾ
    cct_gotoxy(9, 20);
    cout << "=========================";
    cct_gotoxy(9, 21);
    cout << "  A         B         C  ";
    for (i = 0; i < top_A; i++)
    {
        cct_gotoxy(11, 19 - i);
        cout << A[i];
    }
    for (i = 0; i < 10 - top_A; i++)
    {
        cct_gotoxy(11, 19 - top_A - i);
        cout << ' ';
    }
    for (i = 0; i < top_B; i++)
    {
        cct_gotoxy(21, 19 - i);
        cout << B[i];
    }
    for (i = 0; i < 10 - top_B; i++)
    {
        cct_gotoxy(21, 19 - top_B - i);
        cout << ' ';
    }
    for (i = 0; i < top_C; i++)
    {
        cct_gotoxy(31, 19 - i);
        cout << C[i];
    }
    for (i = 0; i < 10 - top_C; i++)
    {
        cct_gotoxy(31, 19 - top_C - i);
        cout << ' ';
    }
 
    //������ʾ
    if(show)
    {
        if (!delay)
        {
            while (getchar() != '\n')
                continue;
        }
        else
        {
            Sleep(100 * (5.05 - delay));
        }
        cct_gotoxy(19, 25);
        cout << "��" << setw(4) << cou << "��(" << setw(2) << yd << ": " << src << "-->" << dst << ")  ";
        changesz(src, dst);

        cout << "A:";
        for (i = 0; i < top_A; i++)
            cout << setw(2) << A[i];
        for (i = 0; i < 10 - top_A; i++)
            cout << "  ";
        cout << " ";
        cout << "B:";
        for (i = 0; i < top_B; i++)
            cout << setw(2) << B[i];
        for (i = 0; i < 10 - top_B; i++)
            cout << "  ";
        cout << " ";
        cout << "C:";
        for (i = 0; i < top_C; i++)
            cout << setw(2) << C[i];
        for (i = 0; i < 10 - top_B; i++)
            cout << "  ";
        cout << " ";
    }
    else
        changesz(src, dst);
    return;
}

/***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int yd = 0;//��ǰ�ƶ��̺�
    if (n == 1)
    {
        cou++;
        if (src == 'A')
            yd = A[top_A - 1];
        else if (src == 'B')
            yd = B[top_B - 1];
        else if (src == 'C')
            yd = C[top_C - 1];
        out(yd,src,dst,n);
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cou++;
        if (src == 'A')
            yd = A[top_A - 1];
        else if (src == 'B')
            yd = B[top_B - 1];
        else if (src == 'C')
            yd = C[top_C - 1];
        out(yd, src, dst,n);
        hanoi(n - 1, tmp, src, dst);
        return;
    }
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    char src, tmp, dst;
    int n;
    //�������ӺͲ���
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && n >= 1 && n <= 10)
            break;
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && src == 65 || src == 97 || src == 66 || src == 98 || src == 67 || src == 99)
            break;
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')
            && dst != src && dst != (src + 'a' - 'A') && dst != (src - 'a' + 'A'))
            break;
        else if (dst == src || dst != (src + 'a' - 'A') || dst != (src - 'a' + 'A'))
            cout << "Ŀ����(" << char(src >= 65 && src <= 67 ? src : src - 32) << ")��������ʼ��("
            << char(src >= 65 && src <= 67 ? src : src - 32) << ")��ͬ" << endl;
    }
    if (src >= 'a')
        src -= 32;
    if (dst >= 'a')
        dst -= 32;
    tmp = 'A' + 'B' + 'C' - src - dst;
    //�����ƶ��ٶ�  �Ƿ���ʾ����
    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> delay; 
        if (cin.good()&&delay >= 0 && delay <= 5)
            break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while (1)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> show;
        if (cin.good() && show == 0 || show == 1)
            break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.clear();
    cin.ignore(10000, '\n');
    //�������
    tcsz(src, n);

    //�������
    cct_cls();
    if(show)
        prime(src, dst, n);
    //�ƶ��������
    hanoi(n, src, tmp, dst);








    cct_gotoxy(0, 26);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}