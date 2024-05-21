/* 2252941 ������ ��04 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */
   //ȫ�ֱ���
int cou = 0;
int ABC[3][10] = { 0 };
int top[3] = { 0 };

/***************************************************************************
  �������ƣ��������
  ��    �ܣ�������ʼ������
  �����������ʼ��������
  �� �� ֵ��
  ˵    ����
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
    �������ƣ�out
    ��    �ܣ���ӡԲ�̱��
    ���������
    �� �� ֵ��
    ˵    ����
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
     �������ƣ�hanoi
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
    int s = src - 'A';
    int d = dst - 'A';
    if (n == 1)
    {
        cou++;
        yd = ABC[s][top[s] - 1];
        cout << "��" << setw(4) << cou << " ��(" << setw(2) << yd << "): " << src << "-->" << dst << '\40';
        changesz(src, dst);
        out();
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cou++;
        yd = ABC[s][top[s] - 1];
        cout << "��" << setw(4) << cou << " ��(" << setw(2) << yd << "): " << src << "-->" << dst << '\40';
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
    int n;
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

    //�������
    tcsz(src, n);

    //��ʼ�����
    cout << "��ʼ:                ";
    out();

    //�ƶ��������
    hanoi(n, src, tmp, dst);

    return 0;
}
