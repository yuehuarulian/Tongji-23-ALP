/* 2252941 ������ ��04 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */
//ȫ�ֱ���
int count = 0;
int A[10] = { 0 };
int B[10] = { 0 };
int C[10] = { 0 };
int top_A = 0;
int top_B = 0;
int top_C = 0;

/***************************************************************************
  �������ƣ��������
  ��    �ܣ�������ʼ������
  �����������ʼ��������
  �� �� ֵ��
  ˵    ����
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
    �������ƣ�out
    ��    �ܣ���ӡԲ�̱��
    ���������
    �� �� ֵ��
    ˵    ����
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
        count++;
        if (src == 'A')
            yd = A[top_A-1];
        else if (src == 'B')
            yd = B[top_B-1];
        else if (src == 'C')
            yd = C[top_C-1];
        printf("��%4d ��(%2d): %c-->%c ", count, yd, src, dst);
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
        printf("��%4d ��(%2d): %c-->%c ", count, yd, src, dst);
        changesz(src, dst);
        out();
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
    int n;//����
    int i, j, k;//ѭ������
    int ret;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
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
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src_t, src_t);
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

    //�������
    tcsz(src,n);

    //��ʼ�����
    printf("��ʼ:                ");
    out();
  
    //�ƶ��������
    hanoi(n, src, tmp, dst);

    return 0;
}
