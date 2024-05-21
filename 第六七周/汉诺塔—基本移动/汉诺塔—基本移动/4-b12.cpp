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
    if (n == 1)
    {
        cout << " 1# " << src << "-->" << dst << endl;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
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
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        if (cin.good() && n >= 1 && n <= 16)
        {
            cin.clear();
            cin.ignore(100000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.good() && src == 65 || src == 97 || src == 66 || src == 98 || src == 67 || src == 99)
        {
            cin.clear();
            cin.ignore(100000, '\n');
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.good() && (dst == 65 || dst == 97 || dst == 66 || dst == 98 || dst == 67 || dst == 99) 
            && dst != src && dst != (src + 32) && dst != (src - 32))
        {
            cin.clear();
            cin.ignore(100000, '\n');
            break;
        }
        else if (dst == src|| dst != (src + 32) || dst != (src - 32))
        {
            cout << "目标柱(" << char(src >= 65 && src <= 67 ? src : src - 32) << ")不能与起始柱("
                << char(src >= 65 && src <= 67 ? src : src - 32) << ")相同" << endl;
            cin.clear();
            cin.ignore(100000, '\n');
        }
        else
        {
            cin.clear();
            cin.ignore(100000, '\n');
        }
    }
    if (src == 65 || src == 97)
    {
        if (dst == 66 || dst == 98)
        {
            src = 65;
            tmp = 67;
            dst = 66;
        }
        else
        {
            src = 65;
            tmp = 66;
            dst = 67;
        }
    }
    else if (src == 66 || src == 98)
    {
        if (dst == 65 || dst == 97)
        {
            src = 66;
            tmp = 67;
            dst = 65;
        }
        else
        {
            src = 66;
            tmp = 65;
            dst = 67;
        }
    }
    else
    {
        if (dst == 65 || dst == 97)
        {
            src = 67;
            tmp = 66;
            dst = 65;
        }
        else
        {
            src = 67;
            tmp = 65;
            dst = 66;
        }
    }
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}