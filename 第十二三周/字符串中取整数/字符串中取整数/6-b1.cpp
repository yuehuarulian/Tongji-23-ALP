/* 2252941 ������ ��04 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	pnum = &a[0];
	is_num = 0;
	for (p = &str[0]; *p != '\0'; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			is_num = 1;
			*pnum = *pnum * 10 + (*p - '0');
			if (p - str == 255)
				break;
			if (*(p + 1) < '0' || *(p + 1) > '9')
				pnum++;
			if (pnum - &a[0] == N)
				break;
		}
	}
	if (is_num)
	{
		cout << "����" << pnum - &a[0] << "������" << endl;
		for (pa = &a[0]; pa < pnum; pa++)
			cout << *pa << ' ';
	}
	else
		cout << "����" << 0 << "������" << endl;

	return 0;
}