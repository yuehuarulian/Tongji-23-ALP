/* ѧ�� ���� �༶ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    char src, tmp, dst;
    int n;
    int ret;
    printf("�����뺺ŵ���Ĳ���(1-16)\n");
    while (1)
    {
        ret = scanf("%d", &n);
        if (ret == 1 && (n >= 1 && n <= 16))
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
        }
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
    }
    while (1)
    {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &src);
        if (ret == 1 && src == 65 || src == 97 || src == 66 || src == 98 || src == 67 || src == 99)
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
            break;
        }
        else
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
        }
    }

    while (1)
    {
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &dst);
        if (ret == 1 && (dst == 65 || dst == 97 || dst == 66 || dst == 98 || dst == 67 || dst == 99)
            && dst != src && dst != (src + 32) && dst != (src - 32))
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
            break;
        }
        else if (dst == src || dst != (src + 32) || dst != (src - 32))
        { 
            char ch;
            ch = src >= 65 && src <= 67 ? src : src - 32;
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", ch, ch);
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
                continue;
        }
        else
        {
            while (getchar() != '\n')//��getchar+ѭ����ջ�����
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);

    return 0;
}