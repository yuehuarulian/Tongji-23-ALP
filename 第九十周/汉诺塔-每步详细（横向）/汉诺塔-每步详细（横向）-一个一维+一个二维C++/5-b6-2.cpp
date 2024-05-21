/* 2252941 杨瑞灵 信04 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */
   //全局变量
int cou = 0;
int ABC[3][10] = { 0 };
int top[3] = { 0 };

/***************************************************************************
  函数名称：填充数组
  功    能：给出初始的数组
  输入参数：起始柱、层数
  返 回 值：
  说    明：
***************************************************************************/
void tcsz(char src, int n)
{
    int s = src - 'A';
    for (top[s] = 0; top[s] < n; top[s]++)
        ABC[s][top[s]] = n - top[s];
}

void changesz(char src, char dst)
{
    int s = src - 'A';
    int d = dst - 'A';
    ABC[d][top[d]++] = ABC[s][--top[s]];
    ABC[s][top[s]] = 0;
    return;
}

/***************************************************************************
    函数名称：out
    功    能：打印圆盘编号
    输入参数：
    返 回 值：
    说    明：
  ***************************************************************************/
void out()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        cout << (char)(i + 'A') << ":";
        for (j = 0; j < top[i]; j++)
            cout << setw(2) << ABC[i][j];
        for (j = 0; j < 10 - top[i]; j++)
            cout << "  ";
        cout << '\40';
    }
    cout << endl;
    return;
}

   /***************************************************************************
     函数名称：hanoi
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
    int s = src - 'A';
    int d = dst - 'A';
    if (n == 1)
    {
        cou++;
        yd = ABC[s][top[s] - 1];
        cout << "第" << setw(4) << cou << " 步(" << setw(2) << yd << "): " << src << "-->" << dst << '\40';
        changesz(src, dst);
        out();
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cou++;
        yd = ABC[s][top[s] - 1];
        cout << "第" << setw(4) << cou << " 步(" << setw(2) << yd << "): " << src << "-->" << dst << '\40';
        changesz(src, dst);
        out();
        hanoi(n - 1, tmp, src, dst);
        return;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    char src, tmp, dst;
    int n;
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

    //填充数组
    tcsz(src, n);

    //初始行输出
    cout << "初始:                ";
    out();

    //移动步骤输出
    hanoi(n, src, tmp, dst);

    return 0;
}
