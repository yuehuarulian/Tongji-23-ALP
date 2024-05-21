/* 2252941 杨瑞灵 信04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */
//全局变量
int count = 0;
int A[10] = { 0 };
int B[10] = { 0 };
int C[10] = { 0 };
int top_A = 0;
int top_B = 0;
int top_C = 0;

/***************************************************************************
  函数名称：填充数组
  功    能：给出初始的数组
  输入参数：起始柱、层数
  返 回 值：
  说    明：
***************************************************************************/
void tcsz(char src,int n)
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
void out()
{
    int i;
    printf("A:");
    for (i = 0; i < top_A; i++)
        printf("%2d", A[i]);
    for (i = 0; i < 10 - top_A; i++)
        printf("  ");
    printf(" ");

    printf("B:");
    for (i = 0; i < top_B; i++)
        printf("%2d", B[i]);
    for (i = 0; i < 10 - top_B; i++)
        printf("  ");
    printf(" ");

    printf("C:");
    for (i = 0; i < top_C; i++)
        printf("%2d", C[i]);
    for (i = 0; i < 10 - top_B; i++)
        printf("  ");
    printf(" ");

    printf(" \n");
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
        count++;
        if (src == 'A')
            yd = A[top_A-1];
        else if (src == 'B')
            yd = B[top_B-1];
        else if (src == 'C')
            yd = C[top_C-1];
        printf("第%4d 步(%2d): %c-->%c ", count, yd, src, dst);
        changesz(src, dst);
        out();
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        count++;
        if (src == 'A')
            yd = A[top_A - 1];
        else if (src == 'B')
            yd = B[top_B - 1];
        else if (src == 'C')
            yd = C[top_C - 1];
        printf("第%4d 步(%2d): %c-->%c ", count, yd, src, dst);
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
    int n;//层数
    int i, j, k;//循环计数
    int ret;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        ret=scanf("%d", &n);
        if (ret==1 && n >= 1 && n <= 10)
        {
            while (getchar() != '\n')
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret=scanf("%c", &src);
        if (ret==1 && src == 'A' || src == 'a' || src == 'B' || src == 'b' || src == 'C' || src == 'c')
        {
            while (getchar() != '\n')
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret=scanf("%c", &dst);
        if (ret==1 && (dst == 'A' || dst == 'a' || dst == 'B' || dst == 'b' || dst == 'C' || dst == 'c')
            && dst != src && dst != (src + 'a' - 'A') && dst != (src - 'a'+'A'))
        {
            while (getchar() != '\n')
                continue;
            break;
        }
        else if (dst == src || dst != (src + 'a' - 'A') || dst != (src - 'a' + 'A'))
        {
            char src_t = (char)(src >= 65 && src <= 67 ? src : src - 32);
            printf("目标柱(%c)不能与起始柱(%c)相同\n", src_t, src_t);
            while (getchar() != '\n')
                continue;
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    if (src == 'A' || src == 'a')
    {
        if (dst == 'B' || dst == 'b')
        {
            src = 'A';
            tmp = 'C';
            dst = 'B';
        }
        else
        {
            src = 'A';
            tmp = 'B';
            dst = 'C';
        }
    }
    else if (src == 'B' || src == 'b')
    {
        if (dst == 'A' || dst == 'a')
        {
            src = 'B';
            tmp = 'C';
            dst = 'A';
        }
        else
        {
            src = 'B';
            tmp = 'A';
            dst = 'C';
        }
    }
    else
    {
        if (dst == 'A' || dst == 'a')
        {
            src = 'C';
            tmp = 'B';
            dst = 'A';
        }
        else
        {
            src = 'C';
            tmp = 'A';
            dst = 'B';
        }
    }

    //填充数组
    tcsz(src,n);

    //初始行输出
    printf("初始:                ");
    out();
  
    //移动步骤输出
    hanoi(n, src, tmp, dst);

    return 0;
}
