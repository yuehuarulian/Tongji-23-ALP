/* 学号 姓名 班级 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
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
int jb = 0;
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        jb += 1;
        printf("%5d:  1# %c-->%c\n", jb, src, dst);
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        jb += 1;
        printf("%5d:%3d# %c-->%c\n", jb, n, src, dst);
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
    int ret;
    printf("请输入汉诺塔的层数(1-16)\n");
    while (1)
    {
        ret = scanf("%d", &n);
        if (ret == 1 && (n >= 1 && n <= 16))
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
        }
        printf("请输入汉诺塔的层数(1-16)\n");
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        if (ret == 1 && src == 65 || src == 97 || src == 66 || src == 98 || src == 67 || src == 99)
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
        }
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        if (ret == 1 && (dst == 65 || dst == 97 || dst == 66 || dst == 98 || dst == 67 || dst == 99)
            && dst != src && dst != (src + 32) && dst != (src - 32))
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
            break;
        }
        else if (dst == src || dst != (src + 32) || dst != (src - 32))
        { 
            char ch;
            ch = src >= 65 && src <= 67 ? src : src - 32;
            printf("目标柱(%c)不能与起始柱(%c)相同\n", ch, ch);
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
        }
        else
        {
            while (getchar() != '\n')//用getchar+循环清空缓存区
                continue;
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
    printf("移动步骤为:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}