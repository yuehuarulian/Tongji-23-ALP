/* ��04 2252941 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, mon, week, day=1;
	int daym=1;//һ���µ�������
	
	//�������²��ж�����
	int ret;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &year, &mon); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 2 && year >= 2000 && year <= 2030 && mon >= 1 && mon <= 12)
			break;
		else
			printf("����Ƿ�������������\n");
		if (ret != 2)
			while (getchar() != '\n');//��getchar+ѭ����ջ�����
	}
	//�������ڼ����ж�����
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, mon);
		ret = scanf("%d", &week); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 1 && week >= 0 && week <= 6)
		{
			printf("\n");
			break;
		}
		else
			printf("����Ƿ�������������\n");
		if (ret != 1)
			while (getchar() != '\n');//��getchar+ѭ����ջ����� 
	}

	//�ж�һ���µ�����
	if (mon == 4 || mon == 9 || mon == 11 || mon == 6)
		daym = 30;
	else if (mon != 2)
		daym = 31;
	else if (mon == 2)
		daym = 28 + (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

	//�������
	int n = 8, p = 1;
	printf("%d��%d�µ�����Ϊ:\n", year, mon);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	while (p < week * 8 + 4)
	{
		printf(" ");
		p++;
	}
	printf("1");
	for (day = 2, week += 1; day <= daym; day++, week++)
	{
		if (day <= 9)
			n = 8;
		else
			n = 7;
		if (week == 7)
		{
			printf("\n");
			week -= 7;
			if (day <= 9)
				n = 4;
			else
				n = 3;
		}
		p = 1;
		while (p < n)
		{
			printf(" ");
			p++;
		}
		printf("%d", day);

	}
	if (week == 7)
		printf("\n");
	printf("\n");




	return 0;
}