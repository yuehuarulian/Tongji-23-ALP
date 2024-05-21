/* 2252941 杨瑞灵 信04 */
#include <iostream>
#include <cstdio>
#include "5-b7.h"
#include <iomanip>
#include <Windows.h>
using namespace std;

//全局变量
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
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay << "，" << (show == 1 ? "" : "不") << "显示内部数组值";
    cct_gotoxy(19, 25);
    cout << "初始:                ";
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
  函数名称：填充数组
  功    能：给出初始的数组
  输入参数：起始柱、层数
  返 回 值：
  说    明：
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
    函数名称：out
    功    能：打印圆盘编号
    输入参数：
    返 回 值：
    说    明：
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
    //纵向显示
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
 
    //横向显示
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
        cout << "第" << setw(4) << cou << "步(" << setw(2) << yd << ": " << src << "-->" << dst << ")  ";
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
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    int yd = 0;//当前移动盘号
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    char src, tmp, dst;
    int n;
    //输入柱子和层数
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && n >= 1 && n <= 10)
            break;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && src == 65 || src == 97 || src == 66 || src == 98 || src == 67 || src == 99)
            break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(100000, '\n');
        if (cin.good() && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')
            && dst != src && dst != (src + 'a' - 'A') && dst != (src - 'a' + 'A'))
            break;
        else if (dst == src || dst != (src + 'a' - 'A') || dst != (src - 'a' + 'A'))
            cout << "目标柱(" << char(src >= 65 && src <= 67 ? src : src - 32) << ")不能与起始柱("
            << char(src >= 65 && src <= 67 ? src : src - 32) << ")相同" << endl;
    }
    if (src >= 'a')
        src -= 32;
    if (dst >= 'a')
        dst -= 32;
    tmp = 'A' + 'B' + 'C' - src - dst;
    //输入移动速度  是否显示数组
    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> delay; 
        if (cin.good()&&delay >= 0 && delay <= 5)
            break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show;
        if (cin.good() && show == 0 || show == 1)
            break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.clear();
    cin.ignore(10000, '\n');
    //填充数组
    tcsz(src, n);

    //输出柱子
    cct_cls();
    if(show)
        prime(src, dst, n);
    //移动步骤输出
    hanoi(n, src, tmp, dst);








    cct_gotoxy(0, 26);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}