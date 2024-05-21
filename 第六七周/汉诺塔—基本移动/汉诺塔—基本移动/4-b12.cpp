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
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
            cout << "Ŀ����(" << char(src >= 65 && src <= 67 ? src : src - 32) << ")��������ʼ��("
                << char(src >= 65 && src <= 67 ? src : src - 32) << ")��ͬ" << endl;
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
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}